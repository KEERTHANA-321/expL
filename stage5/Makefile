LEX = flex
YACC = yacc
CC = gcc
CFLAGS = -Wall -g -std=gnu11
LIBS = -ll

COMPILER_EXE = compiler
LINKER_EXE = linker

C_SRCS = codegen.c nodestructure.c symbolTable.c typecheck.c
COMPILER_LEX = lex.l
COMPILER_YACC = first.y
LINKER_LEX = linker_lex.l
LINKER_SRC = label.c

XSM_OUTPUT = final.xsm

all: $(COMPILER_EXE) $(LINKER_EXE)

$(COMPILER_EXE): y.tab.c lex.yy.c $(C_SRCS)
	$(CC) $(CFLAGS) y.tab.c lex.yy.c $(C_SRCS) -o $(COMPILER_EXE) $(LIBS)

$(LINKER_EXE): $(LINKER_LEX) $(LINKER_SRC)
	$(LEX) -o label_lex.c $(LINKER_LEX)
	$(CC) $(CFLAGS) label_lex.c $(LINKER_SRC) -o $(LINKER_EXE) $(LIBS)
	@rm -f label_lex.c

y.tab.c y.tab.h: $(COMPILER_YACC)
	$(YACC) -d $(COMPILER_YACC)

lex.yy.c: $(COMPILER_LEX) y.tab.h
	$(LEX) $(COMPILER_LEX)

run: $(COMPILER_EXE)
	./$(COMPILER_EXE)

translate: $(LINKER_EXE)
	./$(LINKER_EXE)

generate: clean all
	@echo "--- Running Compiler ---"
	./$(COMPILER_EXE) test6.expl
	@echo "--- Running Label Translator"
	./$(LINKER_EXE)
	@echo "--- Done ---"

clean:
	rm -f lex.yy.c y.tab.c y.tab.h label_lex.c
	rm -f $(COMPILER_EXE) $(LINKER_EXE)
	rm -f $(OUT_DIR)/compiler $(OUT_DIR)/linker


# This is the relative path to the folder where xsm is present
ROOT_DIR = ../../..

test: all
	@echo "--- Starting Automated Testing ---"
	@if [ ! -d "io/expl" ]; then \
		echo "Error: 'io/expl' directory not found."; \
		exit 1; \
	fi
	@if [ ! -f "$(ROOT_DIR)/xsm" ]; then \
		echo "Error: 'xsm' not found at $(ROOT_DIR)/xsm"; \
		exit 1; \
	fi
	@# Initialize counters; use backslashes to run entire block in one shell session
	@total=0; pass=0; fail=0; \
	for src in $$(find io/expl -name "*.expl"); do \
		rel_path=$${src#io/expl/}; \
		base_name=$${rel_path%.expl}; \
		input_file="io/input/$$base_name.txt"; \
		output_file="io/output/$$base_name.txt"; \
		expect_file="io/expected_output/$$base_name.txt"; \
		\
		echo "Testing: $$base_name"; \
		total=$$((total + 1)); \
		\
		# 1. Run Compiler \
		./$(COMPILER_EXE) $$src > /dev/null; \
		if [ $$? -ne 0 ]; then \
			echo "  [ERROR] Compilation failed."; \
			fail=$$((fail + 1)); \
			continue; \
		fi; \
		\
		# 2. Run Linker \
		./$(LINKER_EXE) > /dev/null; \
		if [ $$? -ne 0 ]; then \
			echo "  [ERROR] Linking failed."; \
			fail=$$((fail + 1)); \
			continue; \
		fi; \
		\
		# 3. Prepare Output Directory \
		mkdir -p $$(dirname $$output_file); \
		\
		# Calculate paths relative to ROOT_DIR \
		xsm_rel=$$(realpath --relative-to=$(ROOT_DIR) $(XSM_OUTPUT)); \
		input_rel=$$(realpath --relative-to=$(ROOT_DIR) $$input_file); \
		output_rel=$$(realpath --relative-to=$(ROOT_DIR) $$output_file); \
		\
		# 4. Run XSM \
		if [ -f $$input_file ]; then \
			(cd $(ROOT_DIR) && bash ./xsm -l library.lib -e $$xsm_rel < $$input_rel > $$output_rel); \
		else \
			(cd $(ROOT_DIR) && bash ./xsm -l library.lib -e $$xsm_rel > $$output_rel); \
		fi; \
		\
		# 5. Compare Results \
		if [ -f $$expect_file ]; then \
			if diff -w -B $$output_file $$expect_file > /dev/null; then \
				printf "  \033[0;32m[PASS]\033[0m\n"; \
				pass=$$((pass + 1)); \
			else \
				printf "  \033[0;31m[FAIL]\033[0m Output differs from expected.\n"; \
				printf "         See: $$output_file\n"; \
				fail=$$((fail + 1)); \
			fi; \
		else \
			printf "  [WARN] No expected output file found.\n"; \
			# Optional: Increment fail if you consider missing expected output a failure \
			# fail=$$((fail + 1)); \
		fi; \
	done; \
	\
	printf "\n========================================\n"; \
	printf "             TEST SUMMARY               \n"; \
	printf "========================================\n"; \
	printf "  TOTAL TESTS : $$total\n"; \
	printf "  PASSED      : \033[0;32m$$pass\033[0m\n"; \
	printf "  FAILED      : \033[0;31m$$fail\033[0m\n"; \
	printf "========================================\n"; \
	if [ $$fail -gt 0 ]; then exit 1; fi

.PHONY: all clean run translate generate test