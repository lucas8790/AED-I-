#include <stdio.h>

void Merge(int vetor[], int inicio, int meio, int final){
    int i, j, k;
    int lado1 = meio - inicio + 1;
    int lado2 = final - meio;

    //I = Início e F = Final;
    int I[lado1], F[lado2];

    for(i = 0; i < lado1; i++){
        I[i] = vetor[inicio + i];
    }
    for(j = 0; j < lado2; j++){
        F[j] = vetor[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;
    while(i < lado1 && j < lado2){
        if(I[i] <= F[j]){
            vetor[k] = I[i];
            i++;
        }
        else{
            vetor[k] = F[j];
            j++;
        }
        k++;
    }

    while(i < lado1){
        vetor[k] = I[j];
        j++;
        k++;
    }
    
    while(j < lado2){
        vetor[k] = F[j];
        j++;
        k++;
    }
}

void MergeSort(int vetor[], int inicio, int final){
    if (inicio < final){
        int meio = inicio + (final - 1) / 2;

        MergeSort(vetor, inicio, meio);
        MergeSort(vetor, meio + 1, final);

        Merge(vetor, inicio, meio, final);
    }
}

int main(){
    int vetor[] = {2, 60, 45, 14, 17, 89, 101, 90};
    int n = sizeof(vetor)/sizeof(vetor[0]);

    MergeSort(vetor, 0, n - 1);
    printf("\nLista Ordenada:\n");
    
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}