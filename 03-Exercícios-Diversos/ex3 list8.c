#include <stdio.h>
#define tam 50

int counter(char *p) {

    int count = 0;

   while (*p != '\0') {
        if (*p == ' ') {
            count++;
        }
        p++;
   }

    return count;
}

int main() {

    char str[tam];
    char *p = str;

    printf("Escreva uma frase\n");
    fgets(str, tam, stdin);

    int x = counter(p);

    printf("A quantidade de espaços que aparecem é: %d\n", x);

    return 0;
}