#include <stdio.h>
#include <string.h>
typedef struct
{
    char nome[51];
    char senha[51];
    char arquivo[51];
} Login;
int main ()
{
    int certo2 = 0;
    Login login;
    Login certo;
    int tem;
    char Narq[51];
    FILE *arqL;
    FILE *arq;
    FILE *informacoes;
    printf("Você possui login? 1 -  SIM 2 - NAO\n");
    scanf("%d", &tem);
    getchar();
    if(tem == 1){
        printf("Por favor Digite o seu login: ");
        gets(login.nome);
        printf("Por favor digite a senha: ");
        gets(login.senha);
        arqL = fopen("LoginSenha.txt", "r");
        if(arqL == NULL){
            printf("ERRO AO LER ARQUIVO COM LOGINS E SENHAS!\n");
            return -1;
        }
        while(!feof(arqL)){
            fscanf(arqL, "%s %s %s\n", certo.nome, certo.senha, certo.arquivo);
            if(strcmp(login.nome,certo.nome) == 0 && strcmp(login.senha,certo.senha) == 0){
                printf("LOGIN EFETUADO COM SUCESSO!\n");
                certo2 = 1;
                fclose(arqL);
                break;
            } 
        }
        if(certo2 == 0){
            printf("NAO FOI POSSIVEL ENTRAR!\n");
            return -1;
        }
        informacoes = fopen(certo.arquivo, "a");
        if(informacoes == NULL){
            printf("NAO FOI POSSIVEL RECUPERAR O ARQUIVO DO USUARIO!\n");
            return -1;
        }
        fseek(informacoes,0, SEEK_END);
    }else if(tem == 2){
        printf("Por favor Digite o seu login: ");
        gets(login.nome);
        printf("Por favor digite a senha: ");
        gets(login.senha);
        printf("Por favor digite o nome do arquivo: ");
        gets(login.arquivo);
        arq = fopen("LoginSenha.txt", "a");
        if(arqL == NULL){
            printf("ERRO AO LER ARQUIVO COM LOGINS E SENHAS!\n");
            return -1;
        }
        fseek(arq, 0, SEEK_END);
        fprintf(arq, "%s %s %s\n", login.nome, login.senha, login.arquivo);
        fclose(arq);
        informacoes = fopen(login.arquivo, "w");
        if(informacoes == NULL){
            printf("NAO FOI POSSIVEL CRIAR O ARQUIVO DO USUARIO!\n");
            return -1;
        }
    }
    fprintf(informacoes,"%s\n", "Resultado:");
    int matrix[2][3] ={{2,1,2}, {5,2,7}};
    for(int i=0;i<2;i++) {
        for(int j=0;j<3;j++) {
            fprintf(informacoes,"%d ",matrix[i][j]);
        }
        fprintf(informacoes,"\n");
    }
    fclose(informacoes);
    return 0;
}
