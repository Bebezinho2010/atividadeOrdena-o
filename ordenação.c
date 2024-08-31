#include <stdio.h>

void Ordenado(int vetor[], int *n, int valor) {
    int i;

    for (i = *n - 1; (i >= 0 && vetor[i] > valor); i--) {
        vetor[i + 1] = vetor[i];
    }
    vetor[i + 1] = valor;
    (*n)++;
}

int main() {
    int qtd;
    
    printf("Digite a quantidade: ");
    scanf("%d", &qtd);

    if (qtd <= 0) {
        printf("não é possivel ter quantidades negativas ou zero.\n");
        return 1;
    }

    int vetor[qtd]; 
    int valor;

    int tamanho = 0;

    for (int i = 0; i < qtd; i++) {
        printf("Digite um valor pro vetor: ");
        scanf("%d", &valor);
        Ordenado(vetor, &tamanho, valor);
    }

    printf("Vetor ordenado: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
