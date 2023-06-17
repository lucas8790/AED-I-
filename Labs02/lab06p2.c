#include <stdio.h>
#include "allordenacao.h"
#include <time.h>
#include <stdlib.h>

int main()
{
	//int v[10] = {3, 5, 8, 1, 19, 0, 45, 16, 32, 2};
	int v[10000];
	int n = 0;
	FILE *arquivo;
	
	arquivo = fopen("numeroslista.txt", "r");
	
	while (!feof(arquivo)){
		fscanf(arquivo, "%d", &v[n]);
		n++;
	}
	
    printf("TOTAL DE NÚMEROS: %d\n", n);
    
    fclose(arquivo);
    
    int tamanho = 10000, i;
    
    int *v_copia = (int)calloc(tamanho, sizeof(int));
    
    //Inicialização do vetor cópia
    for (i = 0; i < tamanho; i++){
    	v_copia[i] = v[i];
	}
    
    float tempo_execucao;
    time_t t_ini, t_fim;
    
    
    t_ini = time(NULL);
    bubble_sort(v_copia, tamanho);
    t_fim = time(NULL);
    
    tempo_execucao = difftime(t_fim, t_ini);
    
    for (i = 0; i < n; i++){
		printf("%d ", v_copia[i]);
	}
    printf("\nTempo que levou para ser executado o algoritmo Bubble Sort: %f\n", tempo_execucao);
    
    printf("\n------------------------------------------\n");
    
    //Inicialização do vetor cópia
    for (i = 0; i < tamanho; i++){
    	v_copia[i] = v[i];
	}
    
    t_ini = time(NULL);
    selection_sort(v_copia, tamanho);
    t_fim = time(NULL);
    
    tempo_execucao = difftime(t_fim, t_ini);

	for (i = 0; i < n; i++){
		printf("%d ", v_copia[i]);
	}
	printf("\nTempo que levou para ser executado o algoritmo Selection Sort: %f\n", tempo_execucao);
	
	printf("\n------------------------------------------\n");
	
	
	//Inicialização do vetor cópia
	for (i = 0; i < tamanho; i++){
    	v_copia[i] = v[i];
	}
	
	t_ini = time(NULL);
    insertion_sort(v_copia, tamanho);
    t_fim = time(NULL);
    
    tempo_execucao = difftime(t_fim, t_ini);

	for (i = 0; i < n; i++){
		printf("%d ", v_copia[i]);
	}
	printf("\nTempo que levou para ser executado o algoritmo Insertion Sort: %f\n", tempo_execucao);
	
	printf("\n------------------------------------------\n");
	
	//Inicialização do vetor cópia
	for (i = 0; i < tamanho; i++){
    	v_copia[i] = v[i];
	}
	
	t_ini = time(NULL);
    merge_sort(v_copia, 0, tamanho - 1);
    t_fim = time(NULL);
    
    tempo_execucao = difftime(t_fim, t_ini);

	for (i = 0; i < n; i++){
		printf("%d ", v_copia[i]);
	}
	printf("\nTempo que levou para ser executado o algoritmo Merge Sort: %f\n", tempo_execucao);
	
	printf("\n------------------------------------------\n");
	
	
	//Inicialização do vetor cópia
	for (i = 0; i < tamanho; i++){
    	v_copia[i] = v[i];
	}
	
	t_ini = time(NULL);
    quick_sort(v_copia, 0, tamanho - 1);
    t_fim = time(NULL);
    
    tempo_execucao = difftime(t_fim, t_ini);

	for (i = 0; i < n; i++){
		printf("%d ", v_copia[i]);
	}
	printf("\nTempo que levou para ser executado o algoritmo Quick Sort: %f\n", tempo_execucao);
	
	printf("\n------------------------------------------\n");

    return 0;
}