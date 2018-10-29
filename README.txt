This project is option #3: FSA table + driver.
The fsa table is contained in fsaTable.c and is called fsaTable.
The driver is stored in scanner.c and is called getNextToken().

    This driver is invoked from main.c againt the input file. 
Each invocation produces one token. main.c continues to call
getNextToken() untill an eof token is produced.

    fsaTable.c provies some additional functions and lists to
provide both keyword lookup and charecter groups. The charecter
groups allow the fsa table to treat all of a set of charecters
(e.g. all lowercase letters) as one input. This allowed me to 
simplify the table a good bit, and made the proccess closer
to programs like lex.



