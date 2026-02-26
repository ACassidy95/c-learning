Excluding #include \<stdio.h\>:
        - main.c: In function ‘main’:
main.c:4:9: error: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
    4 |         printf("Hello world\n");
      |         ^\~\~\~\~\~
main.c:1:1: note: include ‘\<stdio.h\>’ or provide a declaration of ‘printf’
  +++ |+#include \<stdio.h\>
    1 | 
main.c:4:9: warning: incompatible implicit declaration of built-in function ‘printf’ [-Wbuiltin-declaration-mismatch]
    4 |         printf("Hello world\n");
      |         ^\~\~\~\~\~
main.c:4:9: note: include ‘\<stdio.h\>’ or provide a declaration of ‘printf’
    - Program doesn't know what 'printf' is.

Excluding int main():
    - main.c:3:1: error: expected identifier or ‘(’ before ‘{’ token
    3 | {
      | ^

Excluding {:
    - main.c: In function ‘main’:
main.c:4:9: error: expected declaration specifiers before ‘printf’
    4 |         printf("Hello world\n");
      |         ^\~\~\~\~\~
main.c:5:1: error: expected declaration specifiers before ‘}’ token
    5 | }
      | ^
main.c:6: error: expected ‘{’ at end of input
    - Program can't tell where main begins.

Excluding }:
    - main.c: In function ‘main’:
main.c:5:9: error: expected declaration or statement at end of input
    5 |         printf("Hello world\n");
      |         ^\~\~\~\~\~
    - Program expected function scope to be closed or addtitional statements after printf statment

Excluding ';':
    - main.c: In function ‘main’:
main.c:5:32: error: expected ‘;’ before ‘}’ token
    5 |         printf("Hello world\n")
      |                                ^
      |                                ;
    6 | }
      | ~
    - Improperly completed statement

Excluding parenthesis in printf statement:
    - main.c: In function ‘main’:
main.c:5:15: error: expected ‘;’ before string constant
    5 |         printf "Hello world\n";
      |               ^\~\~\~\~\~\~\~\~\~\~\~\~\~\~\~
      |               ;
    - Program expected the printf statement to be completed before beginning the constant statement \
      of the hello world

Excluding double-quotes in printf statement:
    - main.c: In function ‘main’:
main.c:5:16: error: ‘Hello’ undeclared (first use in this function); did you mean ‘ftello’?
    5 |         printf(Hello world\n);
      |                ^\~\~\~\~
      |                ftello
main.c:5:16: note: each undeclared identifier is reported only once for each function it appears in
main.c:5:21: error: expected ‘)’ before ‘world’
    5 |         printf(Hello world\n);
      |               ~     ^\~\~\~\~\~
      |                     )
main.c:5:27: error: stray ‘\’ in program
    5 |         printf(Hello world\n);
      |                           ^
    - Program tries to read Hello and World as variables

Excluding printf, i.e ("Hello World\\n"); :
    - No compilation or runtime error - null statement
