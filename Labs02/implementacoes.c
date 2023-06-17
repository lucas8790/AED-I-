#include <stdio.h>

/* Implemente uma função em C que segue o protótipo:
int conta_vogais(char* palavra);
E o retorno dessa função retornará a quantidade de vogais. */
int conta_vagais(char* palavra){
    int contador = 0;
    for(int i = 0; i < palavra[i]; i++){
        if(palavra[i] == 'a' || palavra[i] == 'A' || palavra[i] == 'e' || palavra[i] == 'E' || palavra[i] == 'i' || palavra[i] == 'I' || palavra[i] == 'o' || palavra[i] == 'O' || palavra[i] == 'u' || palavra[i] == 'U'){
            contador++;
        }
    }
    return contador;
}

/* Implemente uma função em C que recebe como entrada um vetor (v1), um elemento a ser inserido,
tamanho do vetor, posiçao no qual o elemento esta inserido. Sempre que o vetor estiver totalmente
preenchido, aloque um novo vetor com o dobro do tamanho do vetor v1, e copie os dados de v1 para o 
novo vetor. Siga o seguinte protótipo:
int* insere(int valor, int* v1, int tamanho, int posicao); */
int* insere(int valor, int* v1, int tamanho, int posicao){
    if(tamanho == 0){
        v1 = (int*)malloc(sizeof(int));
        v1[0] = valor;
        return v1;
    }
    if(posicao >= tamanho){
        int* v2 = (int*)malloc(sizeof(int)* tamanho * 2);
        for(int i = 0; i < tamanho; i++){
            v2[i] = v1[i];
        }
    }
}

/* Implemente em C uma rotina que recebe como entrada duas listas (l1,l2) simplesmente encadeada
e retorne uma lista simplesmente encadeada (l) fruto do merge (intercala) de l1 coml2. Considere 
os seguintes exemplos na elaboração da solução.
- Exemplo 1
l1 = {1, 2, 5}
l2 = {0, 9, 8}
l = {1, 0, 2, 9, 5, 8}
- Exemplo 2:
l1 = {1}
l2 = {0, 9, 8}
l = {1, 0, 9, 8}
- Exemplo 3
l1 = {1, 2, 5}
l2 = { }
l = {1, 2, 5}
As listas não possuem restrição de tamanhos. São listas dinâmicas. Siga o seguinte protótipo.
Lista* intercala (Lista* l1, Lista* l2); */

typedef struct lista{
    int elemento;
    struct lista* proximo;
}Lista;

Lista* intercala(Lista* l1, Lista* l2){
    Lista* l = NULL;
    Lista* aux = NULL;

    while(l1 != NULL && l2 != NULL){
        if(l1->elemento <= l2->elemento){
            if(l = NULL){
                l = aux = l1;
            }else{
                aux->proximo = l1;
                aux = aux->proximo;
            }
            l1 = l1->proximo;
        }else{
            if(l = NULL){
                l = aux = l2;
            }else{
                aux->proximo = l2;
                aux = aux->proximo;
            }
            l2 = l2->proximo;
        }
    }
    return l;
}

/* Implemente busca binária de forma recursiva. */
int busca_bin(int inicio_vetor, int tamanho_fim, int* vet, int elemento){
    if(inicio_vetor > tamanho_fim){
        return -1;
    }
    int meio;
    
    if(inicio_vetor % 2 == 0){
        meio = (inicio_vetor + tamanho_fim)/2;
    }else{
        meio = (inicio_vetor + tamanho_fim + 1)/2;
    }

    if(elemento > vet[meio]){
        busca_bin(meio + 1, tamanho_fim, vet, elemento);
    }else if(elemento < vet[meio]){
        busca_bin(inicio_vetor, meio - 1, vet, elemento);
    }else{
        return meio;
    }
}