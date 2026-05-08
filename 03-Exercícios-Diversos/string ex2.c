#include <stdio.h>
#define tam 500

int main() {

    char str[tam];
    int count = 0;
    int i = 0;

    printf("Digite uma frase:\n");
    fgets(str, tam, stdin);

    while (str[i] != '\0') {
        if (str[i] != '\n' && str[i] != ' ') {
            count++;
        }
        i++;
    }

    printf("%s\n", str);
    printf("A quantidade de caracteres é %d", count);

    return 0;
}