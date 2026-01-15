# 🗂️ Task Manager en C

## 📌 Description
Ce projet est un **mini système de gestion des tâches** écrit en **C**. Il sert d'exercice pour implémenter et utiliser plusieurs structures de données classiques :

- Liste chaînée
- Pile (stack)
- File (queue)
- Arbre binaire de recherche (BST)
- Graphe (dépendances entre tâches)

Chaque fichier source implémente une partie de ces structures et leurs opérations.

## 🎯 Objectifs pédagogiques

- Comprendre l’utilisation des structures de données en C
- Structurer un projet C multi-fichiers avec `.h` / `.c`
- Gérer la mémoire dynamique (`malloc`, `free`)
- Compiler et exécuter une application C sous Windows

## 🧱 Fichiers du projet

Voici les fichiers présents dans ce dépôt (noms exacts) :

- `1_main.c` — point d'entrée (programme principal)
- `Task.c`, `Task.h` — gestion des tâches
- `node.c`, `node.h` — nœuds génériques
- `list.c`, `list.h` — liste chaînée
- `stack.c`, `stack.h` — pile (LIFO)
- `queue.c`, `queue.h` — file (FIFO)
- `tree.c`, `tree.h` — arbre binaire de recherche (BST)
- `graph.c`, `graph.h` — graphe (dépendances)
- `menu.c`, `menu.h` — interface/menu
- `output/` — dossier de sortie (ex. exports, logs)

## ⚙️ Compilation et exécution

Exemples de compilation avec `gcc` sous Windows (PowerShell ou CMD). Les commandes utilisent les fichiers présents dans le projet.

PowerShell :

```powershell
gcc -Wall -Wextra -std=c11 -o TaskManager 1_main.c Task.c list.c stack.c queue.c tree.c graph.c menu.c node.c
.\TaskManager.exe
```

CMD :

```cmd
gcc -Wall -Wextra -std=c11 -o TaskManager 1_main.c Task.c list.c stack.c queue.c tree.c graph.c menu.c node.c
TaskManager.exe
```

Astuce : pour compiler rapidement tous les fichiers `.c` du dossier (si vous préférez) :

```cmd
gcc -Wall -Wextra -std=c11 -o TaskManager *.c
```

## Utilisation

- Lancer l'exécutable `TaskManager.exe` puis suivre le menu affiché.
- Les sorties ou exports éventuels sont placés dans le dossier `output/`.

---

Si vous souhaitez que j'ajoute une section "Contribuer" ou des exemples d'utilisation plus détaillés, dites-le et je l'ajouterai.




