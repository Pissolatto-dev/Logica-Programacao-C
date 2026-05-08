#include <stdio.h>

int fib(int n) {

    if (n == 0) {
        return 0;
    }
    else if (n ==1) {
        return 1;
    }
    else {
        return (n-1) + (n-2);
    }
}

int main() {

    int n;

    printf("Qual fibonnaci vc quer calcular?\n");
    scanf("%d", &n);

    printf("Fibonacci de %d = %d", n, fib(n));

    return 0;
}