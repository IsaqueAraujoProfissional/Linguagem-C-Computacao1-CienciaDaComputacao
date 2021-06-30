#include <stdio.h>
int main()
{
    Vetor3();
    return 0;
}
int Vetor(){
    int numeros[10];
    for(int i = 0; i < 10; i++){
        scanf("%d", &numeros[i]);
        if(numeros[i] <= 0){
            numeros[i] = 1;
        }
    }
    for(int j = 0; j < 10; j++){
        printf("X[%d] = %d\n", j, numeros[j]);
    }
    return 0;
}
int Vetor2(){
    int numeros[10];
    int valor;
    scanf("%d", &numeros[0]);
    for(int i = 0;i < 10; i++){
        if(i > 0){
            numeros[i] = numeros[i-1]*2;
        }
        printf("N[%d] = %d\n", i, numeros[i]);
    }
    return 0;
}
int Vetor3(){
    int numeros[100];
    for(int i = 0; i < 100; i++){
        scanf("%d", &numeros[i]);
    }
    for(int j = 0; j < 100; j++){
        if(numeros[j] <= 10){
            printf("A[%d] = %d\n", j, numeros[j]);
        }
    }
    return 0;
}
int Vetor4(){
    int numeros[20];
    int reverso = 0;
    for(int i = 0; i < 20; i++){
        scanf("%d", &numeros[i]);
    }
    for(int j = 19; j >= 0; j--){
        printf("N[%d] = %d\n", reverso, numeros[j]);
        reverso+=1;
    }
    return 0;
}
int Vetor5(){
    int par[5], j, impar[5], i, P = 0, I = 0, x;
    for (i = 0; i < 15; i++) {
		scanf("%d", &x);
		if (x % 2 == 0) {
			par[P] = x;
			P++;
			if (P == 5) {
				for (j = 0; j < 5; j++) {
					printf("par[%d] = %d\n", j, par[j]);
				}
				P = 0;
			}
		} else {
			impar[I] = x;
			I++;
			if (I == 5) {
				for (j = 0; j < 5; j++) {
					printf("impar[%d] = %d\n", j, impar[j]);
				}
				I = 0;
			}
		}
	}
	for (j = 0; j < I; j++) {
		printf("impar[%d] = %d\n", j, impar[j]);
	}
	for (j = 0; j < P; j++) {
		printf("par[%d] = %d\n", j, par[j]);
	}
    return 0;
}
