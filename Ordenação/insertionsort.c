#include <stdio.h>

void InsertionSort(int vetor[], int n){
    int i = 0, j = 0, aux = 0;
    for(j = 2; j < n; j++){
        aux = vetor[j];
        i = j - 1;
        while(i >=0 && vetor[i] > aux){
            vetor[i+1] = vetor[i];
            i = i - 1;
        }
    vetor[i + 1] = aux;
    }
}

int main(){
    int vetor[] = {3, 5, 80, 45, 72, 18, 9, 10, 15, 90};
    int n = sizeof(vetor)/sizeof(vetor[0]);
    int i;

    InsertionSort(vetor, n);
    printf("\nLista Ordenada:\n");
    for(i = 0; i < 10; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}