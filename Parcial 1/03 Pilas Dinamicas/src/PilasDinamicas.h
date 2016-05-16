/*
* Cabecera que contiene la declaracion de las funciones 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int StackEntry;

typedef struct nodoPila{
    StackEntry entry; 
    struct nodoPila *ptrSiguiente; /** Apuntador al siguiente nodo*/
}NodoPila;

typedef NodoPila *ptrNodoPila;

/** Prototipos */

//void createStack(ptrNodoPila);
void push(ptrNodoPila*, int);
StackEntry pop(ptrNodoPila*);
StackEntry topStack(ptrNodoPila*);
void printStack(ptrNodoPila);
void delStack(ptrNodoPila*); 
bool stackEmpty(ptrNodoPila);
int totalNodes(ptrNodoPila);
int menu();


 
