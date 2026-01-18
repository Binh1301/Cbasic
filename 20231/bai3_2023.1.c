#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    char malop[9];
    char phong[7];
    struct Node* left ;
    struct Node* right;
}Node;
Node* root = NULL;
int count = 1;
Node* makeNode(char s1[], char s2[]){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->malop, s1);
    strcpy(p->phong, s2);
    p->left = NULL;
    p->right = NULL;
    return p;
}
int findNode(Node* r,char s1[]){
    if(r == NULL) return count - 1;
    int c = strcmp(r->malop, s1);
    if(c == 0){
        int tmp  = count;
        count = 0;
        return tmp;
    }
    if(c < 0){
            count += 1;
            return findNode(r->right, s1);}
    else {
        count += 1;
            return findNode(r->left, s1);}}

Node* insert(Node* r, char s1[], char s2[]){
    if( r == NULL) return makeNode(s1, s2);
    int c = strcmp(r->malop, s1);
    if(c == 0) return r;
    else if(c < 0)
        r->right = insert(r->right, s1, s2);
    else
        r->left = insert(r->left, s1, s2);

    return r;

}
int first = 1;
void inOrder(Node * r){
    if (r == NULL) return;
    inOrder(r->left);
    if(!first) printf(" ");
    printf("%s", r->malop);
    first = 0;
    inOrder(r->right);
}


int main(){
    while(1){
        char c[20];
        scanf("%s", c);
        if(strcmp(c, "#") == 0) break;
        if(strcmp(c, "insert") == 0){
            char malop[9], phong[7];
            scanf("%s", malop);
            scanf("%s", phong);
            root = insert(root, malop, phong);
        }if(strcmp(c, "inOrder") == 0){
            first = 1;
            inOrder(root);
            printf("!\n");
        }
        if(strcmp(c, "countStep") == 0){
            char malop[9];
            scanf("%s", malop);
            count = 1;
            int a = findNode(root,malop);
            printf("%d", a);

    }}
    return 0;
}



