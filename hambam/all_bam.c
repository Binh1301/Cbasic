#demsolan
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define N 1000001
typedef struct Node {
  char word[20];
  int occ;
  struct Node * leftChild;
  struct Node * rightChild;
}
Node;

Node * root;
char T[N];
int n;
void input() {
  n = 0;
  while (!feof(stdin)) {
    char c = fgetc(stdin);
    T[n] = c;
    n += 1;
  }
  T[n - 1] = '\0';
}
Node * makeNode(char * w) {
  Node * nod = (Node * ) malloc(sizeof(Node));
  strcpy(nod -> word, w);
  nod -> occ = 1;
  nod -> leftChild = NULL;
  nod -> rightChild = NULL;
  return nod;
}
Node * insert(Node * r, char * w) {
  if (r == NULL) return makeNode(w);
  int c = strcmp(r -> word, w);
  if (c == 0) {
    r -> occ += 1;
    return r;
  }
  if (c < 0)
    r -> rightChild = insert(r -> rightChild, w);
  else
    r -> leftChild = insert(r -> leftChild, w);
  return r;
}
int legal(char c) {
  return (c >= 'a' && c <= 'z' || c >= 'A' && c <=
    'Z' || c >= '0' && c <= '9');
}
void solve() {
  root = NULL;
  char word[30];
  int end = -1;
  for (int i = 0; i < n; i++) {
    if (legal(T[i])) {
      end++;
      word[end] = T[i];
    } else {
      if (end != -1) {
        word[end + 1] = '\0';
        root = insert(root, word);
      }
      end = -1;
    }
  }
}
void inOrder(Node * r) {
  if (r == NULL) return;
  inOrder(r -> leftChild);
  printf("%s %d\n", r -> word, r -> occ);
  inOrder(r -> rightChild);
}

int main() {
  input();
  solve();
  inOrder(root);
  return 0;
}
#hambam

#include <string.h>

#include <stdio.h>

#include <time.h>

#include <stdlib.h>

#define MAX 200
int n, m;
int hashCode(char * k) {
  int c = 0;
  for (int i = 0; i < strlen(k); i++) {
    c = (c * 256 + k[i]) % m;
  }
  return c;
}
void solve() {
  scanf("%d%d", & n, & m);
  char k[200];
  for (int i = 0; i < n; i++) {
    scanf("%s", k);
    int h = hashCode(k);
    printf("%d\n", h);
  }
}
int main() {
  solve();
  return 0;
}
#hangbam

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
#hashinter
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50
#define m 10000

typedef struct Node {
    char key[MAX];
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* T[m];   

Node* makeNode(char* k) {
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->key, k);
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

int h(char* k) {
    int c = 0;
    for (int i = 0; i < strlen(k); i++)
        c = (c * 256 + k[i]) % m;
    return c;
}

Node* findBST(Node* r, char* k) {
    if (r == NULL) return NULL;
    int cmp = strcmp(r->key, k);
    if (cmp == 0) return r;
    if (cmp < 0) return findBST(r->rightChild, k);
    return findBST(r->leftChild, k);
}

Node* insertBST(Node* r, char* k) {
    if (r == NULL) return makeNode(k);
    if (strcmp(r->key, k) < 0)
        r->rightChild = insertBST(r->rightChild, k);
    else
        r->leftChild = insertBST(r->leftChild, k);
    return r;
}

int find(char* k) {
    int i = h(k);
    return (findBST(T[i], k) != NULL);
}

int insert(char* k) {
    int i = h(k);
    if (findBST(T[i], k) != NULL) return 0;
    T[i] = insertBST(T[i], k);
    return 1;
}

int main() {
    char k[MAX], cmd[20];

    for (int i = 0; i < m; i++)
        T[i] = NULL;

    while (1) {
        scanf("%s", k);
        if (strcmp(k, "*") == 0) break;
        insert(k);
    }

    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "find") == 0) {
            scanf("%s", k);
            printf("%d\n", find(k));
        } 
        else if (strcmp(cmd, "insert") == 0) {
            scanf("%s", k);
            printf("%d\n", insert(k));
        } 
        else if (strcmp(cmd, "***") == 0) {
            break;
        }
    }

    return 0;
}
#wordfrequency
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define N 1000001
typedef struct Node {
  char word[20];
  int occ;
  struct Node * leftChild;
  struct Node * rightChild;
}
Node;

Node * root;
char T[N];
int n;
void input() {
  n = 0;
  while (!feof(stdin)) {
    char c = fgetc(stdin);
    T[n] = c;
    n += 1;
  }
  T[n - 1] = '\0';
}
Node * makeNode(char * w) {
  Node * nod = (Node * ) malloc(sizeof(Node));
  strcpy(nod -> word, w);
  nod -> occ = 1;
  nod -> leftChild = NULL;
  nod -> rightChild = NULL;
  return nod;
}
Node * insert(Node * r, char * w) {
  if (r == NULL) return makeNode(w);
  int c = strcmp(r -> word, w);
  if (c == 0) {
    r -> occ += 1;
    return r;
  }
  if (c < 0)
    r -> rightChild = insert(r -> rightChild, w);
  else
    r -> leftChild = insert(r -> leftChild, w);
  return r;
}
int legal(char c) {
  return (c >= 'a' && c <= 'z' || c >= 'A' && c <=
    'Z' || c >= '0' && c <= '9');
}
void solve() {
  root = NULL;
  char word[30];
  int end = -1;
  for (int i = 0; i < n; i++) {
    if (legal(T[i])) {
      end++;
      word[end] = T[i];
    } else {
      if (end != -1) {
        word[end + 1] = '\0';
        root = insert(root, word);
      }
      end = -1;
    }
  }
}
void inOrder(Node * r) {
  if (r == NULL) return;
  inOrder(r -> leftChild);
  printf("%s %d\n", r -> word, r -> occ);
  inOrder(r -> rightChild);
}

int main() {
  input();
  solve();
  inOrder(root);
  return 0;
}
