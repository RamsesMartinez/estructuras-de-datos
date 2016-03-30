/** 
* Programa que examina los delimitadores en una expresiÃƒÂ³n y determina si es vÃƒÂ¡lido o no.
* @author Ramses Martinez Ortiz
* @version 1.0.0    29/03/2016
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

/** Verifica un delimitador. Retorna true si es correcto, de lo contraio retorna false */
bool verificarDelimitador(char expresion [], char cAbre, char cCierra){
    int i=0;
	int posError, aux;
    bool balanceo = true;
    ptrNodoPila pila = NULL; /** Pila donde se almacenaran los delimitadores */
    /** Recorrde la cadena */
    while (expresion[i] != '\0' && balanceo == true){
        /** Si el elemento coincide con el caracter que abre, lo ingresa en la pila*/
        if (expresion[i] == cAbre){
            push(&pila, expresion[i]);
            /* Si el elemento coincide con el caracter que cierra, lo saca de la pila */
        } else 
            if (expresion[i] == cCierra){
                /** 
                * Si la pila esta vacia, significa que los caracteres no estan balanceados
                * porque se encontro un caracter que cierra sin que exista antes un caracter que abre
                */
                if (stackEmpty(&pila)){/*Si la pila esta vacia */
                	printf("\n <<<Error en la posicion %d, se esperaba un %c antes. >>>\n",i+1,cAbre);
					balanceo = false;
                }
                 else /** Si la pila no esta vacia */
                    aux = pop(&pila);
            }
        i++;
    }
  
    /* 
    * Si balanceo = true pero la pila no esta vacia, los caracteres no estann balanceados
    * porque quedaron caracteres que abren sin tener su caracter que cierra
    */
    if (balanceo == true && !stackEmpty(&pila)){
    	printf("\n <<<Error en la expresion, Faltan %c por cerrar >>>\n",cAbre);
    	balanceo = false;
	}
 
    /** Se asegura de dejar la pila vacia */
    while (!stackEmpty(&pila))
        pop(&pila);
        
    return balanceo; 
}

void verificarExpresion(String *cadena){
    bool p,c,l,balanceada; /** Evalua si hay parentesis, corchetes o llaves*/
    p = c = l = false;
    balanceada = true;
    int i=0;
      
    while((*cadena)[i] != '\0'){
    	if((*cadena)[i] == '(' || (*cadena)[i] == ')'){
			printf("no puede ser");
    		p = true;
    	}
    	if ((*cadena)[i] == '{' || (*cadena)[i] == '}')
    		l = true;
    	if ((*cadena)[i] == '[' || (*cadena)[i] == ']')
    		c = true;
    	i++;
	}
	
	if(p == true){
		/** Verifica si los parenetsis estan balanceados */
	    if (verificarDelimitador(*cadena, '(', ')'))
	        printf("Los parentesis estan balanceados\n");
	    else{
	        printf("Los parentesis NO estan balanceados\n");
	        balanceada = false;
	    }
	}  
	if(c == true){
	    /** Verifica si los corchetes estan balanceados */
	    if (verificarDelimitador(*cadena, '[', ']'))
	        printf("Los corchetes estan balanceados\n");
	    else{
	        printf("Los corchetes NO estan balanceados\n");
	        balanceada = false;
	    }
	}
    if(l == true){
		/**Verifica si las llaves estan balanceadas */
	    if (verificarDelimitador(*cadena, '{', '}'))
	        printf("Las llaves estan balanceadas\n");
	    else{
	        printf("Las llaves NO estan balancead s\n");
	        balanceada = false;
	    }
	}
	if(balanceada){
		printf("\n<<<Los delimitadores estan balanceados>>>");
	}
}

void leerCadena(String *cadena){
    char c; /**Almacena el caracter leido */
    int i; /** Contola el tamanioo de la cadena */
    String auxiliar = NULL; /** Almacena la cadena antes de ser copiada a la direccion recibida */

    if((*cadena) !=NULL){
        free(*cadena);
        (*cadena) = NULL;
    }
    i = 1; /** Inicializa en uno para almacenar el primer caracter */
    while ((c = getchar()) != '\n'){
        auxiliar = (String) realloc(auxiliar, (i+2)*sizeof(char));
        if(auxiliar == NULL){
            printf("Memoria insuficiente !\n");
            exit(EXIT_FAILURE);
        }
        auxiliar[i-1] = c;
        auxiliar[i] = '\0';
        i++;
    } if(auxiliar == NULL){
        (*cadena) = (String)realloc((*cadena),5*sizeof(char));
        strcpy((*cadena),"NULO");
    }else{
        (*cadena) = (String)realloc((*cadena),(strlen(auxiliar)+1)*sizeof(char));
        strcpy((*cadena),auxiliar);
    }
    free(auxiliar);
}











