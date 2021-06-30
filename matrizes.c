#include <stdio.h>
#define DIM 3
//Inicia os valores da matriz
void inicM(int x , int y, int s[x][y])
{
    int i, j;
    for (i = 0; i < x; i++)
        for (j = 0; j < y; j++){
            printf("Digite o elemento[%d][%d]: ", i , j);
            scanf("%d", &s[i][j]);
        }
}
//Retorna a transposta
void transposta(int i, int j, int resultado[i][j], int s[j][i]) {
	int k, p;
	for (k = 0; k < i; k++) 
		for (p = 0; p < j; p++) 
			resultado[k][p] = s[p][k];
}
//Retorna a oposta
void opostaM(int i, int j, int resultado[i][j], int matriz[i][j]){
    for(int k = 0; k < i ;k++)
        for(int p = 0; p < j; p++)
            resultado[k][p] = -1*matriz[k][p];
}
//Soma de matrizes
void somaM(int i, int j, int resultado[i][j], int s[i][j], int s2[i][j]){
    for(int k = 0; k < i ;k++)
        for(int p = 0; p < j; p++)
            resultado[k][p] = s[k][p]+s2[k][p];
}
//Subtracao de matrizes
void subtracaoM(int i, int j, int resultado[i][j], int s[i][j], int s2[i][j]){
    for(int k = 0; k < i ;k++)
        for(int p = 0; p < j; p++)
            resultado[k][p] = s[k][p]-s2[k][p];
}
//Multiplicao de matrizes
void multiplicaoM(int i, int j, int resultado[i][j], int coluna1, int coluna2, int s[][coluna1], int s2[][coluna2]){
    int sum = 0;
    for(int p =0;p < i;p++) {
        for(int n = 0;n < j;n++) {
            sum=0;
            for(int k = 0;k < coluna1;k++) {
                sum=sum+(s[p][k]*s2[k][n]);
                resultado[p][n]=sum;
      }
   }
}                 
}
//Multiplicao por escalar
void escalarM(int i, int j, int resultado[i][j], int matriz[i][j], int escalar){
    for(int k = 0; k < i ;k++)
        for(int p = 0; p < j; p++)
            resultado[k][p] = escalar*matriz[k][p];
}
//Matriz diagonal
void diagonal(int i, int j, int matriz[i][j]){
    int k, p;
    int verificador = 1;
    int diagonalprincipal = 0;
	for (k = 0; k < i; k++){ 
		for (p = 0; p < j; p++){ 
			if(k != p){
                if(matriz[k][p] != 0)
                    verificador = 0;
            }
            else if(k == p)
                diagonalprincipal+=matriz[k][p];
        }
    }
    printf("%d\n", diagonalprincipal);
    if(diagonalprincipal == 0)
        verificador = 0;
    if(verificador == 1)
        printf("A matriz e do tipo diagonal\n");
    else
        printf("A matriz nao e do tipo diagonal\n");
}
//Matriz identidade
void identidade(int i, int j, int matriz[i][j]){
    int k, p;
    int verificador = 1;
    int diagonalprincipal = 0;
	for (k = 0; k < i; k++){ 
		for (p = 0; p < j; p++){ 
			if(k != p){
                if(matriz[k][p] != 0)
                    verificador = 0;
            }
            else if(k == p && matriz[k][p] == 1)
                diagonalprincipal+=1;
        }
    }
    printf("%d\n", diagonalprincipal);
    if(diagonalprincipal !=j)
        verificador = 0;
    if(verificador == 1)
        printf("A matriz e do tipo identidade\n");
    else
        printf("A matriz nao e do tipo identidade\n");
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
void mostraM(int x, int y, int s[x][y])
{
    int i,j;
    for (i=0;i<x;i++)
    {
        for (j=0;j<y;j++)
            printf(" [%d] ",s[i][j]);
        printf("\n");
    }
    printf("\n");
}
int main()
{
    int operacao;
    printf("Selecione a operacao quer voce quer fazer:\n");
    printf("Digite 1 para somar duas matrizes(So e possivel somar matrizes de mesmo tamanho)\n");
    printf("Digite 2 para subtrair duas matrizes(So e possivel subtrair matrizes de mesmo tamanho)\n");
    printf("Digite 3 para multiplicar duas matrizes(O numero de linhas da primeira dever ser igual ao numero de colunas da segunda)\n");
    printf("Digite 4 para multiplicar uma matriz qualquer por um escalar\n");
    printf("Digite 5 para obter a oposta de uma matriz qualquer\n");
    printf("Digite 6 para obter a transposta de uma matriz qualquer\n");
    printf("Digite 7 para saber se uma matriz qualquer é do tipo identidade(A matriz deve ser quadrada)\n");
    printf("Digite 8 para saber se uma matriz qualquer é do tipo diagonal(A matriz deve ser quadrada)\n");
    printf("Digite 9 para calcular o determinate de uma matriz 2x2 ou 3x3\n");
    printf("Digite 0 para encerrar a Calculadora\n");
    scanf("%d", &operacao);
    while(operacao > 0){
        switch(operacao){
            case 1:
            {
                int Nlinhas, Ncolunas;
                printf("Digite o número de linhas que sera atribuido as duas matrizes: ");
                scanf("%d", &Nlinhas);
                printf("Digite o número de colunas que sera atribuido as duas matrizes: ");
                scanf("%d", &Ncolunas);
                int matriz1[Nlinhas][Ncolunas];
                printf("Para matriz 1: \n");
                inicM(Nlinhas, Ncolunas, matriz1);
                int matriz2[Nlinhas][Ncolunas];
                printf("Para matriz 2: \n");
                inicM(Nlinhas, Ncolunas, matriz2);
                int matrizResultado[Nlinhas][Ncolunas];
                somaM(Nlinhas, Ncolunas, matrizResultado, matriz1, matriz2);
                mostraM(Nlinhas, Ncolunas, matrizResultado);
                printf("\n");
                break;
            }
            case 2: 
            {
                int Nlinhas, Ncolunas;
            printf("Digite o número de linhas que sera atribuido as duas matrizes: ");
            scanf("%d", &Nlinhas);
            printf("Digite o número de colunas que sera atribuido as duas matrizes: ");
            scanf("%d", &Ncolunas);
            int matriz1[Nlinhas][Ncolunas];
            printf("Para matriz 1: \n");
            inicM(Nlinhas, Ncolunas, matriz1);
            int matriz2[Nlinhas][Ncolunas];
            printf("Para matriz 2: \n");
            inicM(Nlinhas, Ncolunas, matriz2);
            int matrizResultado[Nlinhas][Ncolunas];
            subtracaoM(Nlinhas, Ncolunas, matrizResultado, matriz1, matriz2);
            mostraM(Nlinhas, Ncolunas, matrizResultado);
            printf("\n");
                break;
            }
            case 3:{
                int Nlinhas1, Ncolunas1;
            printf("Digite o número de linhas que sera atribuido a matriz 1: ");
            scanf("%d", &Nlinhas1);
            printf("Digite o número de colunas que sera atribuido a matriz 1: ");
            scanf("%d", &Ncolunas1);
            int Nlinhas2, Ncolunas2;
            printf("Digite o número de linhas que sera atribuido a matriz 2: ");
            scanf("%d", &Nlinhas2);
            printf("Digite o número de colunas que sera atribuido a matriz 2: ");
            scanf("%d", &Ncolunas2);
            int matriz1[Nlinhas1][Ncolunas1];
            printf("Para matriz 1: \n");
            inicM(Nlinhas1, Ncolunas1, matriz1);
            int matriz2[Nlinhas2][Ncolunas2];
            printf("Para matriz 2: \n");
            inicM(Nlinhas2, Ncolunas2, matriz2);
            int matrizResultado[Nlinhas1][Ncolunas2];
            //multiplicaoM(int i, int j, int resultado[i][j], int coluna1, int coluna2, int s[][coluna1], int s2[][coluna2])        
            multiplicaoM(Nlinhas1, Ncolunas2, matrizResultado, Ncolunas1, Ncolunas2, matriz1, matriz2);
            mostraM(Nlinhas1, Ncolunas2, matrizResultado);
            printf("\n");
                break;
            }
        }
       /* if(operacao == 1){
            int Nlinhas, Ncolunas;
            printf("Digite o número de linhas que sera atribuido as duas matrizes: ");
            scanf("%d", &Nlinhas);
            printf("Digite o número de colunas que sera atribuido as duas matrizes: ");
            scanf("%d", &Ncolunas);
            int matriz1[Nlinhas][Ncolunas];
            printf("Para matriz 1: \n");
            inicM(Nlinhas, Ncolunas, matriz1);
            int matriz2[Nlinhas][Ncolunas];
            printf("Para matriz 2: \n");
            inicM(Nlinhas, Ncolunas, matriz2);
            int matrizResultado[Nlinhas][Ncolunas];
            somaM(Nlinhas, Ncolunas, matrizResultado, matriz1, matriz2);
            mostraM(Nlinhas, Ncolunas, matrizResultado);
            printf("\n");
    }else if(operacao == 2){
            int Nlinhas, Ncolunas;
            printf("Digite o número de linhas que sera atribuido as duas matrizes: ");
            scanf("%d", &Nlinhas);
            printf("Digite o número de colunas que sera atribuido as duas matrizes: ");
            scanf("%d", &Ncolunas);
            int matriz1[Nlinhas][Ncolunas];
            printf("Para matriz 1: \n");
            inicM(Nlinhas, Ncolunas, matriz1);
            int matriz2[Nlinhas][Ncolunas];
            printf("Para matriz 2: \n");
            inicM(Nlinhas, Ncolunas, matriz2);
            int matrizResultado[Nlinhas][Ncolunas];
            subtracaoM(Nlinhas, Ncolunas, matrizResultado, matriz1, matriz2);
            mostraM(Nlinhas, Ncolunas, matrizResultado);
            printf("\n");
    }else if(operacao == 3){
            int Nlinhas1, Ncolunas1;
            printf("Digite o número de linhas que sera atribuido a matriz 1: ");
            scanf("%d", &Nlinhas1);
            printf("Digite o número de colunas que sera atribuido a matriz 1: ");
            scanf("%d", &Ncolunas1);
            int Nlinhas2, Ncolunas2;
            printf("Digite o número de linhas que sera atribuido a matriz 2: ");
            scanf("%d", &Nlinhas2);
            printf("Digite o número de colunas que sera atribuido a matriz 2: ");
            scanf("%d", &Ncolunas2);
            int matriz1[Nlinhas1][Ncolunas1];
            printf("Para matriz 1: \n");
            inicM(Nlinhas1, Ncolunas1, matriz1);
            int matriz2[Nlinhas2][Ncolunas2];
            printf("Para matriz 2: \n");
            inicM(Nlinhas2, Ncolunas2, matriz2);
            int matrizResultado[Nlinhas1][Ncolunas2];
            //multiplicaoM(int i, int j, int resultado[i][j], int coluna1, int coluna2, int s[][coluna1], int s2[][coluna2])        
            multiplicaoM(Nlinhas1, Ncolunas2, matrizResultado, Ncolunas1, Ncolunas2, matriz1, matriz2);
            mostraM(Nlinhas1, Ncolunas2, matrizResultado);
            printf("\n");
    }*/
        printf("Quer fazer uma nova operecao? 1 para sim 2 para nao: ");
        int sn;
        scanf("%d", &sn);
        if(sn == 1){
            printf("Selecione a operacao quer voce quer fazer:\n");
            printf("Digite 1 para somar duas matrizes(So e possivel somar matrizes de mesmo tamanho)\n");
            printf("Digite 2 para subtrair duas matrizes(So e possivel subtrair matrizes de mesmo tamanho)\n");
            printf("Digite 3 para multiplicar duas matrizes(O numero de linhas da primeira dever ser igual ao numero de colunas da segunda)\n");
            printf("Digite 4 para multiplicar uma matriz qualquer por um escalar\n");
            printf("Digite 5 para obter a oposta de uma matriz qualquer\n");
            printf("Digite 6 para obter a transposta de uma matriz qualquer\n");
            printf("Digite 7 para saber se uma matriz qualquer é do tipo identidade(A matriz deve ser quadrada)\n");
            printf("Digite 8 para saber se uma matriz qualquer é do tipo diagonal(A matriz deve ser quadrada)\n");
            printf("Digite 9 para calcular o determinate de uma matriz 2x2 ou 3x3\n");
            printf("Digite 0 para encerrar a Calculadora\n");
            scanf("%d", &operacao);
        }else if(sn == 2){
            printf("Calculadora Encerrada!\n");
            break;
        }
    }
    
	/*int teste[3][3] = { {4,2,3}, {5, -2, -2}, {6,2,10}};
    int resultado[3][3];
	//opostaM(3, 3, resultado ,teste);
    //mostraM(3,3, resultado);
    printf("%d\n", determinanteM3(teste));*/
    return 0;
} 
