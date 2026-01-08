#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"

Task* createTask(int id, const char* title, const char* desc, int priority) {
    Task* t = malloc(sizeof(Task));
    t->id = id;
    strcpy(t->title, title);
    strcpy(t->description, desc);
    t->priority = priority;
    t->status = TASK_A_FAIRE;
    return t;
}

void printTask(Task* t) {
    printf("ID:%d | %s | Priority:%d | Status:%d\n",
           t->id, t->title, t->priority, t->status);
}
