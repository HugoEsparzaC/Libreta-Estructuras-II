#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>
#include <stdbool.h>

typedef int list_data_t;
typedef struct list_node list_node_t;

struct list_node {
   list_data_t data;
   struct list_node *next;
};

// initialize the list
void list_init(list_node_t **head);

// destroys an entire list
void list_destroy(list_node_t **head);

// checks if list is empty
bool list_is_empty(const list_node_t *head);

// counts the items on a list
size_t list_count(const list_node_t *head);

// inserts item at back of a list
void list_push_back(list_node_t **head, list_data_t item_data);

// returns the item from the back of a list
list_data_t list_back(const list_node_t *head);

// removes item from back of a list
void list_pop_back(list_node_t **head);

// inserts item at front of a list
void list_push_front(list_node_t **head, list_data_t item_data);

// returns the item from the front of a list
list_data_t list_front(const list_node_t *head);

// removes item from front of a list
void list_pop_front(list_node_t **head);

// deletes a node that holds the matching data
void list_delete(list_node_t **head, list_data_t data);


#endif
