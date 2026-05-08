#include <stdio.h>

int plus (int n) {

    int soma = 0;
    for (int i = 1; i <= n; i++) {
        soma += i;
    }
    return soma;
}
int main() {

    int n;

    printf("Escolha um número inteiro\n");
    scanf("%d", &n);
    plus(n);
    printf("A soma de todos os termos são %d", plus(n));

    return 0;
}