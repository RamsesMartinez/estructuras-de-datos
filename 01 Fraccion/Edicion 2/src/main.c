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
/* math operations with fractions */
#include "mathohm.h"
/* operations with stacks */
#include <math.h>
 

void main(void)
{
    int iopcion  = 0; 
    int flag    = 0; 
    int exp     = 0;
    double num4 = 0.0;
    
    frac *num1 = ( frac * ) malloc( sizeof( frac )*1 );
    frac *num2 = ( frac * ) malloc( sizeof( frac )*1 );
    frac *num3 = ( frac * ) malloc( sizeof( frac )*1 );
    
    if ( flag == 0 )
    {
        printf( "\n*****************************************************************\n\n" );
        printf( "\t\t\"  Menu funciones con fracciones: \"\t\t\n" );
        printf( "1 Suma\n" );
        printf( "2 Resta\n" );
        printf( "3 Multiplicacion\n" );
        printf( "4 Division\n" );
        printf( "5 Potencia\n" );
        printf( "6 Numerador\n" );
        printf( "7 Denominador\n" );
        printf( "8 MCD\n" );
        printf( "9 Simplificar fraccion\n" );
        printf( "10 Convertir fraccion a decimal\n" );
        printf( "0 Salir\n" );
        printf( "\nElige una operacion:\n" );
        scanf( "%d",&iopcion );
        printf( "\n" );    
                    
        if ( iopcion == 0 )
        {/* salir*/
            flag = 1;
            
        }/* if( iopcion == 0 ) */		
        
        else if( iopcion == 1 )
        {/* suma de fracciones */
            do
            {
                printf( "Introduce la primera fraccion:\n" );
                scanf( "%d/%d",&( num1->numerador ),&( num1->denominador ));
                if( verifrac( num1) == 1 )
                printf( "EL DENOMINADOR NO PUEDER CERO\n" );
            }
            while( verifrac( num1 ) == 1 );
            
            do
            {
                printf( "Introduce la segunda fraccion:\n" );
                scanf( "%d/%d",&( num2->numerador ),&( num2->denominador ));
                if( verifrac( num2 ) == 1 )
                printf( "EL DENOMINADOR NO PUEDER CERO\n" );
            }
            while( verifrac( num2 ) == 1 );
        
            num3 = sumafrac( num1,num2 ) ;
            printf( "El resultado es: %d/%d\n",( num3->numerador ),( num3->denominador ) );
            
            num3 = simpfrac( sumafrac( num1,num2 ) );
            printf( "El resultado es: %d/%d\n",( num3->numerador ),( num3->denominador ) );
        
            free( num1 );
            free( num2 );
            free( num3 );
            
            
            }/* if( iopcion == 1 ) */
        
        else if ( iopcion == 2 )
        {/* resta */
            do
            {
                printf( "Introduce la primera fraccion:\n" );
                scanf( "%d/%d",&( num1->numerador ),&( num1->denominador ));
                if( verifrac( num1 ) == 1 )
                printf( "EL DENOMINADOR NO PUEDER CERO\n" );
            }
            while( verifrac( num1 ) == 1 );
            
            do
            {
                printf( "Introduce la segunda fraccion:\n" );
                scanf( "%d/%d",&( num2->numerador ),&( num2->denominador ));
                if( verifrac( num2 ) == 1 )
                printf( "EL DENOMINADOR NO PUEDER CERO\n" );
            }
            while( verifrac( num2 ) == 1 );
            
            num3 = restafrac( num1,num2 );                      
            printf( "El resultado es: %d/%d\n",( num3->numerador ),( num3->denominador ) );
            
            num3 = simpfrac( restafrac( num1,num2 ) );                      
            printf( "El resultado es: %d/%d\n",( num3->numerador ),( num3->denominador ) );
            
            free( num1 );
            free( num2 );
            free( num3 );
            
            
        
        }/* if( iopcion == 2 ) */
        
        else if ( iopcion == 3 )
        {/* multiplicacion */
            do
            {
                printf( "Introduce la primera fraccion:\n" );
                scanf( "%d/%d",&( num1->numerador ),&( num1->denominador ));
                if( verifrac( num1 ) == 1 )
                printf( "EL DENOMINADOR NO PUEDER CERO\n" );
            }
            while( verifrac( num1 ) == 1 );
            
            do
            {
                printf( "Introduce la segunda fraccion:\n" );
                scanf( "%d/%d",&( num2->numerador ),&( num2->denominador ));
                if( verifrac( num2 ) == 1 )
                printf( "EL DENOMINADOR NO PUEDER CERO\n" );
            }
            while( verifrac( num2 ) == 1 );
                
            num3 = multifrac( num1,num2 );                      
            printf( "El resultado es: %d/%d\n",( num3->numerador ),( num3->denominador ) );
            
            num3 = simpfrac( multifrac( num1,num2 ) );                      
            printf( "El resultado es: %d/%d\n",( num3->numerador ),( num3->denominador ) );
        
            free( num1 );
            free( num2 );
            free( num3 );
            
            
        }/* if( iopcion == 3 ) */
        
        else if ( iopcion == 4 )
        {/* division */
            do
            {
                printf( "Introduce la primera fraccion:\n" );
                scanf( "%d/%d",&( num1->numerador ),&( num1->denominador ));
                if( verifrac( num1 ) == 1 )
                printf( "EL DENOMINADOR NO PUEDER CERO\n" );
            }
            while( verifrac( num1 ) == 1 );
            
            do
            {
                printf( "Introduce la segunda fraccion:\n" );
                scanf( "%d/%d",&( num2->numerador ),&( num2->denominador ));
                if( verifrac( num2 ) == 1 )
                printf( "EL DENOMINADOR NO PUEDER CERO\n" );
            }
            while( verifrac( num2 ) == 1 );
                
            num3 = divfrac( num1,num2 );                      
            printf( "El resultado es: %d/%d\n",( num3->numerador ),( num3->denominador ) );
            
            num3 = simpfrac( divfrac( num1,num2 ) );                      
            printf( "El resultado es: %d/%d\n",( num3->numerador ),( num3->denominador ) );
        
            free( num1 );
            free( num2 );
            free( num3 );
            
            
        }/* if( iopcion == 4 ) */
        
        else if ( iopcion == 5 )
        {/* potencia */
            do
            {
                printf( "Introduce la fraccion:\n" );
                scanf( "%d/%d",&( num1->numerador ),&( num1->denominador ));
                if( verifrac( num1 ) == 1 )
                printf( "EL DENOMINADOR NO PUEDER CERO\n" );
            }
            while( verifrac( num1 ) == 1 );
            
            printf( "Introduce el exponente : \n" );
            scanf("%d",&exp);
                
            num3 = simpfrac( potfrac( num1,&exp ) );
        
            printf( "El resultado es: %d/%d\n",( num3->numerador ),( num3->denominador ) );
        
            free( num1 );
            free( num2 );
            free( num3 );
            
            
        }/* if( iopcion == 6 ) */
        
        else if ( iopcion == 6 )
        {/* numerador */
            do
            {
                printf( "Introduce la fraccion:\n" );
                scanf( "%d/%d",&( num1->numerador ),&( num1->denominador ));
                if( verifrac( num1 ) == 1 )
                printf( "EL DENOMINADOR NO PUEDER CERO\n" );
            }
            while( verifrac( num1 ) == 1 );
            
            printf( "El resultado es: %d\n",(num1->numerador));
        
            free( num1 );
            free( num2 );
            free( num3 );
            
            
        }
        
        else if ( iopcion == 7 )
        {/* denomiador */
            do
            {
                printf( "Introduce la fraccion:\n" );
            scanf( "%d/%d",&( num1->numerador ),&( num1->denominador ));
                if( verifrac( num1 ) == 1 )
                printf( "EL DENOMINADOR NO PUEDER CERO\n" );
            }
            while( verifrac( num1 ) == 1 );
            
            printf( "El resultado es: %d\n",(num1->denominador));
        
            free( num1 );
            free( num2 );
            free( num3 );
            
            
        }/* if( iopcion == 7 ) */
        
        else if ( iopcion == 8 )
        {/* MCD */
            do
            {
                printf( "Introduce la fraccion:\n" );
                scanf( "%d/%d",&( num1->numerador ),&( num1->denominador ));
                if( verifrac( num1 ) == 1 )
                printf( "EL DENOMINADOR NO PUEDER CERO\n" );
            }
            while( verifrac( num1 ) == 1 );
            
            printf( "El resultado es: %d\n",mcdfrac( num1 ) );
        
            free( num1 );
            free( num2 );
            free( num3 );	
    
                        
        }/* if( iopcion == 8 ) */
        
        else if ( iopcion == 9 )
        {/* simplificar fraccion */
            do
            {
                printf( "Introduce la fraccion:\n" );
                scanf( "%d/%d",&( num1->numerador ),&( num1->denominador ));
                if( verifrac( num1 ) == 1 )
                printf( "EL DENOMINADOR NO PUEDER CERO\n" );
            }
            while( verifrac( num1 ) == 1 );
            
            num3 = simpfrac( num1 );
        
            printf( "El resultado es: %d/%d\n",( num3->numerador ),( num3->denominador ) );
        
            free( num1 );
            free( num2 );
            free( num3 );
            
            
        }/* if( iopcion == 9 ) */
        
        else if ( iopcion == 10 )
        {/* convertir a decimal */
            do
            {
                printf( "Introduce la fraccion:\n" );
                scanf( "%d/%d",&( num1->numerador ),&( num1->denominador ));
                if( verifrac( num1 ) == 1 )
                printf( "EL DENOMINADOR NO PUEDER CERO\n" );
            }
            while( verifrac( num1 ) == 1 );
        
            num4 = ( ( double )( num1->numerador ) )/( ( double )( num1->denominador ) );
            printf( "El resultado es: %f\n",num4 );
        
            free( num1 );
            free( num2 );
            free( num3 );
            
            
        }/* if( iopcion == 10 ) */
        
    
        else 
        { /* default */
            printf( "\n\n" );
            printf( "%d is not a valid option.\n",iopcion);
            
            flag = 1;
            
            
        } /* default */        
    } /* if ( flag ==0 ) */
}


