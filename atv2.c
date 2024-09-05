#include <stdio.h>
#define QTD_vetor 50

void elementosVetor(int vetor[], int tamanho) {
    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

}

int buscaBinaria(int vetor[], int tamanho, int valor) {
    int esquerda = 0;
    int direita = tamanho - 1;
    int meio;
    while (esquerda <= direita) {
        meio = (esquerda + direita) / 2;
        if (vetor[meio] == valor) {
            return meio;
        } else if (vetor[meio] < valor) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}

void ordenarvetor(int vetor[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

void removeElemento(int vetor[], int* tamanho, int valor) {
    if (*tamanho <= 0) {
        return;
    }
    
    int posicao = buscaBinaria(vetor, *tamanho, valor);
    
    if (posicao != -1) {
        for (int i = posicao; i < *tamanho - 1; i++) {
            vetor[i] = vetor[i + 1];
        }
        (*tamanho)--;
    }
}

void InserirNaOrdenacao(int vetor[], int* tamanho, int valor) {
    if (*tamanho >= QTD_vetor) {
        printf("O vetor está cheio.\n");
        return;
    }

    int i = *tamanho - 1;
    while (i >= 0 && vetor[i] > valor) {
        vetor[i + 1] = vetor[i];
        i--;
    }
    vetor[i + 1] = valor;
    (*tamanho)++;
}

int main() {
    int vetor[QTD_vetor];
    int tamanho = 0;
    int opcao, quantidade, valor;

    printf("Digite o tamanho do vetor (entre 3 e 50): ");
    scanf("%d", &tamanho);

    if (tamanho < 3 || tamanho > 50) {
        printf("Tamanho inválido.\n");
        return 1;
    }

    printf("Digite a quantidade de valores dentro do vetor: ");
    scanf("%d", &quantidade);
    if (quantidade > tamanho) {
        printf("A quantidade de elementos é maior que o tamanho do vetor.\n");
        return 1;
    }

    printf("Digite os valores do vetor:\n");
    for (int i = 0; i < quantidade; i++) {
        scanf("%d", &vetor[i]);
    }
    tamanho = quantidade;

    ordenarvetor(vetor, tamanho);

    do {
        printf("\nMenu\n");
        printf("Digite 1 para imprimir o vetor.\n");
        printf("Digite 2 para buscar um valor.\n");
        printf("Digite 3 para remover um elemento.\n");
        printf("Digite 4 para inserir elemento.\n");
        printf("Digite 5 para ordenar o vetor.\n");
        printf("Digite 6 para sair do programa.\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                elementosVetor(vetor, tamanho);
                break;
            
            case 2:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                {
                    int indice = buscaBinaria(vetor, tamanho, valor);
                    if (indice != -1) {
                        printf("Elemento encontrado na posição %d.\n", indice);                     
                    } else {
                        printf("Elemento não encontrado.\n");
                    }
                }
                break;

            case 3:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                removeElemento(vetor, &tamanho, valor);
                break;
            
            case 4:
                printf("Insira um elemento: ");
                scanf("%d", &valor);
                InserirNaOrdenacao(vetor, &tamanho, valor);
                break;
            
            case 5:
                ordenarvetor(vetor, tamanho);
                printf("Vetor ordenado.\n");
                break; 
            
            case 6:
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;               
        }

    } while (opcao != 6);

    return 0;
}
