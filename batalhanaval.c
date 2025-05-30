#include <stdio.h>

int main() {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};  
    int tabuleiro[10][10]; 

    // Inicializando o tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    //  Posicionando o navio horizontal 
    for (int j = 3; j <= 5; j++) {
        tabuleiro[2][j] = 3;
    }

    //  Posicionando o navio vertical 
    for (int i = 2; i <= 4; i++) {
        tabuleiro[i][7] = 3;
    }

    //  Imprimindo o cabeçalho das colunas (1 a 10)
    printf("   ");
    for (int j = 1; j <= 10; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    // Imprimindo o tabuleiro com letras A a J nas linhas
    for (int i = 0; i < 10; i++) {
        printf(" %c ", linha[i]);  
        for (int j = 0; j < 10; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
