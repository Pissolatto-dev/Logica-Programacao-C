#  Dungeon Crawler: The Rot King's Domain

Este é o projeto de conclusão da disciplina de Programação I. Trata-se de um RPG de texto (Dungeon Crawler) desenvolvido inteiramente em **Linguagem C**, focado em modularização, persistência de dados e gerenciamento de estruturas complexas.

##  O Jogo
O jogador assume o papel de um aventureiro que deve explorar uma dungeon de 30 salas geradas proceduralmente. O objetivo é sobreviver aos encontros, derrotar monstros e chefes, e saquear equipamentos para se tornar forte o suficiente para enfrentar o desafio final.

### Principais Funcionalidades:
* **Sistema de Classes**: Escolha entre Guerreiro, Arqueiro, Lanceiro ou Tanque, cada um com bônus de atributos iniciais distintos.
* **Exploração Procedural**: O mapa é composto por 30 salas, com encontros com Bosses programados a cada 5 salas.
* **Combate por Turnos**: Mecânica de batalha que calcula dano com base em atributos de ataque e defesa.
* **Gestão de Inventário**: Sistema de equipamentos para armas e armaduras encontrados em baús.

##  Destaques Técnicos

O desenvolvimento deste projeto envolveu a aplicação de conceitos avançados de Ciência da Computação:

### 1. Gerenciamento de Memória e Ponteiros
O projeto utiliza **Ponteiros** para gerenciar a existência de entidades dentro das salas. Em vez de alocar memória estática para todos os elementos, o código usa `malloc` para criar instâncias de Bosses e Baús apenas onde necessário, utilizando ponteiros dentro da `struct Sala` para referenciar esses objetos.

### 2. Estruturas de Dados e Classes
Foram utilizadas `structs` e `typedefs` para criar tipos de dados personalizados que funcionam como "classes" de objetos. Isso inclui a organização de dados para o **Jogador**, **Monstros**, **Bosses**, **Itens** e a própria estrutura da **Dungeon**.

### 3. Log de Aventura (Persistência de Dados)
Uma funcionalidade de destaque é o **Sistema de Logs**. O programa utiliza funções de I/O de arquivos para gravar todas as ações importantes do jogador em um arquivo externo chamado `log_aventura.txt`. Isso demonstra a capacidade de implementar persistência de dados em tempo real.

##  Como Executar

1.  Certifique-se de ter um compilador C (como o GCC) instalado.
2.  Compile o arquivo principal:
    ```bash
    gcc "Trabalho Final.c" -o dungeon_crawler
    ```
3.  Inicie a aventura:
    ```bash
    ./dungeon_crawler
    ```

---
*Este projeto documenta minha evolução na compreensão de gerenciamento de memória e lógica estruturada durante o curso de Ciência da Computação.*
