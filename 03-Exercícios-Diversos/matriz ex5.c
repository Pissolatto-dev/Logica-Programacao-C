#include <stdio.h>
#define lin 3
#define col 3

int main() {

    int m[lin][col];
    int s;

    printf("Coloque os números da matriz\n");

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", & m[i][j]);
        }
    }

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            if (i + j == 2) {
                s = m[i][j]
            }
        }
    }

    printf("A soma da diagonal secundária é %d", s);

    return 0;
}