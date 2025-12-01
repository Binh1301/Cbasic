#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 50001

typedef struct Node {
    int id;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    int balanced;
    int h;
} INFO;

Node* nodes[MAX_NODES];
Node* root = NULL;

Node* makeNode(int id) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void addLeft(int u, int v) {
    if (nodes[u] != NULL || nodes[v] == NULL) return;
    if (nodes[v]->left != NULL) return;
    Node* p = makeNode(u);
    nodes[v]->left = p;
    nodes[u] = p;
}

void addRight(int u, int v) {
    if (nodes[u] != NULL || nodes[v] == NULL) return;
    if (nodes[v]->right != NULL) return;
    Node* p = makeNode(u);
    nodes[v]->right = p;
    nodes[u] = p;
}

INFO visit(Node *r) {
    if (r == NULL) {
        INFO i;
        i.balanced = 1;
        i.h = 0;
        return i;
    }
    INFO i1 = visit(r->left);
    INFO i2 = visit(r->right);
    INFO i;
    i.h = (i1.h > i2.h ? i1.h : i2.h) + 1;
    if (!i1.balanced || !i2.balanced || abs(i1.h - i2.h) > 1)
        i.balanced = 0;
    else
        i.balanced = 1;
    return i;
}

int main() {
    for (int i = 0; i < MAX_NODES; i++) nodes[i] = NULL;

    char cmd[20];
    while (scanf("%s", cmd)) {
        if (strcmp(cmd, "*") == 0) break;
        if (strcmp(cmd, "MakeRoot") == 0) {
            int u;
            scanf("%d", &u);
            root = makeNode(u);
            nodes[u] = root;
        } else if (strcmp(cmd, "AddLeft") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            addLeft(u, v);
        } else if (strcmp(cmd, "AddRight") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            addRight(u, v);
        }
    }

    INFO result = visit(root);
    if (result.balanced)
        printf("1 %d\n", result.h);
    else
        printf("0 %d\n", result.h);

    return 0;
}
