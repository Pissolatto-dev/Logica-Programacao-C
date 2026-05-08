// [Algoritmos Avançados] Inversão de Strings via Recursão
// Objetivo: Manipular cadeias de caracteres sem o uso de laços iterativos (for/while).
// Conceitos Aplicados: Recursividade, manipulação de ponteiros de caracteres (char*) e pilha de execução.

#include <stdio.h>
#include <string.h>
#define MAX_TAMANHO 256

void inverte_string_recursiva(char *str) {
   
    if (*str == '\0') {
        return;
    }
    inverte_string_recursiva(str + 1);
    printf("%c", *str);
}

int main() {

    char texto[MAX_TAMANHO];

    printf("Digite uma string para inverter: ");

    if (fgets(texto, sizeof(texto), stdin) != NULL) {

        texto[strcspn(texto, "\n")] = '\0';

        printf("String invertida: ");
        inverte_string_recursiva(texto);
        printf("\n");
    }

    return 0;
}
