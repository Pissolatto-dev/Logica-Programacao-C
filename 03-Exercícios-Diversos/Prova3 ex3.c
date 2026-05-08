#include <stdio.h>

void calc(int n, int m, int *s, int *mu, int *su) {
    
    *s = n + m;
    *su = n - m;
    *mu = n * m;
}

int main() {

    int n, m, s, su, pu;

    printf("Quais valores quer fazer operações?\n");
    scanf("%d%d", &n, &m);

    calc(n, m, &s, &su, &pu);

    printf("Soma: %d\nSubtração: %d\nMultiplicação: %d\n", s, su, pu);

    return 0;
}