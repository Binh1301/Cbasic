void deleteFirstElement() {
  node * del = root;
  if (del == NULL) return;
  root = del -> next;
  free(del);
  cur = root;
  prev = NULL; //update prev – cur
}
