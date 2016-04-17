/**
* Name: Evaluador.c
* Author: Ramses Martinez
* Version: 1.0.0    14/04/2016Archivo que contiene las funciones para el evaluador de notacion posfija
*/
#include "Evaluador.h"
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
                	printf("Se esperaba un operando antes del operador %c en lo posicion %d\n",cadena[i],i+1);
                	break;
                }
            }else{
                printf("Se esperaban dos operandos antes del operador %c en lo posicion %d\n",cadena[i],i+1);
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
