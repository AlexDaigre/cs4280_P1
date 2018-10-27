#include <ctype.h>
#include <string.h>
#include "scanner.h"
#include "token.h"
#include "fsaTable.h"


struct token getNextToken(char* fileName) {
    nextChar = fgetc(fileName);
    int state = 0;
    int nextState;
    struct token newToken;
    char tokenText[8];
    while(state<1000) {
        if (nextChar == '\n'){
            lineNumeber++;
        }
        nextState = fsaTable[state][charToColumn(nextChar)];
        if (nextState < 0){
            ERROR();
        }
        if (nextState >= 1000) {
            if (nextState == 1000) {
                int i;
                for (i = 0; i < keywordListSize; i++){
                    if (tokenText == keywordList[i]){
                        newToken.tokenId = state;
                        newToken.tokenInstance = tokenText;
                        newToken.lineNum = lineNumeber;
                        return newToken;
                    }
                }
                newToken.tokenId = state;
                newToken.tokenInstance = tokenText;
                newToken.lineNum = lineNumeber;
                return newToken;
            } else {
                newToken.tokenId = state;
                newToken.tokenInstance = tokenText;
                newToken.lineNum = lineNumeber;
                return (newToken);
            }
        } else {
            state = nextState;
            strcat(tokenText, nextChar);
            nextChar = fgetc(fileName);
        }
    }
}