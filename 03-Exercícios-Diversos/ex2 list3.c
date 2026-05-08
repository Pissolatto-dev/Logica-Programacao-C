#include <stdio.h>

int main () {

    int num;
    int den;
    double s;

    num = den = 1;
    do {
        s = s + (double)num / den;
        num *= 2;
        den++;
    } while (den <= 100);
    printf("S: %lf \n", s);

    return 0;
}