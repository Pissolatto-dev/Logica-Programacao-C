// [Lógica de Jogos] Simulador de Adivinhação de Números
// Objetivo: Implementar um jogo de interação com o usuário baseado em tentativa e erro.
// Conceitos Aplicados: Geração de números pseudoaleatórios (rand), loops de controle e sementes de tempo.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

    int number = rand() % 100 + 1;
    int guess;
    int count = 0;

    printf("Guess the secret number\n");
    scanf("%d", &guess);

    while (guess < number) {
        printf("Try a bigger number\n");
        printf("What's the new number?\n");
        scanf("%d", &guess);
        count++;
    }
    while (guess > number) {
        printf("Try a smaller number\n");
        printf("What's the new number?\n");
        scanf("%d", &guess);
        count++;
    }
    if (guess == number) {
        printf("Você acertou\n");
        printf("%d", count);
    }

    return 0;
}