#ifndef TASK_H
#define TASK_H

typedef enum {
    TASK_A_FAIRE,   // 0 → tâche dans la liste principale
    TASK_EN_COURS,   // 1 → tâche dans la file / en cours d’exécution
    TASK_TERMINEE     // 2 → tâche exécutée 
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
