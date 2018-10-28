#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "token.h"
#include "scanner.h"

int main (int argc, char *argv[]) {
    char* sourceFileName = "P1_test1.fs182";
    // char* fileExtention = ".fs182";
    if (argc == 2) {
        // sourceFileName = argv[1];
        // strcat(sourceFileName, fileExtention);
    } else {
        printf("A sourcefile is requred as an argument\n");
        return 1;
    }
    
    printf("Reading: %s\n", sourceFileName);

    FILE* sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL){
        printf("Could not open %s: %d\n", sourceFileName, errno);
    }

    struct token newToken;
    do {
        newToken = getNextToken(sourceFile);
        printf("MAIN:\n  Token ID: %d\n  Token Instance: %s\n  Line Number: %d\n", newToken.tokenId, newToken.tokenInstance, newToken.lineNum);
    } while ( newToken.tokenId != 1003);

    fclose(sourceFile);
}