/*

Tarea 11: Árboles Balanceados AVL
Estructuras de Datos II
Fecha de publicación: Viernes 25 de noviembre 2022
Fecha de entrega: Viernes 2 de diciembre 2022

Nombre del alumno: ___________________________________________
Nombre de usuario en omegaUp: ________________________________

*/

#include <stdio.h>
#include <ctype.h>

// IMPORTANT: Comment the next line before submitting to omegaUp
#define DEBUG

void insert_node();
void erase_node();
void print_height();
void print_by_level();

int main(void)  {
    // IMPORTANT: Comment the next line before submitting to omegaUp
    freopen("input.txt", "rt", stdin);
    // freopen("output.txt", "rt", stdout);

    int number_of_operations;
    scanf("%d", &number_of_operations);
    while (number_of_operations--) {
        char operation;
        scanf("\n%c", &operation);
        switch (toupper(operation)) {
            case 'I':
                insert_node();
            break;
            case 'E':   
                erase_node();
            break;
            case 'A':    
                print_height();
            break;
            case 'P':      
                print_by_level();
            break;
        }
    }
    return 0;
}

void insert_node()
{
    int value;
    scanf("%d", &value);
#ifdef DEBUG
    printf("Inserting node with value %d\n", value);
#endif
    // TODO: insert node with the specified value
}

void erase_node()
{
    int value;
    scanf("%d", &value);
#ifdef DEBUG
    printf("Erasing node with value %d\n", value);
#endif
    // TODO: erase node with the specified value
}

void print_height()
{
#ifdef DEBUG
    printf("Printing the tree's height\n");
#endif
    // TODO: print the tree's height
}

void print_by_level()
{
#ifdef DEBUG
    printf("Printing the tree's content level by level\n");
#endif
    // TODO: print the tree's content level by level
}
