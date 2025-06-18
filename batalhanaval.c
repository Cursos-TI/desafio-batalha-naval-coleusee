#include <stdio.h>
#include <stdlib.h>

#define TAM_TAB 10
#define TAM_HAB 7

// Função para inicializar o tabuleiro com 0
int inicializarTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    return 0;
}

// Função para posicionar navios fixos
int posicionarNavios(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int j = 3; j <= 5; j++) {
        tabuleiro[2][j] = 3; // Navio horizontal
    }
    for (int i = 2; i <= 4; i++) {
        tabuleiro[i][7] = 3; // Navio vertical
    }
    return 0;
}

// Gera matriz em forma de cone
int gerarCone(int cone[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i >= 3 && abs(j - 3) <= i - 3)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
    return 0;
}

// Gera matriz em forma de cruz
int gerarCruz(int cruz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == 3 || j == 3)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
    return 0;
}

// Gera matriz em forma de octaedro (losango)
int gerarOctaedro(int octaedro[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - 3) + abs(j - 3) <= 3)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }
    return 0;
}

// Aplica uma habilidade ao tabuleiro
int aplicarHabilidade(int tabuleiro[TAM_TAB][TAM_TAB], int habilidade[TAM_HAB][TAM_HAB], int origemX, int origemY) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int x = origemX - TAM_HAB / 2 + i;
            int y = origemY - TAM_HAB / 2 + j;
            if (x >= 0 && x < TAM_TAB && y >= 0 && y < TAM_TAB) {
                if (habilidade[i][j] == 1 && tabuleiro[x][y] == 0) {
                    tabuleiro[x][y] = 5; // Marca com 5 a área da habilidade
                }
            }
        }
    }
    return 0;
}

// Exibe o tabuleiro
int exibirTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    printf("   ");
    for (int j = 1; j <= TAM_TAB; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAM_TAB; i++) {
        printf(" %c ", 'A' + i);
        for (int j = 0; j < TAM_TAB; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int main() {
    int tabuleiro[TAM_TAB][TAM_TAB];
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, 6, 3);     // Aplica cone em F4
    aplicarHabilidade(tabuleiro, cruz, 5, 7);     // Aplica cruz em E8
    aplicarHabilidade(tabuleiro, octaedro, 8, 5); // Aplica octaedro em I6

    exibirTabuleiro(tabuleiro);

    return 0;
}
