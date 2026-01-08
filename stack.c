#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void push(Node** top, Task* task) {
    Node* n = createNode(task);
    n->next = *top;
    *top = n;
}

Task* pop(Node** top) {
    if (!*top) return NULL;
    Node* tmp = *top;
    Task* t = tmp->data;
    *top = tmp->next;
    free(tmp);
    return t;
}
