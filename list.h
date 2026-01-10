#ifndef LIST_H
#define LIST_H
#include "node.h"

void listAdd(Node** head, Task* task);
void listDisplay(Node* head);
void supprimerTask(Node** head, int id);
Task* getTaskById(Node* head, int id);

#endif



