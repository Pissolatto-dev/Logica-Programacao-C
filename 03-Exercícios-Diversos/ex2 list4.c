#include <stdio.h>

char letr(char letra) {
    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' || letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U') {
        printf("Sua letra é uma vogal\n");
    }
    else {
        printf("Sua letra é uma consoante\n");
    }
}
int main() {

    char letra;

    printf("Qual letra você quer saber se éuma consoante ou vogal?\n");
    scanf("%c", &letra);
    letr(letra);

    return 0;
}
