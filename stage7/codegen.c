#include "constants.h"
#include "nodestructure.h"
#include "symbolTable.h"
#include "typecheck.h"
#include <stdio.h>
#include <stdlib.h>
#include "classtable.h"

extern FILE *out;

int regno = -1, maxreg = 20, label = -1;
int i, j;
int whileStart = -1, whileEnd = -1;

//labels and registers
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

//starting and ending
void initialize() {
    out = fopen("result.xsm", "w");
    fprintf(out, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(out, "MOV SP, %d\n", start);
    fprintf(out, "BRKP\n");
    fprintf(out, "CALL MAIN\n");
    fprintf(out, "INT 10\n");
}
// void generateExitCode() {
//     int reg = getReg();
//     fprintf(out, "MOV R%d, \"Exit\"\n", reg);
//     fprintf(out, "PUSH R%d\n", reg);
//     fprintf(out, "PUSH R%d\n", reg);
//     fprintf(out, "PUSH R%d\n", reg);
//     fprintf(out, "PUSH R%d\n", reg);
//     fprintf(out, "PUSH R%d\n", reg);
//     fprintf(out, "CALL 0\n");
//     freeReg();
// }



int getMemoryAddress(struct tnode *root) {
    int r;
    // if(root->nodetype == FIELD_NODE) {
    //     r = getReg();
    //     struct Fieldlist* ftemp;
    //     if(root->left->Gentry != NULL) {
    //         fprintf(out, "MOV R%d, %d\n", r, root->left->Gentry->binding);
    //     } else {
    //         fprintf(out, "MOV R%d,BP\n", r);
    //         fprintf(out, "ADD R%d,%d\n", r, root->left->Lentry->binding);
    //     }

    //     while(root->right->nodetype == FIELD_NODE) {
    //         ftemp = FLookup(root->right->left->varname, root->left->type->fields); 
    //         fprintf(out, "MOV R%d, [R%d]\n", r, r);
    //         fprintf(out, "ADD R%d, %d\n", r, ftemp->Fieldindex);
    //         root = root->right;
    //     }

    //     ftemp = FLookup(root->right->varname, root->left->type->fields); 
    //     fprintf(out, "MOV R%d, [R%d]\n", r, r);
    //     fprintf(out, "ADD R%d, %d\n", r, ftemp->Fieldindex);
    //     return r;
    // }
    if(root->nodetype == FIELD_NODE) {
    r = getReg();
    struct Fieldlist* ftemp;

    if(root->left->nodetype == SELF_NODE) {
        fprintf(out, "MOV R%d,BP\n", r);
        fprintf(out, "ADD R%d,%d\n", r, root->left->Lentry->binding);
    } else if(root->left->Gentry != NULL) {
        fprintf(out, "MOV R%d, %d\n", r, root->left->Gentry->binding);
    } else {
        fprintf(out, "MOV R%d,BP\n", r);
        fprintf(out, "ADD R%d,%d\n", r, root->left->Lentry->binding);
    }

    while(root->right->nodetype == FIELD_NODE) {
        struct Fieldlist *fields = (root->left->Ctype != NULL)
            ? root->left->Ctype->Memberfield
            : root->left->type->fields;
        ftemp = FLookup(root->right->left->varname, fields);
        fprintf(out, "MOV R%d, [R%d]\n", r, r);
        fprintf(out, "ADD R%d, %d\n", r, ftemp->Fieldindex);
        root = root->right;
    }

    struct Fieldlist *fields = (root->left->Ctype != NULL)
        ? root->left->Ctype->Memberfield
        : root->left->type->fields;
    ftemp = FLookup(root->right->varname, fields);
    fprintf(out, "MOV R%d, [R%d]\n", r, r);
    fprintf(out, "ADD R%d, %d\n", r, ftemp->Fieldindex);
    return r;
}
    else if(root->nodetype == SELF_NODE) {
        r = getReg();
        fprintf(out, "MOV R%d,BP\n", r);
        fprintf(out, "ADD R%d,%d\n", r, root->Lentry->binding);
        return r;
    }
    else if (root->nodetype == VARIABLE_NODE) { 
        r = getReg();
        if (root->Lentry != NULL) { //local variable or param
            fprintf(out, "MOV R%d, BP\n", r);
            if (root->Lentry->binding < 0)
                fprintf(out, "SUB R%d, %d\n", r, -root->Lentry->binding);
            else
                fprintf(out, "ADD R%d, %d\n", r, root->Lentry->binding);
        } else if (root->Gentry != NULL) {// global variable
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
    else {
        printf("cannot find memory address of node type %d\n",root->nodetype);
        exit(1);
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
        case BRKP_NODE:{
                fprintf(out, "BRKP\n");
                return -1;}
        case NUM_NODE:{
                r1 = getReg();
                fprintf(out, "MOV R%d,%d\n", r1, root->value.intval);
                return r1;}
        case VARIABLE_NODE:{
                r1 = getMemoryAddress(root);
                fprintf(out, "MOV R%d,[R%d]\n", r1, r1);
                return r1;}
        case STRVAL_NODE:
            r1 = getReg();
            fprintf(out, "MOV R%d,%s\n", r1, root->value.strval);
            return r1;
        case ARRAY_NODE:
            r1 = getMemoryAddress(root);
            fprintf(out, "MOV R%d, [R%d]\n", r1, r1);
            return r1;
        case ADD_NODE:{
                r1 = codegen(root->left);
                r2 = codegen(root->right);
                fprintf(out, "ADD R%d,R%d\n", r1, r2);
                freeReg();
                return r1;}
        case SUB_NODE:{
                r1 = codegen(root->left);
                r2 = codegen(root->right);
                fprintf(out, "SUB R%d,R%d\n", r1, r2);
                freeReg();
                return r1;}
        case DIV_NODE:{
                r1 = codegen(root->left);
                r2 = codegen(root->right);
                fprintf(out, "DIV R%d,R%d\n", r1, r2);
                freeReg();
                return r1;}
        case MUL_NODE:{
                r1 = codegen(root->left);
                r2 = codegen(root->right);
                fprintf(out, "MUL R%d,R%d\n", r1, r2);
                freeReg();
                return r1;}
        case MOD_NODE:{
                r1 = codegen(root->left);
                r2 = codegen(root->right);
                fprintf(out, "MOD R%d,R%d\n", r1, r2);
                freeReg();
                return r1;}
        case ASSIGN_NODE:{
                r2 = getMemoryAddress(root->left);
                r1 = codegen(root->right); 
                fprintf(out, "MOV [R%d],R%d\n", r2, r1);
                freeReg();
                freeReg();
                return -1;}
        case WRITE_NODE:{
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
                break;}
        case READ_NODE:{
                int addr = getMemoryAddress(root->left);
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
                fprintf(out, "SUB SP,5\n");
                freeReg();
                for (i = status; i >= 0; i--)
                    fprintf(out, "POP R%d\n", i);
                regno = status;
                break;}
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
        case WHILE_NODE:{
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
        case IF_ELSE_NODE:{
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
                break;
            }
        case IF_NODE:{
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
        case FUN_NODE:{
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
        case DELETE_NODE:
        case FREE_NODE:
            // generateFreeCode(root);
            for (i = 0; i <= regno; i++)
                fprintf(out, "PUSH R%d\n", i);
            status = regno;
            r2=getReg();
            fprintf(out, "MOV R%d,\"Free\"\n",r2);
            fprintf(out, "PUSH R%d\n",r2);
            freeReg();

            r1 = codegen(root->left);
            fprintf(out, "PUSH R%d\n", r1); //Argument 1
            freeReg();

            fprintf(out, "ADD SP,3\n");
            fprintf(out, "CALL 0\n");
            fprintf(out, "SUB SP,5\n");

            for (i = status; i >= 0; i--)
                fprintf(out, "POP R%d\n", i);
            regno = status;
            break;
        case INIT_NODE:
            // generateInitCode(root);
            for (i = 0; i <= regno; i++)
                fprintf(out, "PUSH R%d\n", i);
            status = regno;
            r1=getReg();
            fprintf(out, "MOV R%d,\"Heapset\"\n",r1);
            fprintf(out, "PUSH R%d\n",r1);
            freeReg();
            fprintf(out, "ADD SP,4\n");
            fprintf(out, "CALL 0\n");
            fprintf(out, "SUB SP,5\n");

            for (i = status; i >= 0; i--)
                fprintf(out, "POP R%d\n", i);
            regno = status;
            r1 = getReg();
            fprintf(out, "MOV R%d, 1\n", r1);
            return r1;
            break;
        case NEW_NODE:
        case ALLOC_NODE:
            // return generateAllocCode(root);
            for (i = 0; i <= regno; i++)
                fprintf(out, "PUSH R%d\n", i);
            status = regno;
            r1=getReg();
            int size=0;
            if (root->nodetype == NEW_NODE && root->Ctype != NULL)
                size = root->Ctype->Fieldcount;
            else
                size = root->type->size;
            fprintf(out, "MOV R%d,\"Alloc\"\n",r1);
            fprintf(out, "PUSH R%d\n",r1);
            fprintf(out, "MOV R%d, %d\n", r1, size);
            fprintf(out, "PUSH R%d\n", r1);       // size argument
            fprintf(out, "PUSH R%d\n", r1);       // dummy
            fprintf(out, "PUSH R%d\n", r1);       // dummy
            fprintf(out, "PUSH R%d\n", r1);
            
        
            fprintf(out, "CALL 0\n");
            freeReg();

            fprintf(out, "POP R%d\n", status+1); // for return value
            
            fprintf(out, "SUB SP,4\n");

            for (i = status; i >= 0; i--)
                fprintf(out, "POP R%d\n", i);
            regno = status;
            r1 = getReg();
            return r1;
        case NULL_NODE:
            r1 = getReg();
            fprintf(out, "MOV R%d,-1\n", r1);
            return r1;
            break;
        case FIELD_NODE: {
            r1 = getMemoryAddress(root);   // gives address of the field
            fprintf(out, "MOV R%d, [R%d]\n", r1, r1);  // load field value
            return r1;
            break;
        }
        case SELF_NODE:
            r1 = getMemoryAddress(root);
            fprintf(out, "MOV R%d, [R%d]\n", r1, r1);
            return r1;
        // case FIELDFUNC_NODE:
        //     for (i = 0; i <= regno; i++)
        //         fprintf(out, "PUSH R%d\n", i);
        //     status = regno;
        //     regno=-1;

        //     //pushing self
        //     r1 = codegen(root->left);
        //     fprintf(out, "PUSH R%d\n", r1); //Argument 1
        //     freeReg();
        //     pushArguments(root->right->left); //Push Arguments
        //     r1=getReg();
        //     fprintf(out, "PUSH R%d\n",r1); //Space for return value
        //     freeReg();

        //     struct Memberfunclist *mfptr = Class_Mlookup(root->left->Ctype, root->right->varname);
        //     fprintf(out, "CALL M%d\n", mfptr->Flabel);  

        //     r1 = status + 1;
        //     fprintf(out, "POP R%d\n", r1); // for return value
        //     if (status == -1)
        //         r2 = getReg();
        //      // Popping Self
        //     int r = getReg();
        //     fprintf(out, "POP R%d\n", r);
        //     freeReg();
        //     popArguments(root->right->left); // Pop Arguments

        //     if (status == -1)
        //         freeReg();

        //     for (i = status; i >= 0; i--)
        //         fprintf(out, "POP R%d\n", i);
        //     regno = status;
        //     r1 = getReg();
        //     return r1;
        case FIELDFUNC_NODE: {
    int status = regno;

    // Step 1: Evaluate arguments into registers
    struct tnode *arglistnode = root->right->argList;
    struct Memberfunclist *mfptr =
        Class_Mlookup(root->left->Ctype, root->right->varname);

    int nArgs = getNoParams(mfptr->paramlist); // number of declared params
    int argRegs[nArgs + 1]; // +1 for self
    int ind = 0;

    // Step 2: First evaluate self
    argRegs[ind++] = codegen(root->left);

    // Step 3: Evaluate other arguments
    getArgRegs(arglistnode, &ind, argRegs);

    // Step 4: Save registers
    for (int i = 0; i <= status; i++) {
        fprintf(out, "PUSH R%d\n", i);
    }

    // Step 5: Push arguments (right to left)
    for (int i = ind - 1; i >= 0; i--) {
        fprintf(out, "PUSH R%d\n", argRegs[i]);
    }

    // Step 6: Space for return value
    fprintf(out, "PUSH R0\n");

    // Step 7: Call method
    regno = 0;
    fprintf(out, "CALL M%d\n", mfptr->Flabel);

    // Step 8: Restore reg state
    regno = status;

    int retReg = getReg();
    fprintf(out, "POP R%d\n", retReg); // return value

    // Step 9: Pop arguments
    int temp = getReg();
    for (int i = 0; i < ind; i++) {
        fprintf(out, "POP R%d\n", temp);
    }
    freeReg();

    // Step 10: Restore saved registers
    for (int i = status; i >= 0; i--) {
        fprintf(out, "POP R%d\n", i);
    }

    return retReg;
}
    }
}

int generateFunctionCallCode(struct tnode *root) {
    int status = regno;
    struct tnode *arglistnode = root->argList;
    int nArgs = getNoParams(root->Gentry->paramlist);
    int argRegs[nArgs];
    int ind = 0;
    getArgRegs(arglistnode, &ind, argRegs);
    for (int i = 0; i <= status; i++) {
        fprintf(out, "PUSH R%d\n", i);
    }
    for (int i = nArgs - 1; i >= 0; i--) { /// push arguments to the stack right to left
        fprintf(out, "PUSH R%d\n", argRegs[i]);
    }
    fprintf(out, "PUSH R0\n"); // return value
    /* Call function */
    regno = 0;
    fprintf(out, "CALL F%d\n", root->Gentry->flabel);
    /* Pop return value */
    regno = status;
    int retReg = getReg();
    fprintf(out, "POP R%d\n", retReg);
    /* Pop arguments */
    int newreg = getReg();
    for (int i = 0; i < nArgs; i++)
        fprintf(out, "POP R%d\n", newreg);
    freeReg();
    for (int i = status; i >= 0; i--)
        fprintf(out, "POP R%d\n", i);

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