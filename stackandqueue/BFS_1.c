#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Graph using adjacency list
Node* adj[MAX];
int visited[MAX];

// Queue implementation
Node* head = NULL;
Node* tail = NULL;

Node* makeNewNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = v;
    newNode->next = NULL;
    return newNode;
}

int queueEmpty() {
    return head == NULL;
}

void push(int v) {
    Node* p = makeNewNode(v);
    if(queueEmpty()){
        head = tail = p;
    } else {
        tail->next = p;
        tail = p;
    }
}

int pop() {
    if(queueEmpty()) return -1;
    int v = head->value;
    Node* tmp = head;
    head = head->next;
    free(tmp);
    return v;
}

// Graph functions
Node* createGraphNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node* p = createGraphNode(v);
    p->next = adj[u];
    adj[u] = p;

    // For undirected graph, add reverse edge
    p = createGraphNode(u);
    p->next = adj[v];
    adj[v] = p;
}

// BFS function
void BFS(int start) {
    push(start);
    visited[start] = 1;

    while (!queueEmpty()) {
        int u = pop();
        printf("%d ", u);

        Node* p = adj[u];
        while (p != NULL) {
            if (!visited[p->value]) {
                push(p->value);
                visited[p->value] = 1;
            }
            p = p->next;
        }
    }
    printf("\n");
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

    printf("BFS bat dau tu dinh 0: ");
    BFS(0);

    return 0;
}

