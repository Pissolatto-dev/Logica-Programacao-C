#include <stdio.h>

int main() {

    int mat[4][4];
    int *p = &mat[0][0];
    int number;
    int count = 0;

    printf("Insira os números da matriz\n");

    for (int i = 0; i < 16; i++) {
        scanf("%d", &p[i]);
    }

    printf("Qual número você quer contar?\n");
    scanf("%d", &number);

    for (int i = 0; i < 16; i++) {
        if (p[i] == number) {
            count++;
        }
    }

    printf("A quantidade de vezes que %d aparece é: %d", number, count);

    return 0;
}