/*
* Cabecera que contiene la declaracion de las funciones asi como la estructura FRACCION
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Fraccion { 
    int numerador;
    int denominador;
} fraccion; 

void crearFraccion(fraccion*);
void dividir(fraccion*, fraccion*, fraccion*);
void imprimirResultado(fraccion*);
void multiplicar(fraccion*, fraccion*, fraccion*);
void pedirDatos(fraccion*, fraccion*, fraccion*);
void potenciar(fraccion*, fraccion*, int); 
void restar(fraccion*, fraccion*, fraccion*);
void simplificar(fraccion*);
void sumar(fraccion*, fraccion*, fraccion*);
 
 
