#include <stdio.h>

int main() {

    float nota1;
    float nota2;
    float nota3;
    float nota4;
    float mediaFinal;

    printf("Quais as notas do aluno? \n");
    scanf("%f %f %f %f", &nota1, &nota2, &nota3, &nota4);

    mediaFinal = (nota1 + nota2 + nota3 + nota4) / 4;

    if (mediaFinal >= 7) {
        printf("O aluno foi aprovado \n");
    }
    else if (mediaFinal < 7 && mediaFinal >= 4) {
        printf("O aluno ficou de exame \n");
    }
    else {
        printf("O aluno foi reprovado");
    }
    
    printf("A média final foi %.2f \n", mediaFinal);

    return 0;
}