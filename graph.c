#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

Graph* createGraph(int n) {
    Graph* g = malloc(sizeof(Graph));
    g->n = n;
    g->adj = calloc(n, sizeof(Node*));
    return g;
}

void addEdge(Graph* g, int src, Task* dest) {
    Node* n = createNode(dest);
    n->next = g->adj[src];
    g->adj[src] = n;
}

void displayGraph(Graph* g) {
    for (int i = 0; i < g->n; i++) {
        printf("Task %d depends on: ", i);
        Node* tmp = g->adj[i];
        while (tmp) {
            printf("%d ", tmp->data->id);
            tmp = tmp->next;
        }
        printf("\n");
    }
}
