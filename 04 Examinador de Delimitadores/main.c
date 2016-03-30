/** 
* Programa que examina los delimitadores en una expresión y determina si es válido o no.
* @author Ramses Martinez Ortiz
* @version 1.0.0    29/03/2016
*/ 
#include "Delimitadores.h"
 
int main(){
    char opc;
    String resultado;
    do{
        String cadena;
        printf("Ingresa la expresion a evaluar.");
        leerCadena(&cadena);
        int i=0;
        printf("La cadena a analizar es la siguiente: \n");
        printf("\n%s\n",cadena);

        verificarExpresion(&cadena);    

        printf("\nVerificar otra expresion? (s/n): ");
        scanf("%s",&opc);
        fflush( stdin );
    }while(opc == 's' || opc == 'S');
    return 0;
}
 
