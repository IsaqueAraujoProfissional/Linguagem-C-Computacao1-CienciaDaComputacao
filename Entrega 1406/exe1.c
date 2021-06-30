#include <stdarg.h>
#include <stdio.h>
double media_ponderada(int qtd_notas,...)
{
    va_list ap;
    double mediaP = 0;
    int pesos = 0;
    int i;
    int peso = 0;
    float nota = 0;
    va_start(ap, qtd_notas);
    for(i=0; i<qtd_notas; i++){
        peso = va_arg(ap, int);
        nota = va_arg(ap, double);
        mediaP+=peso*nota;
        pesos+=peso;
    }
    mediaP = mediaP/pesos;
    va_end(ap);
    return mediaP;
} 
int main(){
    printf("media: %lf", media_ponderada(3,4,8.0,4,9.5,2,7.0)); 
    printf("media: %lf", media_ponderada(2,5,10.0,5,5.0));
    return 0;
}
