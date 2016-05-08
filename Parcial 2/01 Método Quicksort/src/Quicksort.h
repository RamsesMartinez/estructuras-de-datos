/**
* Name: Quicksort.h
* Author: Ramses Martinez
* Version 1.1.0     08/05/2016
* Decription: Programa para ordena un conjunto de numeros utilizando el metodo Quicksort
*/

#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void crearLista(int**,int*);
void mostrarLista(int**,int);
void quicksort(int**, int, int);
int menu();

#endif    

