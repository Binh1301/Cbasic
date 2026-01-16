#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct node
{
    char name[MAX];
    struct node* parent;
    struct node* leftmostchild;
    struct node* rightsibling;
}node;

node* makenewnode(char data[])
{
    node* p = (node*)malloc(sizeof(node));
    if (p == NULL) return NULL;
    strcpy(p->name, data);  
    p->parent = NULL;
    p->leftmostchild = NULL;
    p->rightsibling = NULL;
    return p;
}

node* find(node* root, char data[])
{
    if (root == NULL) return NULL;
    if (strcmp(root->name, data)==0) return root;
    node* tmp=root->leftmostchild;
    while (tmp != NULL)
    {
        node* found = find(tmp, data);
        if (found != NULL) return found;
        tmp = tmp->rightsibling;
    } 
    return NULL;
}

void addchild(node* parent, node* child)
{
    child->parent = parent;
    if ((parent->leftmostchild == NULL))
    {
        parent->leftmostchild = child;
    }
    else
    {
        node* tmp = parent->leftmostchild;
        while (tmp->rightsibling!=NULL) tmp = tmp->rightsibling;
        tmp->rightsibling=child;
    }
}

node* buildTree() {
    char line[256];

    node* root = NULL;

    while (1) {
        fgets(line, sizeof(line), stdin);

        if (strcmp(line, "\n") == 0) break;

        line[strcspn(line, ";")] = '\0';

        char* token = strtok(line, " ");

        char fatherName[MAX];

        strcpy(fatherName, token);

        node* father = (root == NULL) ? NULL : find(root, fatherName);

        if (father == NULL) 
        {
            father = makenewnode(fatherName);
            if (root == NULL)
                root = father;
        }

        token = strtok(NULL, " ");

        while (token != NULL) 
        {
            node* child = find(root, token);
            if (child == NULL)
                child = makenewnode(token);
            addchild(father, child);
            token = strtok(NULL, " ");
        }
    }
    return root;
}

int depth(node* p) 
{
    int d = 0;
    while (p->parent != NULL) 
    {
        d++;
        p = p->parent;
    }
    return d;
}

void relation(node* root, char a[], char b[]) 
{
    node* A = find(root, a);
    node* B = find(root, b);
    if (depth(A)<depth(B))
        printf("TIEN BOI\n");
    else if (depth(A)>depth(B))
        printf("HAU BOI\n");
    else if (depth(A) == depth(B))
        printf("CUNG BAC\n");
}


int main() 
{
    node* root = buildTree();
    char a[MAX], b[MAX];
    scanf("%s %s", a, b);
    relation(root, a, b);
    return 0;
}


