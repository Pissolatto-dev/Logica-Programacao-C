#include <stdio.h>

int show(int n) {

    for (int i = n; i >= 1; i--) {
        printf("\n %d", i);
    }
}

int main() {

    int n;

    printf("Digite um número inteiro\n");
    scanf("%d", &n);
    show(n);

    return 0;
}