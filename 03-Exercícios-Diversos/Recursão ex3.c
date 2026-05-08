#include <stdio.h>

int count(int n) {

    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return n + count(n-1);
    }
}

int main() {

    int n;

    printf("Qual somatória vc quer calcular?\n");
    scanf("%d", &n);

    printf("Somatória de %d até 1 = %d", n, count(n));

    return 0;
}