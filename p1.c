#include <stdio.h>
#include <string.h>
double porcentagem(int quantidade, int total){
    if(total == 0)
        return 0;
    return ((double)quantidade/total)*100;
}
int Repeticoes(char time[51]){
    char letra = time[0];
    int repeticoes =  0;
    for(int i =0; i < strlen(time); i++){
        if(i > 0){
            if(letra == time[i])
                repeticoes++;
        }
    }
    return repeticoes;
}
void imprime(char caractere, int repeticoes){
    for(int i = 0; i < repeticoes; i++){
        printf("%c", caractere);
    }
    printf("\n");
}
int main(){
    int torcedores;
    scanf("%d", &torcedores);
    getchar();
    char Ltimes [torcedores][51];
    double Ptimes[torcedores];
    int indice = 0;
    int times = 0;
    for(int j = 0; j < torcedores; j++){
        gets(Ltimes[indice]);
        Ptimes[indice] = 1;
        times++;
        for(int i = 0; i < indice; i++){
            if(strcmp(Ltimes[i], Ltimes[indice]) == 0){
                Ptimes[i]++;
                indice--;
                times--;
                break;
            }
        }
        indice++;
    }
    for(int k = 0; k < times; k++){
        int repeticoes = Repeticoes(Ltimes[k]);
        if(repeticoes > 0){
            printf("%s a letra inicial repete (%d)\n", Ltimes[k], repeticoes);
            imprime('*', repeticoes);
        }
    }
    double preferido = 0.0;
    for(int w = 0; w < times; w++){
        if(Ptimes[w] > preferido)
            preferido = Ptimes[w];
    }
    for(int l = 0; l < times; l++){
        if(Ptimes[l] == preferido){
            printf("PREFERIDO: %s %.2lf%%\n", Ltimes[l], porcentagem(Ptimes[l], torcedores));
        }
    }
    return 0;
}
