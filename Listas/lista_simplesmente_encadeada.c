#include <stdio.h>

//Criação da struct, dentro dela haverá um ponteiro para o ''nó'' apontando para o próximo;
typedef struct no{
    int valor;
    struct no *proximo;
}No;

//Criação da struct lista, com uma variavel de info e apontando para a próxima;
typedef struct lista{
    int elemento;
    struct lista *proximo;
}Lista;

//Função de inicialização: retorna uma lista vazia;
Lista* inicializa (void){
    return NULL;
}

//Função de inserir na lista e retornar atualizada;
Lista* insere(Lista* l, int i){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->elemento = i;
    novo->proximo = l;
    printf("\nInserido.\n");
    return novo;
}

//Função para imprimir todos os elementos da lista;
void imprimir(Lista* l){
    Lista* p;         // --> Variável aux;
    for(p = l; p !=NULL; p = p->proximo){
        printf("%d ",p->elemento);
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

//Função de esvaziar a lista (liberar);
void libera(Lista* l){
    Lista* p = l;
    while(p != NULL){
        Lista* t = p->proximo; //Está guardando referência para o próximo elemento;
        free(p);
        p = t;  //Aqui faz ''p'' apontar para o próximo;
    }
}

int main(){

}