#include <stdio.h>
#include <string.h>
#define tam 500

struct product {

    float price;
    char str[tam];
    int qtd;

};

int main() {

    struct product p1;

    printf("Nome do produto\n");
    fgets(p1.str, tam, stdin);
    strlen(p1.str);
    printf("Preço\n");
    scanf("%f", &p1.price);
    printf("Quantidade em estoque\n");
    scanf("%d", &p1.qtd);

    float priceEst;

    priceEst = p1.price*p1.qtd;

    printf("\nProduto: %s", p1.str);
    printf("Preço do Estoque: %.2f\n", priceEst);
    printf("Preço unitário: %.2f\n", p1.price);

    return 0;
}