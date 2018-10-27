#include <ctype.h>
#include <stdio.h>
#include "fsaTable.h"

const int fsaTable[rowSize][colSize] = {
    {1,1,1001,3},
    {-1,1,1001,3},
    {-1,1,1001,3},
    {2,1000,2,3},
    {1002,1000,1001,3},
    {0,1000,1001,3},
    {3,1000,1001,0},
    {1003,1000,1001,1003},
    {-1,-1,-1,3}
};
const char* keywordList[keywordListSize] = {
    "start",
    "stop",
    "loop",
    "void",
    "var",
    "return",
    "scan",
    "out",
    "program",
    "if",
    "then",
    "let"
};
const char opDelList[opDelListSize] = {
    '=',
    '<',
    '>',
    ':',
    '+',
    '-',
    '*',
    '/',
    '%',
    '.',
    '(',
    ')',
    ',',
    '{',
    '}',
    ';',
    '[',
    ']'
};

int isInOpDel(char c);

int charToColumn(char c){
    char c;

    if (isalpha(c)){
        if (islower(c)){
            return 0;
        } else if (isupper(c)){
            return 1;
        }
    } else if (c == '_'){
        return 2;
    } else if (isdigit(c)){
        return 3;
    } else if (isInOpDel(c)){
        return 4;
    } else if (isspace(c)){
        return 5;
    } else if (c == '$') {
        return 6;
    } else if (c == EOF){
        return 7;
    } else {
        return 8;
    }
}

int isInOpDel(char c){
    int i;
    int inOpDel = 0;
    for(i = 0; i <= opDelListSize; i++){
        if (opDelList[i] == c){
            inOpDel = 1;
        }
    }
    return inOpDel;
}