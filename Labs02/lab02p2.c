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
    No *topo;
} Professor;

Professor professores[max_professor];

//Cadastra aluno na turma
void cadastrar_aluno(Professor *professor, int id, char *nome, int idade) {
    No *novo_no = (No *) malloc(sizeof(No));
    novo_no->info.id = id;
    strcpy(novo_no->info.nome, nome);
    novo_no->info.idade = idade;
    novo_no->prox = NULL;

    novo_no->prox = professor->topo;
    professor->topo = novo_no;
}

//Remover aluno no topo da pilha do professor
void remover_aluno(Professor *professor) {
    if (professor->topo == NULL) {
        printf("A pilha do professor %s está vazia.\n", professor->nome);
    } else {
        No *aux = professor->topo;
        professor->topo = aux->prox;
        free(aux);
    }
}

//Cadastrar professor
void cadastrar_professor(char *nome) {
    int i;
    for (i = 0; i < max_professor; i++) {
        if (strlen(professores[i].nome) == 0) {
            strcpy(professores[i].nome, nome);
            professores[i].topo = NULL;
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
