#include <stdio.h>
#include <string.h>
#include <math.h>
#define total 20
typedef struct coordenadas{
    int x1, y1, x2, y2;
} tPonto;
tPonto origem(tPonto origem){
    puts("Digite x1 e y1: ");
    scanf("%d %d", &origem.x1, &origem.y1);
    return origem;
}
tPonto pontofinal(tPonto final){
    puts("Digite x2 e y2: ");
    scanf("%d %d", &final.x2, &final.y2);
    return final;
}
void escreveOrige(tPonto origem){
    printf("x1 = %d e y1 = %d\n", origem.x1, origem.y1);
}
tPonto alteraX1(tPonto alteraX1){
    puts("Digite o novo valor de x1: ");
    scanf("%d", &alteraX1.x1);
    return alteraX1;
}
tPonto alteraY1(tPonto alteraY1){
    puts("Digite o novo valor de y1: ");
    scanf("%d", &alteraY1.y1);
    return alteraY1;
}
tPonto alteraX2(tPonto alteraX2){
    puts("Digite o novo valor de x2: ");
    scanf("%d", &alteraX2.x2);
    return alteraX2;
}
tPonto alteraY2(tPonto alteraY2){
    puts("Digite o novo valor de y2: ");
    scanf("%d", &alteraY2.y2);
    return alteraY2;
}
void escreveTudo(tPonto tudo){
    printf("x1 = %d y1 = %d x2 = %d y2 = %d\n", tudo.x1, tudo.y1, tudo.x2, tudo.y2);
}
void calculoD(tPonto calculoD){
    puts("O valor da distancia entre os pontos eh: ");
    double  distancia = 0;
    distancia = sqrt(pow((calculoD.x2 - calculoD.x1), 2)+pow((calculoD.y2 - calculoD.y1), 2));
    printf("%.3lf\n", distancia);
}
int main(){
    tPonto coordenadas;
    coordenadas = origem(coordenadas);
    escreveOrige(coordenadas);
    coordenadas = pontofinal(coordenadas);
    escreveTudo(coordenadas);
    calculoD(coordenadas);
    return 0 ;
}
int funcaotime(){
    typedef struct estrutura_time{
        char nome[51];
        int pontos;
    } Times;
    Times times[total];
    int PontosMaior = 0;
    int PontosMenor = 0;
    char Vencedor[51];
    char Perdedor[51];
    for(int i = 0; i < total; i++){
        printf("Escreva o nome do time: ");
        gets(times[i].nome);
        printf("\nDigite a quantidade de pontos desse time: ");
        scanf("%d", &times[i].pontos);
        getchar();
        if(i == 0){
           PontosMenor = times[i].pontos;
           PontosMaior = times[i].pontos;
        }else{
            if(times[i].pontos > PontosMaior){
                PontosMaior = times[i].pontos;
                strcpy(Vencedor, times[i].nome);
            }
            if(times[i].pontos < PontosMenor){
                PontosMenor = times[i].pontos;
                strcpy(Perdedor, times[i].nome);
            }
        }
        printf("\n");
    }
    printf("Campeão: %s\n", Vencedor);
    printf("Perdedor: %s\n", Perdedor);
    return 0;
}
