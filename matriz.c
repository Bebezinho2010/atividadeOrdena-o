#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD_LINHAS 100
#define QTD_COLUNAS 100

void lerMatriz(int mat[][QTD_COLUNAS], int lin, int col);
void preencherMatrizAleatoria(int mat[][QTD_COLUNAS], int lin, int col);
void imprimirMatriz(int mat[][QTD_COLUNAS], int lin, int col);
int calculaImpares(int mat[][QTD_COLUNAS], int lin, int col);
void buscaElemento(int mat[][QTD_COLUNAS], int lin, int col, int elemento);
int soma(int mat[][QTD_COLUNAS], int lin, int col);
double mediaElementos(int mat[][QTD_COLUNAS], int lin, int col);
void mediaLinha(int mat[][QTD_COLUNAS], int lin, int col);

int lerDentroIntervalo(int min, int max);

int main() {
    int qtdLinhas, qtdColunas;
    int matriz[QTD_LINHAS][QTD_COLUNAS];
    int elemento;
    
    // deve ser utilizado quando você quiser que a cada execução gere uma sequência diferente
    // de números aleatórios
    //srand(time(0));

    printf("Digite a quantidade de linhas (1-%d): ", QTD_LINHAS);
    qtdLinhas = lerDentroIntervalo(1, QTD_LINHAS);
    printf("Digite a quantidade de colunas (1-%d): ", QTD_COLUNAS);
    qtdColunas = lerDentroIntervalo(1, QTD_COLUNAS);

    preencherMatrizAleatoria(matriz, qtdLinhas, qtdColunas);
    printf("\n--------------------\n");
    imprimirMatriz(matriz, qtdLinhas, qtdColunas);

    int qtdImpares = calculaImpares(matriz, qtdLinhas, qtdColunas);
    printf("A quantidade de números ímpares na matriz é de: %d\n", qtdImpares);

    int somatorio = soma(matriz, qtdLinhas, qtdColunas);
    printf("O somatório de todos os elementos da matriz é de: %d\n", somatorio);

    double media = mediaElementos(matriz, qtdLinhas, qtdColunas);
    printf("A média dos elementos da matriz é de: %.1f\n", media);

    printf("A média dos elementos de cada linha é:\n");
    mediaLinha(matriz, qtdLinhas, qtdColunas);

    printf("Digite o elemento a ser buscado na matriz: ");
    scanf("%d", &elemento);
    buscaElemento(matriz, qtdLinhas, qtdColunas, elemento);

    return 0;
}

void lerMatriz(int mat[][QTD_COLUNAS], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("Digite mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void preencherMatrizAleatoria(int mat[][QTD_COLUNAS], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            mat[i][j] = rand() % 100 + 1;
        }
    }
}

void imprimirMatriz(int mat[][QTD_COLUNAS], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int calculaImpares(int mat[][QTD_COLUNAS], int lin, int col) {
    int cont = 0;
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            if (mat[i][j] % 2 != 0) {
                cont++;
            }
        }
    }
    return cont;
}

void buscaElemento(int mat[][QTD_COLUNAS], int lin, int col, int elemento) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            if (mat[i][j] == elemento) {
                printf("O elemento %d foi encontrado na linha %d e na coluna %d.\n", elemento, i + 1, j + 1);
                return;
            }
        }
    }
    printf("Elemento não encontrado na matriz.\n");
}

int soma(int mat[][QTD_COLUNAS], int lin, int col) {
    int somatorio = 0;
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            somatorio += mat[i][j];
        }
    }
    return somatorio;
}

double mediaElementos(int mat[][QTD_COLUNAS], int lin, int col) {
    double somatorio = 0;
    int totalelementos = lin * col;
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            somatorio += mat[i][j];
        }
    }
    if (totalelementos > 0) {
        return somatorio / totalelementos;
    } else {
        return 0;
    }
}

void mediaLinha(int mat[][QTD_COLUNAS], int lin, int col) {
    for (int i = 0; i < lin; i++) {
        double somatorio = 0;
        
        for (int j = 0; j < col; j++) {
            somatorio += mat[i][j];
        }
        
        double mediaLinha;
        if (col > 0) {
            mediaLinha = somatorio / col;
        } else {
            mediaLinha = 0;
        }
        
        printf("A média dos elementos da linha %d é: %.1f\n", i + 1, mediaLinha);
    }
}

int lerDentroIntervalo(int min, int max) {
    int valor;
    scanf("%d", &valor);
    while (valor < min || valor > max) {
        printf("Valor inválido! Digite valor entre %d e %d: ", min, max);
        scanf("%d", &valor);
    }
    return valor;
}
