#include <stdio.h>
#include <stdlib.h>
#define M 100
#define N 100

void preencherMatriz(int mat[][N], int lin, int col);
void imprimeMatriz(int mat[][N], int lin, int col);
void contaRepeticoes(int mat[][N], int lin, int col);
void encontraMaisRepetidos(int mat[][N], int lin, int col);

int main() {
    int mat[M][N];
    int linha;
    int coluna;
    int opcao;

    printf("Digite o número de linhas: ");
    scanf("%d", &linha);
    printf("Digite o número de colunas: ");
    scanf("%d", &coluna);

    do {
        printf("Digite 1 para preencher a matriz.\n");
        printf("Digite 2 para imprimir a matriz.\n");
        printf("Digite 3 para mostrar as contagens de números repetidos em toda a matriz.\n");
        printf("Digite 4 para mostrar o índice da linha ou coluna onde tem mais números repetidos.\n");
        printf("Digite 0 para sair do programa.\n");
        printf("Digite uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                preencherMatriz(mat, linha, coluna);
                break;
            case 2:
                imprimeMatriz(mat, linha, coluna);
                break;
            case 3:
                contaRepeticoes(mat, linha, coluna);
                break;
            case 4:
                encontraMaisRepetidos(mat, linha, coluna);
                break;
        }
    } while (opcao != 0);

    return 0;
}

void preencherMatriz(int mat[][N], int lin, int col) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            mat[i][j] = rand() % 100 + 1;
        }
    }
    printf("\n");
}

void imprimeMatriz(int mat[][N], int lin, int col) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void contaRepeticoes(int mat[][N], int lin, int col) {
    int ocorrencia[101] = {0};
    int total_repetidos = 0;

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            ocorrencia[mat[i][j]]++;
        }
    }

    printf("Existem números repetidos:\n");
    for (int i = 1; i <= 100; i++) {
        if (ocorrencia[i] > 1) {
            printf("O número %d aparece %d vezes; ", i, ocorrencia[i]);
            total_repetidos++;
        }
    }
    
    if (total_repetidos > 0) {
        printf("\nExistem %d números repetidos.\n", total_repetidos);
    } else {
        printf("\nNão há números repetidos.\n");
    }
}

void encontraMaisRepetidos(int mat[][N], int lin, int col) {
    int max_repetidos = 0;
    int indice_max = -1;
    int numeros_repetidos[101] = {0};
    
    for (int i = 0; i < lin; i++) {
        for (int k = 0; k <= 100; k++) {
            numeros_repetidos[k] = 0;
        }

        for (int j = 0; j < col; j++) {
            numeros_repetidos[mat[i][j]]++;
        }

        int cont_repetidos = 0;
        for (int k = 1; k <= 100; k++) {
            if (numeros_repetidos[k] > 1) {
                cont_repetidos += numeros_repetidos[k] - 1;
            }
        }

        if (cont_repetidos > max_repetidos) {
            max_repetidos = cont_repetidos;
            indice_max = i;
        }
    }

    for (int j = 0; j < col; j++) {
        for (int k = 0; k <= 100; k++) {
            numeros_repetidos[k] = 0;
        }

        for (int i = 0; i < lin; i++) {
            numeros_repetidos[mat[i][j]]++;
        }

        int cont_repetidos = 0;
        for (int k = 1; k <= 100; k++) {
            if (numeros_repetidos[k] > 1) {
                cont_repetidos += numeros_repetidos[k] - 1;
            }
        }

        if (cont_repetidos > max_repetidos) {
            max_repetidos = cont_repetidos;
            indice_max = -1;
            indice_max = j;
        }
    }

    if (indice_max >= 0) {
        printf("A linha %d é a linha com mais números repetidos, total de %d.\n", indice_max, max_repetidos);
    } else {
        printf("A coluna %d é a coluna com mais números repetidos, total de %d.\n", -indice_max, max_repetidos);
    }
}
