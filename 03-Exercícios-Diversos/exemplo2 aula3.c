#include <stdio.h>

int main() {

   int fat;
   int n;

   printf("Entre com um valor inteiro: \n");
   scanf("%d", &n);
   fat = 1;
   
   while(n > 1) {
    fat *= n;
    n--;
   }
    printf("Fatorial = %d \n", fat);

    return 0;
}