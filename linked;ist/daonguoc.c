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
