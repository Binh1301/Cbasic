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
