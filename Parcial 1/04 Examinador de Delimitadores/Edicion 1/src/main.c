/** 
* Programa que examina los delimitadores en una expresionn y determina si es valido o no.
* @author Ramses Martinez Ortiz
* @version 1.0.0    30/03/2016
*/ 
#include "Delimitadores.h"
#include "leercad.h"

int main(){
    char opc;
   
    String cadena;
    do{
        printf("Ingresa la expresion a evaluar.\n>>>   ");
        leerC(&cadena);
        printf("\nLa cadena a analizar es la siguiente:\n>>>   ");
        printf("%s\n",cadena);
        verificarExpresion(&cadena); /**Ejecutamos la funcion para validar la expresion **/
        
        printf("\n\n<<<   Verificar otra expresion? (s/n): >>>   ");
        scanf("%c",&opc);
        fflush( stdin );
        system("cls"); 
    }while(opc == 's' || opc == 'S');
    return 0;
}
 
