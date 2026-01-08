#include "tree.h"
#include <stdio.h>

Node* insertTree(Node* root, Task* task) {
    if (!root) return createNode(task);
    if (task->priority < root->data->priority)
        root->left = insertTree(root->left, task);
    else
        root->right = insertTree(root->right, task);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printTask(root->data);
    inorder(root->right);
}
