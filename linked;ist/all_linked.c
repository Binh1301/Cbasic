#1
void insertAtTail(contact ct){
    node* new = makeNewNode(ct);      // ①
    if (root == NULL) {                // ②
        root = new;
        cur = new;
        prev = NULL;
        return;
    }
    node* p = root;                    // ③
    while (p->next != NULL) p = p->next; // ④
    p->next = new;                     // ⑤
    cur = new;
    prev = p;                          // ⑥
}
node * insertLastRecursive(node * root, contact ct) { // de quy
  if (root == NULL) {
    return makeNewNode(ct);
  }
  root -> next = insertLastRecursive(root -> next, ct);
  return root;
}
void main() {
  contact tmp;
  int i;
  for (i = 0; i < 2; i++) {
    tmp = readNode();
    root = insertLastRecursive(tmp);
    displayNode(root);
  }
}
#2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int elementtype;
struct node_t{
    elementtype element;
    struct node_t* next;
};

typedef struct node_t Node;
Node* root = NULL;
Node* cur = NULL;
Node* prev = NULL;
Node* makeNewNode(elementtype e){
    Node* new = (Node*)malloc(sizeof(Node));
    new->element = e;
    new->next = NULL;
    return new;
}
Node* find(Node* root, elementtype e){
    Node* p;
    for(p = root; p!= NULL; p = p->next){
        if(p->element == e) return p;
    }
    return NULL;
}
void insertAtTail(elementtype e){
    Node* new = makeNewNode(e);
    if(root == NULL){
        root = new;
        cur = new;
        prev = NULL;
        return;
    }
    Node* p = root;
    while(p->next != NULL) p = p->next;
    p->next = new;
    cur = new;
    prev = p;
}
Node * insertLastRecursive(Node* root, elementtype e){
    if(root == NULL){
        return makeNewNode(e);
    }
    root->next = insertLastRecursive(root->next,e);
    return root;
}
void insertAtHead(elementtype e){
    Node* new = makeNewNode(e);
    new->next = root;
    root = new;
    cur = root;
}
Node* removeNodeRecursive(Node* root, elementtype e){
    if(root == NULL) return NULL;
    if(root->element == e){
        Node* tmp = root;
        root = root->next;
        free(tmp);
        return root;
    }
    root->next = removeNodeRecursive(root->next, e);
    return root;
}
void freeList() {
    Node * to_free = root;
    while (to_free != NULL) {
      root = root -> next;
      free(to_free);
      to_free = root;
    }}
Node * addBefore(Node * root, elementtype u, elementtype v) {

  if (root == NULL) return NULL;
  if (find(root, u) != NULL) return root; // do nothing
  if (root -> element == v) {

    Node * q = makeNewNode(u);
    q -> next = root;
    return q;

  }
  root -> next = addBefore(root -> next, u, v);
  return root;

}
Node * addAfter(Node * root, elementtype u, elementtype v) {

  if (root == NULL) return NULL;
  if (root -> element == v) {

    Node * q = makeNewNode(u);
    q -> next = root -> next;
    root -> next = q;
    return root;

  }
  root -> next = addAfter(root -> next, u, v);
  return root;

}
Node * reverse(Node * root) {

  Node * p = root;
  Node * pp = NULL;
  Node * np = NULL;
  while (p != NULL) {

    np = p ->next;
    p->next = pp;
    pp = p;
    p = np;
  }
  return pp;

}
void traverseList(Node * root) {

  Node * p = root;
  while (p != NULL) {

    printf("%d ", p -> element);
    p = p -> next;
  }
  printf("\n");
}
void solve() {
    int n, i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        root = insertLastRecursive(root, k);
    }

    while (1) {
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0) break;

        if (strcmp(cmd, "addlast") == 0) {
            int k;
            scanf("%d", &k);
            if (find(root, k) == NULL)
                root = insertLastRecursive(root, k);
        }
        else if (strcmp(cmd, "addfirst") == 0) {
            int k;
            scanf("%d", &k);
            if (find(root, k) == NULL)
                insertAtHead(k);
        }
        else if (strcmp(cmd, "addafter") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            if (find(root, u) == NULL)
                root = addAfter(root, u, v);
        }
        else if (strcmp(cmd, "addbefore") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            if (find(root, u) == NULL)
                root = addBefore(root, u, v);
        }
        else if (strcmp(cmd, "remove") == 0) {
            int k;
            scanf("%d", &k);
            root = removeNodeRecursive(root, k);
        }
        else if (strcmp(cmd, "reverse") == 0) {
            root = reverse(root);
        }
    }
}

int main() {
    solve();
    traverseList(root);
    freeList();
    return 0;
}



#3
node * list_reverse(node * root) {
  node * cur, * prev;
  cur = prev = NULL;
  while (root != NULL) {

    cur = root;
    root = root -> next;
    cur -> next = prev;
    prev = cur;

  }
  return prev;
}
#4
void traversingList(node * root) {
  node * p;
  for (p = root; p != NULL; p = p -> next)
    displayNode(p);
}
#5
while (to_free != NULL) {
  root = root -> next;
  free(to_free);
  to_free = root;
}
#6
void insertAtHead(contact ct){
    node *new = makeNewNode(ct);
    new->next = root;
    root = new;
    cur = root;
}

void main(){
    contact tmp;
    int i;
    for( i = 0; i< 2; i++){
        tmp = readNode();
        insertAtHead(tmp);
        displayNode(root);
    }


}
#7
tmp = root;
while (tmp != NULL && tmp -> next != cur && cur != NULL)

  tmp = tmp -> next;

prev = tmp;
#8
void insertBeforeCurrent(contact e) {
  node_addr * new = makeNewNode(e);
  if (root == NULL) {
    /* if there is no element */
    root = new;
    cur = root;
    prev = NULL;

  } else {

    new -> next = cur;
    if (cur == root) {
      /* if cur pointed to first element */

      root = new; /* nut moi them vao tro thanh dau danh sach */

    } else prev -> next = new; // assume prev pointer always point to the previous node
    cur = new;

  }
}
#9
Node * removeNodeRecursive(Node * root, contact e) {

  if (root == NULL) return NULL;
  if (root -> el == e) {

    Node * tmp = root;
    root = root -> next;
    free(tmp);
    return root;

  }
  root -> next = removeNodeRecursive(root -> next, e);
  return root;

}
#10
void deleteFirstElement() {
  node * del = root;
  if (del == NULL) return;
  root = del -> next;
  free(del);
  cur = root;
  prev = NULL; //update prev � cur
}
#11
void deleteCurrentElement() {
    if (cur == NULL) return;
    if (cur == root) deleteFirstElement();
    else {
      prev -> next = cur -> next;
      free(cur);
      cur = prev -> next; // or cur = root;
    }
