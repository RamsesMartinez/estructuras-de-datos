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

void createList(int**);
void setSize(int**, int);
void printList(int**, int);
bool insert(int**, int, int, int*, int);
bool inStart(int**, int, int*, int);
bool inEnd(int**, int, int*, int);
bool isEmpty(int);
bool isFull(int, int);
int searchPosition(int**, int, int);
int searchData(int**, int);
int removeData(int**, int, int*);
#endif
