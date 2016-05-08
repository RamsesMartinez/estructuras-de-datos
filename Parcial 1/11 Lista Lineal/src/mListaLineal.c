/**
* Name: mListaLineal.c
* Author: Ramses Martinez
* Version 101.0     08/05/2016
* Description: Programa que implementa el TAD Lista Lineal
*           --> De forma "estática" 
*/
#include "ListaLineal.h"

int main(int argc, char const *argv[]){
int opc;
    createList(&list);
    while((opc = menu()) != 6) {
        system("cls");
        switch(opc){ 
            // Sets the size of the list
            case 1:
                printf("\n>>> Ingrese el tamanio maximo de datos en la lista:\t");
                scanf("%d",&size);
                setSize(&list, size);
                system("cls");
                printf("\n<<< Tamanio asignado >>>\n");
                break;
            // Inserts an element in any position
            case 2:
                printf("\nIngresa el dato: >>> ");
                scanf("%d",&data);
                printf("\nIngresa la posicion: >>>");
                scanf("%d",&pos);
                if(insert(&(*list), data, pos, top, size))
                    printf("\n<<< Dato insertado >>>");
                else
                    printf("\n<<< Dato no insertado >>>");
            break;
            // Inserts an element at the beginning
            case 3:
                if(inStart())
                    printf("\n<<< Dato agregado >>>");
                else
                    printf("\n<<< Dato no agregado >>>");
            break;
            // Removes an element
            case 6:
                printf("BYE BYE");
                break;
            default:
                printf("\n<<< Elija una opcion valida >>>\n");
        }
        printList(&list,end);
    }
    return 0;
}
