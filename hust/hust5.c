#include <stdio.h>
#include <stdlib.h>

#include <string.h>
int cach = 0;
typedef struct Node{
    int key;
    struct Node* left;
    struct Node* right;
}Node;
Node* root;
Node* makeNode(int key){
    Node* p = (Node*)malloc(sizeof(Node));
    p->key = key;
    p->left = NULL;
    p->right = NULL;
    return p;
}
Node* findNode(Node* r,int key){
    if(r == NULL) return NULL;
    if(r->key == key) return r;
    if( r->key > key) return findNode(r->left, key);
    if( r->key < key) return findNode(r->right, key);
}
Node* insert(Node* r, int key){
    if(r == NULL) return makeNode(key);
    if(key < r->key)
        r->left = insert(r->left, key);
    else if(key > r->key)
        r->right = insert(r->right, key);
    return r;
}
Node* findA(Node* r, int n1, int n2){
    if(r == NULL) return NULL;
    Node* a = findNode(r , n1);
    Node* b = findNode(r , n2);
    if(r->key > n1 && r->key > n2){
    while( r->key > n1 && r->key > n2){
        r = r->left;
    }
    return r;}
    if(r->key < n1 && r->key < n2){
    while( r->key < n1 && r->key < n2){
        r = r->right;
    }
    return r;}
    return r;

}
int distance(Node* r,Node* a){

    if(r->key == a->key){
        int p = cach;
        cach = 0;
        return p;
    }
    if( r->key > a->key) {
        cach = cach + 1;
            return distance(r->left, a);}
    if( r->key < a->key) {
        cach = cach + 1;
            return distance(r->right, a);}
}

int main(){
    int n, n1, n2;
    scanf("%d", &n);
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        int key;
        scanf("%d", &key);
        root = insert(root, key);
    }
    scanf("%d %d", &n1,&n2);
    Node* a = findNode(root, n1);
    Node* b = findNode(root, n2);
    Node* c = findA(root, n1, n2);
    int a_1 = distance(c ,a);
    int b_1 = distance(c ,b);
    int tong = a_1 + b_1;
    printf("%d", tong);
    return 0;

}




