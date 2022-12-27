[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-9f69c29eadd1a2efcce9672406de9a39573de1bdf5953fef360cfc2c3f7d7205.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=9207781)
# Tarea 7: Listas de Listas
## Estructuras de Datos II
### Fecha de publicación: Viernes 28 de octubre 2022
### Fecha de entrega: Viernes 4 de noviembre 2022

## Descripción del problema
Crear una aplicación para una pequeña biblioteca. La aplicación permitirá registrar libros en la biblioteca, prestar un libro a un usuario, regresar un libro prestado y mostrar el estado actual de la biblioteca.

La biblioteca tiene un catálogo de autores y un catálogo de usuarios. Cada autor tiene un nombre y una colección de libros, y cada libro tiene un título y una referencia al usuario que tiene el libro prestado. Todos los usuarios tienen un nombre y una lista de libros en préstamo, y los préstamos tienen referencias cruzadas al autor y al libro prestado.

Al mostrar el estado actual de la biblioteca deberá aparecer el catálogo de autores y el catálogo de usuarios de la biblioteca ordenados alfabéticamente por su nombre. Para cada autor se deberá mostrar en orden alfabético el título cada uno de sus libros y en caso de que el libro esté en préstamo deberá aparecer el nombre del usuario que lo tiene prestado. Para cada usuario se deberá mostrar el título y el autor de los libros que tiene en préstamo, si el usuario no tiene libros prestados entonces deberá aparecer un mensaje correspondiente.

Leer la información desde un archivo de texto. La primer línea del archivo contiene un número entero que especifica la cantidad de operaciones a realizar en la biblioteca. Las operaciones se identifican por medio de un número entero: 
* `1` : registrar un nuevo libro en la biblioteca.
* `2` : prestar un libro a un usuario
* `3` : regresar un libro prestado
* `4` : mostrar el estado actual de la biblioteca

Consultar el ejemplo de prueba en el archivo `input.txt` y la salida esperada en `expected_output.txt`. Modificar el archivo de entrada para agregar más casos de prueba.
