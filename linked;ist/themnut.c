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
