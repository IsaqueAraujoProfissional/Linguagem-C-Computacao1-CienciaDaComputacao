#include <stdarg.h>
#include <string.h>
#include <stdio.h> 
typedef struct {
    char nome [50];
    int codigo;
    float preco; 
} Tlivro; 
int main(int argc, char *argv[]){
    FILE *arq;
    if(argc < 2) {
        puts("Digite <nome programa> <arquivo de texto>");
        return -1; 
    }
    arq = fopen(argv[1], "rb+");
    if(arq == NULL) {
            puts("Nao foi possivel abrir o arquivo, execute primeiro o exercicio 2!");
            return - 1;
    }
    Tlivro livro;
    Tlivro livroTemp;
    int total = 0;
    int mudados = 0;
    int verificador;
    //GUARDA posicao
    long int posicao = ftell(arq);
    verificador = fread(&livro, sizeof(Tlivro), 1, arq);
    //printf("%li\n", posicao-ftell(arq));
    while(!feof(arq)){
        //printf("%d\n", verificador);
        total++;
        if(verificador == 1){
            if(livro.preco > 200.0){
                mudados+=1;
                printf("Preco: R$ %.2f\n",livro.preco);
                livro.preco = livro.preco*0.95;
                //AQUI
                fseek(arq, posicao-ftell(arq), SEEK_CUR);
                fwrite(&livro, sizeof(Tlivro), 1, arq);
            }
        }else{
            printf("Erro ao ler as informacoes do livro");
        }
        verificador = fread(&livro, sizeof(Tlivro), 1, arq);
        posicao = ftell(arq);
    }
    printf("Existem %d livros armazenados no arquivo\n", total);
    printf("%d livros tiveram o preco atualizado\n", mudados);
    rewind(arq);
    verificador = fread(&livro, sizeof(Tlivro), 1, arq);
    while(!feof(arq)){
        if(verificador == 1){
            printf("\n----------------------\n");
            printf("Nome livro: %s\n",livro.nome);
            printf("Codigo: %d\n",livro.codigo);
            /*if(livro.preco > 200)
                livro.preco = livro.preco*0.95;*/
            printf("Preco: R$ %.2f\n",livro.preco);

        }else{
            printf("Erro ao ler as informacoes do livro");
        }
        verificador = fread(&livro, sizeof(Tlivro), 1, arq);
    }
    fclose(arq);
    return 0;
}
