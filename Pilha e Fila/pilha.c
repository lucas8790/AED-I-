#include <stdio.h>
#define N 50

typedef struct pilha{
    int elemento;
    float vetor[N];
}Pilha;

//Função de inicialização de uma pilha;
Pilha* inicializar(){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->elemento = 0;          //Inicia a pilha zerada;
    printf("\nPilha Criada.\n");
    return p;
}

//Função para inserir, sempre verificando se a pilha tem espaço livre;
void inserir(Pilha* p, float valor){
    if(p->elemento == N){
        printf("\nPilha totalmente cheia!\n");
        exit(1);
    }
    //Caso não entre no IF, a gente insere:
    p->vetor[p->elemento] = valor;
    p->elemento++;
    printf("\nInserido.\n");
}

//Função de remoção;
float remover(Pilha* p){
    float valor;
    if(p->elemento == NULL){
        printf("\nPilha está vazia.\n");
        exit(1);
    }
    valor = p->vetor[p->elemento - 1];
    p->elemento --;
    printf("\nRemovido.\n");
    return valor;
}

//Função de liberar mémoria;
void libera(Pilha* p){
    printf("Liberando Mémoria.\n");
    free(p);
}

int main(){

}