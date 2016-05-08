/**
* Nombre: main.c
* Autor: Ramses Martinez
* Version 1.0.0     17/04/2016
* Descripcion: Programa que convierte una cadena en notacion interfija a notacion posfija
*/

#include "Stack.h"
#include "leercad.h"
#include "ConversorInPos.h"

int main(int argc, char const *argv[])
{
    char opc;
    String cadena;

    do{
        printf("<<< Ingresa una expresion en notacion interfija para convertir a posfija\n>>>   ");
        leerC(&cadena);
        printf("\n<<< La expresion a analizar es la siguiente:\n>>>   ");
        printf("%s\n",cadena);
        /** Valida los parentesis, corchetes y llaves**/
        verificarDelimitadores(&cadena); 
        /** Convierte la cadena */
        convertirExpresion(&cadena);
        /** Evalua la nueva expresion y muestra el resultado*/        
        verificarExpresion(&cadena);
        printf("\n\n<<< Verificar otra expresion? (s/n): >>>   ");
        scanf("%c",&opc);
        fflush( stdin );
        system("cls"); 
    }while(opc == 's' || opc == 'S');
    return 0;

}
