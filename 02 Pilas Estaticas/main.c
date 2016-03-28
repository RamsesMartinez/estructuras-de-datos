/** Programa para implementar TDA pila de forma estatica
    @autor Ramses Martinez Ortiz
    @version v1.0.0 - 24/02/2016
*/

#include "PilasEstaticas.h"

int main(){
    int opc;
    printf("<<< Pila para %d elementos >>>\n",MAXSTACK);
    StackEntry se;
    Stack p, *pila;
    pila = &p;
    createStack(pila);
    imprimir(pila);
    while((opc = menu()) != 6) {
        system("cls");
        switch(opc){ 
            case 1:
                printf("\nDato:\t");
                scanf("%d",&se);
                if (push(se,pila)) 
                    printf("\n<<< Dato insertado >>>\n");
                else
                    printf("\n<<< Pila llena >>>\n");
                break;
            case 2:
                if(stackEmpty(pila))
                    printf("\n << La pila esta vacia >>\n");
                else{ 
                    StackEntry aux = pop(pila);
                    printf("Dato retirado:\t%d\n",aux);
                }
                break;
            case 3:
                if(emptyStack(pila))
                    printf("<<< Pila vaciada >>>\n");
                else
                    printf("<<< Pila vacia >>>\n");
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                printf("\n<<< Elija una opcion valida >>>\n");
        }
        imprimir(pila);
    }
    return 0;
}



