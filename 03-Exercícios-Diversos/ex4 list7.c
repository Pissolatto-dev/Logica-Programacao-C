#include <stdio.h>
#define max 500
#define numb 10

void subs(char str[], char numbers[], int tam) {

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        for (int j = 0; j < numb; j++) {
            if (str[i] == numbers[j]) {
                str[i] = '*';
            }
        }
    }

    puts(str);
}

int main() {

    char str[max];
    char numbers[numb] = "0123456789";

    printf("Entre com sua string\n");
    fgets(str, max, stdin);

    subs(str, numbers, numb);

    return 0;
}