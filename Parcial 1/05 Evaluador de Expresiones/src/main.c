/** 
* Name: main.c
* Author: Ramses Martinez Ortiz
* Version: 1.0.0    14/04/2016
* Description: Programa que evalua expresiones en notacion posfija, indicando si es valida o no
*/ 

#include "Evaluador.h"
#include "Stack.h"
#include "leercad.h"

int main(int argc, char const *argv[])
{
	char opc;
    String cadena;

    do{
        printf("Ingresa la expresion en notacion posfija que quieras evaluar.\n>>>   ");
        leerC(&cadena);
        printf("\nLa expresion a analizar es la siguiente:\n>>>   ");
        printf("%s\n",cadena);
        verificarExpresion(&cadena); /**Ejecutamos la funcion para validar la expresion **/
        
        printf("\n\n<<<   Verificar otra expresion? (s/n): >>>   ");
        scanf("%c",&opc);
        fflush( stdin );
        system("cls"); 
    }while(opc == 's' || opc == 'S');
	return 0;
}
