// [Gerenciamento de Memória] Vetor Expansível com Realloc
// Objetivo: Gerenciar uma lista de vendas permitindo que o usuário adicione dados dinamicamente.
// Conceitos Aplicados: Alocação de memória dinâmica (malloc), redimensionamento de memória (realloc) e ponteiros.

#include <stdio.h>
#include <stdlib.h>

int main() {

    int i = 0;
    int n, j;
    int *vet;
    int total;
    int media;
    int count = 0;

    vet = (int *) malloc(1 * sizeof(int));

    for (i = 0; i < 1; i++) {
        printf("Quantidade de vendas do mês 1:");
        scanf("%d", &vet[i]);
    }

    printf("Você gostaria de adicionar mais meses?\n");
    scanf("%d", &n);
    
    if (n > 0) {
        vet = (int *) realloc(vet, 1+n * sizeof(int));
        for (i = 1; i < 1+n; i++) {
            printf("Quantidade de vendas do mês %d:", i+1);
            scanf("%d", &vet[i]);
        }
    }
    
    for (i = 0; i < 1+n; i++) {
        printf("O mês %d fez %d vendas\n", i+1, vet[i]);
        total += vet[i];
        count++;
    }
    printf("O total de vendas foi: %d\n", total);
    media = total/count;
    printf("Média: %d\n", media);

    return 0;
}
