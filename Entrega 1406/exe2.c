#include <stdarg.h>
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
    arq = fopen(argv[1], "ab+");
    if(arq == NULL) {
            puts("Nao foi possivel abrir o arquivo");
            return - 1;
    }
    Tlivro livro;
    int verificador;
    printf("Nome do livro: ");
    gets(livro.nome);
    while(livro.nome[0] !='\0'){
        printf("Codigo do livro: ");
        scanf("%d", &livro.codigo);
        printf("Preco do livro: ");
        scanf("%f", &livro.preco);
        verificador = fwrite(&livro, sizeof(Tlivro), 1, arq);
        if(verificador == 1)
            printf("Livro armazenado com sucesso\n");
        else
            printf("Nao foi posssivel armazenar o livro\n");
        getchar();
        printf("Nome do livro: ");
        gets(livro.nome);
    }
    fclose(arq);
    return 0;
}
