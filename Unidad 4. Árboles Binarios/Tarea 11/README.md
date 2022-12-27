[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-f4981d0f882b2a3f0472912d15f9806d57e124e0fc890972558857b51b24a6f9.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=9514155)
# Tarea 11: Árboles Balanceados AVL
### Estructuras de Datos II
### Fecha de publicación: Viernes 25 de noviembre 2022
### Fecha de entrega: Viernes 2 de diciembre 2022

## Descripción del problema
Un árbol binario es una estructura de datos
jerárquica autoreferenciada, donde cada elemento de la
estructura denominado *nodo* contiene un valor único
y un par de referencias a otros dos *nodos* denominados hijos.
Existe un nodo especial llamado *raiz* al cual ningún otro nodo
hace referencia, y los *nodos* que no tienen referencias
hacia ningún otro se denominan *hojas*.

Un árbol binario de búsqueda mantiene la propiedad de que
para cualquier nodo $X$, el conjunto de valores {$I$}
de los nodos del subárbol izquierdo son menores que $X$,
y el conjunto de valores {$D$} de los nodos del
subárbol derecho son mayores que $X$, de tal forma que
{$I$} $\lt X \lt$ {$D$}. Los valores $X$ en el árbol binario
de búsqueda no se pueden repetir.

La altura de un nodo en un árbol binario se define
como la máxima cantidad de aristas que existen en algún
camino que va desde el nodo en cuestión hasta alguna
de sus hojas.
De esta manera, la altura de una hoja es $0$ y
la altura $h$ de un nodo $n$ se define como
$h(n)=1+max(h(n\rightarrow izq), h(n\rightarrow der))$,
por definición la altura de un nodo nulo es $-1$.

Un árbol binario de búsqueda balanceado **AVL**
tiene la característica de que para cualquiera de sus nodos
existe una diferencia máxima de $1$ entre la altura de su
subárbol izquierdo con respecto a la altura de su subárbol derecho.
Para poder expresar esto de manera más concreta, se define el
factor de balance $fb$ de un nodo $n$ como
$fb(n)=h(n\rightarrow izq)-h(n\rightarrow der)$.

Escribir un programa para realizar las operaciones de inserción y
eliminación de números enteros en un árbol AVL, además de poder
consultar la altura del arbol e imprimir su contenido por niveles.

## Entrada
La primer línea de entrada contiene un entero $N$ ($1 \leq N \leq 10^5$),
la cantidad de operaciones a realizar.
Cada una de las siguientes $N$ líneas definen una operación a realizar
sobre un árbol inicialmente vacío.
La operación de inserción se identifica por la letra `I` seguida de un
entero $X$ ($-10^9 \leq X \leq 10^9$) que será agregado al árbol.
La operación de eliminación se representa por medio de la letra `E`
seguida de un entero $X$ ($-10^9 \leq X \leq 10^9$) a eliminar.

La letra `A` imprime la altura del árbol, y la letra `P` imprime
el contenido del árbol por niveles de arriba hacia abajo y de izquierda
a derecha, todo en una misma línea. Si el árbol está vacío entonces
imprime una línea vacía.

## Salida
Imprimir una línea por cada operación `A` o `P` de acuerdo con lo descrito
en el párrafo anterior.

## Ejemplo de entrada
```
13
I 20
I 15
I 5
A
P
I 40
I 50
I 18
A
P
E 20
E 40
P
```

## Ejemplo de salida
```
1
15 5 20
2
20 15 40 5 18 50
15 5 50 18
```

# EVALUACION
* La calificación de esta tarea estará determinada 
por la evaluación que obtenga en el juez de omegaUp.
* Para poder evaluarlo es necesario que se registre en omegaUp y 
proporcione su nombre de usuario en los comentarios del archivo `main.c`.
* En omegaUp solamente se envía el contenido del archivo `main.c`, por lo
cual es necesario colocar todo el código en un mismo archivo.
* Se deben poner en comentarios las líneas `#define DEBUG` y `freopen()` antes de evaluarlo en omegaUp.
* El juez donde se debe evaluar la solución es https://omegaup.com/arena/problem/Arboles-Balanceados-AVL/

# IMPORTANTE
* Realizar `commit` y `push` continuos para un desarrollo incremental.
* Consultar el ejemplo de prueba en el archivo `input.txt` y la salida esperada en `expected_output.txt`.


