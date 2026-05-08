#include <stdio.h>
#include <string.h>
#define max 100

int printword(char str[max], int i) {

    if (str[i] == '\0') {
        return 0;
    }
    else {
        printf("%c \n", str[i]);
        return printword(str, i + 1);
    }
}

int main() {

    char str[max];
    int i = 0;

    printf("Insira uma palavra\n");
    fgets(str, max, stdin);

    printword(str, i);

    return 0;
}