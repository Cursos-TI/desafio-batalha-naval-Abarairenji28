#include <stdio.h>
#include <locale.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5  // Tamanho das matrizes de habilidade

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);  // Alinhamento com 2 espaços
        }
        printf("\n");
    }
}

// Função para criar uma matriz de habilidade do tipo cone
void criarHabilidadeCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    // Inicializa a matriz com 0
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = 0;
        }
    }

    // Define a área de efeito em formato de cone (expandindo para baixo)
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = TAM_HABILIDADE / 2 - i; j <= TAM_HABILIDADE / 2 + i; j++) {
            if (j >= 0 && j < TAM_HABILIDADE) {
                habilidade[i][j] = 1;
            }
        }
    }
}

// Função para criar uma matriz de habilidade do tipo cruz
void criarHabilidadeCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    // Inicializa a matriz com 0
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = 0;
        }
    }

    // Define a área de efeito em formato de cruz (vertical e horizontal)
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        habilidade[TAM_HABILIDADE / 2][i] = 1;  // Linha central
        habilidade[i][TAM_HABILIDADE / 2] = 1;  // Coluna central
    }
}

// Função para criar uma matriz de habilidade do tipo octaedro
void criarHabilidadeOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    // Inicializa a matriz com 0
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = 0;
        }
    }

    // Define a área de efeito em formato de octaedro (losango)
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = TAM_HABILIDADE / 2 - i; j <= TAM_HABILIDADE / 2 + i; j++) {
            if (j >= 0 && j < TAM_HABILIDADE) {
                habilidade[i][j] = 1;
            }
        }
    }
}

// Função para sobrepor a habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int linhaOrigem, int colunaOrigem) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTabuleiro = linhaOrigem + i - TAM_HABILIDADE / 2;
            int colunaTabuleiro = colunaOrigem + j - TAM_HABILIDADE / 2;

            // Verifica se a posição está dentro dos limites do tabuleiro
            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAM_TABULEIRO &&
                colunaTabuleiro >= 0 && colunaTabuleiro < TAM_TABULEIRO &&
                habilidade[i][j] == 1) {
                tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;  // Marca a área afetada pela habilidade
            }
        }
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
    // Posiciona os navios (marcando com 3)
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
        tabuleiro[linhaVertical + i][colunaVertical] = 3;
        tabuleiro[linhaDiagonalCrescente + i][colunaDiagonalCrescente + i] = 3;
        tabuleiro[linhaDiagonalDecrescente + i][colunaDiagonalDecrescente - i] = 3;
    }

    // Criando as matrizes de habilidade
    int habilidadeCone[TAM_HABILIDADE][TAM_HABILIDADE];
    int habilidadeCruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int habilidadeOctaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    criarHabilidadeCone(habilidadeCone);
    criarHabilidadeCruz(habilidadeCruz);
    criarHabilidadeOctaedro(habilidadeOctaedro);

    // Aplicando as habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, habilidadeCone, 4, 4);  // Habilidade Cone no centro do tabuleiro
    aplicarHabilidade(tabuleiro, habilidadeCruz, 5, 5);  // Habilidade Cruz no centro do tabuleiro
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, 6, 6);  // Habilidade Octaedro no centro do tabuleiro

    // Exibindo o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}