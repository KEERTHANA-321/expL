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
    NODE_CONNECTOR
};

enum varType{
    INT = 101,
    STRING,
    NONE
};

#endif
