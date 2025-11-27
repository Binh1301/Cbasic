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
