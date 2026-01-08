#ifndef NODE_H
#define NODE_H

#include "task.h"

typedef struct Node {
    Task* data;
    struct Node* next;   // liste / pile / file
    struct Node* left;   // arbre
    struct Node* right;
} Node;

Node* createNode(Task* task);

#endif
