#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50
#define m 10000

typedef struct Node {
    char key[MAX];
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* T[m];   

Node* makeNode(char* k) {
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->key, k);
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

int h(char* k) {
    int c = 0;
    for (int i = 0; i < strlen(k); i++)
        c = (c * 256 + k[i]) % m;
    return c;
}

Node* findBST(Node* r, char* k) {
    if (r == NULL) return NULL;
    int cmp = strcmp(r->key, k);
    if (cmp == 0) return r;
    if (cmp < 0) return findBST(r->rightChild, k);
    return findBST(r->leftChild, k);
}

Node* insertBST(Node* r, char* k) {
    if (r == NULL) return makeNode(k);
    if (strcmp(r->key, k) < 0)
        r->rightChild = insertBST(r->rightChild, k);
    else
        r->leftChild = insertBST(r->leftChild, k);
    return r;
}

int find(char* k) {
    int i = h(k);
    return (findBST(T[i], k) != NULL);
}

int insert(char* k) {
    int i = h(k);
    if (findBST(T[i], k) != NULL) return 0;
    T[i] = insertBST(T[i], k);
    return 1;
}

int main() {
    char k[MAX], cmd[20];

    for (int i = 0; i < m; i++)
        T[i] = NULL;

    while (1) {
        scanf("%s", k);
        if (strcmp(k, "*") == 0) break;
        insert(k);
    }

    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "find") == 0) {
            scanf("%s", k);
            printf("%d\n", find(k));
        } 
        else if (strcmp(cmd, "insert") == 0) {
            scanf("%s", k);
            printf("%d\n", insert(k));
        } 
        else if (strcmp(cmd, "***") == 0) {
            break;
        }
    }

    return 0;
}
