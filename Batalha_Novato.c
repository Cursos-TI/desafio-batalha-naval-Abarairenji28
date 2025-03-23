#include <stdio.h>
#include <locale.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio horizontalmente
void posicionarNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    // Garantir que o navio não ultrapasse os limites
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (coluna + i >= TAM_TABULEIRO) {
            printf("Posição inválida para o navio horizontal!\n");
            return;
        }
        // Posicionar o navio (marcando com 3)
        tabuleiro[linha][coluna + i] = 3;
    }
}

// Função para posicionar um navio verticalmente
void posicionarNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    // Garantir que o navio não ultrapasse os limites
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linha + i >= TAM_TABULEIRO) {
            printf("Posição inválida para o navio vertical!\n");
            return;
        }
        // Posicionar o navio (marcando com 3)
        tabuleiro[linha + i][coluna] = 3;
    }
}

int main() {
    setlocale(LC_ALL,"Portuguese_Brazil");
    // Criando o tabuleiro 10x10, inicializado com 0 (água)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Definindo as posições iniciais dos navios
    int linhaHorizontal = 2, colunaHorizontal = 1; // Navio horizontal
    int linhaVertical = 5, colunaVertical = 6;     // Navio vertical

    // Posicionando os navios
    posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal);
    posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical);

    // Exibindo o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}