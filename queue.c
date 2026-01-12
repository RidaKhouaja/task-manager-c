#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void initQueue(Queue* q) {
    q->head = q->tail = NULL;
}

void enqueue(Queue* q, Task* task) {
    /* mark task as in-progress when enqueued */
    task->status = TASK_EN_COURS;
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
    /* mark task as completed when dequeued */
    if (t) t->status = TASK_TERMINEE;
    return t;
}
