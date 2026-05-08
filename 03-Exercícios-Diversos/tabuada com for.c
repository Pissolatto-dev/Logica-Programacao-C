#include <stdio.h>

int main() {

    int tab;
    int n;
    int x;

    printf("Qual tabuada você deseja? \n");
    scanf("%d", &n);

    for(x = 0; x <= 10; x++) {  //definir o que eu quero
        tab = n*x;  //fazendo a conta
        printf("%d*%d = %d \n", n, x, tab); //mandando printar o resultado
    }

    return 0;
}