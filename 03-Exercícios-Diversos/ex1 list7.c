#include <stdio.h>
#define tam 500

int printer(char str[], char car) {

    int count = 0;
    int position = 1;

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] == car) {
            printf("Na posição %d o caractere %c aparece\n", position, car);
            count++;
        }
        position++;
    }
    
    return count;
}

int main() {

    char str[tam];
    char car;
    int count;

    printf("Digite sua frase:\n");
    fgets(str, tam, stdin);

    printf("Qual caractere você quer contar?\n");
    scanf("%c", &car);

    count = printer(str, car);
    printf("O caractere %c aparece %d vezes\n", car, count);

    return 0;
}