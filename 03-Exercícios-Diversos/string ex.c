#include <stdio.h>

int main() {

    char str1[20] = "Programação em C";
    char str2[20];
    int i;

    for (i = 0; str1[i] != '\0'; i++) {
        str2[i] = str1[i];
    }

    str2[i] = '\0';
    printf("%s\n", str2);

    return 0;
}