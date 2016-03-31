/* cabecera de funciones con pilas */
#include "stackohm.h"

/* crea pila estatica */
int screatepile( spile *s )
{
    s->top = -1;
}

/* verifica si la pila estatica */
int spempty( spile *s )
{
    return ( s->top <= -1 );    
}

/* verifica si la pila estatica esta llena */
int spfull( spile *s )
{
    return ( s->top >= MAXSTACK );
}

/* insertar elemento stackentry en pila estatica */
int spilepush(stackentry item, spile *s)
{
    if(spfull(s))
    return 0;
    
    else
    {    
       s->entry[ ++s->top ] = item;
       return 1;
    }   
}

/* sacar elemento stackentry en pila estatica */
int spilepop( stackentry *item, spile *s )
{   
    if( spempty( s ) )
    return 0;
    
    else
    {  
       *item = s->entry[ s->top--  ];  
       return 1;
    }   
}       

/* tope de la pila dinamica por referencia item */
int spiletop( stackentry *item, spile *s )
{
    if(spempty(s))
    return 0;
    else
    {    
       spilepop(item,s);
       spilepush(*item,s);
    }
    return 1;
}

/* vaciar pila */
int spiledrop( spile *s )
{
    if(spempty(s))
    return 1;   
    
    else
    {
        --s->top;
        return spiledrop(s);
    }    
}

/* introduce elemento stackentry en pila dinamica */
void dpilepush( ptrnodedstack *ptrCima, stackentry info )
{
    ptrnodedstack ptrNuevo;
    
    ptrNuevo = malloc(sizeof(nodedstack));
    
    if (ptrNuevo != NULL)
    {
        ptrNuevo->dato = info;
        ptrNuevo->ptrnext = *ptrCima;
        *ptrCima = ptrNuevo;
    }
    else 
    {
        printf( "%d nose inserto. Memoria insuficiente.\n",info );
        
    }
}

/* saca elemento stackentry en pila dinamica */
int dpilepop (stackentry *item,ptrnodedstack *ptrCima)
{
    ptrnodedstack ptrTemp;
    stackentry valorElim;
    
    ptrTemp;
    valorElim = (*ptrCima)->dato;
    *ptrCima = (*ptrCima)-> ptrnext;
    free(ptrTemp);
    *item = valorElim;
    
    return 1;
}

/* imprime los elemnetos de la pila pila dinamica */
void pdpile( ptrnodedstack ptrActual)
{
    if (ptrActual == NULL)
    {
        printf("La pila esta vacia.\n\n");
    }
    else 
    {
        printf( "La pila es:\n" );
        
        while ( ptrActual != NULL )

        {
            printf("%d->",ptrActual->dato);
            ptrActual = ptrActual->ptrnext;
        }    
        printf("NULL\n\n");    
    }
    
}

/* verifica si hay elemento stackentrys en pila dinamica */
int dpempty( ptrnodedstack ptrCima )
{
    return ptrCima == NULL;
}


