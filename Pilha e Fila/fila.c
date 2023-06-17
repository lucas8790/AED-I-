#include <stdio.h>
#define N 50

typedef struct fila{
    int elemento;
    int inicio;
    float vetor[N];
}Fila;

//Função de inicialização de uma fila;
Fila* inicializar(void){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->elemento = 0;
    f->inicio = 0;
    return f;
}

//Função de inserir;
void inserir(Fila* f, float valor){
    int final;
    if(f->elemento == N){
        printf("\nPilha sem espaço.\n");
        exit(1);
    }
    final = (f->inicio + f->elemento) % N; //Cálculo do índice do último elemento;
    f->vetor[final] = valor;
    f->elemento ++;
}

//Função de remoção;
void remover(Fila* f, float valor){
    if(f->elemento == NULL){
        printf("Pilha já está vazia.\n");
        exit(1);
    }
    valor = f->vetor[f->inicio];
    f->inicio = (f->inicio + 1) % N;
    f->elemento --;
    return valor;
}


int main(){

}