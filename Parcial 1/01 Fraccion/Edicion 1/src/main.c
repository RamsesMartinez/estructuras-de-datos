/*
* Programa que realiza operaciones con fracciones
* @author Ramses Martinez Ortiz
* @version 1.0.1
*/

#include "Fraccion.h"

int main(){
    fraccion *ap1,*ap2,*apRes; 
    ap1 = (fraccion*) malloc(sizeof(fraccion));
    ap2 = (fraccion*) malloc(sizeof(fraccion));
    apRes = (fraccion*) malloc(sizeof(fraccion));

    pedirDatos(ap1, ap2, apRes);
    printf("BYE BYE");
    
    free(ap1);
    free(ap2);
    free(apRes);
    return 0;
}
