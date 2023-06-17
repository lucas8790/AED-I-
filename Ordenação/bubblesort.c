#include <stdio.h>

void bubblesort(int vetor[], int n){
    int i, j, aux;
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

int main(){
    int vetor[] = {21, 23, 2, 34, 245, 33, 62};
    int n = sizeof(vetor)/sizeof(vetor[0]);
    int i;

    bubblesort(vetor, n);
    printf("\nLista apos ordenacao.\n");
    for(i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}