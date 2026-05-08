#include <stdio.h>
#include <string.h>

struct conta {

    int num;
    char nome[500];
    float saldo;

};

int main() {

    struct conta c1;

    printf("Coloque os dados da conta\n");
    printf("Número: ");
    scanf("%d", &c1.num);
    printf("\nNome: ");
    getchar();
    fgets(c1.nome, sizeof(c1.nome), stdin);
    printf("\nSaldo: ");
    scanf("%f", &c1.saldo);

    printf("\nPrintando os dados do cliente\n");
    printf("Número %d \n", c1.num);
    printf("Nome %s \n", c1.nome);
    printf("Saldo %f \n", c1.saldo);

    return 0;
}