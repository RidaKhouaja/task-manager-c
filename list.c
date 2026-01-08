#include "list.h"
#include <stdio.h>

void listAdd(Node** head, Task* task) {
    Node* n = createNode(task);
    n->next = *head;
    *head = n;
}

void listDisplay(Node* head) {
    while (head) {
        printTask(head->data);
        head = head->next;
    }
}
