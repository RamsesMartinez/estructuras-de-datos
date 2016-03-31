/*
 *    main.c
 * 
 *    Date of creation: 10/03/2016
 *              Author: Hern�ndez Morales Osvaldo
 *             Version: 1.0   
 *                Note: None
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo {
   int valor;
   struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;

/* Funciones con colas: */
void Anadir(pNodo *primero, pNodo *ultimo, int v);
int Leer(pNodo *primero, pNodo *ultimo);
int imprime(pNodo *primero, pNodo *ultimo) ;
 
int main() {
   pNodo primero = NULL, ultimo = NULL;
   int numero, iopcion = 0;
   
   do 
    {
        printf( "\n*****************************************************************\n\n" );
        printf( "\t\t\"  Menu funciones con fracciones: \"\t\t\n" );
        printf( "1 A�adir elemento:\n" );
        printf( "2 Sacar elemento \n" );
        printf( "3 Invertir cola\n" );
        printf( "4 Concatenar cola\n" );
        printf( "5 Imprimir y vaciar cola\n" );
        printf( "0 Salir\n" );
        printf( "\nElige una operacion:\n" );
        scanf( "%d",&iopcion );
        printf( "\n" );    
                    
        if ( iopcion == 0 )
        {/* salir*/
            return 0;
            
        }/* if( iopcion == 0 ) */      
        
        else if( iopcion == 1 )
        {/*  */
            
                printf( "Introduce el elemento entero:\n" );
                scanf( "%d",&numero) ;
                Anadir(&primero, &ultimo, numero);

            
            
        }

        else if( iopcion == 2 )
        {/*  */
            
                printf("ELemento: %d\n", Leer(&primero, &ultimo));

           
            
        }/* if( iopcion == 2 ) */ 

         else if( iopcion == 5 )
        {/*  */
            imprime(&primero, &ultimo); 
                 
            
        }/* if( iopcion == 5 ) */ 
             
   } while ( iopcion != 0 );       

   return 0;
}

void Anadir(pNodo *primero, pNodo *ultimo, int v) {
   pNodo nuevo;
 
   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->valor = v;
   /* Este ser� el �ltimo nodo, no debe tener siguiente */
   nuevo->siguiente = NULL;
   /* Si la cola no estaba vac�a, a�adimos el nuevo a continuaci�n de ultimo */
   if(*ultimo) (*ultimo)->siguiente = nuevo;
   /* Ahora, el �ltimo elemento de la cola es el nuevo nodo */
   *ultimo = nuevo;
   /* Si primero es NULL, la cola estaba vac�a, ahora primero apuntar� tambi�n al nuevo nodo */
   if(!*primero) *primero = nuevo;
}

int Leer(pNodo *primero, pNodo *ultimo) {
   pNodo nodo; /* variable auxiliar para manipular nodo */
   int v;      /* variable auxiliar para retorno */
   
   /* Nodo apunta al primer elemento de la pila */
   nodo = *primero;
   if(!nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
   /* Asignamos a primero la direcci�n del segundo nodo */
   *primero = nodo->siguiente;
   /* Guardamos el valor de retorno */
   v = nodo->valor; 
   /* Borrar el nodo */
   free(nodo);
   /* Si la cola qued� vac�a, ultimo debe ser NULL tambi�n*/
   if(!*primero) *ultimo = NULL;
   return v;
}

int imprime(pNodo *primero, pNodo *ultimo) {
   pNodo nodo;
   nodo = *primero;
   int primeroa;
   int ultimoa;

   if(  *primero  )
   {   
      while  ( *primero )
      {
            
            printf("%d -->", Leer(primero, ultimo));
      }         
      
   } 
   printf(" NULL");
   printf("\n"); 
 
}


