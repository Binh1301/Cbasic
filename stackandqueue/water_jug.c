#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char cmd[20];
    int x, y;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

Node* newNode(char c[], int x, int y) {
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->cmd, c);
    p->x = x;
    p->y = y;
    p->next = NULL;
    return p;
}

void addCommand(char c[], int x, int y) {
    Node* p = newNode(c, x, y);
    if (head == NULL) head = tail = p;
    else {
        tail->next = p;
        tail = p;
    }
}

int main() {
    int a, b; 
    scanf("%d %d", &a, &b);

    while (1) {
        char op[20];
        scanf("%s", op);
        if (strcmp(op, "#") == 0) break;

        if (strcmp(op, "fill") == 0) {
            int x; scanf("%d", &x);
            addCommand(op, x, 0);
        }
        else if (strcmp(op, "empty") == 0) {
            int x; scanf("%d", &x);
            addCommand(op, x, 0);
        }
        else if (strcmp(op, "pour") == 0) {
            int x, y; scanf("%d %d", &x, &y);
            addCommand(op, x, y);
        }
    }

    int jug1 = 0, jug2 = 0;

    Node* cur = head;
    while (cur != NULL) {
        if (strcmp(cur->cmd, "fill") == 0) {
            if (cur->x == 1) jug1 = a;
            else jug2 = b;
        }
        else if (strcmp(cur->cmd, "empty") == 0) {
            if (cur->x == 1) jug1 = 0;
            else jug2 = 0;
        }
        else if (strcmp(cur->cmd, "pour") == 0) {
            int *from, *to, cap;
            if (cur->x == 1)  from = &jug1; 
            else from = &jug2; 

            if (cur->y == 1){
                    to = &jug1;
                    cap = a; 
                    }
            else{
                 to = &jug2; 
                 cap = b;
                }

            int canPour = cap - (*to);   
            if (*from <= canPour) {
                *to += *from;
                *from = 0;
            } else {
                *from -= canPour;
                *to = cap;
            }
        }
        cur = cur->next;
    }

    printf("%d %d\n", jug1, jug2);
    return 0;
}