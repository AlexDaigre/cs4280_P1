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
    int tokenTextLength = 0;
    while(state<1000) {
        if (nextChar == '\n'){
            lineNumber++;
        }
        int charGroup = charToColumn(nextChar);
        nextState = fsaTable[charGroup][state];
        // printf("nextState: %d\n", nextState);
        if (nextState < 0){
            printf("LEX ERROR at line %d\n", lineNumber);
            exit(1);
        }
        if (nextState >= 1000) {
            if (nextState == 1000) {
                int i;
                for (i = 0; i < keywordListSize; i++){
                    if (tokenText == keywordList[i]){
                        newToken.tokenId = nextState;
                        newToken.tokenInstance = tokenText;
                        newToken.lineNum = lineNumber;
                        // printf("SCANNER:\n  Token ID: %d\n  Token Instance: %s\n  Line Number: %d\n", newToken.tokenId, newToken.tokenInstance, newToken.lineNum);
                        return newToken;
                    }
                }
                newToken.tokenId = nextState;
                newToken.tokenInstance = tokenText;
                newToken.lineNum = lineNumber;
                // printf("SCANNER:\n  Token ID: %d\n  Token Instance: %s\n  Line Number: %d\n", newToken.tokenId, newToken.tokenInstance, newToken.lineNum);
                return newToken;
            } else {
                newToken.tokenId = nextState;
                newToken.tokenInstance = tokenText;
                newToken.lineNum = lineNumber;
                // printf("SCANNER:\n  Token ID: %d\n  Token Instance: %s\n  Line Number: %d\n", newToken.tokenId, newToken.tokenInstance, newToken.lineNum);
                return (newToken);
            }
        } else {
            state = nextState;
            // printf("nextChar: %c\n  tokenTextLength: %d\n", nextChar, tokenTextLength);
            tokenText[tokenTextLength] = nextChar;
            tokenTextLength++;
            if (tokenTextLength > 8){
                exit(1);
            }
            nextChar = fgetc(fileName);
        }
    }
    printf("LEX ERROR at line %d\n", lineNumber);
    exit(1);
}