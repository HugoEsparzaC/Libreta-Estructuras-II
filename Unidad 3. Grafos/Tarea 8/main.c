#include <stdio.h>

#define DEBUG

typedef char vertex_id_t;

typedef enum gt_enum {
    UNDIRECTED_GRAPH = 0,
    DIRECTED_GRAPH   = 1
} graph_type_t;

typedef enum op_enum {
    READ_GRAPH      = 1,
    PRINT_GRAPH     = 2, 
    ADD_VERTEX      = 3, 
    ADD_EDGE        = 4, 
    REMOVE_VERTEX   = 5, 
    REMOVE_EDGE     = 6,
    VERTEX_DEGREE   = 7
} operation_t;

void read_from_adjacency_matrix();
void print_graph();
void add_vertex();
void add_edge();
void remove_vertex();
void remove_edge();
void vertex_degree();

int main(void)  {
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "rt", stdout);

    graph_type_t graph_type;
    int number_of_operations;
    scanf("%u%d", &graph_type, &number_of_operations);
#ifdef DEBUG
    printf("The graph type is %s\n", 
        graph_type == DIRECTED_GRAPH ? "Directed" : "Undirected");
#endif
    while (number_of_operations--) {
        operation_t op;
        scanf("%u", &op);
        switch (op) {
            case READ_GRAPH:
                read_from_adjacency_matrix();
            break;
            case PRINT_GRAPH:   
                print_graph();
            break;
            case ADD_VERTEX:    
                add_vertex();
            break;
            case ADD_EDGE:      
                add_edge();
            break;
            case REMOVE_VERTEX: 
                remove_vertex();
            break;
            case REMOVE_EDGE:   
                remove_edge();
            break;
            case VERTEX_DEGREE:   
                vertex_degree();
            break;
        }
    }
    return 0;
}

void read_from_adjacency_matrix()
{
    int number_of_vertices, adjacency;
    scanf("%d", &number_of_vertices);
    for (int i = 0; i < number_of_vertices; i++)    {
        for (int j = 0; j < number_of_vertices; j++)    {
            scanf("%d", &adjacency);
            // TODO: add edge between 'A'+i and 'A'+j
#ifdef DEBUG
            if (adjacency)  {
                printf("Adding adjacency between %c and %c\n", 'A'+i, 'A'+j);
            }
#endif
        }
    }
}

void print_graph()
{
    printf("\nThe graph's adjacency list is:\n");
    printf("------------------------------\n");
    // TODO: print adjacency list
}

void add_vertex()
{
    vertex_id_t vertex_id;
    scanf("\n%c", &vertex_id);
    printf("\nAdding vertex with id = %c\n", vertex_id);
    // TODO: Add the vertex only if doesn't exist
}

void add_edge()
{
    vertex_id_t vertex_u, vertex_v;
    scanf("\n%c %c", &vertex_u, &vertex_v);
    printf("\nAdding edge between the vertices %c and %c\n", vertex_u, vertex_v);
    // TODO: Find the vertices and add them if don't exist yet
    // TODO: Add edge between vertices
}

void remove_vertex()
{
    vertex_id_t vertex_id;
    scanf("\n%c", &vertex_id);
    printf("\nRemoving vertex with id = %c\n", vertex_id);
    // TODO: Remove vertex only if exists
}

void remove_edge()
{
    vertex_id_t vertex_u, vertex_v;
    scanf("\n%c %c", &vertex_u, &vertex_v);
    printf("\nRemoving edge between the vertices %c and %c\n", vertex_u, vertex_v);
    // TODO: Find the vertices and remove the edge between them
}

void vertex_degree()
{
    vertex_id_t vertex_id;
    scanf("\n%c", &vertex_id);
    // TODO: calculate the vertex degree
    int degree = 0;
    printf("\nThe vertex %c has degree = %d\n", vertex_id, degree);
}

