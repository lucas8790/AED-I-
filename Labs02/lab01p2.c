#include <stdio.h>
#include <stdlib.h>

struct lista {
    int valor;
    struct lista* prox;
};
typedef struct lista lista;

void inserir(lista** item, int v) {
    lista* novo_item = (lista*) malloc(sizeof(lista));
    novo_item->valor = v;
    novo_item->prox = NULL;

    if (*item == NULL || (*item)->valor >= v) {
        novo_item->prox = *item;
        *item = novo_item;
    } else {
        lista* item_atual = *item;
        while (item_atual->prox != NULL && item_atual->prox->valor < v) {
            item_atual = item_atual->prox;
        }
        novo_item->prox = item_atual->prox;
        item_atual->prox = novo_item;
    }
}

void print(lista* i) {
    lista* item_atual = i;
    while (item_atual != NULL) {
        printf("%d ", item_atual->valor);
        item_atual = item_atual->prox;
    }
    printf("\n");
}

int main() {
    lista* lista = NULL;
    int valor, qnt, i;

    printf("Digite quantos valores serão inserido na lista: ");
    scanf("%d", &qnt);

    for (i = 0; i < qnt; i++) {
        printf("Digite o %dº valor: ", i + 1);
        scanf("%d", &valor);
        inserir(&lista, valor);
    }

    printf("Lista dos elementos: ");
    print(lista);

    return 0;
}
