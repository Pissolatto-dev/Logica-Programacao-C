#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

//Definição das structs para itens, monstros, bosses, etc...

//Armas
typedef struct {
    char nome[50];
    int bonus_ataque;
    char descricao[150];
} Arma;

//Armaduras
typedef struct {
    char nome[50];
    int bonus_defesa;
    char descricao[150];
} Armadura;

//Jogador
typedef struct {
    char nome[50];
    int classe_id;
    int hp;
    int hp_max;
    int ataque;
    int defesa;
    Arma arma_equipada;
    Armadura armadura_equipada;
} Jogador;

//Monstro
typedef struct {
    char nome[50];
    int hp;
    int ataque;
    int defesa;
    int esta_vivo;
} Monstro;

//Boss
typedef struct {
    char nome[50];
    int hp;
    int ataque;
    int defesa;
    int esta_vivo;
    char dialogo_entrada[150];
} Boss;

//Baú
typedef struct {
    Arma arma;
    Armadura armadura;
    int ouro;
    int aberto; //0 = fechado, 1 = aberto
} Bau;

//Sala
typedef struct {
    char descricao[200];
    Monstro monstros[2];// Toda sala normal tem 2 monstros
    Boss* boss;//Ponteiro: NULL se não houver boss
    Bau* bau;//Ponteiro: NULL se não houver baú
    int sala_limpa;
} Sala;


//Banco de dados dos itens, monstros, bosses, etc...
//Tipos de Monstros personalizáveis

#define NUM_MONSTRO_TEMPLATES 7
Monstro g_monstro_templates[NUM_MONSTRO_TEMPLATES] = {
    {"Goblin Ranhoso", 30, 8, 3, 1},
    {"Morcego da Caverna", 20, 6, 1, 1},
    {"Esqueleto Frágil", 25, 7, 5, 1},
    {"Aranha Peçonhenta", 35, 10, 2, 1},
    {"Lobo das Sombras", 50, 12, 4, 1},
    {"Gárgula de Pedra", 60, 10, 10, 1},
    {"Cultista do Abismo", 45, 15, 3, 1}
};

//Tipo de bosses personalizáveis

#define NUM_BOSSES 6
Boss g_boss_templates[NUM_BOSSES] = {
    {"Krognar, o Esmagador", 150, 20, 10, 1, "KROGNAR BATE NO PEITO. 'VOCE ESMAGADO AGORA!'"},
    {"Syl'zara, a Tecelã de Veneno", 200, 25, 15, 1, "Sons de seda e sussurros... 'Venha, provar meu abraço letal.'"},
    {"Lorde Malakor, o Cavaleiro Caído", 300, 35, 20, 1, "'Sua alma será minha... Junte-se aos meus servos.'"},
    {"Observador, O Olho do Caos", 250, 45, 15, 1, "'Sua sanidade é uma ilusão. Olhe para o vazio!'"},
    {"Gêmeos Abissais (Zyl & Xor)", 400, 30, 25, 1, "'Nós somos um... Nós somos a sua morte!' (Ataque em dobro!)"},
    {"MALKHAV, O REI DA PODRIDAO", 1000, 60, 30, 1, "'Tolos. Esta dungeon é meu corpo. E voce é apenas... uma infecção.'"}
};

//Tipos de itens para os baús
//São 10 baús
//Personalize/Adicione exatamente 10 armas e 10 armaduras.

#define NUM_BAUS 10
Arma g_armas_templates[NUM_BAUS] = {
    {"Adaga Enferrujada", 15, "Melhor que nada. Talvez."},
    {"Espada Curta de Ferro", 15, "Uma lâmina confiável."},
    {"Arco de Caça", 16, "Preciso e rápido."},
    {"Machado de Batalha", 16, "Pesa, mas o corte é profundo."},
    {"Lança de Bronze", 17, "Bom alcance, boa perfuração."},
    {"Maça de Clérigo", 18, "Abençoada para esmagar ossos."},
    {"Espada Longa de Aço", 18, "Uma arma de um verdadeiro cavaleiro."},
    {"Arco Longo Élfico", 19, "Feito de madeira-coração, vibra com energia."},
    {"Martelo de Guerra Anão", 25, "Gravado com runas de poder."},
    {"Lâmina do Caos 'Devoradora'", 40, "A arma do boss final. Ela sussurra para você."}
};

Armadura g_armaduras_templates[NUM_BAUS] = {
    {"Roupas de Linho Rasgadas", 2, "Mal protege do frio."},
    {"Gibão de Couro Batido", 5, "Usado por batedores e ladrões."},
    {"Cota de Malha", 8, "Anéis de metal interligados."},
    {"Peitoral de Bronze", 10, "Brilha fracamente à luz da tocha."},
    {"Armadura de Escamas", 13, "Flexível e resistente."},
    {"Meia-Armadura de Aço", 16, "Proteção sólida onde importa."},
    {"Armadura de Placas Completa", 20, "Você parece uma fortaleza ambulante."},
    {"Armadura Élfica Gravada", 23, "Leve como pluma, forte como aço."},
    {"Armadura Rúnica Anã", 26, "Quase impenetrável."},
    {"Carapaça do Rei da Podridão", 35, "Ainda pulsa com uma energia sombria."}
};


//Funções auxiliares

//Função para registrar ações em log_aventura.txt
void logAcao(const char* acao) {

    FILE* logfile;

    // "a" = Append (Adicionar ao final). 
    logfile = fopen("log_aventura.txt", "a");
    if (logfile == NULL) {
        printf("ERRO CRITICO: Nao foi possivel escrever no arquivo de log.\n");
        return;
    }

    fprintf(logfile, "%s\n", acao);
    fclose(logfile);
}

//Limpa a tela
void limparTela() {
    printf("\033[H\033[J");
}

//Pausa o jogo e espera o usuário pressionar Enter
void pausaEnter() {
    printf("\n(Pressione ENTER para continuar...)");
    while (getchar() != '\n');
    getchar();
}

//Retorna um número aleatório entre min e max para as batalhas
int rolarDado(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}


//Funções principais

//Cria o personagem do jogador
void setupJogador(Jogador* jogador) {

    char buffer_log[100];
    int escolha = 0;

    limparTela();
    printf("========================================\n");
    printf("  CRIAÇÃO DE PERSONAGEM\n");
    printf("========================================\n");
    
    printf("\nQual é o seu nome, aventureiro?\n> ");
    fgets(jogador->nome, 50, stdin);
    jogador->nome[strcspn(jogador->nome, "\n")] = 0;

    sprintf(buffer_log, "Jogador criado com o nome: %s", jogador->nome);
    logAcao(buffer_log);

    printf("\nEscolha sua classe, %s:\n", jogador->nome);
    printf("  [1] Guerreiro (Fúria de Batalha: +10 HP, +5 Ataque)\n");
    printf("  [2] Arqueiro  (Visão de Águia: +15 Ataque, -10 HP)\n");
    printf("  [3] Lanceiro  (Postura de Falange: +5 Ataque, +5 Defesa)\n");
    printf("  [4] Tanque    (Pele de Pedra: +30 HP, +10 Defesa)\n");
    
    while(escolha < 1 || escolha > 4) {
        printf("> ");
        scanf("%d", &escolha);
    }
    
    //Stats base
    jogador->hp_max = 100;
    jogador->ataque = 10;
    jogador->defesa = 5;
    
    //Aplica os buffs da classe
    switch (escolha) {
        case 1: //Guerreiro
            jogador->classe_id = 1;
            jogador->hp_max += 10;
            jogador->ataque += 5;
            logAcao("Classe escolhida: Guerreiro");
            break;
        case 2: //Arqueiro
            jogador->classe_id = 2;
            jogador->hp_max -= 10;
            jogador->ataque += 15;
            logAcao("Classe escolhida: Arqueiro");
            break;
        case 3: //Lanceiro
            jogador->classe_id = 3;
            jogador->ataque += 5;
            jogador->defesa += 5;
            logAcao("Classe escolhida: Lanceiro");
            break;
        case 4: //Tanque
            jogador->classe_id = 4;
            jogador->hp_max += 30;
            jogador->defesa += 10;
            logAcao("Classe escolhida: Tanque");
            break;
    }
    
    jogador->hp = jogador->hp_max;
    
    //Equipamento inicial
    jogador->arma_equipada = (Arma){"Mãos Nuas", 1, "Seus punhos."};
    jogador->armadura_equipada = (Armadura){"Roupas Comuns", 1, "Roupas simples de viagem."};

    printf("\nClasse escolhida! %s, o aventureiro, está pronto!\n", jogador->nome);
    pausaEnter();
}

//Preenche o array das salas da dungeon
void setupDungeon(Sala dungeon[30]) {

    int bau_index = 0;
    int boss_index = 0;
    int i;
    int numero_sala;
    Sala* sala_atual;

    printf("Criando a dungeon... O ar se torna pesado...\n");
    logAcao("Iniciando a criacao da dungeon...");
    
    for (i = 0; i < 30; i++) {
        numero_sala = i + 1;
        sala_atual = &dungeon[i];
        
        //Inicializa a sala
        sala_atual->boss = NULL;
        sala_atual->bau = NULL;
        sala_atual->sala_limpa = 0;
        
        //Lógica de geração

        //Regra 1: Boss Final (Sala 30)
        if (numero_sala == 30) {
            sprintf(sala_atual->descricao, "SALA %d: O TRONO DO REI. \nUm ser colossal observa voce. Ossos estalam sob seus pes.", numero_sala);
            sala_atual->boss = (Boss*) malloc(sizeof(Boss));
            *(sala_atual->boss) = g_boss_templates[5];
            sala_atual->sala_limpa = 0;
        }

        //Regra 2: Boss Normal (Salas 5, 10, 15, 20, 25)
        else if (numero_sala % 5 == 0) {
            sprintf(sala_atual->descricao, "SALA %d: UMA ARENA DE CHEFE. \nO ar está denso com poder sombrio. Um guardião se aproxima.", numero_sala);
            sala_atual->boss = (Boss*) malloc(sizeof(Boss));
            *(sala_atual->boss) = g_boss_templates[boss_index];
            sala_atual->sala_limpa = 0;
            boss_index++;
        }

        //Regra 3: Sala Normal
        else {
            sprintf(sala_atual->descricao, "SALA %d: Uma caverna úmida. \nO som de goteiras ecoa... e algo mais.", numero_sala);
            sala_atual->monstros[0] = g_monstro_templates[rolarDado(0, NUM_MONSTRO_TEMPLATES - 1)];
            sala_atual->monstros[1] = g_monstro_templates[rolarDado(0, NUM_MONSTRO_TEMPLATES - 1)];
            sala_atual->sala_limpa = 0;
        }
        
        // Regra 4: Baús (Salas 3, 6, 9... 30)
        if (numero_sala % 3 == 0) {
            sala_atual->bau = (Bau*) malloc(sizeof(Bau));
            sala_atual->bau->arma = g_armas_templates[bau_index];
            sala_atual->bau->armadura = g_armaduras_templates[bau_index];
            sala_atual->bau->ouro = rolarDado(50, 150) * bau_index;
            sala_atual->bau->aberto = 0;
            bau_index++;
        }
    }
}

//Mostra o status atual do jogador.
void mostrarStatus(Jogador* jogador) {

    logAcao("Jogador verificou o status (inventario/status).");
    limparTela();
    printf("--- STATUS DE %s ---\n", jogador->nome);
    printf("HP: %d / %d\n", jogador->hp, jogador->hp_max);
    printf("Ataque Base: %d\n", jogador->ataque);
    printf("Defesa Base: %d\n", jogador->defesa);
    printf("---------------------------\n");
    printf("Arma: %s (+%d Atk)\n", jogador->arma_equipada.nome, jogador->arma_equipada.bonus_ataque);
    printf("Armadura: %s (+%d Def)\n", jogador->armadura_equipada.nome, jogador->armadura_equipada.bonus_defesa);
    printf("---------------------------\n");
    printf("ATAQUE TOTAL: %d\n", jogador->ataque + jogador->arma_equipada.bonus_ataque);
    printf("DEFESA TOTAL: %d\n", jogador->defesa + jogador->armadura_equipada.bonus_defesa);
    pausaEnter();
}

//Lógica para abrir baú e equipar os itens
void abrirBau(Jogador* jogador, Sala* sala) {

    char buffer_log[256];
    Arma arma_bau;
    Armadura armadura_bau;

    if (sala->bau == NULL) {
        printf("Não há baú nesta sala.\n");
    } else if (sala->bau->aberto == 1) {
        printf("Este baú já foi saqueado.\n");
    } else {
        printf("Você abre o baú com um rangido!\n");
        sala->bau->aberto = 1;
        
        arma_bau = sala->bau->arma;
        armadura_bau = sala->bau->armadura;
        
        printf("VOCÊ ENCONTROU:\n");
        printf("  [Arma] %s (+%d Atk)\n", arma_bau.nome, arma_bau.bonus_ataque);
        printf("  [Armadura] %s (+%d Def)\n", armadura_bau.nome, armadura_bau.bonus_defesa);
        
        sprintf(buffer_log, "Bau: Encontrou %s (+%d) e %s (+%d)", arma_bau.nome, arma_bau.bonus_ataque, armadura_bau.nome, armadura_bau.bonus_defesa);
        logAcao(buffer_log);
        
        //Lógica de Equipar Arma
        if (arma_bau.bonus_ataque > jogador->arma_equipada.bonus_ataque) {
            printf("\nSua nova arma é melhor! Você equipa %s.\n", arma_bau.nome);
            sprintf(buffer_log, "Bau: Equipou nova arma: %s", arma_bau.nome);
            logAcao(buffer_log);
            jogador->arma_equipada = arma_bau;
        } else {
            printf("\nSua arma atual (%s) é melhor.\n", jogador->arma_equipada.nome);
        }

        //Lógica de Equipar Armadura
        if (armadura_bau.bonus_defesa > jogador->armadura_equipada.bonus_defesa) {
            printf("Sua nova armadura é melhor! Você equipa %s.\n", armadura_bau.nome);
            sprintf(buffer_log, "Bau: Equipou nova armadura: %s", armadura_bau.nome);
            logAcao(buffer_log);
            jogador->armadura_equipada = armadura_bau;
        } else {
            printf("Sua armadura atual (%s) é melhor.\n", jogador->armadura_equipada.nome);
        }
    }
    pausaEnter();
}

//Loop principal de combate
int iniciarCombate(Jogador* jogador, Sala* sala) {

    int combate_ativo = 1;
    char buffer_log[256];
    
    // Variáveis do Boss
    Boss* boss;
    char acao;
    int atk_total_jogador, def_total_boss, dano_causado;
    int atk_total_boss, def_total_jogador, dano_recebido;

    // Variáveis dos Monstros
    Monstro* m1;
    Monstro* m2;
    int alvo;
    Monstro* monstro_alvo;
    int def_total_monstro;
    int dano_recebido_m1, dano_recebido_m2;
    
    //Luta com boss
    if (sala->boss != NULL) {
        boss = sala->boss;
        printf("\n%s\n", boss->dialogo_entrada);
        printf("!!! UM CHEFE APARECE: %s !!!\n", boss->nome);
        sprintf(buffer_log, "Combate iniciado (Boss): %s", boss->nome);
        logAcao(buffer_log);
        pausaEnter();

        while (combate_ativo) {
            limparTela();
            printf("--- LUTA DE CHEFE ---\n");
            printf("%s (HP: %d/%d)\n", jogador->nome, jogador->hp, jogador->hp_max);
            printf("vs.\n");
            printf("%s (HP: %d)\n", boss->nome, boss->hp);
            printf("---------------------\n");
            
            //Turno do Jogador
            printf("\nÉ seu turno! [A]tacar\n> ");
            scanf(" %c", &acao);

            if (acao == 'a' || acao == 'A') {
                atk_total_jogador = jogador->ataque + jogador->arma_equipada.bonus_ataque;
                def_total_boss = boss->defesa;
                
                dano_causado = atk_total_jogador - def_total_boss;
                if (dano_causado < 1) dano_causado = 1; //Dano mínimo
                
                printf("Você ataca %s causando %d de dano!\n", boss->nome, dano_causado);
                sprintf(buffer_log, "Jogador ataca %s, causando %d de dano. (HP restante: %d)", boss->nome, dano_causado, boss->hp - dano_causado);
                logAcao(buffer_log);
                boss->hp -= dano_causado;
            } else {
                printf("Ação inválida! Você hesita.\n");
                logAcao("Jogador hesitou (acao invalida).");
            }
            
            //Verifica se o boss morreu
            if (boss->hp <= 0) {
                printf("\n*** VITORIA! ***\n");
                printf("Você derrotou %s!\n", boss->nome);
                sprintf(buffer_log, "VITORIA: Boss %s foi derrotado.", boss->nome);
                logAcao(buffer_log);
                sala->sala_limpa = 1;
                free(sala->boss);
                sala->boss = NULL;
                pausaEnter();
                return 1; //Venceu a luta
            }
            
            pausaEnter();
            
            //Turno do Boss
            printf("\nTurno de %s!\n", boss->nome);
            atk_total_boss = boss->ataque;
            def_total_jogador = jogador->defesa + jogador->armadura_equipada.bonus_defesa;
            
            dano_recebido = atk_total_boss - def_total_jogador;
            if (dano_recebido < 1) dano_recebido = 1;
            
            //Boss Gêmeos (Sala 25) ataca duas vezes
            if(strcmp(boss->nome, "Gêmeos Abissais (Zyl & Xor)") == 0) {
                printf("%s ataca DUAS VEZES, causando %d de dano total!\n", boss->nome, dano_recebido * 2);
                sprintf(buffer_log, "%s ataca (x2), causando %d de dano. (HP restante: %d)", boss->nome, dano_recebido * 2, jogador->hp - (dano_recebido * 2));
                logAcao(buffer_log);
                jogador->hp -= (dano_recebido * 2);
            } else {
                printf("%s ataca você, causando %d de dano!\n", boss->nome, dano_recebido);
                sprintf(buffer_log, "%s ataca, causando %d de dano. (HP restante: %d)", boss->nome, dano_recebido, jogador->hp - dano_recebido);
                logAcao(buffer_log);
                jogador->hp -= dano_recebido;
            }

            if (jogador->hp <= 0) {
                printf("\nVocê foi derrotado...\n");
                combate_ativo = 0;
                sprintf(buffer_log, "GAME OVER: Jogador derrotado por %s.", boss->nome);
                logAcao(buffer_log);
                pausaEnter();
                return 0; //Perdeu (Game Over)
            }
            pausaEnter();
        }
    }

    //Combate contra monstros normais
    else {
        m1 = &sala->monstros[0];
        m2 = &sala->monstros[1];
        printf("\nCriaturas emergem das sombras: %s e %s!\n", m1->nome, m2->nome);
        sprintf(buffer_log, "Combate iniciado (Monstros): %s e %s", m1->nome, m2->nome);
        logAcao(buffer_log);
        pausaEnter();

        while (combate_ativo) {
            limparTela();
            printf("--- COMBATE ---\n");
            printf("%s (HP: %d/%d)\n", jogador->nome, jogador->hp, jogador->hp_max);
            printf("vs.\n");
            if(m1->esta_vivo) printf("  [1] %s (HP: %d)\n", m1->nome, m1->hp);
            if(m2->esta_vivo) printf("  [2] %s (HP: %d)\n", m2->nome, m2->hp);
            printf("---------------------\n");
            
            //Turno do Jogador
            printf("\nÉ seu turno! Atacar [1] ou [2]?\n> ");
            scanf(" %d", &alvo);
            
            monstro_alvo = NULL;
            if(alvo == 1 && m1->esta_vivo) monstro_alvo = m1;
            else if(alvo == 2 && m2->esta_vivo) monstro_alvo = m2;
            else {
                printf("Alvo inválido ou já morto! Você hesita.\n");
                logAcao("Jogador hesitou (alvo invalido).");
                pausaEnter();
                continue; //Pula o turno
            }

            atk_total_jogador = jogador->ataque + jogador->arma_equipada.bonus_ataque;
            def_total_monstro = monstro_alvo->defesa;
            dano_causado = atk_total_jogador - def_total_monstro;
            if (dano_causado < 1) dano_causado = 1;
            
            printf("Você ataca %s causando %d de dano!\n", monstro_alvo->nome, dano_causado);
            sprintf(buffer_log, "Jogador ataca %s, causando %d de dano. (HP restante: %d)", monstro_alvo->nome, dano_causado, monstro_alvo->hp - dano_causado);
            logAcao(buffer_log);
            monstro_alvo->hp -= dano_causado;

            if (monstro_alvo->hp <= 0) {
                printf("%s foi derrotado!\n", monstro_alvo->nome);
                monstro_alvo->esta_vivo = 0;
                sprintf(buffer_log, "Monstro %s foi derrotado.", monstro_alvo->nome);
                logAcao(buffer_log);
            }
            
            //Verifica se todos os monstros morreram
            if (!m1->esta_vivo && !m2->esta_vivo) {
                printf("\n*** VITORIA! ***\n");
                printf("Você limpou a sala!\n");
                logAcao("VITORIA: Monstros da sala derrotados.");
                sala->sala_limpa = 1;
                pausaEnter();
                return 1; //Venceu o combate
            }
            
            pausaEnter();
            
            //Turno dos Monstros
            printf("\nTurno dos monstros!\n");
            if (m1->esta_vivo) {
                dano_recebido_m1 = m1->ataque - (jogador->defesa + jogador->armadura_equipada.bonus_defesa);
                if (dano_recebido_m1 < 1) dano_recebido_m1 = 1;
                printf("%s ataca você, causando %d de dano!\n", m1->nome, dano_recebido_m1);
                sprintf(buffer_log, "%s ataca, causando %d de dano. (HP restante: %d)", m1->nome, dano_recebido_m1, jogador->hp - dano_recebido_m1);
                logAcao(buffer_log);
                jogador->hp -= dano_recebido_m1;
            }
            if (jogador->hp <= 0) break; //Verifica morte no meio do turno
            
            if (m2->esta_vivo) {
                dano_recebido_m2 = m2->ataque - (jogador->defesa + jogador->armadura_equipada.bonus_defesa);
                if (dano_recebido_m2 < 1) dano_recebido_m2 = 1;
                printf("%s ataca você, causando %d de dano!\n", m2->nome, dano_recebido_m2);
                sprintf(buffer_log, "%s ataca, causando %d de dano. (HP restante: %d)", m2->nome, dano_recebido_m2, jogador->hp - dano_recebido_m2);
                logAcao(buffer_log);
                jogador->hp -= dano_recebido_m2;
            }
            
            //Verifica se o jogador morreu
            if (jogador->hp <= 0) {
                printf("\nVocê foi derrotado...\n");
                combate_ativo = 0;
                logAcao("GAME OVER: Jogador derrotado por monstros.");
                pausaEnter();
                return 0; //Perdeu (Game Over)
            }
            pausaEnter();
        }
    }
    return 0;
}


//Loop principal do jogo
int main() {

    Jogador jogador;
    Sala dungeon[30];
    int indice_sala_atual = 0;
    int jogo_ativo = 1;
    
    FILE* logfile_init;
    char buffer_log[100];
    int sala_logada_previamente = -1;
    
    Sala* sala_atual;
    char escolha;
    int resultado_luta;
    int i;

    //Inicializa o gerador de números aleatórios
    srand(time(NULL)); 

    logfile_init = fopen("log_aventura.txt", "w");
    if (logfile_init == NULL) {
        printf("ERRO: Nao foi possivel iniciar o arquivo de log. O jogo continuara sem log.\n");
        pausaEnter();
    } else {
        fprintf(logfile_init, "---INÍCIO DA AVENTURA---\n");
        fclose(logfile_init);
    }
    
    //1. Criar Personagem
    setupJogador(&jogador);
    
    //2. Criar a Dungeon
    setupDungeon(dungeon);
    
    limparTela();
    printf("A porta de pedra se fecha atrás de você com um estrondo.\n");
    printf("Não há caminho a não ser para frente. A aventura começa...\n");
    logAcao("O jogador entrou na dungeon.");
    pausaEnter();

    //3. Loop Principal do Jogo
    while (jogo_ativo) {
        limparTela();
        sala_atual = &dungeon[indice_sala_atual];
        
        if (indice_sala_atual != sala_logada_previamente) {
            sprintf(buffer_log, "Jogador entrou na Sala %d.", indice_sala_atual + 1);
            logAcao(buffer_log);
            sala_logada_previamente = indice_sala_atual;
        }
        
        printf("====================================================\n");
        printf("SALA %d / 30 \n", indice_sala_atual + 1);
        printf("HP: %d / %d\n", jogador.hp, jogador.hp_max);
        printf("====================================================\n\n");
        printf("%s\n", sala_atual->descricao);
        
        //Verifica oq tem na sala
        
        //Se inimigos estão vivos
        if (sala_atual->sala_limpa == 0) {
            printf("\nPERIGO! Inimigos bloqueiam o caminho!\n");
        } else {
            printf("\nA sala está quieta. Os inimigos foram derrotados.\n");
        }
        
        //Se tem baú
        if (sala_atual->bau != NULL) {
            if(sala_atual->bau->aberto == 0) {
                printf("Você avista um BAÚ no canto da sala!\n");
            } else {
                printf("Há um baú aberto e vazio aqui.\n");
            }
        }
        
        //Ações
        printf("\nO que você deseja fazer?\n");
        if (sala_atual->sala_limpa == 0) {
            printf("  [L] Lutar\n");
        } else {
            printf("  [P] Próxima Sala\n");
            if (sala_atual->bau != NULL && sala_atual->bau->aberto == 0) {
                printf("  [A] Abrir Baú\n");
            }
        }
        printf("  [E] Status do Personagem\n");
        printf("  [S] Sair do Jogo\n");
        printf("> ");
        
        scanf(" %c", &escolha);
        
        //Processar ação
        switch (escolha) {
            case 'l':
            case 'L':
                if (sala_atual->sala_limpa == 0) {
                    logAcao("Acao do Jogador: Lutar.");
                    resultado_luta = iniciarCombate(&jogador, sala_atual);
                    if (resultado_luta == 0) {
                        jogo_ativo = 0;//Termina o loop principal
                    }
                } else {
                    printf("Não há nada para lutar aqui.\n");
                    pausaEnter();
                }
                break;
                
            case 'p':
            case 'P':
                if (sala_atual->sala_limpa == 1) {
                    if (indice_sala_atual == 29) {
                        //Jogo ganho (Deve ter matado o boss da sala 30)
                        limparTela();
                        printf("\n\n**************************************************\n");
                        printf("O REI DA PODRIDAO CAIU!\n");
                        printf("Você conquistou a dungeon, %s!\n", jogador.nome);
                        printf("Sua lenda será contada por eras.\n");
                        printf("**************************************************\n");
                        sprintf(buffer_log, "VITORIA FINAL! %s conquistou a dungeon!", jogador.nome);
                        logAcao(buffer_log);
                        jogo_ativo = 0;
                    } else {
                        indice_sala_atual++;
                        printf("Você avança para a próxima sala...\n");
                        logAcao("Acao do Jogador: Avancar para proxima sala.");
                        pausaEnter();
                    }
                } else {
                    printf("Você não pode avançar! Inimigos bloqueiam o caminho.\n");
                    pausaEnter();
                }
                break;
            
            case 'a':
            case 'A':
                if (sala_atual->sala_limpa == 1 && sala_atual->bau != NULL) {
                    logAcao("Acao do Jogador: Abrir Bau.");
                    abrirBau(&jogador, sala_atual);
                } else if (sala_atual->sala_limpa == 0) {
                    printf("Você deve derrotar os inimigos antes de saquear!\n");
                    pausaEnter();
                } else {
                    printf("Não há baú aqui ou ele já foi aberto.\n");
                    pausaEnter();
                }
                break;

            case 'e':
            case 'E':
                mostrarStatus(&jogador);
                break;

            case 's':
            case 'S':
                printf("Você foge da dungeon... covarde.\n");
                logAcao("Acao do Jogador: Sair do Jogo (Fugiu).");
                jogo_ativo = 0;
                break;
                
            default:
                printf("Comando inválido!\n");
                pausaEnter();
                break;
        }
    }
    
    //Fim de jogo
    
    if (jogador.hp <= 0) {
        limparTela();
        printf("\n\n=====================\n");
        printf("    GAME OVER\n");
        printf("=====================\n");
        printf("%s foi derrotado na sala %d.\n", jogador.nome, indice_sala_atual + 1);
        printf("A dungeon clama mais uma vítima...\n");
    }
    
    //Libera toda a memória alocada para baús e bosses
    for (i = 0; i < 30; i++) {
        if(dungeon[i].bau != NULL) free(dungeon[i].bau);
        if(dungeon[i].boss != NULL) free(dungeon[i].boss);
    }
    
    logAcao("---É O FIM DA JORNADA---");
    printf("\nObrigado por jogar! (Verifique log_aventura.txt)\n");
    return 0;
}
