#include <stdlib.h>
#include "node.h"

Node* createNode(Task* task) {
    Node* n = malloc(sizeof(Node));
    n->data = task;
    n->next = n->left = n->right = NULL;
    return n;
}
