#include <stdio.h>

int main(){
    int a, b, c, aux = 0;
    scanf("%d%d%d", &a, &b, &c);

    //B o maior ''1 3 2''
    if(b > a && a > c){
        aux = a;
        a = c;
        c = b;
        b = aux;
    }
    //A o maior
    else if(a > c && c > b){
        aux = c;
        c = a;
        a = b;
        b = aux;
    }
    //A o maior
    else if(a > b && b > c){
        aux = c;
        c = a;
        a = aux;
    }
    printf("%d %d %d", a, b, c);
    return 0;
}

