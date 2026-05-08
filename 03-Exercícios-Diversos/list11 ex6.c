#include <stdio.h>
#define max 10

int soma(int ar[max], int i) {

    if (i < 0) {
        return 0;
    }
    else {
       return ar[i] + soma(ar, i - 1);
    }
}

int main() {

    int ar[max];
    int i = 0;

    printf("Insira uma sequencia de números\n");
    for (i = 0; i < max; i++) {
        scanf("%d", &ar[i]);
    }
    
    int som = soma(ar, max - 1);
    printf("a soma dos números é %d", som);

    return 0;
}