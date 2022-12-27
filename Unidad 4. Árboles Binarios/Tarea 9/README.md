[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-f4981d0f882b2a3f0472912d15f9806d57e124e0fc890972558857b51b24a6f9.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=9395654)
# Tarea 9: Árbol binario de expresiones
## Estructuras de Datos II
### Fecha de publicación: Viernes 11 de noviembre 2022
### Fecha de entrega: Viernes 18 de noviembre 2022

## Descripción del problema
Un árbol binario de expresiones es un tipo específico de árbol binario
utilizado para representar expresiones aritméticas o expresiones booleanas. 
Las hojas de este tipo de árboles son operandos, tales como 
constantes o nombres de variables, y los nodos interiores son operadores.
Un árbol binario de expresiones se puede evaluar aplicando el operador
de un nodo a los valores obtenidos de la evaluación recursiva 
de los subárboles izquierdo y derecho. De la misma manera, el árbol
se puede imprimir de forma recursiva imprimiendo los subárboles izquierdo
y derecho.  

## Actividad por realizar
* Construir un árbol binario de expresiones aritméticas.
* La expresión aritmética será especificada en formato posfijo.
* La expresión estará compuesta únicamente por dígitos y 
operadores `+`, `-`, `*` y `/`.
* Como salida se deberá mostrar el contenido del arbol y el 
valor numérico de su evaluación.

Por ejemplo, la expresión posfija `263*+` se representa
mediante el árbol
  
```
   +
  / \
 2   *
    / \
   6   3
```

Al ser evaluada esta expresión producirá 
como resultado `20`.

Al momento de imprimir este árbol deberá aparecer 
por niveles en forma vertical de la siguiente manera:
```
        [2]
[+]
                [6]
        [*]
                [3]
```

La primer línea de entrada especifica el número N de 
expresiones que serán evaluadas. Las siguientes N líneas
contienen expresiones válidas en formato posfijo. Cada
elemento de la expresión posfija puede ser un dígito
o un operador `+`, `-`, `*`, `/` (división entera).

Consultar el ejemplo de prueba en el archivo `input.txt` y la salida esperada en `expected_output.txt`. 
Modificar el archivo de entrada para agregar más casos de prueba.

Realizar `commit` y `push` continuos para un desarrollo incremental.

## Retos adicionales (puntos extra)
* Implementar el manejo de errores. Por ejemplo
la expresión `26*+3` no se puede evaluar porque está mal
escrita. Detectar e informar cuando una expresión 
posfija está mal escrita y continuar con la siguiente 
expresión.

* Implementar la entrada de expresiones infijas. Se pueden
utilizar expresiones infijas en lugar de posfijas haciendo
una conversión previa de infijo a posfijo o crear el arbol
directamente a partir de la expresión infija. 
Se sugiere utilizar el algoritmo 
[Shunting yard algorithm](https://en.wikipedia.org/wiki/Shunting_yard_algorithm) para esta conversión.

* Implementar el uso de variables. Se puede incorporar
el operador de asignación `=` para asignar el valor
de una expresión a una variable. Todas las variables
serán de tipo entero y constarán de una sola letra 
minúscula.
Por ejemplo, la siguiente entrada muestra el uso de
variables:
```
5
a1=
b2=
cab+=
aa1+=
bca-=
```

Las cuales producirán los siguientes árboles
binarios y resultados de su evaluación cada una:

```
   =
  / \
 a   1
Resultado de la evaluación: 1

   =
  / \
 b   2
Resultado de la evaluación: 2

   =
  / \
 c   +
    / \
   a   b
Resultado de la evaluación: 3

   =
  / \
 a   +
    / \
   a   1
Resultado de la evaluación: 2

   =
  / \
 b   -
    / \
   c   a
Resultado de la evaluación: 1
```
Sugerencia: utilizar un arreglo para almacenar el valor
de las 26 posibles variables, y al final mostrar el valor
de las variables por medio de una tabla, por ejemplo:

| variable | valor |
|----------|-------|
|  a       |   2   |
|  b       |   1   |
|  c       |   3   |

