/*
 *    mathohm.c
 * 
 *    Date of creation: 10/03/2016
 *              Author: Hernández Morales Osvaldo
 *             Version: 1.0   
 *                Note: None
 */

#include "mathohm.h"
#include <math.h>

/* verifica que la fraccion no tenga denominador cero */
int verifrac( frac *a )
{
	if(	a->denominador == 0 )
	return 1;

    return 0;
}

/* verifica que la fraccion no tenga denominador cero */
frac* sumafrac(frac *a, frac *b)
{
	frac *ans;
	
	ans = ( frac * ) malloc( sizeof( frac )*1 );
	
	ans->denominador  = ( a->denominador ) * ( b->denominador );
	ans->numerador = ( ( ( ans->denominador ) / ( a->denominador ) ) * ( a->numerador ) ) + ( ( ( ans->denominador ) / ( b->denominador ) ) * ( b->numerador ) );
	
	return ans;
}

frac* restafrac(frac *a, frac *b)
{
	frac *ans;
	
	ans = ( frac * ) malloc( sizeof( frac )*1 );
	
	ans->denominador  = ( a->denominador ) * ( b->denominador );
	ans->numerador = ( ( ans->denominador  /  a->denominador  ) - ( ans->denominador  /  b->denominador ) );
	
	return ans;
}

frac* multifrac(frac *a, frac *b)
{
	frac *ans;
	
	ans = ( frac * ) malloc( sizeof( frac )*1 );
	
	ans->denominador  = ( a->denominador ) * ( b->denominador );
	ans->numerador = ( a->numerador ) * ( b->numerador );
	
	return ans;
}

frac* divfrac(frac *a, frac *b)
{
	frac *ans;
	
	ans = ( frac * ) malloc( sizeof( frac )*1 );
	
	ans->denominador  = ( a->denominador ) * ( b->numerador );
	ans->numerador = ( a->numerador ) * ( b->denominador );
	
	return ans;
}

frac* potfrac(frac *a, int *exp)
{
	frac *ans;
	
	ans = ( frac * ) malloc( sizeof( frac )*1 );
	
	ans->denominador  = pow((a->denominador),(*exp));
	ans->numerador = pow((a->numerador),(*exp));
	
	return ans;
}

int mcdfrac(frac *a)
{
	unsigned int ans;
	
	a->numerador = ( a->numerador <  0 ) ? a->numerador*(-1) : (a->numerador) ;
	a->denominador  = ( a->denominador <  0 ) ? a->denominador*(-1) : a->denominador;
	ans = ( a->numerador < a->denominador ) ? a->numerador : a->denominador;
	while( ( a->numerador % ans ) || ( a->denominador % ans ) )
	    ans--;
	return ans;
}

frac* simpfrac(frac *a)
{
	frac *ans;
	int mcd;
	
	ans = ( frac * ) malloc( sizeof( frac )*1 );
	*ans = *a;
	mcd = mcdfrac(a);
	
	ans->numerador = ( ans->numerador ) / mcd  ;
	ans->denominador  = ( ans->denominador ) / mcd ;
	
	return ans;
}
