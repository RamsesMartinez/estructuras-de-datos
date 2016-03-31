/*
 *    main.c
 * 
 *    Date of creation: 10/03/2016
 *              Author: Hernández Morales Osvaldo
 *             Version: 1.0   
 *                Note: None
 */

/* Standard Input and Output */ 
#include <stdio.h>
/* Standard General Utilities Library 
   including dynamic memory management, 
   random number generation, communication with the environment */

#include "stackohm.h"

void main (void) {
    char expresion[MAXSTACK];
    char caracter;
    int length;
    int i;
    int counter = 0;
    int pA = 0;
    int pC = 0;
    int aux;
    int posicion;
        
    ptrnodedstack ptrPila1 = NULL;
    ptrnodedstack ptrPila2 = NULL;
	ptrnodedstack ptrPila3 = NULL;
    ptrnodedstack ptrPila4 = NULL;
	ptrnodedstack ptrPila5 = NULL;
    ptrnodedstack ptrPila6 = NULL;
    
    printf("\nExpresion a analizar:\n");
    
    scanf("%s",expresion);
    printf("Expresion:%s\n",expresion);
    length = strlen(expresion);
    printf("Longitud:%d\n\n",length);
    
    
    for( i=0;i<length;i++) 
    {
        
        if ( expresion[i] == '(' )
            dpilepush(&ptrPila1,i);
        if ( expresion[i] == ')' )
            {    
                if ( !dpempty( ptrPila1 ) )
                dpilepop( &aux,&ptrPila1);
                else if ( dpempty( ptrPila2 ) )                
                dpilepush(&ptrPila2,i);
            }                
    }

   
	    if ( !dpempty( ptrPila2 )  )
    {    
        dpilepop( &aux,&ptrPila2);
        dpilepush(&ptrPila2,aux);
        if ( expresion[aux] == ')' )
        printf("Se esperaba un \'(\' antes de la posicion %d\n",aux+1);
    }
    
    if ( !dpempty( ptrPila1 ) ) 
    {
        dpilepop( &aux,&ptrPila1);
        dpilepush(&ptrPila1,aux);
        if ( expresion[aux] == '(' )
        printf("Se esperaba un \')\' despues de la posicion %d\n",aux+1);
    }

    counter = 0;
     pA = 0;
    pC = 0;

    for( i=0;i<length;i++) 
    {
        
        if ( expresion[i] == '[' )
            dpilepush(&ptrPila3,i);
        if ( expresion[i] == ']' )
            {    
                if ( !dpempty( ptrPila3 ) )
                dpilepop( &aux,&ptrPila3);
                else if ( dpempty( ptrPila4 ) )                
                dpilepush(&ptrPila4,i);
            }                
    }

   
	    if ( !dpempty( ptrPila4 )  )
    {    
        dpilepop( &aux,&ptrPila4);
        dpilepush(&ptrPila4,aux);
        if ( expresion[aux] == ']' )
        printf("Se esperaba un \'[\' antes de la posicion %d\n",aux+1);
    }
    
    if ( !dpempty( ptrPila3 ) ) 
    {
        dpilepop( &aux,&ptrPila3);
        dpilepush(&ptrPila3,aux);
        if ( expresion[aux] == '[' )
        printf("Se esperaba un \']\' despues de la posicion %d\n",aux+1);
    }

    counter = 0;
     pA = 0;
    pC = 0;

    for( i=0;i<length;i++) 
    {
        
        if ( expresion[i] == '{' )
            dpilepush(&ptrPila5,i);
        if ( expresion[i] == '}' )
            {    
                if ( !dpempty( ptrPila5 ) )
                dpilepop( &aux,&ptrPila5);
                else if ( dpempty( ptrPila6 ) )                
                dpilepush(&ptrPila6,i);
            }                
    }

   
	    if ( !dpempty( ptrPila6 )  )
    {    
        dpilepop( &aux,&ptrPila6);
        dpilepush(&ptrPila6,aux);
	    if ( expresion[aux] == '}' )
        printf("Se esperaba un \'{\' antes de la posicion %d\n",aux+1);
    }
    
    if ( !dpempty( ptrPila5 ) ) 
    {
        dpilepop( &aux,&ptrPila5);
        dpilepush(&ptrPila5,aux);
        if ( expresion[aux] == '{' )
        printf("Se esperaba un \'}\' despues de la posicion %d\n",aux+1);
    }

    counter = 0;
     pA = 0;
    pC = 0;
	
	
	
    if (  dpempty( ptrPila1  ) && dpempty( ptrPila2  ) && dpempty( ptrPila3  ) && dpempty( ptrPila4 ) && dpempty( ptrPila5  ) && dpempty( ptrPila6  ) )
    {
        printf("Expresion balanceada.\n");
    }
	
}


