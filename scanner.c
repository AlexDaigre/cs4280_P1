#include <ctype.h>
#include <string.h>
#include "token.h"
#include "fsaTable.h"

int currentFSAPosition;
int currentFilePosition;
char nextChar;
int lineNumeber;

struct token getNextToken() {
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
                        newToken.tokenID = state;
                        newToken.tokenInstance = tokenText;
                        newToken.lineNum = lineNumeber;
                        return newToken;
                    }
                }
                newToken.tokenID = state;
                newToken.tokenInstance = tokenText;
                newToken.lineNum = lineNumeber;
                return newToken;
            } else {
                newToken.tokenID = state;
                newToken.tokenInstance = tokenText;
                newToken.lineNum = lineNumeber;
                return (newToken);
            }
        } else {
            state = nextState;
            strcat(tokenText, nextChar);
            nextChar = getchar();
        }
    }
}