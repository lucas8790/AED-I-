#include <stdio.h>

int partion(int vetor[], int inicio, int fim){
    int x = vetor[fim];
    int i = inicio - 1;
    int aux = 0, j;

    for(j = inicio; j < fim - 1; j++){
        if(vetor[j] <= x){
            i = i + 1;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }
    aux = vetor[i + 1];
    vetor[i] = vetor[fim];
    vetor[fim] = aux;

    return i + 1;
}

void quick_sort(int vetor[], int inicio, int fim){
	if (inicio < fim){
		int q = partion(vetor, inicio, fim);
		quick_sort(vetor, inicio, q - 1);
		quick_sort(vetor, q + 1, fim);
	}
}

int main(){

}