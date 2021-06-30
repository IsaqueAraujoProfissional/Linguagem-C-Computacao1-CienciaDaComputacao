#include <stdio.h>
#include <string.h>
int main(){
    int Ncalcados;
    scanf("%d", &Ncalcados);
    int NumeroCalcado[Ncalcados];
    char LetraCalcado[Ncalcados];
    int NumeroCalcadoGravado = 0;
    char LetraCalcadoGravado = 'c';
    int pares = 0;
    for(int i = 0; i < Ncalcados; i++){
        scanf("%d %c", &NumeroCalcado[i], &LetraCalcado[i]);
    }
    for(int j = 0; j < Ncalcados; j++){
        NumeroCalcadoGravado = NumeroCalcado[j];
        LetraCalcadoGravado = LetraCalcado[j];
        for(int k = 0; k < Ncalcados; k++){
            if(NumeroCalcadoGravado == NumeroCalcado[k] && LetraCalcadoGravado != LetraCalcado[k]){
                pares++;
                NumeroCalcado[k] = 0;
                LetraCalcado[k] = 'c';
                break;
            }
        }
    }
    printf("%d\n", pares);
}
int palindrimo(){
    int letras;
    scanf("%d", &letras);
    getchar();
    char palavra[letras+1];
    scanf("%s", palavra);
    char c = 'S';
    for(int i = 0;  i < letras/2; i++){
        if(palavra[i] != palavra[strlen(palavra)-i-1]){
            c = 'N';
            break;
        }
    }
    if(c == 'N'){
        
    }
    return 0;
}
int jogo(){
    int N, D, A;
    scanf("%d", &N);
    scanf("%d", &D);
    scanf("%d", &A);
    int distancia = 0;
    if(A < D){
        distancia = D - A;
    }else{
        distancia = D-A+N;
    }
    printf("%d\n", distancia);
    return 0;
}
