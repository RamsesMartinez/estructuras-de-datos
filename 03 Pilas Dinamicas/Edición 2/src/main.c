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
#include <stdlib.h>

/* operations with stacks */
#include "stackohm.h"

void main (void)
{
    ptrnodedstack ptrPila = NULL;
    int eleccion          = 0;
    int valor;
    int c;
    
    printf("Introduzca su eleccion:\n"
                "1 para insertar un elemento dentro de la pila\n"
                "2 para quitar un elemento de la pila\n"
                "3 para terminar el programa\n");
                
    printf("?");
    scanf( "%d", &eleccion );
    
    while ( eleccion != 3 )
    {
        if ( eleccion == 1 )
        {
            
            printf( "Introduzca un elemento: \n" );
            scanf( "%d",&valor );
            dpilepush(&ptrPila,valor);
            pdpile( ptrPila );
        }
         else if ( eleccion == 2 )
         { 
            if (  !dpempty( ptrPila ) )
            {   
                dpilepop( &c,&ptrPila);
                printf(  "El valor sacado es %d.\n",c );
                    
            }
            pdpile( ptrPila );
         }
         else
         {
            printf( "Eleccion no valida.\n\n" );
            
        }
        
        printf( "? " );
        scanf("%d",&eleccion);
    }
    printf ("Fin del programa.\n");
}

