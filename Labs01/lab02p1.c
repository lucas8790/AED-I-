#include <stdio.h>

int main(){
    int a, b, c, aux = 0;
    scanf("%d%d%d", &a, &b, &c);

    if(b > a && a > c){
        aux = a;
        a = c;
        c = b;
        b = aux;
    }
    else if(a > c && c > b){
        aux = c;
        c = a;
        a = b;
        b = aux;
    }
    else if(a > b && b > c){
        aux = c;
        c = a;
        a = aux;
    }
    printf("Maior: %d \n", c);
    printf("Menor: %d \n", a);

    int vetor[3], i;
    vetor[0] = a;
    vetor[1] = b;
    vetor[2] = c;

    for(i = 0;i < 3;i++){
        if(vetor[i] >= 0){
            printf("Positivo: %d \n", vetor[i]);
        }else{
            printf("Negativo: %d \n", vetor[i]);
        }
        if(vetor[i]%2 == 0 || vetor[i] == 0){
            printf("Par: %d \n", vetor[i]);
        }else{
            printf("Ímpar: %d \n", vetor[i]);
        }
    }
    return 0;
}

