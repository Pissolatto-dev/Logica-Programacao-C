#include <stdio.h>

int main() {

    int n = 4;
    float f = 7.34;
    char c = 'm';

    int *pn = &n;
    float *pf = &f;
    char *pc = &c;

    printf("%d - %p\n", *pn, pn);
    printf("%.2f - %p\n", *pf, pf);
    printf("%c - %p\n", *pc, pc);

    return 0;
}