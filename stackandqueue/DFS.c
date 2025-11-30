#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct StackNode {
    int value;
    struct StackNode* next;
} StackNode;

// Stack functions
StackNode* top = NULL;

StackNode* makeNode(int v) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->value = v;
    newNode->next = NULL;
    return newNode;
}

int stackEmpty() {
    return top == NULL;
}

void push(int v) {
    StackNode* p = makeNode(v);
    p->next = top;
    top = p;
}

int pop() {
    if (stackEmpty()) return -1;
    int v = top->value;
    StackNode* temp = top;
    top = top->next;
    free(temp);
    return v;
}

// Graph using adjacency list
Node* adj[MAX];
int visited[MAX];

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node* p = createNode(v);
    p->next = adj[u];
    adj[u] = p;

    // For undirected graph, add the reverse edge
    p = createNode(u);
    p->next = adj[v];
    adj[v] = p;
}

void DFS(int start) {
    push(start);

    while (!stackEmpty()) {
        int u = pop();
        if (!visited[u]) {
            visited[u] = 1;
            printf("%d ", u);

            // Push neighbors to stack
            Node* p = adj[u];
            while (p != NULL) {
                if (!visited[p->value])
                    push(p->value);
                p = p->next;
            }
        }
    }
}

int main() {
    int n, m;
    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Nhap cac canh u v:\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("DFS bat dau tu dinh 0: ");
    DFS(0);
    printf("\n");

    return 0;
}

