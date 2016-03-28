/** Programa para implementar TDA pila de forma estatica
    @autor Ramses Martinez Ortiz
    @version v1.0.0 - 24/02/2016
*/

#include "PilasEstaticas.h"

int main(){
    int opc;
    printf("Se creara una pila para %d elementos.\n",MAXSTACK);
    StackEntry se;
    Stack p, *pila;
    pila = &p;
    createStack(pila);
    while((opc = menu()) != 7) {
        switch(opc){ 
            case 1:
                printf("\nDato:\t");
                scanf("%d",&se);
                if (push(se,pila))
                    printf("\nNumero insertado\n");
                else
                    printf("Pila Llena! ");
                break;
            case 2:
                
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                imprimir(pila);
                break;
            case 7:
                break;
            
        }
    }
    return 0;
}



