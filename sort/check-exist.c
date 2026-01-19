#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 200003  // số nguyên tố

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* hashTable[HASH_SIZE];

int hash(int x) {
    if (x < 0) x = -x;
    return x % HASH_SIZE;
}

int exists(int x) {
    int h = hash(x);
    Node* cur = hashTable[h];
    while (cur) {
        if (cur->key == x) return 1;
        cur = cur->next;
    }
    return 0;
}

void insert(int x) {
    int h = hash(x);
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = x;
    node->next = hashTable[h];
    hashTable[h] = node;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        if (exists(x)) {
            printf("1\n");
        } else {
            printf("0\n");
            insert(x);
        }
    }
    return 0;
}
