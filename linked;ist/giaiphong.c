while (to_free != NULL) {
  root = root -> next;
  free(to_free);
  to_free = root;
}
