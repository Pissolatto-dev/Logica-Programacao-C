#include <stdio.h>
#define max 500
#define alfa 26

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
    int countM;
    int countm;

    printf("Entre com a sua string\n");
    fgets(str, max, stdin);

    countm = counterm(str, alphabetm, alfa);
    countM = counterM(str, alphabetM, alfa);

    printf("Existem %d letras maiusculas e %d letras minusculas\n", countM, countm);

    return 0;
}