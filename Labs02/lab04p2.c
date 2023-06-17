#include <stdio.h>
#define TAM_VETOR 20

int busca_bin (int inicio_vetor, int tamanho_fim, int* vet, int elem){
    if (inicio_vetor > tamanho_fim){
        return -1;
    }
    int meio;

    if (inicio_vetor % 2 == 0){
        meio = (inicio_vetor + tamanho_fim)/2;
    } else {
        meio = (inicio_vetor + tamanho_fim + 1)/2;
    }

    if (elem > vet[meio]){
        busca_bin(meio + 1, tamanho_fim, vet, elem);
    } else if (elem < vet[meio]) {
        busca_bin(inicio_vetor, meio - 1, vet, elem);
    } else {
        return meio;
    }
}

int main()
{
    int vetor[TAM_VETOR] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17, 18, 19, 20, 21};
    int busca = 13;
    int inicio = 0;
    int fim = TAM_VETOR - 1;
    int indice = busca_bin(inicio, fim, vetor, busca);

    if (indice==-1){
        printf("Valor %d não encontrado!\n", busca);
    } else {
        printf("Valor %d encontrado na posição %d do vetor!\n", busca, indice);
    }

    return 0;
}
