/**
* Archivo que contiene las funciones para el funcionamiento de la calculadora
*/
#include "Fraccion.h"

void pedirDatos(fraccion *ap1,fraccion *ap2,fraccion *apRes){
    int opc; /** Variable para la eleccion del menu*/
    char cont='s'; /** Variable para continuar con el boocle del menu */
    printf("Bienvenido\n");
    while (cont != 'n' || cont == 'N'){  
        printf("1. Sumar\n");
        printf("2. Restar\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("5. Potenciar\n\n");
        printf("Selecciona la operacion que quieres hacer:\t");
        scanf("%d",&opc);
        
        switch(opc){ /** Evalua la opcion elegida del menu*/
            case 1: 
                printf("\nSuma\n");
                printf("Fraccion 1:\n"); 
                crearFraccion(ap1);
                printf("\nFraccion 2:\n");
                crearFraccion(ap2);
                sumar(ap1, ap2, apRes);
                imprimirResultado(apRes);
                break;
            case 2:
                printf("\nResta\n");
                printf("Fraccion 1:\n");
                crearFraccion(ap1);
                printf("\nFraccion 2:\n");
                crearFraccion(ap2);
                restar(ap1, ap2, apRes);
                imprimirResultado(apRes);
                break;
            case 3:
                printf("\nMultiplicacion\n");
                printf("Fraccion 1:\n");
                crearFraccion(ap1);
                printf("\nFraccion 2:\n");
                crearFraccion(ap2);
                multiplicar(ap1, ap2, apRes);
                imprimirResultado(apRes);
                break;
            case 4:
                printf("\nDivision\n");
                printf("Fraccion 1:\n");
                crearFraccion(ap1);
                printf("\nFraccion 2:\n");
                crearFraccion(ap2);
                dividir(ap1, ap2, apRes);
                imprimirResultado(apRes);
                break;
            case 5:
                printf("\nPotencia\n");
                int pot;
                printf("Fraccion 1:\n");
                crearFraccion(ap1);
                do{
                    printf("\nPotencia (entero):\t");
                    scanf("%d",&pot);
                    if (pot < 0)
                        printf("La potencia debe ser un entero positivo\n");
                }while (pot < 0);
                potenciar(ap1, apRes, pot);
                imprimirResultado(apRes);
                break;
            default:
                printf("Opcion invalida");
        }
        printf("\nOtra operacion? (s/n):\t");    
        scanf("%s",&cont);
    }
}

void crearFraccion(fraccion *ap){
    int num, den; 
    printf("Numerador:\t");
    scanf("%d",&num);
    
    printf("Denominador:\t");
    scanf("%d",&den);
    
    if(den == 0){ /** Evita la division entre cero */
        while(den == 0){
            printf("\nEl denominador no puede ser 0");
            printf("\nDenominador:\t");
            scanf("%d",&den);
        }
    }
    
    ap -> numerador = num;
    ap -> denominador = den;
    
}

/** Funciones para realizar las operaciones */
void sumar(fraccion *ap1, fraccion *ap2, fraccion *apRes){      
    apRes -> numerador = ap1 -> numerador * ap2 -> denominador + ap1 -> denominador * ap2 -> numerador;
    apRes -> denominador = ap1 -> denominador * ap2 -> denominador;    
}

void restar(fraccion *ap1, fraccion *ap2, fraccion *apRes){      
    apRes -> numerador = ap1 -> numerador * ap2 -> denominador - ap1 -> denominador * ap2 -> numerador;
    apRes -> denominador = ap1 -> denominador * ap2 -> denominador;    
}
void multiplicar(fraccion *ap1, fraccion *ap2, fraccion *apRes){      
    apRes -> numerador = ap1 -> numerador * ap2 -> numerador;
    apRes -> denominador = ap1 -> denominador * ap2 -> denominador;    
}
void dividir(fraccion *ap1, fraccion *ap2, fraccion *apRes){      
    apRes -> numerador = ap1 -> numerador * ap2 -> denominador;
    apRes -> denominador = ap1 -> denominador * ap2 -> numerador;
}
void potenciar(fraccion *ap1, fraccion *apRes, int pot){
    int x, y;
    apRes -> numerador = pow(ap1 -> numerador, pot);
    apRes -> denominador = pow(ap1 -> denominador, pot);
}

 void imprimirResultado(fraccion *apRes){
    printf("\nResultado:");
    simplificar(apRes);
    printf("\nnumerador: %d\ndenominador: %d\n",apRes -> numerador, apRes -> denominador );
 }
 
void simplificar(fraccion *apRes){
    int mcd = MCD(apRes);

    apRes -> numerador = apRes -> numerador / mcd;
    apRes -> denominador = apRes -> denominador / mcd;

    /**Verifica que el numerador y denominador no tengan el mismo signo*/
    if (apRes -> numerador < 0 || apRes -> denominador < 0) {
        apRes -> numerador = apRes -> numerador * -1;
        apRes -> denominador = apRes -> denominador * -1;
    }
}

int MCD(fraccion* ap){
    int x = ap -> numerador;
    int y = ap -> denominador;
    int residuo, mcd;
    do{
        residuo = x % y;
        if(residuo != 0){
            x = y;
            y = residuo;
        }else{
            mcd = y;
        }
    }while (residuo != 0);
    return mcd;
}