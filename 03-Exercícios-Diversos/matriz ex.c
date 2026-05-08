#include <stdio.h>
#define lin 2
#define col 2

int main() {

    int i;
    int j;
    float nota[lin][col];

    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            printf("Entre com a nota [%d %d]:", i, j);
            scanf("%f", &nota[i][j]);
        }
    }

    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            printf("\t %.1f", nota[i][j]);
        }
        printf("\n");
    }

    return 0;
}