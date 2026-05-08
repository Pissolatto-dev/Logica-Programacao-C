#include <stdio.h>

int main() {

    int n;

    for(n = 1; n < 20; n++) {
        if (n % 2 != 0){ //falando oq eu quero, ou seja, pegando só os pares
            continue; //mandando continuar
        }
        printf("%d \n", n);
    }

    return 0;
}