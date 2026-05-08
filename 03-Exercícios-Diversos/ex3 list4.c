#include <stdio.h>

int somaMultiplos(int limit, int div) {
    int mult = 0;
    for (int i = div; i <= limit; i++) {
        if (i % div == 0) {
            mult += i;
        }
    }
    
    return mult;
}

int main() {

    int div;
    int limit;
    int mult;

    printf("Informe o número e seu divisor\n");
    scanf("%d %d", &limit, &div);
    somaMultiplos(limit, div);
    printf("a soma é %d \n", somaMultiplos(limit, div));

    return 0;
}