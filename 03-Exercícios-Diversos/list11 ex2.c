#include <stdio.h>

int printer (int n) {

    if (n == 0) {
        printf("%d ", n);
        return 0;
    }
    else if (n % 2 == 0){
        printf("%d ", n);
        return printer(n - 1);
    }
    else if (n % 2 != 0){
        return printer(n - 1);
    }
}

int main() {

    int n;

    printf("Coloque um número par\n");
    scanf("%d", &n);

    printer(n);

    return 0;
}