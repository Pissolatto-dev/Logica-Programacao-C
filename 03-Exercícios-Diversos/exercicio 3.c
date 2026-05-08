#include <stdio.h>

int main() {

    char letra;

    printf("Coloque uma letra para saber se a mesma é vogal ou não \n");
    scanf("%c", &letra);

    if (letra == "a"||letra == "e"||letra == "i"||letra == "o"||letra == "u"||letra =="A"||letra == "E"||letra == "I"||letra == "O"|| letra =="U") {
        printf("Sua letra é uma vogal \n");
    }
    else {
        printf("Sua letra é uma consoante \n");
}

    return 0;
    
}