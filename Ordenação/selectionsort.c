#include <stdio.h>

void SelectionSort(int vetor[], int n){
    int aux = 0, i, j;
    for(i = 0; i < n - 1; i++){
        int pos_menor = i;
        for(j = i + 1; j < n; j++){
            if(vetor[j] < vetor[pos_menor]){
                pos_menor = j;
            }
        }
        aux = vetor[pos_menor];
        vetor[pos_menor] = vetor[i];
        vetor[i] = aux;
    }
}

int main(){
    int vetor[] = {3, 5, 19, 4, 39, 90, 15, 17, 82, 100};
    int n = sizeof(vetor)/sizeof(vetor[0]);
    int i;

    SelectionSort(vetor, n);
    printf("\nLista Ordenada:\n");
    for(i = 0; i < 10; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}