#ifndef DFA_GRAPH_H
#define DFA_GRAPH_H
#include "char_set.h"

typedef struct {
    char* start;
    char* symbol;
    char* dest;
} edge_t;

typedef struct {
    set_t nodes;
    edge_t* edges;
    int size;
} dfa_graph_t;

dfa_graph_t create_graph();

void graph_add_node(dfa_graph_t* graph, char node);

bool graph_contains_node(dfa_graph_t* graph, char node);

void graph_add_edge(dfa_graph_t* graph, char start, char end, char symbol);

#endif //DFA_GRAPH_H