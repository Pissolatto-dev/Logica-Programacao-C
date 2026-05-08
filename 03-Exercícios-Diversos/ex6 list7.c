#include <stdio.h>
#define tam 500

int comparate(char str[], char str2[]) {

    int count = 0;

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
            if (str[i] != str2[i]) {
                count++;
            }
        }
    return count;
}

int main() {

    char str[tam];
    char str2[tam];
    int count;

    printf("Entre com a primeira string:\n");
    fgets(str, tam, stdin);

    printf("Entre com a segunda string:\n");
    fgets(str2, tam, stdin);

    count = comparate(str, str2);

    if (count > 0) {
        printf("As strings são diferentes\n");
    }
    else {
        printf("As strings são iguais\n");
    }

    return 0;
}