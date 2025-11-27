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
