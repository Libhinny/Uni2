#include <stdio.h>
#include "circulo.h"

int main(void){
    Circulo* c = circ_cria(0, 0, 5.0);
    Ponto* p = pto_cria(3.0, 4.0);
    printf("Área do círculo: %.2f\n", circ_area(c));

    if (circ_interior(c, p)){
        printf("O ponto está dentro do circulo\n");
    } 
    else{
        printf("O ponto não esta dentro do circulo\n");
    }

    pto_libera(p);
    circ_libera(c);

    return 0;
}
