#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_professor 5

typedef struct {
    int id;
    char nome[50];
    int idade;
} Aluno;

typedef struct no {
    Aluno info;
    struct no *prox;
} No;

typedef struct {
    char nome[50];
    No *inicio; // aponta para o início da fila
    No *fim; // aponta para o fim da fila
} Professor;

Professor professores[max_professor];

//Cadastra aluno na turma
void cadastrar_aluno(Professor *professor, int id, char *nome, int idade) {
    No *novo_no = (No *) malloc(sizeof(No));
    novo_no->info.id = id;
    strcpy(novo_no->info.nome, nome);
    novo_no->info.idade = idade;
    novo_no->prox = NULL;

    // insere o novo nó no fim da fila
    if (professor->inicio == NULL) { // fila vazia
        professor->inicio = novo_no;
    } else {
        professor->fim->prox = novo_no;
    }
    professor->fim = novo_no;
}

//Remover aluno no início da fila do professor
void remover_aluno(Professor *professor) {
    if (professor->inicio == NULL) {
        printf("A fila do professor %s está vazia.\n", professor->nome);
    } else {
        No *aux = professor->inicio;
        professor->inicio = aux->prox;
        if (professor->inicio == NULL) { // fila ficou vazia
            professor->fim = NULL;
        }
        free(aux);
    }
}

//Cadastrar professor
void cadastrar_professor(char *nome) {
    int i;
    for (i = 0; i < max_professor; i++) {
        if (strlen(professores[i].nome) == 0) {
            strcpy(professores[i].nome, nome);
            professores[i].inicio = NULL;
            professores[i].fim = NULL;
            break;
        }
    }
    if (i == max_professor) {
        printf("Não é possível cadastrar professores.\n");
    }
}

int main() {
    cadastrar_professor("Lucas");
    cadastrar_aluno(&professores[0], 1, "Iasmin", 20);
    cadastrar_aluno(&professores[0], 2, "Miguel", 19);
    cadastrar_aluno(&professores[0], 3, "Julia", 18);
    remover_aluno(&professores[0]);
    cadastrar_aluno(&professores[0], 4, "Sara", 21);
    return 0;
}
