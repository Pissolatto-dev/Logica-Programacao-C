// [Estruturas de Dados] Gerenciamento de Dados Compostos
// Objetivo: Organizar informações relacionadas utilizando estruturas de dados aninhadas.
// Conceitos Aplicados: Structs compostas, gerenciamento de strings com fgets e limpeza de buffer (getchar).

#include <stdio.h>
#include <string.h>
#define tam 500

struct adrees {

    int number;
    char street[tam];
    char city[tam];

};

struct person {

    char name[tam];
    int age;
    struct adrees mail;

};

int main() {

    struct person p[3];

    for (int i = 0; i < 3; i++) {

        printf("Nome\n");
        fgets(p[i].name, tam, stdin);
        
        printf("Idade\n");
        scanf("%d", &p[i].age);
        getchar();
        
        printf("Endereço\n");
        
        printf("Rua:\n");
        fgets(p[i].mail.street, tam, stdin);
        
        printf("Cidade:\n");
        fgets(p[i].mail.city, tam, stdin);
        
        printf("Número:\n");
        scanf("%d", &p[i].mail.number);
        getchar();
    }

    for (int i = 0; i < 3; i++) {

        printf("\n \nNome: %s", p[i].name);
        printf("Idade: %d\n", p[i].age);
        printf("\nEndereço:\nRua %sNúmero %d\nCidade %s\n", p[i].mail.street, p[i].mail.number, p[i].mail.city);
    }

    return 0;
}