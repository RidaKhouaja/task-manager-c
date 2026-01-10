#include "list.h"
#include <stdio.h>
#include <stdlib.h>

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

void supprimerTask(Node** head, int id) {
    Node* cur = *head;
    Node* prev = NULL;
    while (cur) {
        if (cur->data && cur->data->id == id) {
            if (prev) prev->next = cur->next;
            else *head = cur->next;
            free(cur->data);
            free(cur);
            printf("Tâche %d supprimée.\n", id);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    printf("Tâche %d non trouvée.\n", id);
}

Task* getTaskById(Node* head, int id) {
    while (head) {
        if (head->data && head->data->id == id) return head->data;
        head = head->next;
    }
    return NULL;
}
