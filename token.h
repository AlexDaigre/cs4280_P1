#ifndef TOKEN_H
#define TOKEN_H

    enum tokenIdEnum {
        eofTk = 1003, 
        idTk = 1000,
        intTk = 1001,
        opDelTk = 1002,
        keywordTK = 1004
    }; 

    extern char* tokenNames[];

    struct token {
        enum tokenIdEnum tokenId;
        char* tokenInstance;
        int lineNum;
    };
    
#endif