#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STACKOHM_H_
#define STACKOHM_H_

/* define the max size of the stack */
#define MAXSTACK 50
/* symbolic constant to boolean value */
#define TRUE 1

typedef int stackentry;

/* Define the type structure of spile that is sstack, 
   spile is a type data*/
typedef struct sstack
{
    int top;
    stackentry entry[MAXSTACK];  
} spile;

/* estructura de nodo para pila dinamica */
typedef struct nodedstack 
{ 
    stackentry dato; 
    struct nodedstack *ptrnext;
} nodedstack, *ptrnodedstack;

/* prototipos de pila estatica */
int spilepush( stackentry item, spile *s );/* introduce un elemento a la pila estatica */int spilepop( stackentry *item, spile *s ); /* sacar elemento de pila estatica */
int spempty( spile *s );/* verifica si la pila estatica esta vacia */
int spfull( spile *s );/* verifica si la pila estatica esta llena */
int screatepile( spile *s );/* crea y reserva espacio para pila estatica */
int spiletop( stackentry *item, spile *s );/* sacar un elemento de la pila */
int spilepop( stackentry *item, spile *s );/* saca un elmento de la pila */

/* prototipos de pila dinamica */
void dpilepush ( ptrnodedstack *ptrCima, stackentry info );
int dpilepop ( stackentry *item, ptrnodedstack *ptrCima );
int dpempty( ptrnodedstack ptrCima );
void pdpile ( ptrnodedstack ptrActual ); /* imprime la pila */

#endif /* STACKOHM_H_ */