#include <stdio.h>

int main() {

    int x;
    int y;
    int n;

    printf("Entre com um intervalo de x a y \n");
    scanf("%d %d", &x, &y);
                    //for sempre tem q  ue separar as operações por ; e não por ,
    for(n = x+1; n < y; n++) { //n=x+1 é o primeiro, em seguda vem o comando da frente, n++ é o último a ser executado, sendo executado após do q tem dentro do for  
        printf("%d \n", n); //vem antes do n++
    }

    return 0;

}