#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char malop[8];
    char phong[7];
    struct Node* left;
    struct Node* right;
} Node;

Node* root = NULL;

Node* makeNode(char s1[], char s2[]){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->malop, s1);
    strcpy(p->phong, s2);
    p->left = p->right = NULL;
    return p;
}

Node* insert(Node* r, char s1[], char s2[]){
    if(r == NULL) return makeNode(s1, s2);

    int c = strcmp(r->malop, s1);
    if(c == 0) return r;
    else if(c < 0)
        r->right = insert(r->right, s1, s2);
    else
        r->left = insert(r->left, s1, s2);

    return r;
}

void inOrder(Node* r){
    if(r == NULL) return;
    inOrder(r->left);
    printf("%s ", r->malop);
    inOrder(r->right);
}

int main(){
    while(1){
        char cmd[20];
        scanf("%s", cmd);
        if(strcmp(cmd, "#") == 0) break;

        if(strcmp(cmd, "insert") == 0){
            char malop[8], phong[7];
            scanf("%s %s", malop, phong);
            root = insert(root, malop, phong);
        }
        else if(strcmp(cmd, "inOrder") == 0){
            inOrder(root);
            printf("\n");
        }
    }
    return 0;
}

