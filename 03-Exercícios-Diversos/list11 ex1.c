#include <stdio.h>

int printer (int n, int s) {

    if (n == 0) {
        printf("%d ", n);
        return 0;
    }
    else if (s <= n && s % 2 == 0){
        printf("%d ", s);
        return printer(n, s + 1);
    }
    else if (s % 2 != 0){
        return printer(n, s + 1);
    }
}

int main() {

    int n;
    int s = 0;

    printf("Coloque um número par\n");
    scanf("%d", &n);

    printer(n, s);

    return 0;
}