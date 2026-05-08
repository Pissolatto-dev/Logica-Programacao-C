#include <stdio.h>

int main() {

    int nota1;
    int nota2;
    int nota3;
    int nota4;
    float mediaFinal;
    int count;
    count = 0;

    while(count <= 30) {
        printf("Qual as notas do aluno? \n");
        scanf("%d %d %d %d", &nota1, &nota2, &nota3, &nota4);
        mediaFinal = (nota1 + nota2 + nota3 + nota4) / 4;
        printf("A média final do aluno %d é %f \n", count, mediaFinal);
        count++;
    }

    return 0;
}