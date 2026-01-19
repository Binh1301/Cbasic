#balancebanarytree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

#define MAX_NODES 50001

typedef struct Node {
    int id;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    int balanced; 
    int h;        
} INFO;

Node* nodes[MAX_NODES];
Node* root = NULL;

Node* makeNode(int id) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void addLeft(int u, int v) {
    if (nodes[u] != NULL || nodes[v] == NULL) return;
    if (nodes[v]->left != NULL) return;
    Node* p = makeNode(u);
    nodes[v]->left = p;
    nodes[u] = p;
}

void addRight(int u, int v) {
    if (nodes[u] != NULL || nodes[v] == NULL) return;
    if (nodes[v]->right != NULL) return;
    Node* p = makeNode(u);
    nodes[v]->right = p;
    nodes[u] = p;
}

INFO visit(Node *r) {
    if (r == NULL) {
        INFO i;
        i.balanced = 1;
        i.h = 0;
        return i;
    }
    INFO i1 = visit(r->left);
    INFO i2 = visit(r->right);
    INFO i;
    i.h = (i1.h > i2.h ? i1.h : i2.h) + 1;
    if (!i1.balanced || !i2.balanced || abs(i1.h - i2.h) > 1)
        i.balanced = 0;
    else
        i.balanced = 1;
    return i;
}

int main() {
    for (int i = 0; i < MAX_NODES; i++) nodes[i] = NULL;

    char cmd[20];
    while (scanf("%s", cmd)) {
        if (strcmp(cmd, "*") == 0) break;
        if (strcmp(cmd, "MakeRoot") == 0) {
            int u;
            scanf("%d", &u);
            root = makeNode(u);
            nodes[u] = root;
        } else if (strcmp(cmd, "AddLeft") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            addLeft(u, v);
        } else if (strcmp(cmd, "AddRight") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            addRight(u, v);
        }
    }

    INFO result = visit(root);
    if (result.balanced)
        printf("1 %d\n", result.h);
    else
        printf("0 %d\n", result.h);

    return 0;
}
#binarytravel
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node {
  int id;
  struct Node * leftChild;
  struct Node * rightChild;

}
Node;
Node * makeNode(int u) {
  Node * p = (Node * ) malloc(sizeof(Node));
  p -> leftChild = NULL;
  p -> rightChild = NULL;
  p -> id = u;
  return p;
}
Node * find(int u, Node * r) {
  if (r == NULL) return NULL;
  if (r -> id == u) return r;
  Node * p = find(u, r -> leftChild);
  if (p != NULL) return p;
  return find(u, r -> rightChild);
}
void addLeft(int u, int v, Node * r) {
  Node * p = find(v, r);
  if (p == NULL) return;

  if (p -> leftChild != NULL) return;
  Node * q = find(u, r);
  if (q != NULL) return;
    p -> leftChild = makeNode(u);
}


void addRight(int u, int v, Node *r) {
    Node * p = find(v, r);
    if (p == NULL) return;
    if (p -> rightChild != NULL) return;
    Node * q = find(u, r);
    if (q != NULL) return;
    p -> rightChild = makeNode(u);
}
void preOrder(Node * r) {
  if (r == NULL) return;
  printf("%d ", r -> id);
  preOrder(r -> leftChild);
  preOrder(r -> rightChild);
}

void inOrder(Node * r) {
  if (r == NULL) return;
  inOrder(r -> leftChild);
  printf("%d ", r -> id);
  inOrder(r -> rightChild);
}

void postOrder(Node * r) {
  if (r == NULL) return;
  postOrder(r -> leftChild);
  postOrder(r -> rightChild);
  printf("%d ", r -> id);
}
int main() {
  char cmd[100];
  Node * root = NULL;
  while (1) {
    scanf("%s", cmd);
    if (strcmp(cmd, "*") == 0) break;
    else if (strcmp(cmd, "MakeRoot") == 0) {
      int u;
      scanf("%d", & u);
      root = makeNode(u);
    } else if (strcmp(cmd, "AddLeft") == 0) {
      int u, v;
      scanf("%d%d", & u, & v);
      addLeft(u, v, root);
    } else if (strcmp(cmd, "AddRight") == 0) {
      int u, v;
      scanf("%d%d", & u, & v);
      addRight(u, v, root);
    } else if (strcmp(cmd, "InOrder") == 0) {
      inOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "PreOrder") == 0) {
      preOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "PostOrder") == 0) {
      postOrder(root);
      printf("\n");
    }
  }
}
#cay1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    int id;
    struct Node* leftmostchild;
    struct Node* rightSibling;
    struct Node* parent;
}Node;
Node* makeNode(int id){
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id;
    p->leftmostchild = NULL;
    p->rightSibling = NULL;
    p->parent = NULL;
    return p;

}
Node* find(Node* r, int u){
    if( r == NULL) return NULL;
    if( r->id == u) return r;
    Node* p = r->leftmostchild;
    while ( p != NULL){
        Node* q = find(p,u);
        if( q != NULL) return q;
        p = p->rightSibling;
    }
    return NULL;
}
void insert(Node* r, int u, int v){
    Node* p = find(r , v);
    if( p == NULL) return;
    Node* q = makeNode(u);
    if(p->leftmostchild == NULL){
        p->leftmostchild = q;
        q->parent = p;
        return;}
        Node* h = p->leftmostchild;
        while(h->rightSibling != NULL)
            h = h->rightSibling;
        h->rightSibling = q;
        q->parent = p;
    }
int depth(Node* r){
    Node* p = r;
    int d = 0;
    while(p != NULL){
        d += 1;
        p = p->parent;
    }
    return d;
}
int height(Node* r){
    int maxH = 0;
    if(r == NULL) return 0;
    for(Node* p = r->leftmostchild; p != NULL; p = p->rightSibling){
            int h = height(p);
            if(h > maxH) maxH = h;
}
return maxH + 1;
}

void freeTree(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftmostchild;
  while (p != NULL) {
    Node * np = p -> rightSibling;
    free(p);
    p = np;
  }
  free(r);
}
void solve() {
  Node * root = NULL;
  char cmd[50];
  while (1) {
    scanf("%s", cmd);
    if (strcmp(cmd, "*") == 0) break;
    else if (strcmp(cmd, "MakeRoot") == 0) {
      int id;
      scanf("%d", & id);
      root = makeNode(id);
    } else if (strcmp(cmd, "Insert") == 0) {
      int u, v;
      scanf("%d%d", & u, & v);
      insert(root, u, v);
    } else if (strcmp(cmd, "Height") == 0) {
      int id;
      scanf("%d", & id);
      Node * p = find(root, id);
      printf("%d\n", height(p));
    } else if (strcmp(cmd, "Depth") == 0) {
      int id;
      scanf("%d", & id);
      Node * p = find(root, id);
      int ans = depth(p);
      printf("%d\n", ans);
    }
  }
  freeTree(root);
}
int main() {
  solve();
}


#cay2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
  int id;
  struct Node* leftMostChild;
  struct Node* rightSibling;
}Node;
Node * makeNode(int u) {
  Node * p = (Node * ) malloc(sizeof(Node));
  p -> id = u;
  p -> leftMostChild = NULL;
  p -> rightSibling = NULL;
  return p;
}
Node * find(Node * r, int u) {
  if (r == NULL) return NULL;
  if (r -> id == u) return r;
  Node * p = r -> leftMostChild;
  while (p != NULL) {
    Node * q = find(p, u);
    if (q != NULL) return q;
    p = p -> rightSibling;
  }
  return NULL;
}
void insert(Node * r, int u, int v) {
  Node* p = find(r, v);
  if (p == NULL) return;
  Node * q = makeNode(u);
  if (p -> leftMostChild == NULL) {
    p -> leftMostChild = q;
    return;
  }
  Node * h = p -> leftMostChild;
  while (h -> rightSibling != NULL)
    h = h -> rightSibling;
  h -> rightSibling = q;
}

void preOrder(Node * r) {
  if (r == NULL) return;
  printf("%d ", r -> id);
  Node * p = r -> leftMostChild;
  while (p != NULL) {
    preOrder(p);
    p = p -> rightSibling;
  }
}

void inOrder(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftMostChild;
  inOrder(p);
  printf("%d ", r -> id);
  if (p == NULL) return;
  p = p -> rightSibling;
  while (p != NULL) {
    inOrder(p);
    p = p -> rightSibling;
  }
}

void postOrder(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftMostChild;

  while (p != NULL) {
    postOrder(p);
    p = p -> rightSibling;
  }
  printf("%d ", r -> id);
}
void freeTree(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftMostChild;
  while (p != NULL) {
    Node * np = p -> rightSibling;
    free(p);
    p = np;
  }
  free(r);
}
void solve() {
  Node * root = NULL;
  char cmd[50];
  while (1) {
    scanf("%s", cmd);
    if (strcmp(cmd, "*") == 0) break;
    else if (strcmp(cmd, "MakeRoot") == 0) {
      int id;
      scanf("%d", & id);
      root = makeNode(id);
    } else if (strcmp(cmd, "Insert") == 0) {
      int u, v;
      scanf("%d%d", & u, & v);
      insert(root, u, v);
    } else if (strcmp(cmd, "PreOrder") == 0) {
      preOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "InOrder") == 0) {
      inOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "PostOrder") == 0) {
      postOrder(root);
      printf("\n");
    }
  }
  freeTree(root);
}
int main() {
  solve();
}

#cay3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
  int id;
  struct Node* leftMostChild;
  struct Node* rightSibling;
}Node;
Node * makeNode(int u) {
  Node * p = (Node * ) malloc(sizeof(Node));
  p -> id = u;
  p -> leftMostChild = NULL;
  p -> rightSibling = NULL;
  return p;
}
Node * find(Node * r, int u) {
  if (r == NULL) return NULL;
  if (r -> id == u) return r;
  Node * p = r -> leftMostChild;
  while (p != NULL) {
    Node * q = find(p, u);
    if (q != NULL) return q;
    p = p -> rightSibling;
  }
  return NULL;
}
void insert(Node * r, int u, int v) {
  Node* p = find(r, v);
  if (p == NULL) return;
  Node * q = makeNode(u);
  if (p -> leftMostChild == NULL) {
    p -> leftMostChild = q;
    return;
  }
  Node * h = p -> leftMostChild;
  while (h -> rightSibling != NULL)
    h = h -> rightSibling;
  h -> rightSibling = q;
}

void preOrder(Node * r) {
  if (r == NULL) return;
  printf("%d ", r -> id);
  Node * p = r -> leftMostChild;
  while (p != NULL) {
    preOrder(p);
    p = p -> rightSibling;
  }
}

void inOrder(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftMostChild;
  inOrder(p);
  printf("%d ", r -> id);
  if (p == NULL) return;
  p = p -> rightSibling;
  while (p != NULL) {
    inOrder(p);
    p = p -> rightSibling;
  }
}

void postOrder(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftMostChild;

  while (p != NULL) {
    postOrder(p);
    p = p -> rightSibling;
  }
  printf("%d ", r -> id);
}
void freeTree(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftMostChild;
  while (p != NULL) {
    Node * np = p -> rightSibling;
    free(p);
    p = np;
  }
  free(r);
}
void solve() {
  Node * root = NULL;
  char cmd[50];
  while (1) {
    scanf("%s", cmd);
    if (strcmp(cmd, "*") == 0) break;
    else if (strcmp(cmd, "MakeRoot") == 0) {
      int id;
      scanf("%d", & id);
      root = makeNode(id);
    } else if (strcmp(cmd, "Insert") == 0) {
      int u, v;
      scanf("%d%d", & u, & v);
      insert(root, u, v);
    } else if (strcmp(cmd, "PreOrder") == 0) {
      preOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "InOrder") == 0) {
      inOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "PostOrder") == 0) {
      postOrder(root);
      printf("\n");
    }
  }
  freeTree(root);
}
int main() {
  solve();
}
#cay1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node {
  int id;
  struct Node * leftChild;
  struct Node * rightChild;

}
Node;
Node * makeNode(int u) {
  Node * p = (Node * ) malloc(sizeof(Node));
  p -> leftChild = NULL;
  p -> rightChild = NULL;
  p -> id = u;
  return p;
}
Node * find(int u, Node * r) {
  if (r == NULL) return NULL;
  if (r -> id == u) return r;
  Node * p = find(u, r -> leftChild);
  if (p != NULL) return p;
  return find(u, r -> rightChild);
}
void addLeft(int u, int v, Node * r) {
  Node * p = find(v, r);
  if (p == NULL) return;

  if (p -> leftChild != NULL) return;
  Node * q = find(u, r);
  if (q != NULL) return;
    p -> leftChild = makeNode(u);
}


void addRight(int u, int v, Node *r) {
    Node * p = find(v, r);
    if (p == NULL) return;
    if (p -> rightChild != NULL) return;
    Node * q = find(u, r);
    if (q != NULL) return;
    p -> rightChild = makeNode(u);
}
void preOrder(Node * r) {
  if (r == NULL) return;
  printf("%d ", r -> id);
  preOrder(r -> leftChild);
  preOrder(r -> rightChild);
}

void inOrder(Node * r) {
  if (r == NULL) return;
  inOrder(r -> leftChild);
  printf("%d ", r -> id);
  inOrder(r -> rightChild);
}

void postOrder(Node * r) {
  if (r == NULL) return;
  postOrder(r -> leftChild);
  postOrder(r -> rightChild);
  printf("%d ", r -> id);
}
int main() {
  char cmd[100];
  Node * root = NULL;
  while (1) {
    scanf("%s", cmd);
    if (strcmp(cmd, "*") == 0) break;
    else if (strcmp(cmd, "MakeRoot") == 0) {
      int u;
      scanf("%d", & u);
      root = makeNode(u);
    } else if (strcmp(cmd, "AddLeft") == 0) {
      int u, v;
      scanf("%d%d", & u, & v);
      addLeft(u, v, root);
    } else if (strcmp(cmd, "AddRight") == 0) {
      int u, v;
      scanf("%d%d", & u, & v);
      addRight(u, v, root);
    } else if (strcmp(cmd, "InOrder") == 0) {
      inOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "PreOrder") == 0) {
      preOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "PostOrder") == 0) {
      postOrder(root);
      printf("\n");
    }
  }
}
#cay2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 50001

typedef struct Node {
    int id;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    int balanced;
    int h;
} INFO;

Node* nodes[MAX_NODES];
Node* root = NULL;

Node* makeNode(int id) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void addLeft(int u, int v) {
    if (nodes[u] != NULL || nodes[v] == NULL) return;
    if (nodes[v]->left != NULL) return;
    Node* p = makeNode(u);
    nodes[v]->left = p;
    nodes[u] = p;
}

void addRight(int u, int v) {
    if (nodes[u] != NULL || nodes[v] == NULL) return;
    if (nodes[v]->right != NULL) return;
    Node* p = makeNode(u);
    nodes[v]->right = p;
    nodes[u] = p;
}

INFO visit(Node *r) {
    if (r == NULL) {
        INFO i;
        i.balanced = 1;
        i.h = 0;
        return i;
    }
    INFO i1 = visit(r->left);
    INFO i2 = visit(r->right);
    INFO i;
    i.h = (i1.h > i2.h ? i1.h : i2.h) + 1;
    if (!i1.balanced || !i2.balanced || abs(i1.h - i2.h) > 1)
        i.balanced = 0;
    else
        i.balanced = 1;
    return i;
}

int main() {
    for (int i = 0; i < MAX_NODES; i++) nodes[i] = NULL;

    char cmd[20];
    while (scanf("%s", cmd)) {
        if (strcmp(cmd, "*") == 0) break;
        if (strcmp(cmd, "MakeRoot") == 0) {
            int u;
            scanf("%d", &u);
            root = makeNode(u);
            nodes[u] = root;
        } else if (strcmp(cmd, "AddLeft") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            addLeft(u, v);
        } else if (strcmp(cmd, "AddRight") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            addRight(u, v);
        }
    }

    INFO result = visit(root);
    if (result.balanced)
        printf("1 %d\n", result.h);
    else
        printf("0 %d\n", result.h);

    return 0;
}
#familytree
#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 10
#define MAX_NAME 32

typedef struct Person {
    char name[MAX_NAME];
    struct Person* children[MAX_PEOPLE];
    int child_count;
} Person;

Person people[MAX_PEOPLE];
int people_count = 0;
int visited[MAX_PEOPLE];

/* tìm hoặc tạo người */
Person* get_person(const char* name) {
    for (int i = 0; i < people_count; i++)
        if (strcmp(people[i].name, name) == 0)
            return &people[i];

    strcpy(people[people_count].name, name);
    people[people_count].child_count = 0;
    return &people[people_count++];
}

/* đếm hậu duệ */
int count_descendants(Person* p) {
    int idx = p - people;
    if (visited[idx]) return 0;
    visited[idx] = 1;

    int count = 0;
    for (int i = 0; i < p->child_count; i++) {
        count += 1;
        count += count_descendants(p->children[i]);
    }
    return count;
}

/* đếm số thế hệ */
int count_generations(Person* p) {
    int idx = p - people;
    if (visited[idx]) return 0;
    visited[idx] = 1;

    int max_gen = 0;
    for (int i = 0; i < p->child_count; i++) {
        int gen = count_generations(p->children[i]);
        if (gen > max_gen)
            max_gen = gen;
    }
    return p->child_count ? max_gen + 1 : 0;
}

int main() {
    char child[MAX_NAME], parent[MAX_NAME];

    /* đọc cây gia đình */
    while (scanf("%s", child), strcmp(child, "***") != 0) {
        scanf("%s", parent);
        Person* p_parent = get_person(parent);
        Person* p_child  = get_person(child);
        p_parent->children[p_parent->child_count++] = p_child;
    }

    char cmd[MAX_NAME], param[MAX_NAME];

    /* xử lý truy vấn */
    while (scanf("%s", cmd), strcmp(cmd, "***") != 0) {
        scanf("%s", param);

        Person* p = NULL;
        for (int i = 0; i < people_count; i++) {
            if (strcmp(people[i].name, param) == 0) {
                p = &people[i];
                break;
            }
        }

        if (!p) {
            printf("0\n");
            continue;
        }

        memset(visited, 0, sizeof(visited));

        if (strcmp(cmd, "descendants") == 0)
            printf("%d\n", count_descendants(p));
        else if (strcmp(cmd, "generation") == 0)
            printf("%d\n", count_generations(p));
    }

    return 0;
}
#nhap
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char key;
    struct Node* left;
    struct Node* right;
} Node;

Node* makeNode(char key){
    Node* p = (Node*)malloc(sizeof(Node));
    p->key = key;
    p->left = p->right = NULL;
    return p;
}

Node* insert(Node* root, char key){
    if (root == NULL) return makeNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

Node* findMin(Node* root){
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, char key){
    if (root == NULL) return NULL;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void postOrder(Node* root){
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->key);
}

/* optional: free whole tree to avoid memory leak */
void freeTree(Node* root){
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(){
    Node* root = NULL;
    char cmd[20], key;

    while (1){
        if (scanf("%s", cmd) != 1) break;
        if (strcmp(cmd, "#") == 0) break;

        /* read key character (skipping whitespace) */
        if (scanf(" %c", &key) != 1) break;

        if (strcmp(cmd, "insert") == 0){
            root = insert(root, key);
        } else if (strcmp(cmd, "delete") == 0 || strcmp(cmd, "del") == 0){
            root = deleteNode(root, key);
        } else {
            /* nếu có lệnh khác: bỏ qua hoặc thông báo (ở đây ta bỏ qua) */
        }
    }

    if (root == NULL)
        printf("NULL\n");
    else {
        postOrder(root);
        printf("\n");
    }

    freeTree(root);
    return 0;
}

#treeheight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    int id;
    struct Node* leftmostchild;
    struct Node* rightSibling;
    struct Node* parent;
}Node;
Node* makeNode(int id){
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id;
    p->leftmostchild = NULL;
    p->rightSibling = NULL;
    p->parent = NULL;
    return p;

}
Node* find(Node* r, int u){
    if( r == NULL) return NULL;
    if( r->id == u) return r;
    Node* p = r->leftmostchild;
    while ( p != NULL){
        Node* q = find(p,u);
        if( q != NULL) return q;
        p = p->rightSibling;
    }
    return NULL;
}
void insert(Node* r, int u, int v){
    Node* p = find(r , v);
    if( p == NULL) return;
    Node* q = makeNode(u);
    if(p->leftmostchild == NULL){
        p->leftmostchild = q;
        q->parent = p;
        return;}
        Node* h = p->leftmostchild;
        while(h->rightSibling != NULL)
            h = h->rightSibling;
        h->rightSibling = q;
        q->parent = p;
    }
int depth(Node* r){
    Node* p = r;
    int d = 0;
    while(p != NULL){
        d += 1;
        p = p->parent;
    }
    return d;
}
int height(Node* r){
    int maxH = 0;
    if(r == NULL) return 0;
    for(Node* p = r->leftmostchild; p != NULL; p = p->rightSibling){
            int h = height(p);
            if(h > maxH) maxH = h;
}
return maxH + 1;
}

void freeTree(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftmostchild;
  while (p != NULL) {
    Node * np = p -> rightSibling;
    free(p);
    p = np;
  }
  free(r);
}
void solve() {
  Node * root = NULL;
  char cmd[50];
  while (1) {
    scanf("%s", cmd);
    if (strcmp(cmd, "*") == 0) break;
    else if (strcmp(cmd, "MakeRoot") == 0) {
      int id;
      scanf("%d", & id);
      root = makeNode(id);
    } else if (strcmp(cmd, "Insert") == 0) {
      int u, v;
      scanf("%d%d", & u, & v);
      insert(root, u, v);
    } else if (strcmp(cmd, "Height") == 0) {
      int id;
      scanf("%d", & id);
      Node * p = find(root, id);
      printf("%d\n", height(p));
    } else if (strcmp(cmd, "Depth") == 0) {
      int id;
      scanf("%d", & id);
      Node * p = find(root, id);
      int ans = depth(p);
      printf("%d\n", ans);
    }
  }
  freeTree(root);
}
int main() {
  solve();
}
#treetravel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
  int id;
  struct Node* leftMostChild;
  struct Node* rightSibling;
}Node;
Node * makeNode(int u) {
  Node * p = (Node * ) malloc(sizeof(Node));
  p -> id = u;
  p -> leftMostChild = NULL;
  p -> rightSibling = NULL;
  return p;
}
Node * find(Node * r, int u) {
  if (r == NULL) return NULL;
  if (r -> id == u) return r;
  Node * p = r -> leftMostChild;
  while (p != NULL) {
    Node * q = find(p, u);
    if (q != NULL) return q;
    p = p -> rightSibling;
  }
  return NULL;
}
void insert(Node * r, int u, int v) {
  Node* p = find(r, v);
  if (p == NULL) return;
  Node * q = makeNode(u);
  if (p -> leftMostChild == NULL) {
    p -> leftMostChild = q;
    return;
  }
  Node * h = p -> leftMostChild;
  while (h -> rightSibling != NULL)
    h = h -> rightSibling;
  h -> rightSibling = q;
}

void preOrder(Node * r) {
  if (r == NULL) return;
  printf("%d ", r -> id);
  Node * p = r -> leftMostChild;
  while (p != NULL) {
    preOrder(p);
    p = p -> rightSibling;
  }
}

void inOrder(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftMostChild;
  inOrder(p);
  printf("%d ", r -> id);
  if (p == NULL) return;
  p = p -> rightSibling;
  while (p != NULL) {
    inOrder(p);
    p = p -> rightSibling;
  }
}

void postOrder(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftMostChild;

  while (p != NULL) {
    postOrder(p);
    p = p -> rightSibling;
  }
  printf("%d ", r -> id);
}
void freeTree(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftMostChild;
  while (p != NULL) {
    Node * np = p -> rightSibling;
    free(p);
    p = np;
  }
  free(r);
}
void solve() {
  Node * root = NULL;
  char cmd[50];
  while (1) {
    scanf("%s", cmd);
    if (strcmp(cmd, "*") == 0) break;
    else if (strcmp(cmd, "MakeRoot") == 0) {
      int id;
      scanf("%d", & id);
      root = makeNode(id);
    } else if (strcmp(cmd, "Insert") == 0) {
      int u, v;
      scanf("%d%d", & u, & v);
      insert(root, u, v);
    } else if (strcmp(cmd, "PreOrder") == 0) {
      preOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "InOrder") == 0) {
      inOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "PostOrder") == 0) {
      postOrder(root);
      printf("\n");
    }
  }
  freeTree(root);
}
int main() {
  solve();
}