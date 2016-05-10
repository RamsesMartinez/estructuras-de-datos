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
int *list;
int size = 0;
int top = -1;
int data, pos;

    createList(&list);
    while((opc = menu()) != 8) {
        system("cls");
        switch(opc){ 
            // Sets the size of the list
            case 1:
                printf("\n>>> Ingrese el tamanio maximo de datos en la lista:\t");
                scanf("%d",&size);
                setSize(&list, size);
                system("cls");
                printf("\n<<< Tamanio asignado >>>\n");
                top=-1;
                break;
            // Inserts an element in any position
            case 2:
                printf("\nIngresa el dato: >>> ");
                scanf("%d",&data);
                printf("\nIngresa la posicion: >>>");
                scanf("%d",&pos);
                if(insert(&list, data, pos, &top, size))
                    printf("\n<<< Dato insertado >>>");
                else
                    printf("\n<<< Dato no insertado >>>");
                break;
            // Inserts an element at the beginning
            case 3:
                printf("\nIngresa el dato: >>> ");
                scanf("%d",&data);
                if(inStart(&list, data, &top, size))
                    printf("\n<<< Dato agregado >>>");
                else
                    printf("\n<<< Dato no agregado >>>");
                break;
            // Inserts an element at the end
            case 4:
                printf("\nIngresa el dato: >>> ");
                scanf("%d",&data);
                if(inEnd(&list, data, &top, size))
                    printf("\n<<< Dato agregado >>>");
                else
                    printf("\n<<< Dato no agregado >>>");
                break;
            // Searches a data
            case 5:
                printf("\nDato a buscar: >>> ");
                scanf("%d",&data);
                if(top < 0)
                    printf("\nLa lista esta vacia");
                else{
                    pos = searchPosition(&list, data, top);
                    if(pos == 0)
                        printf("\n<<< El dato no existe en la lista >>>");
                    else
                        printf("\n<<< El dato se encuentra en la posicion: %d >>>",pos);
                }
                break;
            //Searches a data given position
            case 6:
                printf("\nPosicion: >>> ");
                scanf("%d",&pos);
                if(pos-1 > top || pos-1 < 0)
                    printf("\n<<< Posicion fuera de la lista >>>");
                else {
                    data = searchData(&list,pos);
                    printf("<<< Dato encontrado: %d >>>",data);
                    }
                break;
            // Removes an element
            case 7:
            	printf("Posicion a remover: >>>");
            	scanf("%d",&pos);
                if(pos -1 > top || pos-1 < 0 )
                    printf("\n<<< Posicion fuera de la lista >>>");
                else{
                    data = removeData(&list, pos, &top);
                    printf("<<<\nDato eliminado: %d >>>",data);

                }
                break;
            case 8:
                printf("BYE BYE");
                    break;
            default:
                printf("\n<<< Elija una opcion valida >>>\n");
        }
        printList(&list,top);
    }
    return 0;
}
