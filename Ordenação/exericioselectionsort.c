#include <stdio.h>

typedef struct{
    int id;
    float altura;
    int idade;
}Aluno;

//Adicionar os alunos no vetor
void printAlunos(Aluno alunos[], int n){
    printf("Alunos:\n");
    for(int i = 0; i < n; i++){
        printf("Id: %d, Altura: %.2f, Idade: %d\n", alunos[i].id, alunos[i].altura, alunos[i].idade);
    }
    printf("\n");
}

//Função do SelectionSort (Ordenando no criterio de altura)
void SelectionSort(Aluno alunos[], int n){
    for(int i = 0; i < n - 1; i++){
        int menor = i;
        for(int j = i +1; j < n; j++){
            if(alunos[j].altura < alunos[menor].altura){
                menor = j;
            }
        }
        if(i != menor){
            Aluno temp = alunos[i];
            alunos[i] = alunos[menor];
            alunos[menor] = temp;
        }
    }
}

int main(){
    Aluno alunos[10];
    for(int i = 0; i < 10; i++){
        printf("Informe os dados do aluno %d:\n", i+1);
        printf("Id: ");
        scanf("%d", &alunos[i].id);
        printf("Altura: ");
        scanf("%f", &alunos[i].altura);
        printf("Idade: ");
        scanf("%d", &alunos[i].idade);
    }
    
    SelectionSort(alunos, 10);
    printAlunos(alunos, 10);

    return 0;
}