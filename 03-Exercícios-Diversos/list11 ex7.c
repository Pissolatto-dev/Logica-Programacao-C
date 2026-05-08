#include <stdio.h>
#define max 10

int soma(int ar[max], int i) {

    if (i == max) {
        return 0;
    }
    else {
       return ar[i] + soma(ar, i + 1);
    }
}

int main() {

    int ar[max];

    printf("Insira uma sequencia de números\n");
    for (int i = 0; i < max; i++) {
        scanf("%d", &ar[i]);
    }
    int i = 0;
    
    int som = soma(ar, i);
    printf("a média dos números é %d", (som/max));

    return 0;
}