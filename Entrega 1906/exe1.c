#include <stdio.h>
#include <stdlib.h>
typedef struct{
 int horaM, minutosM;   
} HoraD;
void fHora(int minutos, HoraD *horaD){
    horaD->horaM = minutos/60;
    horaD->minutosM = minutos-horaD->horaM*60;
    printf("%d:%d\n", horaD->horaM, horaD->minutosM);
}
int main(){
    int minutosP;
    scanf("%d", &minutosP);
    HoraD horad;
    fHora(minutosP, &horad);
    return 0;
}
