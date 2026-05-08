#include <stdio.h>
#define max 500
#define alfa 26
#define numb 10

int counternumb(char str[], char number[], int tam) {

    int count = 0;

     for (int i = 0;  str[i] != '\0' && str[i] != '\n'; i++) {
        for (int j = 0; j < tam; j++) {
            if (str[i] == number[j]) {
                count++;
            }
        }
     }

     return count;
}

int counterM(char str[], char alphabetM[], int tam) {

    int count = 0;

    for (int i = 0;  str[i] != '\0' && str[i] != '\n'; i++) {
        for (int j = 0; j < tam; j++) {
            if (str[i] == alphabetM[j]) {
                count++;
            }
        }
    }

    return count;
}

int counterm(char str[], char alphabetm[], int tam) {

    int count = 0;

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        for (int j = 0; j < tam; j++) {
            if (str[i] == alphabetm[j]) {
                count++;
            }
        }
    }

    return count;
}

int main() {

    char str[max];
    char alphabetM[alfa] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alphabetm[alfa] = "abcdefghijklmnopqrstuvwxyz";
    char number[numb] = "0123456789";
    int countM;
    int countm;
    int countnumb;

    printf("Entre com a sua string\n");
    fgets(str, max, stdin);

    countm = counterm(str, alphabetm, alfa);
    countM = counterM(str, alphabetM, alfa);
    countnumb = counternumb(str, number, numb);

    printf("Existem %d letras maiusculas, %d letras minusculas e %d digitos\n", countM, countm, countnumb);

    return 0;
}