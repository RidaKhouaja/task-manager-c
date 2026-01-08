# 🗂️ Task Manager en C

## 📌 Description
Ce projet est un **mini système de gestion des tâches** développé en langage **C**.  
Il a pour objectif de mettre en pratique les **structures de données fondamentales** :

- Liste chaînée
- Pile (Stack)
- File (Queue)
- Arbre binaire de recherche (BST)
- Graphe (dépendances entre tâches)

Chaque structure est utilisée dans un **contexte réel et logique**.

---

## 🎯 Objectifs pédagogiques
- Comprendre l’utilisation des structures de données en C
- Apprendre à structurer un projet C multi-fichiers
- Appliquer les bonnes pratiques (séparation `.h` / `.c`)
- Manipuler la mémoire dynamique (`malloc`, `free`)
- Utiliser Git et GitHub pour gérer un projet

---

## 🧱 Structures utilisées et leurs rôles

| Structure | Rôle |
|---------|------|
| Liste chaînée | Stocker toutes les tâches |
| Pile | Historique / Undo |
| File | Tâches en attente d’exécution |
| Arbre (BST) | Organisation des tâches par priorité |
| Graphe | Gestion des dépendances entre tâches |

---

## 📁 Structure du projet

Task_Manager/
│
├── task.h / task.c       // Définition et gestion des tâches
├── node.h / node.c       // Nœud générique
│
├── list.h / list.c       // Liste chaînée
├── stack.h / stack.c     // Pile (LIFO)
├── queue.h / queue.c     // File (FIFO)
├── tree.h / tree.c       // Arbre binaire (BST)
├── graph.h / graph.c     // Graphe (dépendances)
│
├── main.c                // Programme principal
└── README.md             // Ce fichier


---

## ⚙️ Compilation et exécution

### 🔹 Sous Windows (PowerShell)
```powershell
gcc (Get-ChildItem *.c) -o task_manager
.\task_manager.exe

### 🔹 Sous Windows CMD
```cmd
gcc *.c -o task_manager
task_manager.exe




