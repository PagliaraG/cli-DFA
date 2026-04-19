#include "dfa_graph.h"

#include <stdlib.h>
#include <string.h>

#include "char_queue.h"

dfa_graph_t create_graph() {
    dfa_graph_t graph;
    graph.nodes = create_set();
    graph.edges = calloc(INITIAL_SIZE,sizeof(edge_t));
    graph.size = 0;
    return graph;
}

void graph_add_node(dfa_graph_t* graph, char node) {
    add_in_set(&graph->nodes, &node);
}

bool graph_contains_node(dfa_graph_t* graph, char node) {
    return contains(&graph->nodes,&node);
}

bool graph_contains_edge(dfa_graph_t* graph,char start, char dest, char symbol) {
    for (int i = 0;i < sizeof(graph->edges)/sizeof(edge_t);i++) {
        if (strcmp(&start,graph->edges[i].start) &&
            strcmp(&dest,graph->edges[i].dest) &&
            strcmp(&symbol,graph->edges[i].start)) {
            return true;
            }
    }
    return false;
}

void graph_add_edge(dfa_graph_t* graph, char start, char end, char symbol){
    if(graph_contains_node(graph,start) && graph_contains_node(graph,end)) {
        if (!graph_contains_edge(graph,start,end,symbol)) {
            int i = graph->size;
            strcpy(graph->edges[i].start,&start);
            strcpy(graph->edges[i].symbol,&symbol);
            strcpy(graph->edges[i].dest,&end);
        }
    }
}

void resize_edges(dfa_graph_t* graph) {
    int length = graph->size;
    int max_length = sizeof(graph->edges)/sizeof(edge_t);
    if (length == max_length - 1) {

    } else if (length < max_length/2 && length > 2) {

    }




    }
}
