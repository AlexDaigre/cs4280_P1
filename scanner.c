#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"
#include "token.h"
#include "fsaTable.h"

struct token getNextToken(FILE* fileName) {
    nextChar = fgetc(fileName);
    int state = 0;
    int nextState;
    struct token newToken;
    char tokenText[8];
    while(state<1000) {
        if (nextChar == '\n'){
            lineNumber++;
        }
        int stateNumber = charToColumn(nextChar);
        nextState = fsaTable[state][stateNumber];
        if (nextState < 0){
            printf("LEX ERROR at line %d", lineNumber);
            exit(1);
        }
        if (nextState >= 1000) {
            if (nextState == 1000) {
                int i;
                for (i = 0; i < keywordListSize; i++){
                    if (tokenText == keywordList[i]){
                        newToken.tokenId = state;
                        newToken.tokenInstance = tokenText;
                        newToken.lineNum = lineNumber;
                        return newToken;
                    }
                }
                newToken.tokenId = state;
                newToken.tokenInstance = tokenText;
                newToken.lineNum = lineNumber;
                return newToken;
            } else {
                newToken.tokenId = state;
                newToken.tokenInstance = tokenText;
                newToken.lineNum = lineNumber;
                return (newToken);
            }
        } else {
            state = nextState;
            strcat(tokenText, nextChar);
            nextChar = fgetc(fileName);
        }
    }
    printf("LEX ERROR at line %d", lineNumber);
    exit(1);
}