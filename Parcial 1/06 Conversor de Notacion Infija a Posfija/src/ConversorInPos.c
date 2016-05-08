/**
* Name: ConversorInPos.c
* Author: Ramses Martinez
* Version: 1.0.0    14/04/2016
* Description: Archivo que contiene las funciones para el conversor de expresiones infijas a posfijas
*/
#include "ConversorInPos.h"
#include "Stack.h"
#include "leercad.h"

void verificarExpresion(char** cad){
    String cadena = *cad;
    int length = strlen(cadena);
    /** Auxiliares para continuar con el ciclo*/
    int i = 0; 
    StackEntry op1, op2, res;
    int posError;
    bool evalacion = true;

    /** Pila para el evaluador */
    ptrNodoPila pila = NULL; 

    while(cadena[i] != '\0' && evalacion == true){
        /** Validamos si se trata de un operando */
        if(esOperando(cadena[i])){
            int aux = cadena[i] -'0';
            push(&pila,aux);
        }
        else /**Validamos si es un operador */
        if (esOperador(cadena[i])){
            /** Valida si existen al menos dos operandos */
            if(!stackEmpty(&pila)){
                op2 = pop(&pila);
                if (!stackEmpty(&pila)){
                    op1 = pop(&pila);
                    res = calcular(op1, cadena[i], op2);
                    push(&pila,res);
                }else{
                	printf("\nSe esperaba un operando antes del operador %c en lo posicion %d\n",cadena[i],i+1);
                	break;
                }
            }else{
                printf("\nSe esperaban dos operandos antes del operador %c en lo posicion %d\n",cadena[i],i+1);
                break;
            }
        }else{
        	printf("Caracter invalido en la posicion %d\n",i+1);
        	break;
        }
        /** Valida que haya quedado solo un numero en la pila */
        i++;
    }
    if(!stackEmpty(&pila)){
    	res = pop (&pila);
    	if(stackEmpty(&pila))
        	printf("\n<<< Expresion posfija valida!>>>\n<<< Resultado final:\t%d>>>\n",res);
        else
        	printf("\n>>> Se esperaban mas operadores\n");
    }
        
}

void convertirExpresion(char **cad){
    String cadena = *cad;
    String cPosfija = (String*) malloc(sizeof(String));; //Cadena donde se insertara la expresion convertida
    cPosfija = (String *) malloc(sizeof(String));
    /** Pilas para los delimitadores*/
        ptrNodoPila pilaExpresion = NULL;
    int i = 0;
    while(cadena[i] != '\0'){
        if (esOperando(cadena[i]))
            push(&pilaExpresion,cadena[i]);
        else  
        if(esOperador(cadena[i])){
            if (stackEmpty(pila))
            {
                /* code */
            }
        }

        i++;
    }
}

bool esOperador(char c){
    if (c == '+' || c== '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

bool esOperando(char c){
    if(c >= '0' && c <= '9')
        return true;
    return false;
}

int calcular(int op1, char operador, int op2){
    int res;
    switch(operador){
        case '+':
            res = op1 + op2;
        break;
        case '-':
            res = op1 - op2;
        break;
        case '*':
            res = op1 * op2;
        break;
        case '/':
            res = op1 / op2;
        break;
        case '^':
            res = pow(op1,op2);
        break;
    }
    return res;
}


void verificarDelimitadores(char **cad){
    String cadena = *cad;
    int length;
    StackEntry cAbre, cCierra; /** delimitadores que se enviara a las pilas */
  
    /** Evaluamos los parentesis */
    cAbre = '(';
    cCierra = ')';
    verificarDelimitador(&cadena,cAbre,cCierra);
    
    /** Evaluamos los corchetes */
    cAbre = '[';
    cCierra = ']';
    verificarDelimitador(&cadena,cAbre,cCierra);
    
    /** Evaluamos las llaves */
    cAbre = '{';
    cCierra = '}';
    verificarDelimitador(&cadena,cAbre,cCierra);
    

}

void verificarDelimitador(char **cad, char cAbre, char cCierra){
    String cadena = *cad;
    int length = strlen(cadena);
    int i=0; /**Manejara el tamanio de la cadena */
    int posError;
    bool existe = false; /** Variable que nos permite saber si la expresion contiene alguno de los delimitadores */
    
    /** Pilas para los delimitadores*/
    ptrNodoPila pila1P = NULL;
    ptrNodoPila pila2P = NULL;
    
    bool evaluacion1 = true; /** Auxilia a saber si se debe continuar evaluando la expresion */
    bool evaluacion2 = true; /** Auxilia a saber si se debe continuar evaluando la expresion */
    
    /**Ciclo que permite validar la expresion caracter por caracter de izquierda a derecha*/
    while( (cadena)[i] != '\0' && evaluacion1 == true){ 
        if ( (cadena)[i] == cAbre ){ /** Si hay delimitador que abre */
            existe = true;
            push(&pila1P,cAbre );
            evaluacion1 = true;
        } else 
        if ( (cadena)[i] == cCierra ) { /**Si hay delimitador que cierra */
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
    /**Ciclo que permite validar la expresion caracter por caracter de derecha a izquierda*/
    while( i > 0 && evaluacion2 == true){
        if ( (cadena)[i] == cCierra ){ /** Si hay delimitador que cierra */
            push(&pila2P,cCierra );
            evaluacion2 = true;
        } else 
        if ( (cadena)[i] == cAbre ) { /**Si hay delimitador que abre */
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
 
