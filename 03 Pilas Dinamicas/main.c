/** 
* Programa que maneja las pilas utilizando memoria dinamica
* @author Ramses Martinez Ortiz
* @version 1.0.0    28/03/2016
*/ 
#include "PilasDinamicas.h"

int main(){
    /** Apunta al tope de la pila */
    ptrNodoPila ptrPila = NULL;
    int opc;
    StackEntry se;
      
    //printStack(pila);

    while((opc = menu()) != 6) {
        system("cls");
        switch(opc){ 
            /** Inserta un elemento */
            case 1:
                printf("\nDato:\t");
                scanf("%d",&se);
                push(&ptrPila,se);
                printf("\n<<< Dato insertado >>>\n");
                break;

            /** Remover un elemento */                
            case 2:
                if(stackEmpty(ptrPila))
                    printf("\n << La pila esta vacia >>\n");
                else{ 
                    StackEntry aux = pop(&ptrPila);
                    printf("\n<<< Dato retirado: %d >>>\n",aux);
                }
                break;

            /** Vacia toda la pila*/
            case 3:
                if (stackEmpty(ptrPila))
                    printf("\n <<< Pila vacia >>>\n");
                else{
                    delStack(&ptrPila);
                    printf("\n<<< Pila vaciada >>>\n");
                }
                break;
            /** Obtiene la cima de la pila */
            case 4:
                /*if (stackEmpty(ptrPila))
                    printf("\n << La pila esta vacia >>\n");
                else         
                    printf("\n<<< Cima de la pila: %d >>>\n", ptrPila -> entry[pila -> top]);
                break;
                */
            /** Otiene la cantidad de elementos en la pila */
            case 5:
                // printf("\n<<< Elementos en la pila: %d >>>\n", ptrPila -> top + 1);
                break;
            case 6:
                printf("BYE BYE");
                break;
            default:
                printf("\n<<< Elija una opcion valida >>>\n");
        }
        printStack(ptrPila);
    }
    return 0;
}
