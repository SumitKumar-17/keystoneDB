# Notes on parser

## Interfacing with yacc (from flex's docs)

One of the main uses of 'flex' is as a companion to the 'yacc'
parser-generator.  'yacc' parsers expect to call a routine named
'yylex()' to find the next input token. The routine is supposed to
return the type of the next token as well as putting any associated
value in the global 'yylval'. To use 'flex' with 'yacc', one specifies
the '-d' option to 'yacc' to instruct it to generate the file 'y.tab.h'
containing definitions of all the '%tokens' appearing in the 'yacc'
input. This file is then included in the 'flex' scanner. For example,
if one of the tokens is 'TOK_NUMBER', part of the scanner might look
like:

```lex
         %{
         #include "y.tab.h"
         %}
     
         %%
     
         [0-9]+        yylval = atoi( yytext ); return TOK_NUMBER;
```

## Action in flex

Actions can include arbitrary C code, including 'return' statements
to return a value to whatever routine called `yylex()`. Each time
`yylex()` is called it continues processing tokens from where it last
left off until it either reaches the end of the file or executes a
return.

Actions are free to modify `yytext` except for lengthening it (adding
characters to its end-these will overwrite later characters in the input
stream).

## Start Condition

'flex' provides a mechanism for conditionally activating rules. Any
rule whose pattern is prefixed with '<sc>' will only be active when the
scanner is in the "start condition" named 'sc'. For example,

```
         <STRING>[^"]*        { /* eat up the string body ... */
                     ...
                     }
```

will be active only when the scanner is in the 'STRING' start
condition, and

```
         <INITIAL,STRING,QUOTE>\.        { /* handle an escape ... */
                     ...
                     } 
```

will be active only when the current start condition is either
'INITIAL', 'STRING', or 'QUOTE'.

Example for detecting multiline comment in C:

```lex
 %x comment
         %%
                 int line_num = 1;
     
         "/*"         BEGIN(comment);
         <comment>[^*\n]*        /* eat anything that's not a '*' */
         <comment>"*"+[^*/\n]*   /* eat up '*'s not followed by '/'s */
         <comment>\n             ++line_num;
         <comment>"*"+"/"        BEGIN(INITIAL);
```

## Different input source

```flex
%{
#undef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
    { \
    int c = getchar(); \
    result = (c == EOF) ? YY_NULL : (buf[0] = c, 1); \
    }
%}
```

## Reentrant C Scanner

'flex' has the ability to generate a reentrant C scanner. This is
accomplished by specifying '%option reentrant' ('-R') The generated
scanner is both portable, and safe to use in one or more separate
threads of control.(19 Reentrant C Scanners
)

We also need to configure it in bison:

```bison
%lex-param   { yyscan_t scanner }
```

## Bison

### Definition

+ %type -> non-terminal types
+ %token -> terminal types (upper-case conventionally)
+ %left (+-*/) & %right (=) & %nonassoc

Example:

```bison
%left AA BB
%nonassoc CC
%right DD
```

Example:

```bison
%token <num> NUMBER
%token <op> ADDOP MULOP LPAREN RPAREN
%union {
 char op;
 double num;
}
```


Example:

```bison
%%
 program: program expr '\n' { printf("%d\n", $2); }
 ;
 expr: expr '+' expr { $$ = $1 + $3; }
 | expr '-' expr { $$ = $1 - $3}
 ;
%%
```


### Compile Bison

```shell
# -d generate bison_demo.tab.h
bison -d bison_demo.y
```

### Generate counter examples

```shell
bison -Wcounterexamples ./parser/sql.y 
```

### Freeing Discarded Symbols

As a rule of thumb, destructors are invoked only when user actions cannot manage the memory.

```bison
%destructor {
    //
    free( ($$) );
}<str>
```

## C++

### Class V.S. Struct in C++

+ Members of a structure are public by default, while members of a class are private by default.

+ A structure is mainly used for grouping data, while a class is mainly used for data abstraction and inheritance.

## Construct C++ String from C string

+ duplicated rules could lead to conflict.
+ Token precedence and associativity should be correct.

```c++
#include <iostream>
 
int main()
{
    // C-style string
    const char* cstr = "Techie Delight";
 
    // string constructor accepts `const char*` as a parameter
    std::string s(cstr);
    std::cout << s << std::endl;
 
    return 0;
}
```

### public inheritance

```shell
‘skDB::SQLStmt’ is an inaccessible base of ‘skDB::DropStmt’
```

We should use public inheritance here.

### Token Precedence and Associativity

[Article on token precedence and associativity ](https://cloud.tencent.com/developer/article/2190364)

### Matching Rule in Flex (Scanner)

If it finds more than one match, it takes the one matching the most text (for trailing context
rules, this includes the length of the trailing part, even though it
will then be returned to the input). If it finds two or more matches of
the same length, the rule listed first in the 'flex' input file is
chosen.

### Buffer in Flex

It should be noted that some characters may exist in flex's buffer when parser error occur in `bison`

