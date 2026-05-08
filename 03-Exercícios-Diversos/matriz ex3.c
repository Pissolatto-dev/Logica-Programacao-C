#include <stdio.h>
#define lin 4
#define col 4

int main() {

    int m[lin][col];
    int s;

    printf("Preencha a matriz 4x4\n");
    
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", m[i][j]);
        }
    }

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            if (i == j) {
                s = m[i][j] + m[i][j];
                printf("A soma dos itens da diagonal principal é:\n");
                printf("%d\n", s);
            }
        }
    }

    return 0;
}