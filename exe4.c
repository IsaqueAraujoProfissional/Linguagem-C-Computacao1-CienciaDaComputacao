#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int LIN, COL, n, m;
    scanf("%d %d %d %d", &LIN, &COL, &n, &m);
    int * matriz1 = (int *) malloc (LIN * COL * sizeof (int)), i, j;
    int inicio = 0, fim = 0;
    int soma = 0;
    int maiorS = soma;
    if (!matriz1)
    {
        printf ("Erro de alocacao de memoria\n");
        return -1;
    }
    for (i=0; i<LIN; i++){
        for (j=0; j<COL; j++)
        {
            printf("Matriz[%d][%d]: ", i, j);
            scanf ("%d", matriz1 + ((i * COL) + j));
        }
    }
    int trocou = 0;
    for (i=0; i<(LIN*COL)/(n*m); i++)
    {
        soma = 0;
        for (j = inicio; j < n+inicio; j++){
            for(int k = fim; k < m+fim; k++){
                soma+= *(matriz1 + ((j * COL) + k));
                //printf ("[%d] ", *(matriz1 + ((j * COL) + k)));
            }
        }
        if(soma > maiorS)
            maiorS = soma;
        if(i < (LIN*COL)/(n*m)/2-1)
            fim+=m;
        else{
            if(n > m){
                inicio = n;
                 if(trocou == 0){
                    fim = 0;
                trocou++;
            }
            else
                fim+=m;
            }
            else if(n == m){
                printf("aqui\n");
                inicio = n;
            if(trocou == 0){
                fim = 0;
                trocou++;
            }
            else
                fim+=m;
            }
        else{
              inicio = n+1;
            if(trocou == 0){
                fim = 0;
                trocou++;
            }
            else
                fim+=m;
        }
        }     
    }
    free(matriz1);
    printf("%d\n", maiorS);
    return 0;
}
