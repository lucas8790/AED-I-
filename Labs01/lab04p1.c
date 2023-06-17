#include <stdio.h>

struct pessoa {
    int dia, mes, ano;
    char genero;
    int idade;
};
typedef struct pessoa Pessoa;

//Função para achar a idade:
int idade(int ano) {
    int ano_hoje = 2023;
    return ano_hoje - ano;
}

//Função para a maior idade das N pessoas:
float media_idade_geral(Pessoa *p){
    int i;
    float soma = 0;
    for (i = 0; i < 5; i++){
        soma += p[i].idade;
    }
    return soma/5;
}

//Função para idade media dos homemns e idade media das mulheres:
float media_idade_genero(char genero, Pessoa *p){
    int i, aux = 0;
    float soma = 0;
    for (i = 0; i < 5; i++){
        if(p[i].genero == genero){
            soma += p[i].idade;
            aux++;
        }
    }
    return soma/aux;
}

//Função para alteração de dados
void alter_dados(Pessoa *p){
    p[1].dia = 19;
    p[1].mes = 8;
    p[1].ano = 1997;
    p[1].genero = 'M';
    p[1].idade = idade(p[1].ano);
}


int main()
{
    int n = 5, i;
    Pessoa p[n];
    int dia[] = {1, 2, 3, 4, 5};
    int mes[] = {1, 2, 3, 4, 5};
    int ano[] = {2000, 2001, 2002, 2003, 2004};
    char genero[] = {'F', 'M', 'F', 'M', 'F'};

    for (i = 0; i < 5; i++) {
        p[i].dia = dia[i];
        p[i].mes = mes[i];
        p[i].ano = ano[i];
        p[i].genero = genero[i];

        p[i].idade = idade(ano[i]);

        printf("Pessoa %d -> \n", i + 1);
        printf("Nascimento: %d/%d/%d \n", p[i].dia, p[i].mes, p[i].ano);
        printf("Idade: %d \n", p[i].idade);
        printf("Genero: %c \n \n", p[i].genero);
    }

    printf("Media geral das Idades: %2.f\n", media_idade_geral(p));
    printf("Media das Idades - Feminino: %2.f\n", media_idade_genero('F', p));
    printf("Media das Idades - Masculino: %2.f\n", media_idade_genero('M', p));

    printf("################ Alteração #################");
    alter_dados(p);

    for (i = 0; i < 5; i++) {
        printf("Pessoa %d -> \n", i + 1);
        printf("Nascimento: %d/%d/%d \n", p[i].dia, p[i].mes, p[i].ano);
        printf("Idade: %d \n", p[i].idade);
        printf("Genero: %c \n \n", p[i].genero);
    }

    printf("Media geral das Idades: %2.f\n", media_idade_geral(p));
    printf("Media das Idades - Feminino: %2.f\n", media_idade_genero('F', p));
    printf("Media das Idades - Masculino: %2.f\n", media_idade_genero('M', p));

    return 0;
}
