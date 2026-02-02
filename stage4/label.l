%{
    #include <stdio.h>
    #include "string.h"
    #include "constants.h"
    #include "label.h"

    int pass=1;
    int addr=2056;
    FILE * final;
%}

%option noinput
%option nounput

number [0-9]+
reg R{number}
label L{number}
labelname L{number}:\n
jzinstr (JZ[ ]{reg},{label}\n)
jnzinstr (JNZ[ ]{reg},{label}\n)
jmpinstr (JMP[ ]{label}\n)
callinstr (CALL[ ]{label}\n)
header (0\n{number}\n0\n0\n0\n0\n0\n0\n)

%%

{header} { if(pass==2){
    fprintf(final,"%s",yytext);
}}

{labelname} {
    if(pass==1){
        char labelN[yyleng+1];
        sscanf(yytext, "%[^:]", labelN);
        addnewLabel(labelN, addr);
    }
}

{jzinstr} {
    if(pass==1){
        addr+=2;
    }
    else if(pass==2){
        char regname[5], labelname[yyleng];
        sscanf(yytext, "JZ %[^,],%s", &regname, &labelname);
        int memAddr=getmemaddr(labelname);
        fprintf(final, "JZ %s, %d\n", regname, memAddr);
    }
}

{jnzinstr} {
    if(pass==1){
        addr+=2;
    }
    else if(pass==2){
        char regname[5], labelname[yyleng];
        sscanf(yytext, "JNZ %[^,],%s", &regname, &labelname);
        int memAddr=getmemaddr(labelname);
        fprintf(final, "JNZ %s, %d\n", regname, memAddr);
    }
}

{jmpinstr} {
    if(pass==1){
        addr+=2;
    }
    else if(pass==2){
        char labelname[yyleng];
        sscanf(yytext, "JMP %s\n", &labelname);
        int memAddr=getmemaddr(labelname);
        fprintf(final, "JMP %d\n",memAddr);
    }
}

{callinstr} {
    if(pass==1){
        addr+=2;
    }
    else if(pass==2){
        char labelname[yyleng];
        sscanf(yytext, "CALL %s\n",&labelname);
        int memAddr=getmemaddr(labelname);
        fprintf(final, "CALL %d\n", memAddr);
    }
}

.*\n {
    if (pass == 1) {
        addr += 2;
    } else if (pass == 2) {
        fprintf(final, yytext);
    }
}

%%

int yywrap(){
    if(pass==1){
        rewind(yyin);
        pass=2;
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    yyin=fopen("result.xsm","r");
    final=fopen("final.xsm","w");
    yylex();
    return 0;
}

