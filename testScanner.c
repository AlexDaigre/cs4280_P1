#include <stdio.h>
#include "testScanner.h"
#include "token.h"
#include "scanner.h"

void testScanner(FILE* sourceFile){
    struct token newToken;
    lineNumber = 1;
    do {
        newToken = getNextToken(sourceFile);
        printf("MAIN:\n  Token ID: %d\n  Token Instance: %s\n  Line Number: %d\n", newToken.tokenId, newToken.tokenInstance, newToken.lineNum);
    } while ( newToken.tokenId != 1003);
}