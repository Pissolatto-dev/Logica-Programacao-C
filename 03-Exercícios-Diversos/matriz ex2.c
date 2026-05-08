#include <stdio.h>

int main() {

    int lin;
    int col;

    printf("Qual o tamanho das duas matrizes?\n");
    scanf("%d %d", &lin, &col);

    int m1[lin][col];
    int m2[lin][col];

    printf("Agora preencha a primeira matriz\n");

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &m1[i][j]);
        }
    }

    printf("Agora preencha a segunda matriz\n");

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &m2[i][j]);
        }
    }

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            m3[i][j] = m1[i][j] + m2[i][j];
            printf("\t %d", m3[i][j]); 
        }
        printf(\n);
    }
}