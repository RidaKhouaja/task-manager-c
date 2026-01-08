#include <stdio.h>
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "tree.h"
#include "graph.h"

int main() {
    Node* list = NULL;
    Node* stack = NULL;
    Queue q; initQueue(&q);
    Node* tree = NULL;

    Task* t1 = createTask(1,"Code","Write code",3);
    Task* t2 = createTask(2,"Compile","Compile project",1);
    Task* t3 = createTask(3,"Test","Test app",2);

    listAdd(&list, t1);
    listAdd(&list, t2);
    listAdd(&list, t3);

    push(&stack, t1);
    enqueue(&q, t2);

    tree = insertTree(tree, t1);
    tree = insertTree(tree, t2);
    tree = insertTree(tree, t3);

    Graph* g = createGraph(3);
    addEdge(g, 0, t2);

    listDisplay(list);
    inorder(tree);
    displayGraph(g);

    return 0;
}
