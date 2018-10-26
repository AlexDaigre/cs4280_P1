#ifndef TOKEN_H
#define TOKEN_H
    enum tokenID {
        eofTk, 
        idTk,
        intTk,
        opDelTk,
        startTk,
        stopTk,
        loopTk,
        voidTk,
        varTk,
        returnTk,
        scanTk,
        outTk,
        programTk,
        ifTk,
        thenTk,
        letTk
    }; 

    char* tokenNames[] = {
        "End of field token",
        "Identifier token",
        "Integer token",
        "Operator or delimiter token",
        "Start keyword token",
        "Stop keyword token",
        "Loop keyword token",
        "Void keyword token",
        "Var keyword token",
        "Return keyword token",
        "Scan keyword token",
        "Out keyword token",
        "Program keyword token",
        "If keyword token",
        "Then keyword token",
        "Let keyword token"
    };

    struct token {
        struct tokenID;
        char* tokenInstance;
        int lineNum;
    };
#endif