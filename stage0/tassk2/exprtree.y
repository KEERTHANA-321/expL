%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "exprtree.h"
    #include "exprtree.c"

    int yylex(void);
    void yyerror(char const *msg);

    int regno=-1;
    int maxreg=20;
    FILE* target_file;
    #define reg_index int
    reg_index codeGen( struct tnode *t);
    reg_index operatorCodeGen(struct tnode *t,reg_index p,reg_index q);
    void write(int var);
    int getReg();
    void freeReg();
%}


%union {
    struct tnode *node;
}

%type <node> expr NUM program END
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program : expr END {
    $$ = $1;
    printf("Answer: %d\n", evaluate($1));
    printf("Postfix:\n");
    postfix($1);
    printf("\nPrefix:\n");
    print($1);
    prefix($1);
    fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
    fprintf(target_file, "BRKP\n");
    fprintf(target_file, "MOV SP, %d\n", 4097);
    reg_index r=codeGen($1);
    fprintf(target_file,"MOV [%d],R%d\n",4096,r);
    write(4096);
    reg_index reg = getReg();
    fprintf(target_file, "MOV R%d, \"%s\"\n", reg, "Exit");
    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "CALL 0\n");
    
    exit(0);
};

expr : expr PLUS expr { $$ = makeOperatorNode('+', $1, $3); }
    | expr MINUS expr { $$ = makeOperatorNode('-', $1, $3); }
    | expr MUL expr { $$ = makeOperatorNode('*', $1, $3); }
    | expr DIV expr { $$ = makeOperatorNode('/', $1, $3); }
    | '(' expr ')' { $$ = $2; }
    | NUM { $$ = $1;}
    ;

%%


void freeReg(){
    if(regno>=0){
        regno--;
    }
}
int getReg(){
    if(regno==maxreg-1){
        printf("Out of registers\n");
        freeReg();
        return getReg();
    }
    else{
        regno++;
        return regno;
    }
}

void write(int var) {
    int reg = getReg();
    fprintf(target_file, "MOV R%d, \"%s\"\n", reg, "Write");
    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "MOV R%d, %d\n", reg, -2);
    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "MOV R%d, [%d]\n", reg, var);
    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "CALL 0\n");
}


void yyerror(char const *msg) {
    printf("[Error] : %s\n", msg);
    return;
}

reg_index operatorCodeGen(struct tnode *t,reg_index p,reg_index q){
    char c=t->op[0];
    switch(c){
        case '+':{
            fprintf(target_file, "ADD R%d, R%d\n", p,q);
            break;
        }
        case '*':{
            fprintf(target_file, "MUL R%d, R%d\n", p,q);
            break;
        }
        case '-':{
            fprintf(target_file, "SUB R%d, R%d\n", p,q);
            break;
        }
        case '/':{
            fprintf(target_file, "DIV R%d, R%d\n", p,q);
            break;
        }


    }
    freeReg();
    return p;
}
reg_index codeGen( struct tnode *t) {
    if(!t) return -1;
    reg_index left=codeGen(t->left);
    reg_index right=codeGen(t->right);
    
    if(!t->op){
        int p=getReg();
        fprintf(target_file,"MOV R%d,%d\n",p,t->val);
        return p;
    }
    else{
        if(left!=-1 && right!=-1){
            return operatorCodeGen(t,left,right);
        }
        else return -1;
        
    }
} 

int main() {
    target_file = fopen("result.xsm", "w");
    return yyparse();
}