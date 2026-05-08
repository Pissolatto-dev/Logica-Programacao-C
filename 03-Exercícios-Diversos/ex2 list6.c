#include <stdio.h>
#define lin 3
#define col 5

void somam(int m[lin][col]) {

    for (int i = 0; i < col; i++) {
        int soma = 0;
        for (int j = 0; j < lin; j++) {
            soma += m[j][i];
        }
        printf("A soma da coluna %d é %d\n", i+1, soma);
    }
}

int main () {

    int m[lin][col];

    printf("Preencha a matriz de ordem 3x5\n");

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    somam(m);

    return 0;
}