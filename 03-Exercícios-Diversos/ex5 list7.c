#include <stdio.h>
#include <string.h>

void counterwords(char str[]) {
    int count = 0;
    char *palavra = strtok(str, " ");

    while (palavra != NULL) {
        count++;
        palavra = strtok(NULL, " "); 
    }

    printf("A string possui %d palavra(s).\n", count);

    printf("Palavras da string:\n");
    palavra = strtok(str, " ");
    while (palavra != NULL) {
        printf("%s\n", palavra);
        palavra = strtok(NULL, " ");
    }
}

int main() {

    char str[200];
    
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    counterwords(str);

    return 0;
}