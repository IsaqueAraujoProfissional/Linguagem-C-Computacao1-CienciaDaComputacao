int Senha(){
    int senha;
    scanf("%d", &senha);
    while(senha != 2002){
        printf("Senha Invalida\n");
        scanf("%d", &senha);
    }
    printf("Senha Valida\n");
    return 0;
}
int Quadrante(){
    int x, y;
    scanf("%d %d", &x, &y);
    while(x!=0 || y!=0){
        if(x > 0 && y > 0){
            printf("primeiro\n");
        }else if(x < 0 && y > 0){
            printf("segundo\n");
        }
        else if(x < 0 && y < 0){
            printf("terceiro\n");
        }else{
            printf("quarto\n");
        }
        scanf("%d %d", &x, &y);
    }
    return 0;
}
int NotaValida(){
    double n1, n2, media;
    do{
        scanf("%lf", &n1);
        if(n1 < 0 || n1 > 10){
            printf("nota invalida\n");
        }
    }while(n1 < 0 || n1 > 10);
    do{
        scanf("%lf", &n2);
        if(n2 < 0 || n2 > 10){
            printf("nota invalida\n");
        }
    }while(n2 < 0 || n2 > 10);
    media = (n1+n2)/2;
    printf("media = %.2lf\n", media);
    return 0;
}
int Futebol(){
    int grenais = 0;
    int novogrenal, inter, gremio;
    int interGanhou = 0; 
    int gremioGanhou = 0;
    int empates = 0;
    do{
        scanf("%d %d", &inter, &gremio);
        printf("Novo grenal (1-sim 2-nao)\n");
        scanf("%d", &novogrenal);
        grenais +=1;
        if(inter > gremio){
            interGanhou +=1;
        }else if(inter < gremio){
            gremioGanhou +=1;
        }else{
            empates +=1;
        }

    }while(novogrenal == 1);
    printf("%d grenais\n", grenais);
    printf("Inter: %d\n", interGanhou);
    printf("Gremio: %d\n", gremioGanhou);
    printf("Empates: %d\n", empates);
    if(interGanhou > gremioGanhou){
        printf("Inter venceu mais\n");
    }else if(interGanhou < gremioGanhou){
        printf("Gremio venceu mais\n");
    }
    return 0;
}
int SequenciaCrescente(){
    int variavel, contador;
    do{
        scanf("%d", &variavel);
        contador = 0;
        while(contador < variavel){
            contador+=1;
            printf("%d ", contador);
        }
    }while(variavel != 0);
    return 0;
}
