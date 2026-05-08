#include <stdio.h>
#include <stdlib.h>

int main() {

    int **p;
    int i;
    int j;

    p = (int **) malloc(4 * sizeof(int *));

    for (i = 0; i < 4; i++) {
        p[i] = (int *) malloc(3 * sizeof(int));
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &p[i][j]);
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d", p[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 4; i++) {
        free(p[i]);
    }
    free(p);

    return 0;
}