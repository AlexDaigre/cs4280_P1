#include <stdio.h>
#include "token.h"
#include "scanner.h"

int main (int argc, char *argv[]) {
    char* fileName = "code.c";
    FILE* sourceFile = fopen(fileName, "r");

    struct token newToken;
    do {
        newToken = getNextToken(sourceFile);

    } while ( newToken.tokenId != eofTk);
}