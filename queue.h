#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"

typedef struct {
    Node* head;
    Node* tail;
} Queue;

void initQueue(Queue* q);
void enqueue(Queue* q, Task* task);
Task* dequeue(Queue* q);

#endif
