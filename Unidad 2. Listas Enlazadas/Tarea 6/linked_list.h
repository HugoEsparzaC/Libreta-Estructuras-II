#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>
#include <stdbool.h>

typedef int list_data_t;
typedef struct list_node list_node_t;
typedef struct list list_t;

struct list_node {
   list_data_t data;
   struct list_node *prev;
   struct list_node *next;
};

struct list {
   struct list_node *sentinel;
   size_t size;
};

// initialize the list
void list_init(list_t *list);

// destroys an entire list
void list_destroy(list_t *list);

// checks if list is empty
bool list_is_empty(const list_t *list);

// counts the items on a list
size_t list_size(const list_t *list);

// inserts item at front of a list
void list_push_front(list_t *list, list_data_t item_data);

// returns the item from the front of a list
list_data_t list_front(const list_t *list);

// removes item from front of a list
void list_pop_front(list_t *list);

// inserts item at back of a list
void list_push_back(list_t *list, list_data_t item_data);

// returns the item from the back of a list
list_data_t list_back(const list_t *list);

// removes item from back of a list
void list_pop_back(list_t *list);

// deletes a node that holds the matching data
void list_delete(list_t *list, list_data_t data);

// reverses the order of the elements in the list
void list_reverse(list_t *list);

// sorts the elements in the list
void list_sort(list_t *list);

#endif
