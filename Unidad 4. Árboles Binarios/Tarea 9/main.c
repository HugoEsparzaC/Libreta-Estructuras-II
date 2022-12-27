#include <stdio.h>

typedef struct node_tree node_tree_t;

node_tree_t *build_tree(char *);
void print_tree(node_tree_t *);
void evaluate_tree(node_tree_t *);

int main(void)  {
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "rt", stdout);
    int n;
    char postfix_expression[80];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)    {
        printf("\n--------------\nExpression #%d\n--------------\n", i);
        scanf("%s", postfix_expression);
        node_tree_t *root_node = build_tree(postfix_expression);
        print_tree(root_node);
        evaluate_tree(root_node);
    }
    return 0;
}

node_tree_t *build_tree(char *postfix_expression)
{
    printf("The expression is %s\n", postfix_expression);
    return NULL;
}

void print_tree(node_tree_t *root_node)
{
    if (root_node == NULL)  {
        printf("First build the tree!\n");
    }
    else {
        printf("The contents of the tree is\n");
        printf("---------------------------\n");
    }
}

void evaluate_tree(node_tree_t *root_node)
{
    if (root_node == NULL)  {
        printf("First build the tree!\n");
    }
    else {
        printf("---------------------------------\n");
        printf("The result of the evaluation is:\n");
    }
}
