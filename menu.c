#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"
#include "list.h"
#include "Task.h"
#include "stack.h"
#include "queue.h"
#include "tree.h"

static void trim_newline(char *s) {
    if (!s) return;
    size_t l = strlen(s);
    while (l > 0 && (s[l-1] == '\n' || s[l-1] == '\r')) { s[l-1] = '\0'; l--; }
}

static int getIntFromLine(const char *prompt, int *out) {
    char line[200];
    char *endptr;
    long val;
    if (prompt) printf("%s", prompt);
    if (!fgets(line, sizeof(line), stdin)) return 0; /* EOF */
    trim_newline(line);
    val = strtol(line, &endptr, 10);
    if (endptr == line) return -1; /* invalid */
    *out = (int)val;
    return 1;
}

void afficherMenuPrincipal(void) {
    printf("\n===== TASK MANAGER =====\n");
    printf("1. Gestion des taches (liste)\n");
    printf("2. Gestion des dependances (graphe)\n");
    printf("3. Pile (Undo)\n");
    printf("4. File (Planification)\n");
    printf("5. Arbre (Recherche)\n");
    printf("6. Quitter\n");
}

/* ---------- Sous-menus ---------- */
void menuTasks(Node **tasks, Node **undo) {
    int choix = 0;
    char line[200];
    while (1) {
        printf("\n-- Menu Taches --\n1.Add\n2.Delete\n3.List\n4.Back\nVotre choix: ");
        if (!fgets(line, sizeof(line), stdin)) break;
        trim_newline(line);
        if (sscanf(line, "%d", &choix) != 1) { printf("Choix invalide\n"); continue; }
        if (choix == 4) break;
        if (choix == 1) {
            int id=0, priority=0;
            char title[50] = "";
            char desc[100] = "";
            printf("ID: "); if (!fgets(line, sizeof(line), stdin)) break; sscanf(line, "%d", &id);
            printf("Title: "); if (fgets(title, sizeof(title), stdin)) trim_newline(title);
            printf("Description: "); if (fgets(desc, sizeof(desc), stdin)) trim_newline(desc);
            printf("Priority: "); if (!fgets(line, sizeof(line), stdin)) break; sscanf(line, "%d", &priority);
            if (getTaskById(*tasks, id) != NULL) {
                printf("Erreur : une tache avec l'ID %d existe deja.\n", id);
            } else {
                Task* t = createTask(id, title, desc, priority);
                listAdd(tasks, t);
                printf("Tache ajoutee : ID=%d, Titre='%s'\n", t->id, t->title);
            }
        } else if (choix == 2) {
            int id = 0;
            printf("ID de la tache a supprimer : "); if (!fgets(line, sizeof(line), stdin)) break; sscanf(line, "%d", &id);
            /* remove node manually so we can push Task* onto undo stack */
            Node *cur = *tasks, *prev = NULL;
            while (cur) {
                if (cur->data && cur->data->id == id) {
                    if (prev) prev->next = cur->next; else *tasks = cur->next;
                    Task* t = cur->data;
                    free(cur); /* free node but keep task */
                    if (undo) push(undo, t);
                    printf("Tache %d supprimee et empilee pour undo.\n", id);
                    break;
                }
                prev = cur; cur = cur->next;
            }
        } else if (choix == 3) {
            listDisplay(*tasks);
        } else printf("Choix invalide\n");
    }
}

void menuGraphe(Graph *g, Node *tasks) {
    int choix = 0;
    char line[200];
    while (1) {
        printf("\n-- Menu Graphe --\n1.Add Edge\n2.Display\n3.Back\nVotre choix: ");
        if (!fgets(line, sizeof(line), stdin)) break;
        trim_newline(line);
        if (sscanf(line, "%d", &choix) != 1) { printf("Choix invalide\n"); continue; }
        if (choix == 3) break;
        if (choix == 1) {
            int src = 0, dest = 0;
            printf("Index sommet source (0..n-1): "); if (!fgets(line, sizeof(line), stdin)) break; sscanf(line, "%d", &src);
            printf("ID tache destination: "); if (!fgets(line, sizeof(line), stdin)) break; sscanf(line, "%d", &dest);
            Task* d = getTaskById(tasks, dest);
            if (!d) printf("Tache destination %d introuvable.\n", dest);
            else addEdge(g, src, d);
        } else if (choix == 2) displayGraph(g);
        else printf("Choix invalide\n");
    }
}

void menuPile(Node **undo, Node **tasks) {
    int choix = 0;
    char line[200];
    while (1) {
        printf("\n-- Menu Pile (Undo) --\n1.Afficher\n2.Undo (pop)\n3.Back\nVotre choix: ");
        if (!fgets(line, sizeof(line), stdin)) break;
        trim_newline(line);
        if (sscanf(line, "%d", &choix) != 1) { printf("Choix invalide\n"); continue; }
        if (choix == 3) break;
        if (choix == 1) {
            Node *t = *undo;
            while (t) { printTask(t->data); t = t->next; }
        } else if (choix == 2) {
            Task* t = pop(undo);
            if (!t) printf("Pile vide\n"); else { listAdd(tasks, t); printf("Undo effectue: tache %d restauree dans la liste.\n", t->id); }
        } else printf("Choix invalide\n");
    }
}

void menuFile(Queue *q, Node *tasks) {
    int choix = 0;
    char line[200];
    while (1) {
        printf("\n-- Menu File (Planification) --\n1.Enqueue (by ID)\n2.Dequeue\n3.Afficher\n4.Back\nVotre choix: ");
        if (!fgets(line, sizeof(line), stdin)) break;
        trim_newline(line);
        if (sscanf(line, "%d", &choix) != 1) { printf("Choix invalide\n"); continue; }
        if (choix == 4) break;
        if (choix == 1) {
            int id=0; printf("ID tache a mettre en file: "); if (!fgets(line, sizeof(line), stdin)) break; sscanf(line, "%d", &id);
            Task* t = getTaskById(tasks, id);
            if (!t) printf("Tache %d introuvable.\n", id); else { enqueue(q, t); printf("Tache %d enqueued.\n", id); }
        } else if (choix == 2) {
            Task* t = dequeue(q);
            if (!t) printf("File vide\n"); else { printf("Dequeued: "); printTask(t); }
        } else if (choix == 3) {
            Node *n = q->head; while (n) { printTask(n->data); n = n->next; }
        } else printf("Choix invalide\n");
    }
}

void menuArbre(Node **root, Node *tasks) {
    int choix = 0;
    char line[200];
    while (1) {
        printf("\n-- Menu Arbre --\n1.Insert (by ID)\n2.Afficher inorder\n3.Back\nVotre choix: ");
        if (!fgets(line, sizeof(line), stdin)) break;
        trim_newline(line);
        if (sscanf(line, "%d", &choix) != 1) { printf("Choix invalide\n"); continue; }
        if (choix == 3) break;
        if (choix == 1) {
            int id=0; printf("ID tache a inserer: "); if (!fgets(line, sizeof(line), stdin)) break; sscanf(line, "%d", &id);
            Task* t = getTaskById(tasks, id);
            if (!t) printf("Tache %d introuvable.\n", id); else *root = insertTree(*root, t);
        } else if (choix == 2) inorder(*root);
        else printf("Choix invalide\n");
    }
}
 /*=========================================================*/
 //                menu principal                           //
 /*========================================================*/
void menuPrincipal(Node **tasks, Graph *g) {
    int choix = 0;
    /* structures auxiliaires gérées localement */
    Node *undo = NULL; /* pile pour undo */
    Queue q; initQueue(&q);
    Node *root = NULL; /* arbre */

    while (1) {
        afficherMenuPrincipal();
        printf("Choix : ");
        if (!getIntFromLine(NULL, &choix)) break; /* EOF */
        if (choix == 6) { printf("Fin du programme\n"); break; }
        switch (choix) {
            case 1: menuTasks(tasks, &undo); break;
            case 2: menuGraphe(g, *tasks); break;
            case 3: menuPile(&undo, tasks); break;
            case 4: menuFile(&q, *tasks); break;
            case 5: menuArbre(&root, *tasks); break;
            default: printf("Choix invalide\n");
        }
    }
}

