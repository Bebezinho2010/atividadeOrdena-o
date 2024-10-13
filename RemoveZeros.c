#include <stdio.h>
#include <string.h>

void RemoveZeros(char* str);

int main(){
    int m, n;

    while(1){
        printf("Digite o primeiro valor: ");
        scanf("%d", &m);
        printf("Digite o segundo valor: ");
        scanf("%d", &n);

        if(m == 0 &&  n == 0){
            printf("Pelo menos um valor deve ser maior que 0.\n");
            break;
        }

        int soma = m + n;
        char resultado[20];
        sprintf(resultado, "%d", soma);
        RemoveZeros(resultado);
        printf("resultado da soma sem os 'zeros': %s.\n", resultado);

    }

    return 0;
}

void RemoveZeros(char* str){
    int j = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] != '0'){
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

