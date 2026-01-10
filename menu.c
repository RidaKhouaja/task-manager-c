#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "list.h"
#include "Task.h"

/* ============================= */
/* Menu principal du programme  */
/* ============================= */

static void trim_newline(char *s) {
    if (!s) return;
    size_t l = strlen(s);
    while (l > 0 && (s[l-1] == '\n' || s[l-1] == '\r')) { s[l-1] = '\0'; l--; }
}

void menuPrincipal(Node **tasks, Graph *g) {
    int choix = 0;
    char line[200];

    do {
        printf("\n========== TASK MANAGER ==========\n");
        printf("1. Ajouter une tache\n");
        printf("2. Supprimer une tache\n");
        printf("3. Afficher les taches\n");
        printf("4. Ajouter une dependance\n");
        printf("5. Afficher les dependances\n");
        printf("6. Quitter\n");
        printf("=================================\n");
        printf("Votre choix : ");
        if (!fgets(line, sizeof(line), stdin)) break;
        trim_newline(line);
        sscanf(line, "%d", &choix);

        switch (choix) {

            /* ---------- TASKS ---------- */
            case 1: {
                int id = 0, priority = 0;
                char title[50] = "";
                char description[100] = "";
                printf("ID: ");
                if (fgets(line, sizeof(line), stdin)) sscanf(line, "%d", &id);
                printf("Title: ");
                if (fgets(title, sizeof(title), stdin)) { trim_newline(title); }
                printf("Description: ");
                if (fgets(description, sizeof(description), stdin)) { trim_newline(description); }
                printf("Priority: ");
                if (fgets(line, sizeof(line), stdin)) sscanf(line, "%d", &priority);
                if (getTaskById(*tasks, id) != NULL) {
                    printf("Erreur : une tâche avec l'ID %d existe déjà.\n", id);
                } else {
                    Task* t = createTask(id, title, description, priority);
                    listAdd(tasks, t);
                    printf("Tâche ajoutée : ID=%d, Titre='%s'\n", t->id, t->title);
                }
                break;
            }

            case 2: {
                int id = 0;
                printf("ID de la tache a supprimer : ");
                if (fgets(line, sizeof(line), stdin)) sscanf(line, "%d", &id);
                supprimerTask(tasks, id);
                break;
            }

            case 3:
                listDisplay(*tasks);
                break;

            /* ------- DEPENDANCES ------- */
            case 4: {
                int src = 0, dest = 0;
                printf("ID tache source : ");
                if (fgets(line, sizeof(line), stdin)) sscanf(line, "%d", &src);
                printf("ID tache destination : ");
                if (fgets(line, sizeof(line), stdin)) sscanf(line, "%d", &dest);

                /* ajout d’une dépendance dans le graphe */
                Task* d = getTaskById(*tasks, dest);
                if (d == NULL) printf("Tâche destination %d introuvable.\n", dest);
                else addEdge(g, src, d);
                break;
            }

            case 5:
                displayGraph(g);
                break;

            case 6:
                printf("Fin du programme.\n");
                break;

            default:
                printf("Choix invalide.\n");
        }

    } while (choix != 6);
}
