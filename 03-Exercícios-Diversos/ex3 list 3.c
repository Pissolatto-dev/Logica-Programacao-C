#include <stdio.h>

int main () {

    int den;
    int num;
    double s;

    num = den = 1;
    do {
        s = s + (double)num/den;
        num += 2;
        den++;
    } while ( num <= 90, den <= 50);
    printf("S = %lf \n", s);

    return 0;
}