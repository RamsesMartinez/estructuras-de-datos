/**
* Name: ListaLineal.h
* Author: Ramses Martinez
* Version 1.0.0     08/05/2016
* Description: Archivo de cabecera para la implementacion del TAD Lista Lineal
*/

#ifndef LISTA_LINEAL_H
#define LISTA_LINEAL_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSTACK 5 
typedef struct list{
    int top;
    int entry[MAXSTACK];
}List;


void createList(int**);
void setSize(int**, int);
void printList(int**, int);
void insert(int**, int, int, int);
bool inStart();
bool inEnd();
bool isEmpty(int**);


struct list{
    int* list;
};
#endif
