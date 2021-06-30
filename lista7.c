#include <stdio.h>
#include <stdbool.h>
int main(){
    
}
int Matriz1(){
    int coluna;
    char operacao;
    scanf("%d %c", &coluna, &operacao);
    double matriz[12][12];
    double soma = 0, media = 0;
    int linhas = 0 ;
    int j;
    int i;
    for(i = 0; i < 12; i++){
        j = 0;
        while(j < 12){
            scanf ("%lf", &matriz[i][j]);
            if(j == coluna){
                soma+=matriz[i][j];
                linhas+=1;
            }
            j++;
        }
    }
    if(operacao == 'S')
    {
        printf("%.1lf\n", soma);
    }else if(operacao == 'M'){
        media = soma/linhas;
        printf("%.1lf\n", media);
    }
    return 0;
}
int Matriz2(){
    char operacao;
    scanf("%c", &operacao);
    double matriz[12][12];
    double soma = 0, media = 0;
    int j;
    int i;
    int somados = 0;
    int p = 1;
    int u = 11;
    for(i = 0; i < 12; i++){
        j = 0;
        while(j < 12){
            scanf ("%lf", &matriz[i][j]);
            if(i < 5){
                if(j >= p && j < u){
                    soma+=matriz[i][j];
                    somados+=1;
                }
            }
            j++;
        }
        p+=1;
        u-=1;
    }
    if(operacao == 'S'){
        printf("%.1lf\n", soma);
    }else if(operacao == 'M'){
        media = soma/somados;
        printf("%.1lf\n", media);
    }
    return 0;
}
int solutioncopiedMatriz3(){
    int x, y, elemento, cont, index = -1;
    int i, j;
    bool ok = true, pri_esq;
    scanf("%d %d", &x, &y);
    for(i = 0; i < x; i++){
        pri_esq = true;
        cont = 0;
        for(j = 0; j < y; j++){
            scanf("%d", &elemento);
            if(elemento == 0 && pri_esq)
                cont++;
            else
                pri_esq = false;
        }
        if(cont <= index && cont < y)
            ok = false;
        index = cont;
    }
    if(ok)
        printf("S\n");
    else
        printf("N\n");
    return 0;
}
int matrix4(){
    int x, y;
    int i = 0;
    int j = 0;
    int pao = 0;
    int k = 0;
    int cima = 0, baixo = 0, esquerdo = 0, direito = 0;
    while(scanf("%d %d", &x, &y) != EOF){
        int matriz[x][y];
        int matriz2[x][y];
    for(i = 0; i < x; i++){
        j = 0;
        while(j < y){
            scanf ("%d", &matriz[i][j]);
            j++;
        }
    }
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            if(matriz[i][j] == 1){
                matriz2[i][j] = 9;
            }else if(matriz[i][j] == 0){
                pao = 0;
                k = 0;
                cima = 0 ;
                baixo = 0;
                direito = 0;
                esquerdo = 0;
                while(k < 4){
                    if(matriz[i-1][j] == 1 && cima == 0 && i > 0){
                        pao+=1;
                        cima = 1;
                    }
                    if(matriz[i+1][j] == 1 && baixo == 0 && i < x-1){
                        pao+=1;
                        baixo = 1;
                    }
                    if(matriz[i][j+1] == 1 && direito == 0 && j < y-1){
                        pao+=1;
                        direito = 1;
                    }
                    if(matriz[i][j-1] == 1 && esquerdo == 0 && j > 0){
                        pao+=1;
                        esquerdo = 1;
                    }
                    k++;
                }
                matriz2[i][j] = pao;
            }
            printf("%d", matriz2[i][j]);
        }
        printf("\n");
    }
    }
    return 0;
}
int finalMatriz3(){
    //Com 5% de erro
    int i = 0;
    int j;
    int x, y;
    scanf("%d %d", &x, &y);
    int matriz[x][y];
    int posicao = 0;
    int verifica = 0;
    int k = 0;
    int contador;
    int temzero = 0;
    int contadorAux = 0;
    for(i = 0; i < x; i++){
        j = 0;
        while(j < y){
            scanf ("%d", &matriz[i][j]);
            j++;
        }
    }
    for(j = 0; j < y; j++){
        for(i = 0; i < x; i++){
            if(matriz[i][j] == 0 && k == 0){
                posicao = i;
                k = 1;
                temzero+=1;
            }
            if(matriz[i][j] != 0 && i > posicao && k == 1 && temzero <= i){
                verifica = 1;
            }
            if(j > 0){
                if(matriz[i][j] !=0 && i == contador+temzero){
                    verifica = 1;
                }
            }
        }
        contador = posicao;
        k = 0;
    }
    for(j = 0; j < 1; j++){
        for(i = 0; i < x; i++){
            if(matriz[i][j] != 0){
                contadorAux +=1;
            }
        }
    }
    if(contadorAux == x){
        verifica = 1;
    }
    if(verifica == 0){
        printf("S\n");
    }else{
        printf("N\n");
    }
    return 0;
}
