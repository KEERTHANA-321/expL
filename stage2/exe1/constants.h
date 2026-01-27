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
    NONE
};

enum nodeTypes {
    EMPTY_NODE,
    ASSIGN_NODE,
    CONNECTOR_NODE,
    VARIABLE_NODE,
    NUM_NODE,
    READ_NODE,
    WRITE_NODE,
    ADD_NODE,
    SUB_NODE,
    MUL_NODE,
    DIV_NODE,
};

#endif