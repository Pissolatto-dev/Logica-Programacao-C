#include <stdio.h>

typedef struct {

    char name[60];
    int nota;
    int num;

} Cadastro;


int main() {

    Cadastro als[3];

    for (int i = 0; i < 3; i++) {
        scanf("%d", &als[i].num);
        scanf("%d", &als[i].nota);
        getchar();
        fgets(als[i].name, 60, stdin);
    }

    for (int i = 0; i < 3; i++) {
        printf("Aluno %d: \n", i+1);
        printf("Nome: %s \n", als[i].name);
        printf("Número: %d\n", als[i].num);
        printf("Nota: %d\n", als[i].nota);
    }

    return 0;
}