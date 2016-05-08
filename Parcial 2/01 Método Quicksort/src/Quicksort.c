/**
* Name: Quicksort.c
* Author: Ramses Martinez
* Version 1.1.0     08/05/2016
* Decription: Archivo que contiene los metodos para el programa Quicksort
*               --> usando recursividad
*/
#include "quicksort.h"

int menu(){
    int opc;
    printf("\n***** Elige una opcion: *****\n");
    printf("1. Crear nueva lista de numeros\n");
    printf("2. Ordenar lista\n");
    printf("3. Mostrar lista\n");
    printf("4. Salir\n");
    printf(">>>>> ");
    scanf("%d",&opc);
    printf("\n");
    fflush( stdin);
    return opc;
}

/** Crea la lista de numeros de forma dinamica */
void crearLista(int **L,int *tam){
    int num,i;
    char cont = 's';
    if(*L != NULL){
        free(*L);
        *L = NULL;
    }
    /** reserva espacio para la lista */
    *L = (int*) malloc(sizeof(int));
    i=1;
    /** Solicita los numeros*/
    while(cont == 's' || cont == 'S'){
        /**Asigna mas memoria */
        *L = (int*) realloc(*L, (i)*sizeof(int));
        printf("Numero %d:\t>>> ",i);
        scanf("%d",&num);
        fflush(stdin);
        (*L)[i-1] = num;
        *tam  = i++; //Asigna el tamanio de i a tam y luego incrementa i en 1
        printf("Otro? (s/n) >>> ");
        scanf("%c",&cont);
        fflush( stdin);
    }
}

void mostrarLista(int **L, int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("%d: %d\n", i+1,(*L)[i]);
	}
}

 /** Reordena la lista que reciba utilizando el metodo quicksort */
void quicksort(int **L, int ini, int fin){
    int aux;
    int izq = ini;
    int der = fin;
    int pos = ini;
    bool band = true;
    while(band){
        band = false;
        while((*L)[pos] <= (*L)[der] && pos != der){ 
            der = der - 1;
        } 
        if (pos != der){
            aux = (*L)[pos];
            (*L)[pos] = (*L)[der];
            (*L)[der] = aux;
            pos = der;
            while((*L)[pos] >=  (*L)[izq] && pos != izq){
                izq = izq + 1;
            } 
            if (pos != izq) { 
                band = true;
                aux = (*L)[pos];
                (*L)[pos] = (*L)[izq];
                (*L)[izq] = aux;
                pos = izq;
            }
        }
    }  
    if (pos-1 > ini)
        quicksort(&(*L), ini, pos-1);

    if (fin > pos+1)
        quicksort(&(*L), pos+1, fin);
}
