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

void main(void)
{
    int   iopcion  = 0;
    int   flag     = 0;
    int entrada1   = 0;
    int  salida1   = 0;
    spile pile1;
    
    screatepile(&pile1);
       
    while ( flag == 0 )
    {        
        printf( "\n*****************************************************************\n\n" );
        printf( "\t\t\"  Menu funciones con pilas estaticas: \"\t\t\n" );
        printf( "1 Ingresar elemento\n" );
        printf( "2 Quitar elemento y mostrarlo\n" );
        printf( "3 Mostrar tope\n" );
        printf( "4 Vaciar pila\n" );
        printf( "0 Terminar\n" );
        printf( "\nElige una operacion:\n" );
        scanf( "%d",&iopcion );
        printf( "\n" );
        
        if ( iopcion == 0 )
        {/* salir*/
            flag = 1;
            
        }/* if( iopcion == 0 ) */	       
        
        else if ( iopcion == 1 )
        {/* introducir un elemento a la pila */		
            printf( "Introduce un elemento a la pila:\n");
            scanf( "%d",&entrada1 );
            
                   
            if ( spilepush( entrada1,&pile1 ) == 0 )
            printf( "La pila esta llena!\n" );
            if ( spilepush( entrada1,&pile1 ) != 0 )
            printf( "Elemento introducido exitosamente\n" );
        }
        
        else if ( iopcion == 2 )
        {/* sacar un elemento a la pila y mostrarlo*/		
            if ( spilepop( &salida1,&pile1 ) ==  0 )
            printf("La pila esta vacia!\n");
            if ( spilepop( &salida1,&pile1 ) != 0 )
            printf( "El elemento sacado es: %d\n",salida1 );
                        
        }
        
        else if ( iopcion == 3 )
        {/* mostrar tope de pila */		
            
            if ( spiletop(&salida1, &pile1) == 0 )
            printf("La pila esta vacia!\n");
            if ( spiletop(&salida1, &pile1) != 0 )
            printf( "El elemento del tope es: %d\n",salida1 );
        }
        
        else if ( iopcion == 4 )
        {/* vaciar pila */	
            if ( spiledrop(&pile1) == 1 )
            printf( "Pila vaciada! \n" );
        }
        
        else 
        { /* default */
            printf( "\n\n" );
            printf( "%d is not a valid option. \n",iopcion);
            flag = 1;
           
        } /* default */  
    } /* while ( flag == 0 ) */
}
