#include <stdio.h>
#include <stdlib.h>

void soma(int n, int **matriz1, int **matriz2){
    int i, j;
    int matriz_soma[n][n];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matriz_soma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    printf("\n Soma das Matrizes:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz_soma[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, i, j;
    scanf("%d", &n);
    int **mat1, **mat2;

    mat1 = malloc(n*sizeof(int*));
    mat2 = malloc(n*sizeof(int*));
    for (i = 0; i < n; i++) {
        mat1[i] = malloc(n*sizeof(int));
        mat2[i] = malloc(n*sizeof(int));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("1 - Digite o valor da linha => %d coluna => %d\n", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("2 - Digite o valor da linha => %d coluna => %d\n", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    printf("Matriz 1:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }

    printf("Matriz 2:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }

    soma(n, mat1, mat2);

    return 0;
}
