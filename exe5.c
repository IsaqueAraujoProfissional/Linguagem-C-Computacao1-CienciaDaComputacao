#include <stdio.h>
#define N 3
void lernotas(float matrix[N][4], int n){
    for(int i = 0; i < n; i++){
        printf("Digite as 3 notas do %d aluno: ", i+1);
        for(int j =0; j < 3; j++ ){
            scanf("%f", &matrix[i][j]);
            //OU
            //scanf("%f", &*(*(matrix+i)+j));
        }
        printf("\n");
    }
}
float mediageral(float matrix[N][4], int n){
    float mediaG = 0;
    float mediaaluno = 0;
    for(int i =0; i < n; i++){
        mediaaluno = 0;
        for(int j =0; j < 3; j++ ){
            mediaaluno+=matrix[i][j];
            //OU
            //mediaaluno+=*(*(matrix+i)+j);
        }
        matrix[i][3] = mediaaluno/3;
        //OU
        //*(*(matrix+i)+3) = mediaaluno/3;
        mediaG+=mediaaluno/3;    
    }
    return mediaG/N;
}
void mostrarmedias(float matrix[N][4], int n){
    for(int i =0; i < n; i++){
        printf("Media do aluno %d: %.2f\n", i+1, matrix[i][3]);
    }
}
int main(){
    float matriz[N][4];
    lernotas(matriz, N);
    printf("Media Geral = %.2f\n", mediageral(matriz, N));
    mostrarmedias(matriz, N);
    return 0;
}
