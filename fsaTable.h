#ifndef FSATABLE_H
#define FSATABLE_H

    #define rowSize 9
    #define colSize 4
    #define keywordListSize 12
    #define opDelListSize 18

    extern int fsaTable[rowSize][colSize];
    extern char* keywordList[keywordListSize];
    enum tokenID;
    char* tokenNames[];

    int charToColumn(char c);

#endif