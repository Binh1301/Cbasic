#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Customer {
    char id[8];
    char name[21];
    char level[7];
    struct Customer *next;
} Customer;

Customer *root = NULL;

void Create() {
    root = NULL;
}

Customer* makeNode(char *id, char *name, char *level) {
    Customer *p = (Customer*)malloc(sizeof(Customer));
    strcpy(p->id, id);
    strcpy(p->name, name);
    strcpy(p->level, level);
    p->next = NULL;
    return p;
}

void Insert(char *id, char *name, char *level) {
    Customer *newNode = makeNode(id, name, level);

    if (root == NULL) {
        root = newNode;
        return;
    }

    Customer *p = root;
    while (p->next != NULL)
        p = p->next;
    p->next = newNode;
}

void Print() {
    if (root == NULL) {
        printf("EMPTY\n");
        return;
    }

    Customer *p = root;
    while (p != NULL) {
        printf("%s %s %s\n", p->id, p->name, p->level);
        p = p->next;
    }
}

void Vip() {
    while (root != NULL && strcmp(root->level, "VIP") == 0) {
        Customer *tmp = root;
        root = root->next;
        free(tmp);
    }

    Customer *p = root;
    while (p != NULL && p->next != NULL) {
        if (strcmp(p->next->level, "VIP") == 0) {
            Customer *tmp = p->next;
            p->next = tmp->next;
            free(tmp);
        } else {
            p = p->next;
        }
    }
}

void Gold() {
    int cnt = 0;
    Customer *p = root;
    while (p != NULL) {
        if (strcmp(p->level, "GOLD") == 0)
            cnt++;
        p = p->next;
    }

    if (cnt == 0)
        printf("NO GOLD\n");
    else
        printf("%d\n", cnt);
}

void Serve() {
    if (root == NULL) return;

    Customer *tmp = root;
    root = root->next;
    free(tmp);
}

int main() {
    char cmd[20];

    while (scanf("%s", cmd) == 1) {
        if (strcmp(cmd, "#") == 0)
            break;

        if (strcmp(cmd, "Create") == 0) {
            Create();
        } 
        else if (strcmp(cmd, "Insert") == 0) {
            char id[8], name[21], level[7];
            scanf("%s %s %s", id, name, level);
            Insert(id, name, level);
        } 
        else if (strcmp(cmd, "Print") == 0) {
            Print();
        } 
        else if (strcmp(cmd, "Vip") == 0) {
            Vip();
        } 
        else if (strcmp(cmd, "Gold") == 0) {
            Gold();
        } 
        else if (strcmp(cmd, "Serve") == 0) {
            Serve();
        }
    }

    return 0;
}
