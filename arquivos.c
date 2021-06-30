#include <stdio.h>
#include <string.h>
typedef struct{
    char nome[100];
    float notas[3];
    float media;
} Taluno;
int setAluno(){
    Taluno aluno;
    FILE *arquivo;
    int verificador;
    arquivo = fopen("alunos.dat", "wb");
    if(arquivo == NULL)
        printf("Erro na criacao do arquivo");
    else{
        for(;;){
            printf("Digite o nome do aluno: ");
            gets(aluno.nome);
            aluno.media = 0;
            if(aluno.nome[0] == '\0')
                break;
            for(int i = 0; i < 3; i++){
                printf("Digite a nota da %dº avaliação desse aluno: ", i+1);
                scanf("%f", &aluno.notas[i]);
                aluno.media+=aluno.notas[i];
            }
            aluno.media = aluno.media/3;
            verificador = fwrite(&aluno, sizeof(Taluno), 1, arquivo);
            if(verificador == 1)
                printf("Sucesso ao gravar!\n");
            else
                printf("Falha ao gravar dado...\n");
            getchar();
        }
        fclose(arquivo);
    }
    return 0;
}
int getAluno(){
    Taluno aluno;
    FILE *arquivo;
    int verificador;
    arquivo = fopen("alunos.dat", "rb");
    if(arquivo == NULL)
        printf("Erro na leitura do arquivo");
    else{
        verificador = fread(&aluno, sizeof(Taluno), 1, arquivo);
        while(!feof(arquivo)){
            if(verificador == 1){
                printf("%s\n", aluno.nome);
                for(int i = 0; i < 3; i++){
                    printf("Nota %i: %.2f\n", i+1, aluno.notas[i]);
                }
                printf("Media: %.2f\n", aluno.media);
            }
            else
                printf("Erro ao recuper aluno!");
            verificador = fread(&aluno, sizeof(Taluno), 1, arquivo);                
        }
        fclose(arquivo);
    }
    return 0;
}
int main(){
    getAluno();
    return 0;
}
