#include <stdio.h>
#define lin 5
#define col 3
#define tam 15

int main() {

    int m[lin][col];
    int v[tam];
    int count = 0;

    printf("Preencha a matriz de ordem 5x3\n");

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            if (m[i][j] % 3 == 0) {
                v[count] = m [i][j];
                count++;
            }
        }
    }
    for (int g = 0; g < count; g++) {
        printf("O valor %d é múltiplo de 3\n", v[g]);
    }

    return 0;
}