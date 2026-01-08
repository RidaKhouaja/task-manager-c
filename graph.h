#ifndef GRAPH_H
#define GRAPH_H
#include "node.h"

typedef struct {
    int n;
    Node** adj;
} Graph;

Graph* createGraph(int n);
void addEdge(Graph* g, int src, Task* dest);
void displayGraph(Graph* g);

#endif
