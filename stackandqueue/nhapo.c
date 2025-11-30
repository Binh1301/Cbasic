#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char key;
    struct Node* left;
    struct Node* right;
} Node;

Node* makeNode(char key){
    Node* p = (Node*)malloc(sizeof(Node));
    p->key = key;
    p->left = p->right = NULL;
    return p;
}

Node* insert(Node* root, char key){
    if (root == NULL) return makeNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

Node* findMin(Node* root){
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, char key){
    if (root == NULL) return NULL;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void postOrder(Node* root){
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->key);
}

/* optional: free whole tree to avoid memory leak */
void freeTree(Node* root){
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(){
    Node* root = NULL;
    char cmd[20], key;

    while (1){
        if (scanf("%s", cmd) != 1) break;
        if (strcmp(cmd, "#") == 0) break;

        /* read key character (skipping whitespace) */
        if (scanf(" %c", &key) != 1) break;

        if (strcmp(cmd, "insert") == 0){
            root = insert(root, key);
        } else if (strcmp(cmd, "delete") == 0 || strcmp(cmd, "del") == 0){
            root = deleteNode(root, key);
        } else {
            /* nếu có lệnh khác: bỏ qua hoặc thông báo (ở đây ta bỏ qua) */
        }
    }

    if (root == NULL)
        printf("NULL\n");
    else {
        postOrder(root);
        printf("\n");
    }

    freeTree(root);
    return 0;
}

