#include <stdio.h>
#include <string.h>
#define max 100

int countword(char str[max], int i, int count) {

    if (str[i] == '\0') {
        printf("a string tem %d caracteres\n", count - 1);
    }
    else if (str[i] == '\0' || str[i] == ' ') {
        return countword(str, i + 1, count);
    }
    else {
        count++;
        return countword(str, i + 1, count);
    }
}

int main() {

    char str[max];
    int i = 0;
    int count = 0;

    printf("Insira uma palavra\n");
    fgets(str, max, stdin);

    countword(str, i, count);

    return 0;
}