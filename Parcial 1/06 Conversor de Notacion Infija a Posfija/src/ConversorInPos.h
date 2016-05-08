/** 
* Name: ConversorInPos.h
* Author: Ramses Martinez
* Version: 1.0.0 	14/04/2016
* Description: Cabecera que contiene la declaracion de las funciones para onvertir la expresion infija a posfija
*/
#ifndef CONVERSOR_DE_NOTACION_H
#define CONVERSOR_DE_NOTACION_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Stack.h"

/** Prototipos */
void verificarExpresion(char**);
void convertirExpresion(char **);
void verificarDelimitadores(char**);
void verificarDelimitador(char**,char,char);
bool esOperador(char);
bool esOperando(char);
int calcular(int, char, int);

#endif
