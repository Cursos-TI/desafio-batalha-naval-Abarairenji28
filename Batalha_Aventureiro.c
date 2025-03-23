#include <stdio.h>
#include <locale.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);  // Alinhamento com 2 espaços
        }
        printf("\n");
    }
}

// Função para verificar se uma posição está válida para posicionar o navio
int verificarPosicaoValida(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int horizontal) {
    if (horizontal) {
        // Verifica se o navio ultrapassa os limites horizontais
        if (coluna + TAM_NAVIO > TAM_TABULEIRO) return 0;
        // Verifica se as posições estão livres (valores diferentes de 0)
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0;
        }
    } else {
        // Verifica se o navio ultrapassa os limites verticais
        if (linha + TAM_NAVIO > TAM_TABULEIRO) return 0;
        // Verifica se as posições estão livres (valores diferentes de 0)
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0;
        }
    }
    return 1;
}

// Função para verificar se a posição do navio diagonal é válida
int verificarPosicaoValidaDiagonal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int crescente) {
    if (crescente) {
        // Verifica se o navio ultrapassa os limites da diagonal crescente
        if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna + TAM_NAVIO > TAM_TABULEIRO) return 0;
        // Verifica se as posições estão livres (valores diferentes de 0)
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna + i] != 0) return 0;
        }
    } else {
        // Verifica se o navio ultrapassa os limites da diagonal decrescente
        if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna - TAM_NAVIO < -1) return 0;
        // Verifica se as posições estão livres (valores diferentes de 0)
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna - i] != 0) return 0;
        }
    }
    return 1;
}

// Função para posicionar um navio horizontalmente
void posicionarNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (!verificarPosicaoValida(tabuleiro, linha, coluna, 1)) {
        printf("Posição inválida para o navio horizontal!\n");
        return;
    }
    // Posicionar o navio (marcando com 3)
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
}

// Função para posicionar um navio verticalmente
void posicionarNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (!verificarPosicaoValida(tabuleiro, linha, coluna, 0)) {
        printf("Posição inválida para o navio vertical!\n");
        return;
    }
    // Posicionar o navio (marcando com 3)
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
}

// Função para posicionar um navio na diagonal crescente
void posicionarNavioDiagonalCrescente(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (!verificarPosicaoValidaDiagonal(tabuleiro, linha, coluna, 1)) {
        printf("Posição inválida para o navio diagonal crescente!\n");
        return;
    }
    // Posicionar o navio (marcando com 3)
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = 3;
    }
}

// Função para posicionar um navio na diagonal decrescente
void posicionarNavioDiagonalDecrescente(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (!verificarPosicaoValidaDiagonal(tabuleiro, linha, coluna, 0)) {
        printf("Posição inválida para o navio diagonal decrescente!\n");
        return;
    }
    // Posicionar o navio (marcando com 3)
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = 3;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Criando o tabuleiro 10x10, inicializado com 0 (água)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Definindo as posições iniciais dos navios
    int linhaHorizontal = 2, colunaHorizontal = 1; // Navio horizontal
    int linhaVertical = 5, colunaVertical = 6;     // Navio vertical
    int linhaDiagonalCrescente = 0, colunaDiagonalCrescente = 0;  // Navio diagonal crescente
    int linhaDiagonalDecrescente = 0, colunaDiagonalDecrescente = 9; // Navio diagonal decrescente

    // Posicionando os navios
    posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal);
    posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical);
    posicionarNavioDiagonalCrescente(tabuleiro, linhaDiagonalCrescente, colunaDiagonalCrescente);
    posicionarNavioDiagonalDecrescente(tabuleiro, linhaDiagonalDecrescente, colunaDiagonalDecrescente);

    // Exibindo o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}