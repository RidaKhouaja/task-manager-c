#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void initQueue(Queue* q) {
    q->head = q->tail = NULL;
}

void enqueue(Queue* q, Task* task) {
    Node* n = createNode(task);
    if (!q->tail)
        q->head = q->tail = n;
    else {
        q->tail->next = n;
        q->tail = n;
    }
}

Task* dequeue(Queue* q) {
    if (!q->head) return NULL;
    Node* tmp = q->head;
    Task* t = tmp->data;
    q->head = tmp->next;
    if (!q->head) q->tail = NULL;
    free(tmp);
    return t;
}
