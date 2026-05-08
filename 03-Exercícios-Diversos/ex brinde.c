#include <stdio.h>

int main() {

    int alun;
    int aula;

    printf("Qual a quantidade de alunos na sala?\n");
    scanf("%d", &alun);
    printf("Qual a quantidade de aulas?\n");
    scanf("%d", &aula);

    int faltas[alun][aula];

    for (int i = 0; i < alun; i++) {
        for (int j = 0; j < aula; j++) {
            printf("O aluno %d esteve presente na aula %d?\n", i+1, j+1);
            scanf("%d", &faltas[i][j]);
        }
    }

    float porcentagem[alun][1];

    for (int i = 0; i < alun; i++) {
        for (int j = 0; j < aula; j++) {
            porcentagem[i][1] += (100 / aula) * faltas[i][j];
        }
    }

     for (int i = 0; i < alun; i++) {
        printf("O percentual de presença do aluno %d é %.2f\n", i+1, porcentagem[i][1]);
        if (porcentagem[i][1] > 75) {
            printf("O aluno %d foi aprovado\n", i+1);
        }
        else {
            printf("O aluno %d foi reprovado\n", i+1);
        }
        printf("\n");
    }

    return 0;
}