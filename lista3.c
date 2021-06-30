#include <stdio.h>
int numerosPares();
int Intervalo();
int Experiencia();
int Fatorial();
int Positivos();
int main(){
    Fatorial();
    return 0;
}
int numerosPares(){
    for(int i = 0; i <= 100; i++){
        if(i%2 == 0)
            printf("%d\n", i);
    }
    return 0;
}
int Positivos(){
    int positivos = 0;
    double valor, soma = 0, media = 0;
    for(int i = 0; i < 6; i++){
        scanf("%lf", &valor);
        if(valor > 0){
            positivos+=1;
            soma+=valor;
        }
    }
    media = soma/positivos;
    printf("%d valores positivos\n", positivos);
    printf("%.1lf\n", media);
    return 0;
}
int Intervalo(){
    int quantidade, valor, dentro = 0, fora = 0;
    scanf("%d", &quantidade);
    for(int i =0; i < quantidade; i++){
        scanf("%d", &valor);
        if(valor >= 10 && valor <= 20){
            dentro+=1;
        }else{
            fora+=1;
        }
    }
    printf("%d in\n", dentro);
    printf("%d out\n", fora);
    return 0;
}
int Experiencia(){
    int casos, Qexperimento = 0, totalCobaias = 0, Ncoelhos = 0, Nratos = 0, Nsapos = 0;
    char animal;
    double pCoelhos = 0.0, pRatos = 0.0, pSapos = 0.0;
    scanf("%d", & casos);
    for(int i = 0; i < casos; i++){
        scanf("%d %c", &Qexperimento, & animal);
        switch(animal){
            case 'C':
                Ncoelhos+= Qexperimento;
                break;
            case 'R':
                Nratos+= Qexperimento;
                break;
            case 'S':
                Nsapos+= Qexperimento;
                break;
        }
        totalCobaias+= Qexperimento;
    }
    pCoelhos = (Ncoelhos/(totalCobaias*1.0))*100;
    pRatos = (Nratos/(totalCobaias*1.0))*100;
    pSapos = (Nsapos/(totalCobaias*1.0))*100;
    printf("Total: %d cobaias\n", totalCobaias);
    printf("Total de coelhos: %d\n", Ncoelhos);
    printf("Total de ratos: %d\n", Nratos);
    printf("Total de sapos: %d\n", Nsapos);
    printf("Percentual de coelhos: %.2lf %%\n", pCoelhos);
    printf("Percentual de ratos: %.2lf %%\n", pRatos);
    printf("Percentual de sapos: %.2lf %%\n", pSapos);
    return 0;
}
int Fatorial(){
    int valor, fatorial = 1;
    scanf("%d", &valor);
    for(int i = 1; i <= valor; i++){
        fatorial=fatorial*i;
    }
    printf("%d\n", fatorial);
    return 0;
}
