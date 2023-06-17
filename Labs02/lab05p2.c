#include <stdio.h>
#include <stdlib.h>

//Definir as duas structs, uma para o nó (pedaço) e outra para a lista;
typedef struct no No;
struct no{
    int valor; //Valor guardado pelo nó;
    No* proximo;  //Ponteiro nó apontando para o próximo;
};

typedef struct lista Lista;
struct lista{
    No* inicio; //Ponteiro nó apontando para o inicio e final da lista;
    No* fim;
};

//Função cria lista; Lista* <--- Lista referência o ponteiro;
//Qual a logica para criação de uma lista? 
//Aloca dinamicamente um espaço para lista;
//Em seguida aponta Lista inicio é igual a nulo, e lista final também;
//Logo a lista está vazia e pronta para ser criada.
Lista* criaLista(){
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

//Função para adicionar o nódulo;
//Aloca dinamicamente um espaço para o nodulo;
//Guarda um valor no nódulo e coloca o proximo nodulo para receber nulo;
//SE, no final da lista não conter nada, então o lista inicio recebe nodulo;
//SE NÃO, o lista fim proximo recebe o nó; 
void adicionaNo(Lista* lista, int valor) {
    No* no = (No*) malloc(sizeof(No));
    no->valor = valor;
    no->proximo = NULL;
    
    if (lista->fim == NULL) {
        lista->inicio = no;
    } else {
        lista->fim->proximo = no;
    }
    lista->fim = no;
}

//Função para imprimir a lista;
//O ponteiro que referência nó recebe nó como lista inicio;
//Então enquanto o inicio da lista não for vazia, ele digita e guarda no valor e coloca o nó para proximo;
void imprimirLista(Lista* lista){
    No* no = lista->inicio;
    while(no != NULL){
        printf("%d", no->valor);
        no = no->proximo;
    }
    printf("\n");
}

//Função (Concatena);
//Usa a função cria lista para criar a lista que sera a concatenada;
//O nódulo 1, vai receber lista 1 inicio;
//Enquanto o no1 for diferente de nulo ou seja não for vazia, ele usa a função de adicionar o nó e no1 recebe proximo;
//Repete a ação acima agora com a lista 2 e o nódulo 2;
Lista* concatena(Lista* l1, Lista* l2) {
    Lista* l = criaLista();

    No* no1 = l1->inicio;
    while (no1 != NULL) {
        adicionaNo(l, no1->valor);
        no1 = no1->proximo;
    }
    No* no2 = l2->inicio;
    while (no2 != NULL) {
        adicionaNo(l, no2->valor);
        no2 = no2->proximo;
    }
    return l;
}

//Função principal (main);
//Criação do menu para o usuario falar quantos valores ele quer adicionar na lista e assim concatenala;
//Criação da lista 1 e 2 ;
//Chamar a função concatena e logo em seguida a função imprimir;
int main(){
    int i, qtd, num;
    
    printf("Digite a quantidade de numeros que serao adicionados na a lista 1.\n");
    scanf("%d", &qtd);

    Lista* l1 = criaLista();
    for(i = 0; i < qtd; i++){
        printf("Digite os numeros para a lista 1.\n");
        scanf("%d", &num);
        adicionaNo(l1, num);
    }
    printf("\n");

    printf("Digitar a quantidade de numeros que serao adicionados na lista 2.\n");
    scanf("%d", &qtd);

    Lista*l2 = criaLista();
    for(i = 0; i < qtd; i++){
        printf("Digite os numeros para a lista 2.\n");
        scanf("%d", &num);
        adicionaNo(l2, num);
    }
    
    Lista* l = concatena(l1, l2);
    printf("Lista concatenada: ");
    imprimirLista(l);

    return 0;
}