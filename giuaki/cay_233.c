#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[21];
    struct Node *parent;
    struct Node *leftmostChild;
    struct Node *rightSibling;
} Node;

Node *nodes[1000];
int nodeCount = 0;

Node* createNode(char *name) {
    Node *p = (Node*)malloc(sizeof(Node));
    strcpy(p->name, name);
    p->parent = NULL;
    p->leftmostChild = NULL;
    p->rightSibling = NULL;
    nodes[nodeCount++] = p;
    return p;
}

Node* findNode(char *name) {
    for (int i = 0; i < nodeCount; i++)
        if (strcmp(nodes[i]->name, name) == 0)
            return nodes[i];
    return NULL;
}

void addChild(Node *father, Node *child) {
    child->parent = father;
    if (father->leftmostChild == NULL) {
        father->leftmostChild = child;
    } else {
        Node *p = father->leftmostChild;
        while (p->rightSibling)
            p = p->rightSibling;
        p->rightSibling = child;
    }
}

int depth(Node *p) {
    int d = 0;
    while (p) {
        d++;
        p = p->parent;
    }
    return d;
}

int isAncestor(Node *A, Node *B) {
    Node *p = B->parent;
    while (p) {
        if (p == A) return 1;
        p = p->parent;
    }
    return 0;
}

int main() {
    char line[200];
    Node *root = NULL;

    /* đọc cây */
    while (1) {
        fgets(line, sizeof(line), stdin);
        if (strcmp(line, "\n") == 0) break;

        char *token = strtok(line, " \n");
        Node *father = findNode(token);
        if (!father) {
            father = createNode(token);
            if (!root) root = father;
        }

        while ((token = strtok(NULL, " \n")) != NULL) {
            Node *child = findNode(token);
            if (!child)
                child = createNode(token);
            addChild(father, child);
        }
    }

    /* đọc A B */
    char Aname[21], Bname[21];
    scanf("%s %s", Aname, Bname);

    Node *A = findNode(Aname);
    Node *B = findNode(Bname);

    if (depth(A) == depth(B))
        printf("cung thu bac\n");
    else if (isAncestor(A, B))
        printf("tien boi\n");
    else if (isAncestor(B, A))
        printf("hau boi\n");

    return 0;
}
