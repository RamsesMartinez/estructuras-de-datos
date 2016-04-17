/** 
* Name: Evaluador.h
* Author: Ramses Martinez
* Version: 1.0.0 	14/04/2016
* Description: Cabecera que contiene la declaracion de las funciones del evaluador de expresiones
*/

#ifndef EVALUADOR_H
#define EVALUADOR_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Stack.h"

/** Prototipos */
void verificarExpresion(char**);
bool esOperador(char);
bool esOperando(char);
int calcular(int, char, int);
#endif
