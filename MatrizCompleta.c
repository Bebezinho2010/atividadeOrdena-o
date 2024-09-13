#include <stdio.h>
#include <stdlib.h>
#define QTD_LINHAS 100
#define QTD_COLUNAS 100

void preencherMatrizAleatoria(int mat[][QTD_COLUNAS], int lin, int col);
void imprimirMatriz(int mat[][QTD_COLUNAS], int lin, int col);
int calculaImpares(int mat[][QTD_COLUNAS], int lin, int col);
void buscaElemento(int mat[][QTD_COLUNAS], int lin, int col, int elemento);
int soma(int mat[][QTD_COLUNAS], int lin, int col);
double mediaElementos(int mat[][QTD_COLUNAS], int lin, int col);
void mediaLinha(int mat[][QTD_COLUNAS], int lin, int col);
void mediaColuna(int mat[][QTD_COLUNAS], int lin, int col);
void transporMatriz(int mat[][QTD_COLUNAS], int lin, int col, int matTransp[][QTD_COLUNAS]);
void imprimirMatrizTrans(int mat[][QTD_LINHAS], int lin, int col);
void encontrarMaxMin(int mat[][QTD_COLUNAS], int lin, int col, int *max, int *min);
int lerDentroDoIntervalo(int min, int max);

int main(){
    int qtd_linhas;
    int qtd_colunas;
    int matriz[QTD_LINHAS][QTD_COLUNAS];
    int elemento;
    int matTransposta[QTD_COLUNAS][QTD_LINHAS];
    int max, min;
  
    //srand(time(0));
  
    printf("Digite a quantidade de linhas: ");
    qtd_linhas = lerDentroDoIntervalo(1, QTD_LINHAS);
    printf("Digite a quantidade de colunas: ");
    qtd_colunas = lerDentroDoIntervalo(1, QTD_COLUNAS);

    preencherMatrizAleatoria(matriz, qtd_linhas, qtd_colunas);
    printf("\n-----------------------------------\n");
    imprimirMatriz(matriz, qtd_linhas, qtd_colunas);
    printf("-----------------------------------\n");

    int qtdImpares = calculaImpares(matriz, qtd_linhas, qtd_colunas);
    printf("A quantidade de números impares dessa matriz é de %d.\n", qtdImpares);

    int somatorio = soma(matriz, qtd_linhas, qtd_colunas);
    printf("A soma de todos os elementos da matriz é de %d.\n", somatorio);
    double media = mediaElementos(matriz, qtd_linhas, qtd_colunas);
    printf("A media de todos os elementos da matriz é de %.1f.\n", media);

    printf("a media dos elementos de cada linha é:\n");
    mediaLinha(matriz, qtd_linhas, qtd_colunas);
    printf("a media dos elementos de cada coluna é:\n");
    mediaColuna(matriz, qtd_linhas, qtd_colunas);

    encontrarMaxMin(matriz, qtd_linhas, qtd_colunas, &max, &min);
    printf("o maior valor da matriz é %d.\n", max);
    printf("o menor valor da matriz é %d.\n", min);
    
    printf("Digite um elemento a ser buscado: ");
    scanf("%d", &elemento);
    buscaElemento(matriz, qtd_linhas, qtd_colunas, elemento);

    transporMatriz(matriz, qtd_colunas, qtd_linhas, matTransposta);
    printf("\nA sua transposta é:\n");
    imprimirMatrizTrans(matTransposta, qtd_colunas, qtd_linhas);

    return 0;
}

void preencherMatrizAleatoria(int mat[][QTD_COLUNAS], int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            mat[i][j] = rand() % 100 + 1;
        }
    }
}

void imprimirMatriz(int mat[][QTD_COLUNAS], int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int calculaImpares(int mat[][QTD_COLUNAS], int lin, int col){
    int cont = 0;
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            if(mat[i][j] % 2 != 0){
                cont++;
            }
        }
    }
    return cont;
}

void buscaElemento(int mat[][QTD_COLUNAS], int lin, int col, int elemento){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            if(mat[i][j] == elemento){
                printf("O elemento que deseja buscar está na linha %d e na coluna %d.\n", i + 1, j + 1);
                return;
            }         
        }
    }
    printf("elemento não encontrado na matriz.\n"); 
}

int soma(int mat[][QTD_COLUNAS], int lin, int col){
    int somatorio = 0;
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            somatorio += mat[i][j];
        }
    }
    return somatorio;
}

double mediaElementos(int mat[][QTD_COLUNAS], int lin, int col){
    int somatorio = 0;
    double totalElementos = lin * col;
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            somatorio += mat[i][j];
        }
        if(totalElementos > 0){
            return somatorio / totalElementos;
        }else{
            return 0;
        }
    }
}

void mediaLinha(int mat[][QTD_COLUNAS], int lin, int col){
    for(int i = 0; i < lin; i++){
        double somatorio = 0.0;
        double medialinha;
        for(int j = 0; j < col; j++){
            somatorio += mat[i][j];
        }if(col > 0){
            medialinha = (double)somatorio / col;
        }else{
            medialinha = 0;
        }
        printf("a media da linha %d é de %.2f.\n", i + 1, medialinha);
    }
}

void mediaColuna(int mat[][QTD_COLUNAS], int lin, int col){
    for(int j = 0; j < col; j++){
        double somatorio = 0.0;
        double mediacoluna;
        for(int i = 0; i < lin; i++){
            somatorio +=mat[i][j];
        }if(lin > 0){
            mediacoluna = somatorio / lin;
        }else{
            mediacoluna = 0;
        }
        printf("a media da coluna %d é de %.2f.\n", j + 1, mediacoluna);
        
    }
}

void transporMatriz(int mat[][QTD_COLUNAS], int lin, int col, int matTransp[][QTD_LINHAS]){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            matTransp[j][i] = mat[i][j];
        }
    }
}

void imprimirMatrizTrans(int mat[][QTD_LINHAS], int lin, int col){
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void encontrarMaxMin(int mat[][QTD_COLUNAS], int lin, int col, int *max, int *min){
    *max = mat[0][0];
    *min = mat[0][0];

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            if(mat[i][j] > *max){
                *max = mat[i][j];
            }
            if(mat[i][j] < *min){
                *min = mat[i][j];
            }
        }
    }
}
int lerDentroDoIntervalo(int min, int max){
    int valor = 0;
    scanf("%d", &valor);
    while(valor < min || valor > max){
        printf("Valor inválido! Digite valor entre %d e %d: ", min, max);
        scanf("%d", &valor);
    }
    return valor;
}
