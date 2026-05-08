#include <stdio.h>
#include <string.h>
#define tam 50

int main() {

    char str[tam] = "Não gosto de programar em C";
    char *p1;
    char *p2;

    p1 = str;
    p2 = p1 + 4;

    printf(p2);

    return 0;    
}