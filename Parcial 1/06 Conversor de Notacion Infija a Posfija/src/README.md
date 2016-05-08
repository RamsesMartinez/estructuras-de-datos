#Reglas para la conversion
Para cada caracter que se vaya leyendo de la cadena se validara cada una de las siguientes condiciones de acuerdo al operador que ya exista en la pila.
####Operadondo
Si el caracter es un operando se agrega a la expresion
####Operador == Precedencia 
Se intercambian los operadores. El operador de la pila se saca y el oeprador de la cadena se mete a la pila.
####Operador > Precedencia 
Si el oeprador de la  cadena es de mayor precedencia que el operador de la pila, entonce se agrega a la pila
####Operador < Precedencia
Se sacan los oepradores de la pila que sean de menor precedencia que el operador de la cadena
####Parentesis derecho
Si aparece un parentesis de cierre, entonces se imprimen todos los operadores de la pila hasta que aparesca un parentesis de apertura.