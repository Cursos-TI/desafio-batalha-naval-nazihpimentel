#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 10

char tabuleiro[TAMANHO][TAMANHO];

// Estrutura para representar um navio
typedef struct {
    int linha;
    int coluna;
    int tamanho;
    char orientacao; // 'H' ou 'V'
} Navio;

// Lista de navios
Navio navios[] = {
    {0, 0, 4, 'H'},
    {2, 2, 3, 'V'},
    {5, 5, 2, 'H'},
    {9, 7, 3, 'H'}
};

void inicializarTabuleiro() {
    for (int i = 0; i < TAMANHO; i++)
        for (int j = 0; j < TAMANHO; j++)
            tabuleiro[i][j] = 'O';
}

bool posicaoValida(Navio navio) {
    if (navio.orientacao == 'H') {
        if (navio.coluna + navio.tamanho > TAMANHO)
            return false;
        for (int i = 0; i < navio.tamanho; i++)
            if (tabuleiro[navio.linha][navio.coluna + i] != 'O')
                return false;
    } else if (navio.orientacao == 'V') {
        if (navio.linha + navio.tamanho > TAMANHO)
            return false;
        for (int i = 0; i < navio.tamanho; i++)
            if (tabuleiro[navio.linha + i][navio.coluna] != 'O')
                return false;
    } else {
        return false;
    }
    return true;
}

void posicionarNavios() {
    int quantidade = sizeof(navios) / sizeof(navios[0]);
    for (int i = 0; i < quantidade; i++) {
        if (posicaoValida(navios[i])) {
            for (int j = 0; j < navios[i].tamanho; j++) {
                if (navios[i].orientacao == 'H')
                    tabuleiro[navios[i].linha][navios[i].coluna + j] = 'N';
                else
                    tabuleiro[navios[i].linha + j][navios[i].coluna] = 'N';
            }
        } else {
            printf("Erro ao posicionar navio %d!\n", i + 1);
        }
    }
}

void imprimirTabuleiro() {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    inicializarTabuleiro();
    posicionarNavios();
    imprimirTabuleiro();
    return 0;
}