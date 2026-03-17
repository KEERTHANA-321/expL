
#include "constants.h"
#include "nodestructure.h"
#include "symbolTable.h"
#include "typecheck.h"
#include <stdio.h>
#include <stdlib.h>

extern FILE *out;

int regno = -1, maxreg = 20, label = -1;
int i, j;
int whileStart = -1, whileEnd = -1;

int getLabel() { return ++label; }
int getReg() {
    if (regno == maxreg - 1) { // maximum register available is 20
        printf("Out of registers\n");
        exit(1);
    } else {
        regno++;
        return regno;
    }
}
void freeReg() {
    if (regno >= 0) {
        regno--;
    }
}

// //arguments is a given as binary tree list in arglist as right new node is new and left node is prev list
// void pushArguments(struct tnode *t) {
//     if (t == NULL)
//         return;

//     if (t->nodetype == CONNECTOR_NODE) {
//         pushArguments(t->right);
//         pushArguments(t->left);//push arguments from  right to left
//     } else {
//         int r = codegen(t);
//         fprintf(out, "PUSH R%d\n", r);
//         freeReg();
//     }
// }
// void popArguments(struct tnode *t) {
//     if (t == NULL)
//         return;

//     if (t->nodetype == CONNECTOR_NODE) {
//         popArguments(t->left);
//         popArguments(t->right);//pop arguments from  left to right
//     } else {
//         fprintf(out, "POP R19\n");
//     }
// }

void generateExitCode() {
    int reg = getReg();
    fprintf(out, "MOV R%d, \"Exit\"\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);

    fprintf(out, "CALL 0\n");

    freeReg();
}

void initialize() {
    out = fopen("result.xsm", "w");
    fprintf(out, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(out, "MOV SP, %d\n", start);
    fprintf(out, "BRKP\n");
    fprintf(out, "CALL MAIN\n");
    fprintf(out, "INT 10\n");
}

int getMemoryAddress(struct tnode *root) {
    int r;

    if (root->nodetype == VARIABLE_NODE) {

        r = getReg();

        if (root->Lentry != NULL) {
            // LOCAL VARIABLE OR PARAMETER
            fprintf(out, "MOV R%d, BP\n", r);

            if (root->Lentry->binding < 0)
                fprintf(out, "SUB R%d, %d\n", r, -root->Lentry->binding);
            else
                fprintf(out, "ADD R%d, %d\n", r, root->Lentry->binding);
        } else if (root->Gentry != NULL) {
            // GLOBAL VARIABLE
            fprintf(out, "MOV R%d, %d\n", r, root->Gentry->binding);
        } else {
            printf("Error: Variable entry missing\n");
            exit(1);
        }

        return r;
    }

    else if (root->nodetype == ARRAY_NODE) {

        if (root->right == NULL)
            r = getReg();
        else
            r = codegen(root->right);

        if (root->left->Lentry != NULL) {
            fprintf(out, "ADD R%d, %d\n", r, root->left->Lentry->binding);
        } else if (root->left->Gentry != NULL) {
            fprintf(out, "ADD R%d, %d\n", r, root->left->Gentry->binding);
        } else {
            printf("Error: Array entry missing\n");
            exit(1);
        }

        return r;
    }

    return -1;
}
int codegen(struct tnode *root) {
    int r1, r2, r3, number, status = 0;
    int prevWhileStart, prevWhileEnd;

    if (root == NULL) {
        return -1;
    }
    switch (root->nodetype) {
        case CONNECTOR_NODE:
            codegen(root->left);
            codegen(root->right);
            return -1;

        case BRKP_NODE:
            {
                fprintf(out, "BRKP\n");
                return -1;
            }
        case NUM_NODE:
            {
                r1 = getReg();
                fprintf(out, "MOV R%d,%d\n", r1, root->value.intval);
                return r1;
            }
        case VARIABLE_NODE:
            {
                r1 = getMemoryAddress(root);
                fprintf(out, "MOV R%d,[R%d]\n", r1, r1);
                return r1;
            }
        case STRVAL_NODE:
            r1 = getReg();
            fprintf(out, "MOV R%d,%s\n", r1, root->varname);
            return r1;
        case ARRAY_NODE:
            r1 = getMemoryAddress(root);
            fprintf(out, "MOV R%d, [R%d]\n", r1, r1);
            return r1;
        case ADD_NODE:
            {
                r1 = codegen(root->left);
                r2 = codegen(root->right);
                fprintf(out, "ADD R%d,R%d\n", r1, r2);
                freeReg();
                return r1;
            }
        case SUB_NODE:
            {
                r1 = codegen(root->left);
                r2 = codegen(root->right);
                fprintf(out, "SUB R%d,R%d\n", r1, r2);
                freeReg();
                return r1;
            }
        case DIV_NODE:
            {
                r1 = codegen(root->left);
                r2 = codegen(root->right);
                fprintf(out, "DIV R%d,R%d\n", r1, r2);
                freeReg();
                return r1;
            }
        case MUL_NODE:
            {
                r1 = codegen(root->left);

                // fprintf(out,"PUSH R%d\n",r1);   // protect left operand
                // freeReg();

                r2 = codegen(root->right);

                // int r3 = getReg();
                // fprintf(out,"POP R%d\n",r3);

                fprintf(out, "MUL R%d,R%d\n", r1, r2);
                freeReg();

                return r1;
            }
        case MOD_NODE:
            {
                r1 = codegen(root->left);
                r2 = codegen(root->right);
                fprintf(out, "MOD R%d,R%d\n", r1, r2);
                freeReg();
                return r1;
            }
        case ASSIGN_NODE:
            {
                r2 = getMemoryAddress(root->left); // addr in r2

                r1 = codegen(root->right); // value in r1
                fprintf(out, "MOV [R%d],R%d\n", r2, r1);
                freeReg();
                freeReg();
                return -1;
            }
        case WRITE_NODE:
            {
                r1 = codegen(root->left); // evaluating before saving registers
                for (i = 0; i <= regno; i++)
                    fprintf(out, "PUSH R%d\n", i);
                status = regno;
                int k = getReg();
                fprintf(out, "MOV R%d,\"Write\"\n", k);
                fprintf(out, "PUSH R%d\n", k); // function code "Write"
                fprintf(out, "MOV R%d,-2\n", k);
                fprintf(out, "PUSH R%d\n", k); // Argument 1

                fprintf(out, "PUSH R%d\n", r1); // Argument 2 value to write
                freeReg();
                fprintf(out, "MOV R%d,0\n", k);
                fprintf(out, "PUSH R%d\n", k); // Argument 3
                fprintf(out, "PUSH R%d\n", k);
                fprintf(out, "CALL 0\n");
                fprintf(out, "SUB SP,5\n");
                freeReg();

                for (i = status; i >= 0; i--)
                    fprintf(out, "POP R%d\n", i);
                regno = status;
                break;
            }
        case READ_NODE:
            {
                int addr = getMemoryAddress(root->left);

                // Save registers
                for (i = 0; i <= regno; i++)
                    fprintf(out, "PUSH R%d\n", i);
                status = regno;
                int k = getReg();

                fprintf(out, "MOV R%d,\"Read\"\n", k);
                fprintf(out, "PUSH R%d\n", k); // first push

                fprintf(out, "MOV R%d,-1\n", k);
                fprintf(out, "PUSH R%d\n", k); // second push code -1

                fprintf(out, "PUSH R%d\n", addr); // 3 push address to read into

                fprintf(out, "MOV R%d,-1\n", k);
                fprintf(out, "PUSH R%d\n", k); // push 4
                fprintf(out, "PUSH R%d\n", k); // push 4

                fprintf(out, "CALL 0\n");

                // Pop syscall args
                fprintf(out, "SUB SP,5\n");
                freeReg();

                // Restore registers
                for (i = status; i >= 0; i--)
                    fprintf(out, "POP R%d\n", i);
                regno = status;
                // freeReg(); //freeing addr register

                break;
            }

        case LT_NODE:
            r1 = codegen(root->left);
            r2 = codegen(root->right);
            fprintf(out, "LT R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case GT_NODE:
            r1 = codegen(root->left);
            r2 = codegen(root->right);
            fprintf(out, "GT R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case LE_NODE:
            r1 = codegen(root->left);
            r2 = codegen(root->right);
            fprintf(out, "LE R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case GE_NODE:
            r1 = codegen(root->left);
            r2 = codegen(root->right);
            fprintf(out, "GE R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case EQ_NODE:
            r1 = codegen(root->left);
            r2 = codegen(root->right);
            fprintf(out, "EQ R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NE_NODE:
            r1 = codegen(root->left);
            r2 = codegen(root->right);
            fprintf(out, "NE R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case WHILE_NODE:
            {
                int label_1 = getLabel();
                int label_2 = getLabel();
                prevWhileStart = whileStart;
                prevWhileEnd = whileEnd;
                whileStart = label_1;
                whileEnd = label_2;
                fprintf(out, "L%d:\n", label_1);
                r1 = codegen(root->left);
                fprintf(out, "JZ R%d,L%d\n", r1, label_2);
                freeReg();
                number = codegen(root->right);
                freeReg();
                fprintf(out, "JMP L%d\n", label_1);
                fprintf(out, "L%d:\n", label_2);
                whileStart = prevWhileStart;
                whileEnd = prevWhileEnd;
                break;
            }
        case IF_ELSE_NODE:
            {
                int label_1 = getLabel();
                int label_2 = getLabel();
                r1 = codegen(root->left);
                fprintf(out, "JZ R%d,L%d\n", r1, label_1);
                freeReg();
                number = codegen(root->middle);
                freeReg();
                fprintf(out, "JMP L%d\n", label_2);
                fprintf(out, "L%d:\n", label_1);
                number = codegen(root->right);
                freeReg();
                fprintf(out, "L%d:\n", label_2);
                // freeReg();
                // freeReg();
                break;
            }
        case IF_NODE:
            {
                int label_1 = getLabel();
                r1 = codegen(root->left);
                fprintf(out, "JZ R%d,L%d\n", r1, label_1);
                freeReg();
                number = codegen(root->right);
                freeReg();
                fprintf(out, "L%d:\n", label_1);
                break;
            }
        case BREAK_NODE:
            if (whileEnd != -1) fprintf(out, "JMP L%d\n", whileEnd);
            break;
        case CONT_NODE:
            if (whileStart != -1) fprintf(out, "JMP L%d\n", whileStart);
            break;
        case DOWHILE_NODE:
            {
                int label_1 = getLabel();
                int label_2 = getLabel();
                prevWhileStart = whileStart;
                prevWhileEnd = whileEnd;
                whileStart = label_1;
                whileEnd = label_2;
                fprintf(out, "L%d:\n", label_1);
                number = codegen(root->left);
                freeReg();
                r1 = codegen(root->right);
                fprintf(out, "JNZ R%d,L%d\n", r1, label_1);
                freeReg();
                fprintf(out, "L%d:\n", label_2);
                whileStart = prevWhileStart;
                whileEnd = prevWhileEnd;
                break;
            }
        case REPEAT_NODE:
            {
                int label_1 = getLabel();
                int label_2 = getLabel();
                prevWhileStart = whileStart;
                prevWhileEnd = whileEnd;
                whileStart = label_1;
                whileEnd = label_2;
                fprintf(out, "L%d:\n", label_1);
                number = codegen(root->left);
                freeReg();
                r1 = codegen(root->right);
                fprintf(out, "JZ R%d,L%d\n", r1, label_1);
                freeReg();
                fprintf(out, "L%d:\n", label_2);
                whileStart = prevWhileStart;
                whileEnd = prevWhileEnd;
                break;
            }
        case FUN_NODE:
            {
                return generateFunctionCallCode(root);
            }
        case RET_NODE:

            r2 = codegen(root->left);
            r1 = getReg();
            fprintf(out, "MOV R%d,BP\n", r1);
            fprintf(out, "SUB R%d,%d\n", r1, 2);
            fprintf(out, "MOV [R%d], R%d\n", r1, r2);
            freeReg();
            freeReg();

            Ltemp = Lhead; // deallocate all locals at once
            fprintf(out, "SUB SP, %d\n", localbindingstart - 1);
            fprintf(out, "POP BP\n"); // restore caller's BP
            fprintf(out, "RET\n");
            break;
    }
}

int generateFunctionCallCode(struct tnode *root) {
    int status = regno;

    struct tnode *arglistnode = root->argList;
    int nArgs = getNoParams(root->Gentry->paramlist);
    int argRegs[nArgs];
    int ind = 0;
    
    getArgRegs(arglistnode, &ind, argRegs);

    // for(int i=0;i<nArgs;i++){
    //     printf("%d, ",argRegs[i]);
    // }
    // int returnReg=getReg();
    for (int i = 0; i <= status; i++) {
        fprintf(out, "PUSH R%d\n", i);
    }
    
    for (int i = nArgs - 1; i >= 0; i--) { /// push arguments to the stack right to left
        fprintf(out, "PUSH R%d\n", argRegs[i]);
    }

    // regno-=nArgs;
    fprintf(out, "PUSH R0\n"); // return value

    /* Call function */
    regno = 0;
    fprintf(out, "CALL F%d\n", root->Gentry->flabel);

    /* Pop return value */
    regno = status;
    int retReg = getReg(); // status+1
    fprintf(out, "POP R%d\n", retReg);

    /* Pop arguments */
    int newreg = getReg();
    for (int i = 0; i < nArgs; i++)
        fprintf(out, "POP R%d\n", newreg);
    freeReg();

    /* Restore registers */
    // int k=getReg();
    // fprintf(out,"MOV R%d,R%d\n",k,retReg);
    // for(int i=status;i>=0;i--){
    //     if(i!=k)
    //     fprintf(out,"POP R%d\n", i);
    // }
    for (int i = status; i >= 0; i--)
        fprintf(out, "POP R%d\n", i);
    // int result = getReg(); // = status + 1 again
    // fprintf(out, "MOV R%d, R%d\n", result, retReg);

    // regno = status+2;

    return retReg;
}

void getArgRegs(struct tnode *arglistnode, int *ind, int *argRegs) {
    if (!arglistnode) {
        return;
    }
    switch (arglistnode->nodetype) {
        case CONNECTOR_NODE:
            getArgRegs(arglistnode->left, ind, argRegs);
            getArgRegs(arglistnode->right, ind, argRegs);
            break;

        default:
            argRegs[*ind] = codegen(arglistnode);
            // freeReg();
            (*ind)++;
            break;
    }
}

int getNoParams(struct Paramstruct *paramList) {
    struct Paramstruct *head = paramList;
    int length = 0;

    while (head) {
        length++;
        head = head->next;
    }

    return length;
}