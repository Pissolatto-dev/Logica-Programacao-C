#include <stdio.h>



void semaforo (int atual) {

    switch (atual) {
        case 0:
        printf("[0] Verde\n");
        break;
        case 1:
        printf("[1] Amarelo\n");
        break;
        case 2:
        printf("[2] Vermelho\n");
    }
}

int main() {

    int atual = 0;

    for (int i = 0; i < 6; i++) {
        semaforo(atual)
        atual = next(atual)
    }
    return 0;
}