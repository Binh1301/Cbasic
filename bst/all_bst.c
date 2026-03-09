#1
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



#2
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

typedef struct Node {
  int key;
  struct Node * leftChild;
  struct Node * rightChild;
}
Node;
Node * root;
Node * makeNode(int k) {
  Node * p = (Node * ) malloc(sizeof(Node));
  p -> key = k;
  p -> leftChild = NULL;
  p -> rightChild = NULL;
  return p;
}
Node * insert(Node * r, int k) {
  if (r == NULL) r = makeNode(k);
  else if (r -> key > k)
    r -> leftChild = insert(r -> leftChild, k);
  else if (r -> key < k)
    r -> rightChild = insert(r -> rightChild, k);
  return r;
}
void preOrder(Node * r) {
  if (r == NULL) return;
  printf("%d ", r -> key);
  preOrder(r -> leftChild);
  preOrder(r -> rightChild);
}
void postOrder(Node * r) {
  if (r == NULL) return;
  postOrder(r -> leftChild);
  postOrder(r -> rightChild);
  printf("%d ", r -> key);
}
Node * removeRoot(Node * r) {
  if (r == NULL) return NULL;
  if (r -> rightChild == NULL) {
    Node * tmp = r;
    r = r -> leftChild;
    free(tmp);
    return r;
  }
  Node * p = r -> rightChild;
  Node * pp = r;
  if (p -> leftChild == NULL) {
    r -> key = p -> key;
    Node * tmp = p;
    r -> rightChild = p -> rightChild;
    free(tmp);
    return r;
  }
  while (p -> leftChild != NULL) {
    pp = p;
    p = p -> leftChild;
  }
  pp -> leftChild = p -> rightChild;
  r -> key = p -> key;
  free(p);
  return r;
}
Node * removeNode(Node * r, int k) {
  if (r == NULL) return NULL;
  if (r -> key == k)
    return removeRoot(r);
  else if (r -> key < k)
    r -> rightChild = removeNode(r -> rightChild, k);
  else
    r -> leftChild = removeNode(r -> leftChild, k);
  return r;
}
int main() {
  root = NULL;
  while (1) {
    char cmd[256];
    scanf("%s", cmd);
    if (strcmp(cmd, "#") == 0) break;
    else if (strcmp(cmd, "insert") == 0) {
      int k;
      scanf("%d", & k);
      root = insert(root, k);
    } else if (strcmp(cmd, "remove") == 0) {
      int k;
      scanf("%d", & k);
      root = removeNode(root, k);
    } else if (strcmp(cmd, "preorder") == 0) {
      preOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "postorder") == 0) {
      postOrder(root);
      printf("\n");
    }
  }
  preOrder(root);
  printf("\n");
  return 0;
}
#3

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#define MAX 50
#define m 10000
typedef struct Node {
  char key[MAX];
  struct Node * leftChild;
  struct Node * rightChild;
}
Node;
Node * T[m];
Node * makeNode(char * k) {
  Node * p = (Node * ) malloc(sizeof(Node));
  strcpy(p -> key, k);
  p -> leftChild = NULL;
  p -> rightChild = NULL;
  return p;
}

int h(char * k) {
  int c = 0;
  for (int i = 0; i < strlen(k); i++)
    c = (c * 256 + k[i]) % m;
  return c;
}
Node * findBST(Node * r, char * k) {
  if (r == NULL) return NULL;
  int c = strcmp(r -> key, k);
  if (c == 0) return r;
  if (c < 0) return findBST(r -> rightChild, k);
  else return findBST(r -> leftChild, k);
}
Node * insertBST(Node * r, char * k) {
  if (r == NULL) return makeNode(k);
  if (strcmp(r -> key, k) < 0)
    r -> rightChild = insertBST(r -> rightChild, k);
  else
    r -> leftChild = insertBST(r -> leftChild, k);
  return r;
}
int find(char * k) {
  int i = h(k);
  Node * p = findBST(T[i], k);
  if (p == NULL) return 0;
  return 1;
}
int insert(char * k) { // put(k)
  int i = h(k);
  Node * p = findBST(T[i], k);
  if (p != NULL) return 0;
  T[i] = insertBST(T[i], k);
  return 1;
}
int main() {
  char k[MAX], cmd[20];
  while (1) {
    scanf("%s", k);
    if (strcmp(k, "*") == 0) break;
    insert(k); // put k into the hash table (+BST)
  }
  while (1) {
    scanf("%s", cmd);
    if (strcmp(cmd, "find") == 0) {
      scanf("%s", k);
      int ans = find(k);
      printf("%d\n", ans);
    } else if (strcmp(cmd, "insert") == 0) {
      scanf("%s", k);
      int ans = insert(k);
      printf("%d\n", ans);
    } else if (strcmp(cmd, "***") == 0) {
      break;
    }
  }
  return 0;
}
#4
#include <stdio.h>

#include <stdlib.h>

#define N 100001
int n;
int a[N];
int ok = 1;
typedef struct Node {
  int id;
  struct Node * leftChild;
  struct Node * rightChild;

}
Node;
Node * makeNode(int id) {
  Node * p = (Node * ) malloc(sizeof(Node));
  p -> id = id;
  p -> leftChild = NULL;
  p -> rightChild = NULL;
  return p;
}
Node * build(int start, int end) {
  if (start > end) return NULL;
  if (start == end) {
    return makeNode(a[start]);
  }
  Node * r = makeNode(a[start]);
  int i = start + 1;
  while (i <= end && a[i] < a[start]) i++;
  for (int j = i; j <= end; j++)
    if (a[j] < a[start]) {
      ok = 0;
      break;
    }

  r -> leftChild = build(start + 1, i - 1);
  r -> rightChild = build(i, end);
  return r;
}
void postOrder(Node * r) {
  if (r == NULL) return;
  postOrder(r -> leftChild);
  postOrder(r -> rightChild);
  printf("%d ", r -> id);
}
int main() {
  scanf("%d", & n);
  for (int i = 1; i <= n; i++) scanf("%d", & a[i]);
  ok = 1;
  Node * root = build(1, n);
  if (ok == 0) {
    printf("NULL");
    return 0;
  }
  postOrder(root);
  printf("\n");
  return 0;
}
