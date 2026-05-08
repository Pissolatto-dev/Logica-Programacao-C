// [Estruturas de Dados] Sistema de Cadastro Acadêmico
// Objetivo: Armazenar e filtrar registros de alunos para identificar maiores pontuações.
// Conceitos Aplicados: Vetores de tipos personalizados (structs), busca linear e tipos de dados primitivos.

#include <stdio.h>
#include <string.h>
#define tam 500

struct aluno {

    int age;
    float note;
    char name[tam];

};

int main() {

    struct aluno s[5];
    float maior;

    for (int i = 0; i < 5; i++) {
        printf("Preencha os dados do aluno %d\n", i+1);
        printf("Idade\n");
        scanf("%d", &s[i].age);
        printf("Nome\n");
        getchar();
        fgets(s[i].name, tam, stdin);
        printf("Nota\n");
        scanf("%f", &s[i].note);
    }

    for (int i = 0; i < 5; i++) {
        if (s[i].note > maior) {
            maior = s[i].note;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (maior == s[i].note) {
            printf("\n");
            printf("O aluno %s teve a maior nota de: %.2f", s[i].name, maior);
        }
    }

    return 0;
}
