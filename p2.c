#include <stdio.h>
#include <string.h>
#define MAX 100
void cripto1(char *palavra){
    int tam = strlen(palavra);
    for(int i = 0; i < tam; i++){
        *palavra+=3;
        palavra++;
    }
}
void cripto2(char palavra[MAX]){
    int tam = strlen(palavra);
    char invertida[MAX];
    for(int i =0; i < tam; i++){
        invertida[i] = palavra[tam-i-1];
    }
    invertida[tam] = '\0';
    strcpy(palavra, invertida);
}
void cripto3(char *palavra){
    int tam = strlen(palavra);
    for(int i = tam/2; i < tam; i++){
        *(palavra+i)-=1;
    }
}
int contador(char *palavra, char c){
    int tam = strlen(palavra);
    int count =0 ;
    for(int i = 0; i < tam; i++){
        if(*(palavra+i) == c)
            count++;
    }
    return count;
}
typedef struct{
    char c;
    double media_sem_cripto;
    double media_com_cripto;
} Tsaida;
int main(int argc, char *argv[]){
    if(argc != 3)
        return -1;
    FILE *arqL;
    FILE *arqG;
    arqL = fopen(argv[1], "r");
    if(arqL == NULL)
        return - 1;
    arqG = fopen(argv[2], "w");
    if(arqG == NULL)
        return -1;
    Tsaida saida;
    saida.media_sem_cripto = 0.0;
    saida.media_com_cripto = 0.0;
    char palavra[MAX];
    int N;
    fscanf(arqL, "%d %c\n", &N, &saida.c);
    for(int i = 0; i < N; i++){
        fscanf(arqL, "%s\n", palavra);
        saida.media_sem_cripto+=contador(palavra, saida.c);
        cripto1(palavra);
        cripto2(palavra);
        cripto3(palavra);
        saida.media_com_cripto+=contador(palavra, saida.c);
        fprintf(arqG, "%s\n", palavra);
    }
    fclose(arqL);
    fclose(arqG);
    saida.media_sem_cripto/=N;
    saida.media_com_cripto/=N;
    printf("Caracter: %c\n", saida.c);
    printf("Media sem criptografia: %.2lf\n", saida.media_sem_cripto);
    printf("Media com criptografia: %.2lf\n", saida.media_com_cripto);
    return 0;
}
