#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{
    char key;
    struct Node* left;
    struct Node* right;

}Node;
Node* makeNode(char key){
    Node* new = (Node*)malloc(sizeof(Node));
    new->key = key;
    new->left = NULL;
    new->right = NULL;
    return new;
}
Node* find(Node* r, char key){
    if( r == NULL) return NULL;
    if( r->key == key ) return r;
    Node* p = r->left;
    while(p!= NULL){
        Node* q = find(p , key);
        if(q != NULL) return q;
        p = p->right;

    }
    return NULL;
}
Node* insert(Node* root, char key){
    if(root == NULL) return makeNode(key);
    if( key < root->key){
        root->left = insert(root->left, key);
    }else if ( key > root->key) root->right = insert(root->right, key);
    return root;
}
Node* findmin(Node* root){
    while(root->left != NULL)
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
        Node* temp = findmin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->key);
}

int main() {
    Node* root = NULL;
    char s[10], key;

    while (1) {
        scanf("%s", s);
        if (strcmp(s,"#") == 0) break;

        scanf(" %c", &key);

        if (strcmp(s,"insert") == 0)
            root = insert(root, key);

        if (strcmp(s,"delete") == 0)
            root = deleteNode(root, key);
    }

    if (root == NULL)
        printf("NULL\n");
    else {
        postOrder(root);
        printf("\n");
    }
    return 0;
}
