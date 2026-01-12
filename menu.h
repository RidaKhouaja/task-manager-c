#ifndef MENU_H
#define MENU_H

#include "node.h"
#include "graph.h"
#include "stack.h"
#include "queue.h"
#include "tree.h"

/* Menu principal */
void menuPrincipal(Node **tasks, Graph *g);

/* Sous-menus */
void menuTasks(Node **tasks, Node **undo);
void menuGraphe(Graph *g, Node *tasks);
void menuPile(Node **undo, Node **tasks);
void menuFile(Queue *q, Node *tasks);
void menuArbre(Node **root, Node *tasks);
void afficherMenuPrincipal(void);

#endif
