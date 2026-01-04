#ifndef CONSTANTS_H
#define CONSTANTS_H

enum nodeType{
    NODE_NUM = 1,
    NODE_ID,

    NODE_PLUS,
    NODE_MINUS,  
    NODE_MUL,
    NODE_DIV,   
    
    NODE_ASSIGN,

    NODE_READ, 
    NODE_WRITE,

    NODE_CONNECTOR,

    NODE_WHILE,
    NODE_IF,
    NODE_IFELSE,

    NODE_BREAK,    
    NODE_CONTINUE,
    NODE_DOWHILE,    
    NODE_REPEAT,  

    NODE_LT,
    NODE_LE,
    NODE_GT,
    NODE_GE,
    NODE_EQ,
    NODE_NE,
};

enum varType{
    INT = 101,
    STRING,
    BOOL,
    NONE
};

#define MAX_LABELS 256

#define STACK_START 4096
#define CODE_START 2056
#define CODE_END 4095
#define NUM_STATIC_VARS 26
#define HEADER_SIZE 8
#define TOTAL_REGISTERS 20
#define INSTR_SIZE 2


#endif
