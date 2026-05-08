#include <stdio.h>

int div (int n) {

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d é divisor de %d\n", i, n);
            count += 1;
        }
    
    }
    return count;
}

int main() {

    int n;
    int count;
    int resultado;

    printf("Entre com os um número para achar os divisores\n");
    scanf("%d", &n);
    resultado = div(n);
    printf("existem %d divisores para %d\n", resultado, n);

    return 0;
}