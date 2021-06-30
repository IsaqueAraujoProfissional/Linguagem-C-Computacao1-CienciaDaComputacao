#include "operacoes.h"
#include <stdio.h>
#include <string.h>
//Estrutura de Login
typedef struct
{
	char nome[51];
	char senha[51];
	char arquivo[51];
} Login;
//Salva os resultados obtitdos da operacoes feitas pelo usuario
void salvarOperacao(FILE *file, int tam, int matrix[tam][tam], char oper[]) {
	fprintf(file, "%s %s\n", "Resultado ", oper);
	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {
			fprintf(file, "%d ", matrix[i][j]);
		}
		fprintf(file, "\n");
	}
}
void operacoes(){
    printf("Selecione a operacao desejada:\n");
    printf("1 para soma\n");
    printf("2 para subtracao\n");
    printf("3 para multiplicacao de duas matrizes\n");
    printf("4 para multiplicacao por um escalar\n");
    printf("5 para matriz oposta\n");
    printf("6 para matriz transposta\n");
    printf("7 para verificar se a matriz e identidade\n");
    printf("8 para verificar se a matriz e diagonal\n");
    printf("9 para matriz Determinante (2x2 ou 3x3)\n");
    printf("0 para encerrar a Calculadora\n");
    printf("Operacao: ");
}
//MAIN
int main(int argc, char *argv[])
{
	if (argc < 2) {
		puts("Digite <nome programa> <senha> ");
		return -1;
	}
	if (strcmp("comp1dcc", argv[1]) != 0) {
		puts("Senha incorreta!");
		return -1;
	}
	int certoC = 0;
	Login login;
	Login certo;
	int tem;
	FILE *arqL;
	FILE *informacoes;
	printf("Você possui login? 1 -  SIM 2 - NAO\n");
	scanf("%d", &tem);
	getchar();
	if (tem == 1) {
		printf("Por favor Digite o seu login: ");
        scanf("%s", login.nome);
		//gets(login.nome);
		printf("Por favor digite a senha: ");
		//gets(login.senha);
        scanf("%s", login.senha);
		arqL = fopen("LoginSenha.txt", "r");
		if (arqL == NULL) {
			printf("ERRO AO LER ARQUIVO COM LOGINS E SENHAS!\n");
			return -1;
		}
		while (!feof(arqL)) {
			fscanf(arqL, "%s %s %s\n", certo.nome, certo.senha, certo.arquivo);
			if (strcmp(login.nome, certo.nome) == 0 && strcmp(
				login.senha, certo.senha) == 0) {
				printf("LOGIN EFETUADO COM SUCESSO!\n");
				certoC = 1;
				fclose(arqL);
				break;
			}
		}
		if (certoC == 0) {
			printf("NAO FOI POSSIVEL ENTRAR!\n");
			return -1;
		}
		informacoes = fopen(certo.arquivo, "a");
		if (informacoes == NULL) {
			printf("NAO FOI POSSIVEL RECUPERAR O ARQUIVO DO USUARIO!\n");
			return -1;
		}
		fseek(informacoes, 0, SEEK_END);
	}
	else if (tem == 2) {
		printf("Por favor Digite o seu login: ");
        scanf("%s", login.nome);
		//gets(login.nome);
		printf("Por favor digite a senha: ");
        scanf("%s", login.senha);
		//gets(login.senha);
		printf("Por favor digite o nome do arquivo: ");
        scanf("%s", login.arquivo);
		//gets(login.arquivo);
		arqL = fopen("LoginSenha.txt", "a");
		if (arqL == NULL) {
			printf("ERRO AO LER ARQUIVO COM LOGINS E SENHAS!\n");
			return -1;
		}
		fseek(arqL, 0, SEEK_END);
		fprintf(arqL, "%s %s %s\n", login.nome, login.senha, login.arquivo);
		fclose(arqL);
		informacoes = fopen(login.arquivo, "w");
		if (informacoes == NULL) {
			printf("NAO FOI POSSIVEL CRIAR O ARQUIVO DO USUARIO!\n");
			return -1;
		}
	}else{
        return -1;
    }
    int tam;
    int operacao;
    operacoes();
    scanf("%d", &operacao);
	if (operacao == 0)
		fclose(informacoes);
    while(operacao > 0){
        switch(operacao){
            case 1:
            {
                
                printf("Digite tamanho da matriz quadrada: ");
                scanf("%d",&tam);
                
                int matriz1[tam][tam];
                printf("Para matriz 1: \n");
                inicM(tam, matriz1);
                int matriz2[tam][tam];
                printf("Para matriz 2: \n");
                inicM(tam, matriz2);
                int matrizResultado[tam][tam];
                somaM(tam, matrizResultado, matriz1, matriz2);
                mostraM(tam, matrizResultado);
				salvarOperacao(informacoes, tam, matrizResultado, "SOMA:");
                break;
            }
            case 2: 
            {
                printf("Digite tamanho da matriz quadrada: ");
                scanf("%d",&tam);
                
                int matriz1[tam][tam];
                printf("Para matriz 1: \n");
                inicM(tam, matriz1);
                int matriz2[tam][tam];
                printf("Para matriz 2: \n");
                inicM(tam, matriz2);
                int matrizResultado[tam][tam];
                
                subtracaoM(tam, matrizResultado, matriz1, matriz2);
                mostraM(tam, matrizResultado);
				salvarOperacao(informacoes, tam, matrizResultado, "SUBTRACAO:");
				break;
                
            
            }
            case 3:{
                
                printf("Digite tamanho da matriz quadrada: ");
                scanf("%d",&tam);
                
                int matriz1[tam][tam];
                printf("Para matriz 1: \n");
                inicM(tam, matriz1);
                int matriz2[tam][tam];
                printf("Para matriz 2: \n");
                inicM(tam, matriz2);
                int matrizResultado[tam][tam];
                
                multiplicaoM(tam, matrizResultado, matriz1, matriz2);
                mostraM(tam, matrizResultado);
				salvarOperacao(informacoes, tam, matrizResultado, "MULTIPLICAO:");
                break;
            }
            case 4:{
                
                int escalar;
                printf("Digite tamanho da matriz quadrada: ");
                scanf("%d",&tam);
                printf("Digite numero que deseja multiplicar: ");
                scanf("%d",&escalar);
                
                int matriz1[tam][tam];
                printf("Para matriz 1: \n");
                inicM(tam, matriz1);
                int matrizResultado[tam][tam];
                escalarM(tam,matrizResultado, matriz1, escalar);
                mostraM(tam, matrizResultado);
				salvarOperacao(informacoes, tam, matrizResultado, "MULTIPLICAO POR ESCALAR:");
				break;
                
            }
            case 5:{
                printf("Digite tamanho da matriz quadrada: ");
                scanf("%d",&tam);
                int matriz1[tam][tam];
                printf("Para matriz 1: \n");
                inicM(tam, matriz1);
                int matrizResultado[tam][tam];
                opostaM(tam, matrizResultado, matriz1);
                mostraM(tam, matrizResultado);
				salvarOperacao(informacoes, tam, matrizResultado, "OPOSTA:");
				break;
            }
            case 6:{
                printf("Digite tamanho da matriz quadrada: ");
                scanf("%d",&tam);
                int matriz1[tam][tam];
                printf("Para matriz : \n");
                inicM(tam, matriz1);
                int matrizResultado[tam][tam];
                transpostaM(tam, matrizResultado, matriz1);
                mostraM(tam, matrizResultado);
				salvarOperacao(informacoes, tam, matrizResultado, "TRANSPOSTA:");
				break;
            }
			case 7:{
				printf("Digite tamanho da matriz quadrada: ");
				scanf("%d", &tam);
				int matriz1[tam][tam];
				printf("Para matriz : \n");
				inicM(tam, matriz1);
				if(identidade(tam, matriz1) == 1)
                    salvarOperacao(informacoes, tam, matriz1, "IDENTIDADE:");
                else
                    salvarOperacao(informacoes, tam, matriz1, "NAO E IDENTIDADE:");
				break;
			}
			case 8: {
				printf("Digite tamanho da matriz quadrada: ");
				scanf("%d", &tam);
				int matriz1[tam][tam];
				printf("Para matriz : \n");
				inicM(tam, matriz1);
				if(diagonal(tam, matriz1) == 1)
                    salvarOperacao(informacoes, tam, matriz1, "DIAGONAL:");
                else
                    salvarOperacao(informacoes, tam, matriz1, "NAO DIAGONAL:");
				break;
			}
			case 9: {
				printf("Digite tamanho da matriz quadrada(2 ou 3): ");
				scanf("%d", &tam);
                while(tam!=2 && tam!=3){
					printf("Digite tamanho da matriz quadrada(2 ou 3): ");
					scanf("%d",&tam);
				}				
				int matriz1[tam][tam];
				printf("Para matriz : \n");
				inicM(tam, matriz1);
				printf("Determinante: %d\n", determinanteM(tam, matriz1));
				fprintf(informacoes, "%s\n", "Resultado DETERMINANTE:");
				fprintf(informacoes, "%d\n", determinanteM(tam, matriz1));
				break;
			}
        }
        printf("Quer fazer uma nova operecao? 1 para sim 0 para nao: ");
        int sn;
        scanf("%d", &sn);
        if(sn == 1){
        	operacoes();
            scanf("%d", &operacao);
            if(operacao == 0){
                fclose(informacoes);
                printf("Todas as operacoes realizadas foram salvas no documento!\n");
                break;
            }
        }else if(sn == 0){
			fclose(informacoes);
            printf("Todas as operacoes realizadas foram salvas no documento!\n");
            break;
        }else{
            fclose(informacoes);
            printf("Todas as operacoes realizadas foram salvas no documento!\n");
            break;
            
        }
    }
	printf("Calculadora Encerrada!\n");
    return 0;
} 
