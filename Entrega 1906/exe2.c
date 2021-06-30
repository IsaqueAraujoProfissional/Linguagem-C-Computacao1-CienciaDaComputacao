#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int *i, j;
    float *notas;
    char *nome;
    //Letra A
    i = (int *)malloc(2*sizeof(int));
    *i = 10;
    printf("%d\n", *i);
    *i = 20;
    printf("%d\n", *i);
    j = 10;
    *i = j;
    printf("%d\n", *i);
    free(i);
    //Letra B
    notas = (float *)calloc(5, sizeof(float));
    int k = 0;
    while (k < 5){
        scanf("%f", notas+k);
        k++;
    }
    for(int p = 0; p  < 5; p++){
        printf("%.1f\n", *(notas+p));
    }
    free(notas);
    //Letra C
    nome = (char *)malloc(51*sizeof(char));
    int n = 0;
    fgets(nome, 51, stdin);
    while(nome[n] != '\0'){
        if(n == 0 || nome[n-1] == ' ')
            nome[n] = toupper(nome[n]);
        printf("%c", nome[n]);
        n++;
    }
    printf("\n");
    free(nome);
    return 0;
}
