#ifndef TASK_H
#define TASK_H

typedef enum {
    TASK_A_FAIRE,
    TASK_EN_COURS,
    TASK_TERMINEE
} TaskStatus;

typedef struct {
    int id;
    char title[50];
    char description[100];
    int priority;
    TaskStatus status;
} Task;

Task* createTask(int id, const char* title, const char* desc, int priority);
void printTask(Task* t);

#endif
