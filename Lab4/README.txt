Respecto de la gramatica:
Para que funcionase con bison, fue necesario marcar una division entre 
numeros reales y enteros, ya que para mostrar el resultado se requeria hacer
uso de un printf() y este printf() cambia respecto del valor que se encuenre dentro,
por lo tanto si se quiere mostrar un numero entero el printf quedaria como printf("%d\n",$1)
en cambio si hubiese sido un numero real el printf seria printf("%f\n",$1), haciendo la 
distincion entre %d y %f.

Adicionalmente respecto a la gramatica, para poder realizar las operaciones, estas fueron 
desarrolladas y por consiguiente, movidas de su posicion original 

Instrucciones referentes al programa:

Compilacion:
    flex lexico.l
    bison sintac.y -dy
    gcc y.tab.c lex.yy.c -o sintac


Funcionalidades:
Funciona la mayoria de las operaciones tanto para numeros enteros como para numeros reales,
la resta funciona y entre numeros negativos, no obtante expresiones como -2-2 no son consideradas,
pero si -2+-2.

Las expresiones que el programa toma en cuenta van todas juntas y no debe existir espacios entre
elementos, i.e: "1 + 2" mostrara por pantalla solo 1, en cambio "1+2" dara el resultado de 3.
Por lo anterior, la funcion solicitada, raiz cuadrada, no debe tener espacios entre su llamado
y el numero, i.e: "sqrt 2" dira que es una expresion incorrecta, pero "sqrt2" mostrara un resultado.

Dado que numeros enteros y reales fueron vistos de forma paralela, combinaciones como
"1+1.2" dira que es una expresion incorrecta, no obstante "1.2+1" mostrara un resultado
lo cual es algo que no pude arreglar.

Finalmente tener en cuenta que nuevamente esta separacion de numeros implica que la division
entre numeros enteros exista, pero esta pasa a ser division entera, junto tambien con la
operaciones sqrt.