#include <stdio.h>

//Struct da lista duplamente encadeada, com a diferença que agora o valor apontado para o prox e anterior;
typedef struct lista{
    int elemento;
    struct lista* anterior;
    struct lista* proximo;
}Lista;

//Função de inserir;
Lista* insere(Lista* l, int i){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->elemento = i;
    novo->proximo = l;
    novo->anterior = NULL;

    if(l != NULL){
        l->anterior = novo;
    }
    return novo;
}

//Função para imprimir todos os elementos da lista;
void imprimir(Lista* l){
    Lista* p;         // --> Variável aux;
    for(p = l; p !=NULL; p = p->proximo){
        printf("%d ",p->elemento);
    }
}

//Função de esvaziar a lista (liberar);
void libera(Lista* l){
    Lista* p = l;
    while(p != NULL){
        Lista* t = p->proximo; //Está guardando referência para o próximo elemento;
        free(p);
        p = t;  //Aqui faz p apontar para o próximo;
    }
}

//Função para buscar um determinado elemento da lista;
Lista* busca(Lista* l, int v){
    Lista* p;
    for(p = l; p != NULL; p = p->proximo){
        if(p->elemento = v){
            return p;
        }
    }
    return NULL; //Se não, então ele retorna nulo (não achou o elemento);
}

//Função de remoção;
Lista* remover(Lista* l, int i){
    Lista* p = busca(l, i);
    if(p == NULL){       //Não encontrou o elemento;
        return l;
    }
    if(l == p){
        l = p->proximo;
    }else{
        p->anterior->proximo = p->proximo;
    }
    if(p->proximo != NULL){
        p->proximo->anterior = p->anterior;
        free(p);
        return l;
    }
}

int main(){

}