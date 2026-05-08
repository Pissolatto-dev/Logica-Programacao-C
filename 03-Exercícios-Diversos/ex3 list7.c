#include <stdio.h>
#include <ctype.h>

#define max 555
#define alfa 26

void stringReader(char str[], int tam) {

    printf("Entre com a string: \n");
    fgets(str, tam, stdin);
}

void criptography(char str[], char alphabet[], char invertedAlphabet[], int tam) {

    int i;
    int j;

    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        for (j = 0; j < tam; j++) {
            if (str[i] == alphabet[j]) {
                str[i] = invertedAlphabet[j];
                break;
            }
        }
    }
}

int main() {

    char str[max];
    char alphabet[alfa] = "abcdefghijklmnopqrstuvwxyz";
    char invertedAlphabet[alfa] = "zyxwvutsrqponmlkjihgfedcba";

    stringReader(str, sizeof(str));
    criptography(str, alphabet, invertedAlphabet, alfa);
    puts(str);
}

