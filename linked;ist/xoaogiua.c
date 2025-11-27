void deleteCurrentElement() {
    if (cur == NULL) return;
    if (cur == root) deleteFirstElement();
    else {
      prev -> next = cur -> next;
      free(cur);
      cur = prev -> next; // or cur = root;
    }
