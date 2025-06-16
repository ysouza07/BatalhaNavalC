#include <stdio.h>

// definições de valores máximos dentro da matriz e dos navios. 
 #define LINHAS 10
 #define COLUNAS 10
 #define NAVIO 3

void inserirCone(int matriz[LINHAS][COLUNAS], int cone[3][5], int linhaInicial, int colunaInicial) {
    for (int i = 0; i < 3; i++) { // função para incluir a habilidade de cone na matriz principal.
        for (int j = 0; j < 5; j++) {
            // Verifica se a posição está dentro dos limites da matriz principal
            if (linhaInicial + i < LINHAS && colunaInicial + j < COLUNAS) {
               // Apenas sobrescreve se a célula não contiver um navio (NAVIO = 3)
                if (cone[i][j] == 1 && matriz[linhaInicial + i][colunaInicial + j] != NAVIO) {
                    matriz[linhaInicial + i][colunaInicial + j] = cone[i][j];
                }
            }
        }
    }
}

void inserirCruz(int matriz[LINHAS][COLUNAS], int cruz[3][5], int linhaInicial, int colunaInicial) {
    for (int i = 0; i < 3; i++) { // função para incluir a habilidade de cruz na matriz principal.
        for (int j = 0; j < 5; j++) {
            // Verifica se a posição está dentro dos limites da matriz principal
            if (linhaInicial + i < LINHAS && colunaInicial + j < COLUNAS) {
               // Apenas sobrescreve se a célula não contiver um navio (NAVIO = 3)
                if (cruz[i][j] == 1 && matriz[linhaInicial + i][colunaInicial + j] != NAVIO) {
                    matriz[linhaInicial + i][colunaInicial + j] = cruz[i][j];
                }
            }
        }
    }
}

void inserirOctaedro(int matriz[LINHAS][COLUNAS], int octaedro[3][5], int linhaInicial, int colunaInicial) {
    for (int i = 0; i < 3; i++) { // função para incluir a habilidade de octaedro na matriz principal.
        for (int j = 0; j < 5; j++) {
            // Verifica se a posição está dentro dos limites da matriz principal
            if (linhaInicial + i < LINHAS && colunaInicial + j < COLUNAS) {
               // Apenas sobrescreve se a célula não contiver um navio (NAVIO = 3)
                if (octaedro[i][j] == 1 && matriz[linhaInicial + i][colunaInicial + j] != NAVIO) {
                    matriz[linhaInicial + i][colunaInicial + j] = octaedro[i][j];
                }
            }
        }
    }
}

int main() {
  
int matriz[LINHAS][COLUNAS] = {0}; //tabuleiro, inicializado em zero.
int cone[3][5] = {{0, 0, 1, 0, 0}, {0, 1, 1, 1, 0}, {1, 1, 1, 1, 1}}; //matriz de habilidade de cone.
int cruz[3][5] = {{0, 0, 1, 0, 0}, {1, 1, 1, 1, 1}, {0, 0, 1, 0, 0}}; //matriz de habilidade de cruz.
int octaedro[3][5] = {{0, 0 , 1, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 1, 0, 0}}; //matriz de habilidade de octaedro
int navio1L = 5, navio1C = 1;  // Navio horizontal
int navio2L = 6, navio2C = 7;  // Navio vertical
int navio3L = 2, navio3C = 0; // Primeio navio na Diagonal
int navio4L = 4, navio4C = 7; // Segundo navio na diagonal
    
    for (int j = 0; j < NAVIO;j++) { //posicionamento do navio na horizontal, linha fixa, coluna variável.
        matriz[navio1L][navio1C + j] = NAVIO;
    }
    for (int i = 0; i < NAVIO;i++) { //posicionamento do navio na vertical, coluna fixa, linha variável.
        matriz[navio2L + i][navio2C] = NAVIO;
    }
    for (int i = 0; i < NAVIO;i++) { //posicionamento do navio na diagonal, linhas e colunas incrementadas.
        matriz[navio3L + i][navio3C + i] = NAVIO;
    }
    for (int i = 0; i < NAVIO;i++) { //posicionamento do navio na diagonal, linhas e colunas decrementadas.
        matriz[navio4L - i][navio4C - i] = NAVIO;
    }
    
    inserirCone(matriz, cone, 7, 0); // função para incluir habilidade cone na matriz principal.
    //alterando os valores dentro dos () você também altera onde a habilidade irá entrar na matriz.
    
    inserirCruz(matriz, cruz, 0, 0); // função para incluir habilidade cone na matriz principal.
    //alterando os valores dentro dos () você também altera onde a habilidade irá entrar na matriz.
    
    inserirOctaedro(matriz, octaedro, 0, 5); // função para incluir habilidade cone na matriz principal.
    //alterando os valores dentro dos () você também altera onde a habilidade irá entrar na matriz.

    for (int i = 0; i < LINHAS; i++) { // tabuleiro gerando a matriz 10x10 após definição da posição dos navios e habilidades.
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n"); //para melhor apresentação do resultado.
    } printf("\n");

    for (int i = 0; i < 3; i++) { // apresentando a matriz de habilidade cone.
        for (int j = 0; j < 5; j++) {
            printf("%d ", cone[i][j]);
        }
    printf("\n");
    } printf("Matriz Cone.\n\n");


    for (int i = 0; i < 3; i++) { // apresentando a matriz de habilidade cruz.
        for (int j = 0; j < 5; j++) {
            printf("%d ", cruz[i][j]);
        }
    printf("\n");
    } printf("Matriz Cruz.\n\n");
    

    for (int i = 0; i < 3; i++) { // apresentando a matriz de habilidade octaedro.
        for (int j = 0; j < 5; j++) {
            printf("%d ", octaedro[i][j]);
        }
    printf("\n");
    } printf("Matriz Octaedro.\n\n");


    return 0;
}