/**
* Name: Stack.h 
* Author: Ramses Martinez
* Version: 1.0.0 	14/04/2016
* Description: Cabecera que contiene la declaracion de las funciones para la pila
*/

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long StackEntry;
typedef struct nodoPila{
    StackEntry entry; 
    struct nodoPila *ptrSiguiente; /** Apuntador al siguiente nodo*/
}NodoPila;
 
typedef NodoPila *ptrNodoPila; 

/** Prototipos */
void push(ptrNodoPila*, StackEntry);
StackEntry pop(ptrNodoPila*);
StackEntry topStack(ptrNodoPila*);
void printStack(ptrNodoPila);
void delStack(ptrNodoPila*); 
bool stackEmpty(ptrNodoPila*);

#endif
