// [Projeto de Lógica] Simulador de Exploração de Dungeon
// Objetivo: Implementação de uma Máquina de Estados Finita (FSM) para gerenciar o fluxo do jogo.
// Conceitos Aplicados: Estruturas de controle (switch-case), loops de eventos e estados transicionais.

#include <stdio.h>
#include <stdlib.h>

//Definição dos estados usando constantes inteiras
#define ENTRA_DUNGEON 0
#define EXPLORAR_SALA 1
#define MATAR_MONSTRO 2
#define ABRIR_BAU 3
#define ENTRAR_SALA 4
#define FIM_DE_JOGO 5
#define SAIR_DUNGEON 6

int main() {

    //O personagem começa no estado inicial
    int estadoAtual = ENTRA_DUNGEON;
    int escolha;

    printf("=== BEM-VINDO A EXPLORACAO DE DUNGEON ===\n\n");

    //Loop do Jogo: Continua rodando ate atingir um dos dois estados finais
    while (estadoAtual != FIM_DE_JOGO && estadoAtual != SAIR_DUNGEON) {
        
        //Estrutura principal de controle de estados
        switch (estadoAtual) {
            
            case ENTRA_DUNGEON:
                printf("Personagem entrou na Dungeon\n");
                printf("Ações disponíveis:\n");
                printf("1 - Andar pela sala\n");
                printf("2 - Desistir\n");
                printf("Escolha sua ação: ");
                scanf("%d", &escolha);

                if (escolha == 1) {
                    estadoAtual = EXPLORAR_SALA;
                } else if (escolha == 2) {
                    estadoAtual = SAIR_DUNGEON;
                } else {
                    printf("-> Ação inválida! Tente novamente.\n\n");
                }
                break;

            case EXPLORAR_SALA:
                printf("Explorando a sala\n");
                printf("Ações disponíveis:\n");
                printf("1 - Encontrou Monstro\n");
                printf("2 - Encontrou Baú\n");
                printf("3 - Próxima Sala\n");
                printf("4 - Desistir\n");
                printf("Escolha sua ação: ");
                scanf("%d", &escolha);

                if (escolha == 1) {
                    estadoAtual = MATAR_MONSTRO;
                } else if (escolha == 2) {
                    estadoAtual = ABRIR_BAU;
                } else if (escolha == 3) {
                    estadoAtual = ENTRAR_SALA;
                } else if (escolha == 4) {
                    estadoAtual = SAIR_DUNGEON;
                } else {
                    printf("-> Ação inválida! Tente novamente.\n\n");
                }
                break;

            case MATAR_MONSTRO:
                printf("Matar Monstro\n");
                printf("Ações disponíveis:\n");
                printf("1 - Voltar Explorar (Venceu a batalha)\n");
                printf("2 - Morreu\n");
                printf("3 - Desistir\n");
                printf("Escolha sua ação: ");
                scanf("%d", &escolha);

                if (escolha == 1) {
                    estadoAtual = EXPLORAR_SALA;
                } else if (escolha == 2) {
                    estadoAtual = FIM_DE_JOGO;
                } else if (escolha == 3) {
                    estadoAtual = SAIR_DUNGEON;
                } else {
                    printf("-> Ação inválida! Tente novamente.\n\n");
                }
                break;

            case ABRIR_BAU:
                printf("Abriu o Baú, infelizmente alguém já passou aqui!\n");
                printf("Ações disponíveis:\n");
                printf("1 - Próxima Sala\n");
                printf("2 - Desistir\n");
                printf("Escolha sua ação: ");
                scanf("%d", &escolha);

                if (escolha == 1) {
                    estadoAtual = ENTRAR_SALA;
                } else if (escolha == 2) {
                    estadoAtual = SAIR_DUNGEON;
                } else {
                    printf("-> Ação inválida! Tente novamente.\n\n");
                }
                break;

            case ENTRAR_SALA:
                printf("Você entrou na sala\n");
                printf("Ações disponíveis:\n");
                printf("1 - Andar pela sala\n");
                printf("2 - Desistir\n");
                printf("Escolha sua ação: ");
                scanf("%d", &escolha);

                if (escolha == 1) {
                    estadoAtual = EXPLORAR_SALA;
                } else if (escolha == 2) {
                    estadoAtual = SAIR_DUNGEON;
                } else {
                    printf("-> Ação inválida! Tente novamente.\n\n");
                }
                break;
                
            default:
                printf("Erro: Estado desconhecido!\n");
                break;
        }
        printf("\n-----------------------------------\n\n");
    }

    //Tratamento dos estados finais
    if (estadoAtual == FIM_DE_JOGO) {
        printf("Fim de Jogo.\n");
        printf("Voce morreu! A exploracao acabou por aqui.\n");
    } else if (estadoAtual == SAIR_DUNGEON) {
        printf("Saiu da Dungeon.\n");
        printf("Voce desistiu e saiu da dungeon em seguranca.\n");
    }

    return 0;
}
