/*
* Cabecera que contiene la declaracion de las funciones 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int StackEntry;

typedef struct nodoPila{
	StackEntry dato; 
	struct nodoPila *ptrSiguiente; /** Apuntador al siguiente nodo*/
}NodoPila;

typedef NodoPila *ptrNodoPila;

/** Prototipos */

//void createStack(ptrNodoPila);
void push(ptrNodoPila *ptrCima, int info);
StackEntry pop(ptrNodoPila *ptrCima);
bool stackEmpty(ptrNodoPila ptrCima);
void printStack(ptrNodoPila ptrActual);
bool delStack(ptrNodoPila); 
void printStack(ptrNodoPila);
int menu();


 