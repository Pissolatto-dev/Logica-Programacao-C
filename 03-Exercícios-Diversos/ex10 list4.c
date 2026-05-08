#include <stdio.h>
#include <math.h>

float rdelta (int a, int b, int c) {
    
    int delta;
    delta = pow(b,2) - (4 * a * c);

    return delta;
}
float bask1(int delta, int a, int b) {

    int x1;
    x1 = (-(b) + sqrt(delta)) / (2*a);

    return x1;
}
float bask2(int delta, int a, int b) {

    int x2;
    x2 = (-(b) - sqrt(delta)) / (2*a);

    return x2;
}


int main() {

     int a;
     int b;
     int c;
     int delta;
     float x1;
     float x2;

    printf("Quais os valores de a, b e c?\n");
    scanf("%d %d %d", &a, &b, &c);
    
    if (a == 0) {
        printf("Não é uma função do segundo grau\n");
    }
    else {
        delta = rdelta(a, b, c);
        if (delta < 0) {
            printf("Não existe solução nos números reais\n");
        }
        else {
            x1 = bask1(delta, a, b);
            x2 = bask2(delta, a, b);
            printf("x1:%d  x2:%d", x1, x2);
        }
    }

    return 0;

}