/** 
* Programa para implementar TDA pila de forma estatica
* @autor Ramses Martinez Ortiz
* @version v1.0.2 - 29/02/2016
*    Modificado de la funcion delStack(). 
*    Las validaciones para la pila vacia se hacen ahora desde el main.
*	 Reparado error al crear nueva pila
*/

#include "PilasEstaticas.h"

int main(){ 
    int opc;
    printf("<<< Pila para %d elementos >>>\n",MAXSTACK);
    StackEntry se;
    Stack p, *pila;
    pila = &p;
    createStack(pila);
    printStack(pila);
    while((opc = menu()) != 6) {
        system("cls");
        switch(opc){  
            /** Inserta un elemento*/
            case 1:
                printf("\nDato:\t");
                scanf("%d",&se);
                if (push(se,pila)) 
                    printf("\n<<< Dato insertado >>>\n");
                else
                    printf("\n<<< Pila llena >>>\n");
                break;
            /** Remover un elemento */
            case 2:
                if(stackEmpty(pila))
                    printf("\n << La pila esta vacia >>\n");
                else{ 
                    StackEntry aux = pop(pila);
                    printf("\n<<< Dato retirado: %d >>>\n",aux);
                }
                break;
            /** Vaciar toda la pila */
            case 3:
                if(stackEmpty(pila)){
                	delStack(pila);
                    printf("\n<<< Pila vaciada >>>\n");
                }
                else
                    printf("\n<<< Pila vacia >>>\n");
                break;
            /** Obtener cima de la pila */
            case 4:
                if (stackEmpty(pila))
                    printf("\n << La pila esta vacia >>\n");
                else         
                    printf("\n<<< Cima de la pila: %d >>>\n", pila -> entry[pila -> top]);
                break;
            /** Obtiene el total de elementos en la pila */
            case 5:
                printf("\n<<< Elementos en la pila: %d >>>\n", pila -> top + 1);
                break;
            case 6:
                printf("BYE BYE");
                break;
            default:
                printf("\n<<< Elija una opcion valida >>>\n");
        }
        printStack(pila);
    }
    return 0;
}



