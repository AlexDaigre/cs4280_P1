#ifndef FSATABLE_H
#define FSATABLE_H

    int currentFSAPosition;
    int currentFilePosition;
    char nextChar;
    int lineNumeber;

    struct token getNextToken(char* fileName);

#endif