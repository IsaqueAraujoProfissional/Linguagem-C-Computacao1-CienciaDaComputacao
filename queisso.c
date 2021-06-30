#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MIN(a, b) ((a) < (b) ?  (a) : (b))
#define MAX(a, b) ((a) > (b) ?  (a) : (b))
#define ABS(a)  ((a) <  0  ? -(a) : (a))
#define IMPAR(a) ((a)&1)
#define CTOI(a)  ((a) - '0')
#define ITOC(a)  ((a) + '0')

#define TRUE 1
#define FALSE 0
int lingua();
int aliteracao();
int aliteracao2();
int mensagem();
int bloggo();
int main()
{
    aliteracao2();
 return 0;
}
int lingua(){
    int casos, pessoas;
    char lingua[1001];
    char linguaauxiliar[1001];
    scanf("%d", &casos);
    for(int i = 0; i < casos; i++){
        scanf("%d", &pessoas);
        int idiomadiferente = 0;
        for(int j = 0; j < pessoas; j++){
            strcpy(linguaauxiliar, lingua);
            scanf("%s", lingua);
            if(j > 0){
                if(strcmp(lingua, linguaauxiliar) == 0){
                    idiomadiferente = 0;
                }else{
                    idiomadiferente = 1;
            }
            }
        }
        if(idiomadiferente == 1){
            printf("ingles\n");
        }else{
            printf("%s\n", lingua);
        }
    }
    return 0;
}
int aliteracao(){
    char expressao[100][51];
    int quant = 0,  i = 0, j = 0;
    char palavra[51];
    int auxiliar = 1;
    while(scanf("%s", expressao[0])!= EOF){
        for(i = 0; i < 8; i++){
            scanf("%s", expressao[i]);
        }
        auxiliar = 1;
        quant = 0;
    for(j = 0; j < 8; j++){
        if(j > 0){
            if(tolower(expressao[j][0]) != tolower(palavra[0])){
                auxiliar = 1;
            }
            else if(tolower(expressao[j][0]) == tolower(palavra[0]) && auxiliar == 1){
                quant += 1;
                auxiliar = 0; 
            }
        }
        strcpy(palavra, expressao[j]);
    }
    printf("%d", quant);
    }
    return 0;
}
int aliteracao2(){
    char frase[10000];
    char auxiliar;
    int pegou = 0;
    int quant = 0;
    gets(frase);
    while(strcmp(frase, "") != 0){
        pegou = 0;
        quant = 0;
        for(int i = 0; i < strlen(frase) -1; i++){
            if(i > 1){
                if(tolower(frase[i-1]) == ' ' && tolower(frase[i]) == auxiliar && pegou == 0){
                    quant++;
                    pegou = 1;
                }
                if(frase[i-1] == ' ' && auxiliar != tolower(frase[i])){
                    auxiliar = tolower(frase[i]);
                    pegou = 0;
                }
            }
            if(i == 0){
                auxiliar = tolower(frase[i]);
            }
        }
        printf("%d\n", quant);
        gets(frase);
    }
    return 0;
}
int mensagem(){
    char palavra[1001];
    int casos, i;
    scanf("%d", &casos);
    for(i = 0; i < casos; i++){
        scanf("%s", palavra);
        for(int j = strlen(palavra)-1; j >=0; j--){
            if(!isupper(palavra[j])){
                printf("%c", palavra[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
int bloggo(){
    char texto[51];
    char textohtml[51];
    gets(texto);
    int posicao = 0;
    int j = 0;
    for(int i = 0; i < strlen(texto)-1; i++){
        if(texto[i] == '*'){
            if(posicao == 0){
                strcat(textohtml, "abc");
                posicao = 1;
                j+=2;
            }
            if(posicao == 1){
                strcat(textohtml, "abcd");
                j+=3;
                posicao = 0;
            }
        }else {
            textohtml[j] = texto[i];
        }
        j+=1;
        
    }
    puts(textohtml);
    return 0;
}
int exe1(){
    int i, p;
    char expressao[1001];
    while(scanf(" %s", expressao) != EOF){
        if(expressao[0] == ')' || expressao[strlen(expressao) - 1] == '(')
            p = 1;
        else{
            p = 0;
            for(i = 0; expressao[i] != '\0'; i++)
                if(expressao[i] == '(')
                    p++;
                else if(expressao[i] == ')')
                    p--;
        }
        if(!p)
            printf("correct\n");
        else
            printf("incorrect\n");
    }
 return 0;
}
