/** 
* Name: Delimitadores.c
* Programa que examina los delimitadores en una expresion y determina si es valido o no.
* Author Ramses Martinez Ortiz
* Version 1.0.0    30/03/2016
* Archivo que contiene las funciones
*/ 
#include "Delimitadores.h"

/** Insertar un nuevo nodo */
void push(ptrNodoPila *ptrCima, StackEntry entry){
    ptrNodoPila ptrNuevo; /** Apuntador al nuevo nodo */
    ptrNuevo = malloc(sizeof(NodoPila));

    /** Inserta el nuevo nodo encima de la pila */
    if(ptrNuevo != NULL){
        ptrNuevo -> entry = entry;
        ptrNuevo -> ptrSiguiente = *ptrCima;
        *ptrCima = ptrNuevo;
    }else{
        printf("%d No se inserto. Memoria insuficiente. \n",entry);
    }
} 

/** Eliminar un nodo de la cima de la pila */
StackEntry pop(ptrNodoPila *ptrCima){
    ptrNodoPila ptrTemp; /** Apuntador a un nodo temporal */
    StackEntry valorElim; /* Valor del nodo */
    
    ptrTemp = *ptrCima;
    valorElim = ( *ptrCima )-> entry;
    *ptrCima = ( *ptrCima ) -> ptrSiguiente;
    free(ptrTemp);
    return valorElim;
}

/** Devuelve la cima de la pila */
StackEntry topStack(ptrNodoPila *ptrCima){
     return (*ptrCima) -> entry;
}

/**Imprimir la pila */
void printStack(ptrNodoPila ptrActual){
    if (ptrActual == NULL){
        printf("\n\t--------");
        printf("\n\t| NULL |");
        printf("\n\t--------");
        printf("\n\t| PILA |");
        printf("\n\t--------\n");
    }else{
        printf("\n\t--------");
        printf("\n\t| NULL |");
        /**Mientras no sea el final de la pila*/
        while(ptrActual != NULL){
            printf("\n\t--------");
            printf("\n\t|  %d   |", ptrActual -> entry);
            ptrActual = ptrActual -> ptrSiguiente;
        }
        printf("\n\t--------");
        printf("\n\t| PILA |");
        printf("\n\t--------\n");
    }
}

/** Elimina toda la pila */
void delStack(ptrNodoPila *ptrActual){
    while(!stackEmpty(ptrActual)){
        StackEntry aux = pop(ptrActual);
    }
}

/** Devuelve true si la pila esta vacia, de lo contrario false */
bool stackEmpty(ptrNodoPila *ptrCima){
    return *ptrCima == NULL;
    
}

int totalNodes(ptrNodoPila ptrActual){
    int nodes = 0; /** Conteo de los nodos */
    while(ptrActual != NULL){
        ptrActual = ptrActual -> ptrSiguiente;
        nodes++;
    }
    return nodes;
}

void verificarExpresion(char **cadena){
	int length;
    StackEntry cAbre, cCierra; /** delimitadores que se enviara a las pilas */

    
    length = strlen(*cadena);
    printf("\n>>>   Longitud de la expresion:   %d",length);


    /** Evaluamos los parentesis */
    cAbre = '(';
    cCierra = ')';
    verificarDelimitador(cadena,cAbre,cCierra);
    
    /** Evaluamos los corchetes */
    cAbre = '[';
    cCierra = ']';
    verificarDelimitador(cadena,cAbre,cCierra);
    
    /** Evaluamos las llaves */
    cAbre = '{';
    cCierra = '}';
    verificarDelimitador(cadena,cAbre,cCierra);
    

}

void verificarDelimitador(char **cadena, char cAbre, char cCierra){
	int length = strlen(*cadena);
	int i=0; /**Manejara el tamanio de la cadena */
	int posError;
	bool existe = false; /** Variable que nos permite saber si la expresion contiene alguno de los delimitadores */
	
    /** Pilas para los delimitadores*/
    ptrNodoPila pila1P = NULL;
    ptrNodoPila pila2P = NULL;
    
	bool evaluacion1 = true; /** Auxilia a saber si se debe continuar evaluando la expresion */
    bool evaluacion2 = true; /** Auxilia a saber si se debe continuar evaluando la expresion */
    
    while( (*cadena)[i] != '\0' && evaluacion1 == true){
        if ( (*cadena)[i] == cAbre ){ /** Si hay delimitador que abre */
        	existe = true;
            push(&pila1P,cAbre );
            evaluacion1 = true;
        } else 
        if ( (*cadena)[i] == cCierra ) { /**Si hay delimitador que cierra */
        	existe = true;
            if ( stackEmpty(&pila1P) ){ /**Si la pila esta vacia*/
                printf("\n\nSe Esperaba un '%c'' antes de la posicion %d",cAbre,i+1);
                evaluacion1 = false;
            }else{
                pop(&pila1P);
                evaluacion1 = true;
            }
        }else
            evaluacion1 = true;
        i++;   
    }
    
    i = length;
    while( i > 0 && evaluacion2 == true){
        if ( (*cadena)[i] == cCierra ){ /** Si hay delimitador que cierra */
            push(&pila2P,cCierra );
            evaluacion2 = true;
        } else 
        if ( (*cadena)[i] == cAbre ) { /**Si hay delimitador que abre */
            if ( stackEmpty(&pila2P) ){ /**Si la pila esta vacia*/
                printf("\n\nSe Esperaba un '%c'' despues de la posicion %d",cCierra,i+1);
                evaluacion2 = false;
            }else{
                pop(&pila2P);
                evaluacion2 = true;
            }
        }else
            evaluacion2 = true;
        i--;   
    }
    if(existe){ /** Imprimimos el resultado de las evalaciones si existieron los delimitadores */
		/**Si todas las pilas estan vacias, entonces los delimitadores estan balanceada */
	    if ( evaluacion1 == true && evaluacion2 == true )
	        printf("\n\n<<<   Los --> %c %c <-- estan balanceados   >>>\n",cAbre,cCierra);
	    else
	        printf("\n\n<<<   Los --> %c %c <-- NO estan balanceados   >>>\n",cAbre,cCierra);
	    }
}
 

