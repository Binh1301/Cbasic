void traversingList(node * root) {
  node * p;
  for (p = root; p != NULL; p = p -> next)
    displayNode(p);
}
