#include <stdio.h>

int main() {

    int altura;
    int idade;

    printf("Qual sua altura? (em centimetros) \n");
    scanf("%d", &altura);
    printf("Qual sua idade? \n");
    scanf("%d", &idade);

    if (idade >= 12 & altura >= 150) {
        printf("Você pode ir na Barca Viking \n");
        
        if (idade >= 14 & altura >= 140) {
            printf("Você pode ir no Elevador \n");
            
            if (idade >= 16 & altura >= 170) {
                printf("Você pode ir no Final Killer \n");
            }
        }
    }
    else {
        printf("Você não pode ir em nenhum brinquedo \n");
    }

    return 0;
}