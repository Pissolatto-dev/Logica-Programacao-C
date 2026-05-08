#include <stdio.h>
#define lin 5
#define col 3

void somam(int m[lin][col]) {

    for (int i = 0; i < lin; i++) {
        int soma = 0;
        for (int j = 0; j < col; j++) {
            soma += m[i][j];
        }
        printf("Soma da linha %d é %d\n", i+1, soma);
    }
}

int main() {

    int m[lin][col];

    printf("Coloque os valores da matriz\n");

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("\t%d", m[i][j]);
        }
        printf("\n");
    }
    
    somam(m);

    return 0;

}