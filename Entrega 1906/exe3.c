#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
typedef struct { 
    float x, y; 
    
} t_Ponto; 
typedef struct Plano { 
    t_Ponto p; int id; 
}; 
float comp (t_Ponto *p1, t_Ponto *p2) {   
    return sqrt (pow (p2->x -p1->x, 2) + pow(p2->y -p1->y , 2)); 
    
} int main (void) { 
    struct Plano pla;   
    t_Ponto p1, p2; 
    puts ("Coordenadas do ponto 1:");   
    scanf ("%f %f", &p1.x, &p1.y);   
    puts ("Coordenadas do ponto 2:");   
    scanf ("%f %f", &p2.x, &p2.y);   
    printf ("\nComprimento da reta= %.1f\n", comp(&p1, &p2)); 
    pla.p.x=1.1;   pla.p.y=2.2;  pla.id=0;   
    printf("%.1f %.1f %d\n", pla.p.x, pla.p.y, pla.id);   
    return 0; 
    
}
