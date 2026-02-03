#ifndef CONSTANTS_H
#define CONSTANTS_H

#define NOT_CONSTANT 1000000

#define regIndex int

#define STACK_START 4096

#define SOURCE_FILE "input.expl"
#define OUTPUT_FILE "result.xsm"

enum type {
    INT,
    STRING,
    BOOL,
    NONE,
    
};

enum nodeTypes {
    EMPTY_NODE,
    ASSIGN_NODE,
    CONNECTOR_NODE,
    VARIABLE_NODE,
    STRVAL_NODE,
    ARRAY_NODE,
    NUM_NODE,
    READ_NODE,
    WRITE_NODE,
    ADD_NODE,
    SUB_NODE,
    MUL_NODE,
    DIV_NODE,
    LT_NODE,
    LE_NODE,
    GE_NODE,
    GT_NODE,
    EQ_NODE,
    NE_NODE,
    IF_NODE,
    IF_ELSE_NODE,
    WHILE_NODE,
    BREAK_NODE,
    CONT_NODE,
    DOWHILE_NODE,
    REPEAT_NODE,
    MOD_NODE
};
int getLabel();
void freeReg();
int getReg();
void generateExitCode();
void initialize();
  
#endif