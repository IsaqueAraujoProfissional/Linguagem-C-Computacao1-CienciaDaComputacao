#include <stdio.h>
//Inicia os valores da matriz
void inicM(int x , int s[x][x])
{
    int i, j;
    for (i = 0; i < x; i++)
        for (j = 0; j < x; j++){
            printf("Digite o elemento[%d][%d]: ", i , j);
            scanf("%d", &s[i][j]);
        }
}
//Retorna a transposta
void transpostaM(int i, int resultado[i][i], int s[i][i]) {
	int k, p;
	for (k = 0; k < i; k++) 
		for (p = 0; p < i; p++) 
			resultado[k][p] = s[p][k];
}
//Retorna a oposta
void opostaM(int i, int resultado[i][i], int matriz[i][i]){
    for(int k = 0; k < i ;k++)
        for(int p = 0; p < i; p++)
            resultado[k][p] = -1*matriz[k][p];
}
//Soma de matrizes
void somaM(int i, int resultado[i][i], int s[i][i], int s2[i][i]){
    for(int k = 0; k < i ;k++)
        for(int p = 0; p < i; p++)
            resultado[k][p] = s[k][p]+s2[k][p];
}
//Subtracao de matrizes
void subtracaoM(int i, int resultado[i][i], int s[i][i], int s2[i][i]){
    for(int k = 0; k < i ;k++)
        for(int p = 0; p < i; p++)
            resultado[k][p] = s[k][p]-s2[k][p];
}
//Multiplicacao de matrizes
void multiplicaoM(int i, int resultado[i][i],int s[i][i],int s2[i][i]){
    int sum = 0;
    for (int p = 0; p<i; p++) {
        for (int n =0; n<i;n++){
            sum=0;
            for(int k = 0; k<i; k++){
                sum+=(s[p][k]*s2[k][n]);
                resultado[p][n] = sum;
            }
            
        }
    }
}
//Multiplicao por escalar
void escalarM(int i, int resultado[i][i], int matriz[i][i], int escalar){
    for(int k = 0; k < i ;k++)
        for(int p = 0; p < i ; p++)
            resultado[k][p] = escalar*matriz[k][p];
}
//Matriz diagonal
int diagonal(int i, int matriz[i][i]){
    int k, p;
    int verificador = 1;
    int diagonalprincipal = 0;
	for (k = 0; k < i; k++){ 
		for (p = 0; p < i; p++){ 
			if(k != p){
                if(matriz[k][p] != 0)
                    verificador = 0;
            }
            else if(k == p)
                diagonalprincipal+=matriz[k][p];
        }
    }
    if(diagonalprincipal == 0)
        verificador = 0;
    if(verificador == 1)
        printf("A matriz e do tipo diagonal\n");
    else
        printf("A matriz nao e do tipo diagonal\n");
    return verificador;
}
//Matriz identidade
int identidade(int i, int matriz[i][i]){
    int k, p;
    int verificador = 1;
    int diagonalprincipal = 0;
	for (k = 0; k < i; k++){ 
		for (p = 0; p < i; p++){ 
			if(k != p){
                if(matriz[k][p] != 0)
                    verificador = 0;
            }
            else if(k == p && matriz[k][p] == 1)
                diagonalprincipal+=1;
        }
    }
    if(diagonalprincipal !=i)
        verificador = 0;
    if(verificador == 1)
        printf("A matriz e do tipo identidade\n");
    else
        printf("A matriz nao e do tipo identidade\n");
    return verificador;
}
//Determinante
int determinanteM(int tipo, int matriz[tipo][tipo]){
    if(tipo == 2)
        return matriz[0][0]*matriz[1][1]-matriz[0][1]*matriz[1][0];
    else{
        int matrizR[3][5];
        int lado1 = 0, lado2 = 0;
        int multiplicatorio = 1;
        for(int i = 0; i < 3; i++){
            int k = 0;
            for(int j = 0; j < 5; j++){
                if(j < 3){
                    matrizR[i][j] = matriz[i][j];
                }else{
                    matrizR[i][j] = matriz[i][k];
                    k++;
                }
            }
        }
        for(int n = 0; n < 3; n++){
            multiplicatorio = 1;
            for(int p = 0; p < 3; p++){
                multiplicatorio = multiplicatorio*matrizR[p][p+n];
            }
            lado1+=multiplicatorio;
        }
        multiplicatorio = 1;
        for(int n = 4; n >= 2; n--){
            multiplicatorio = 1;
            for(int p = 0; p < 3; p++){
                multiplicatorio = multiplicatorio*matrizR[p][n-p];
            }
            lado2+=multiplicatorio;
        }
        return lado1 - lado2;
    }
}
//Mostra a matriz
void mostraM(int x, int s[x][x])
{
    int i,j;
    for (i=0;i<x;i++)
    {
        for (j=0;j<x;j++)
            printf(" [%d] ",s[i][j]);
        printf("\n");
    }
    printf("\n");
}
