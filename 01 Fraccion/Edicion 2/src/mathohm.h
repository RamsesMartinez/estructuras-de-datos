/*
 *    mathohm.h
 * 
 *    Date of creation: 10/03/2016
 *              Author: Hernández Morales Osvaldo
 *             Version: 1.0   
 *                Note: None
 */

#include <string.h>
#include <stdlib.h>
#include <math.h>


#ifndef MATHOHM_H_
#define MATHOHM_H_

/* Define the type structure of fraccion */
typedef struct fraccion
	{
		int numerador;
		int denominador;		
	} frac;

frac* sumafrac( frac *b, frac *c ); /*  Suma de dos fracciones */
frac* restafrac( frac *b, frac *c ); /*  Resta de dos fracciones */
frac* multifrac(frac *a, frac *b); /* Multiplica fraccion */
frac* divfrac( frac *a, frac *b); /* Divide fracciones*/
frac* potfrac( frac *a, int *b ); /* Eleva a una potencia la fraccion*/
frac* simpfrac(frac *a); /* Simplifica una fraccion*/
int mcdfrac(frac *a); /* Devuelve el mcd de el numerador y denominador de una fraccion*/
int verifrac( frac *a ); /* Verifica que el denominador de la fraccion no sea cero*/

#endif /* MATHOHM_H_ */
