#include <stdio.h>
int mdc(int a, int b){
    if(a%b == 0){
        return b;
    }
    return mdc(b, a%b);
}
void inverte(){
    char c = getchar();
    if(c == '\n')
        return;
    inverte();
    printf("%c", c);
}
void inverteV(int vetor[], int esq, int dir){
    if(esq >= dir)
        return;
    int aux = vetor[esq];
    vetor[esq] = vetor[dir];
    vetor[dir] = aux;
    inverteV(vetor, esq+1, dir-1);
}
void Fibonacci(int anterior, int posterior, int numeros, int v[], int inicial){
    if(numeros == 0)
        return;
    printf("%d ", anterior);
    v[inicial] = anterior;
    int aux = anterior;
    anterior = posterior;
    posterior = aux+posterior;
    Fibonacci(anterior, posterior, numeros-1, v, inicial+1);
    
}
int main(){
    //printf("%d\n", mdc(48,30));
    //inverte();
    /*int v[] = {1,2,3,4,5};
    inverteV(v, 0, 4);
    for(int i = 0; i < 5; i++){
        printf("%d ", v[i]);
    }
    printf("\n");*/
    int v[15];
    Fibonacci(1, 1, 15, v, 0);
    printf("\n");
    for(int i = 0; i < 15; i++){
        printf("%d\n", v[i]);
    }
    printf("\n");
    return 0;
}
