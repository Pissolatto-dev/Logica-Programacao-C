#include <stdio.h>

int main() {

    int lin;
    int col;

    printf("Entre com a quantidade de linhas e colunas da matriz\n");
    scanf("%d %d", &lin, &col);

    int m[lin][col];
    int maior = m[0][0];

    printf("Entre com os números da matriz\n");

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            if (m[i][j]  > maior) {
                maior = m[i][j];
            }
        }
    }

    printf("O maior valor é %d", maior);

    return 0;
}