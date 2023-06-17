#include <stdio.h>

struct livro {
    int cod;
    int qtd_pag;
    float valor;
};
typedef struct livro Livro;

void desconto(Livro l){
    float resultado;
    resultado = l.valor - (l.valor * 0.2);

    printf("Código do Livro: %d\n", l.cod);
    printf("Quantidade de Página: %d\n", l.qtd_pag);
    printf("Valor do Livro com Desconto: %.2f\n", resultado);
}

int main()
{
    Livro l;
    scanf("%d", &l.cod);
    scanf("%d", &l.qtd_pag);
    scanf("%f", &l.valor);

    printf("Código do Livro: %d\n", l.cod);
    printf("Quantidade de Página: %d\n", l.qtd_pag);
    printf("Valor do Livro: %.2f\n\n", l.valor);

    desconto(l);
    return 0;
}
