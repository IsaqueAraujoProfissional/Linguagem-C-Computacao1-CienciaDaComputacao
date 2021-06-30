#include <stdarg.h>
#include <stdio.h>  
int main(int argc, char *argv[]){
    FILE *arq;
    if(argc < 2) {
        puts("Digite <nome programa> <arquivo de texto>");
        return -1; 
    }
    arq = fopen(argv[1], "wb+");
    if(arq == NULL) {
            puts("Nao foi possivel abrir o arquivo");
            return - 1;
    }
    int N;
    int verificador = 0;
    printf("Informe o valor de N: ");
    scanf("%d", &N);
    int vetorescrito[N];
    int vetorlido[N];
    for(int i =  0; i < N; i++){
        vetorescrito[i] = N-i;
        printf("%d ", vetorescrito[i]);
    }    
    printf("\n");
    verificador = fwrite(vetorescrito, sizeof(vetorescrito), 1, arq);
    if(verificador == 1)
        puts("Numeros salvos com sucesso...");
    else{
        puts("Nao foi possivel salvar os numeros");
        fclose(arq);
        return -1;
    }
    rewind(arq);
    verificador = fread(vetorlido, sizeof(vetorlido), 1, arq);
    if(verificador == 1){
        for(int i =  N-1; i >= 0; i--)
            printf("%d ", vetorlido[i]);
        printf("\n");
        puts("Numeros lidos com sucesso...");
    }
    else
        puts("Nao foi possivel ler os numeros");
    fclose(arq);
    return 0;
}
