#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <stddef.h>
#include <stdbool.h>

typedef struct node node_t;

struct node {
   node_t *right;
   node_t *left;
   int data;
};

void free_tree(node_t *tree);
bool insert_data(node_t **tree, int data);
node_t *search_data(node_t *tree, int data);
bool delete_data(node_t **tree, int data);
node_t *build_tree(const int *tree_data, size_t tree_data_len);
int *sorted_data(const node_t *tree);

#endif
