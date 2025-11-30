
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_t{
    int key;
    struct Node_t* next;
}Node;
Node* tail = NULL;
Node* head = NULL;
Node* makeNewNode(int u){
    Node* new = (Node*)malloc(sizeof(Node));
    new->key = u;
    new->next = NULL;
    return new;
}
int queueEmpty(){
    return head == NULL;
}
void push(int u){
    Node* p = makeNewNode(u);
    if(queueEmpty()){
        head = tail = p;
    }else{
    tail->next = p;
    tail = p;
}}
int pop(){
    if(queueEmpty()) return -1;
    int v = head->key;
    Node* tmp = head;
    head = head->next;
    free(tmp);
    return v;

}
void print_list(){
    Node* p =head;
    while(p != tail){
        printf("%d", p->key);
        p = p->next;
    }
}
int main(){
    char cmd[256];
    while(1){
        scanf("%s", cmd);
        if(strcmp(cmd,"#") == 0){
            break;
        }
        if(strcmp(cmd,"PUSH") == 0){
            int v;
            scanf("%d", &v);
            push(v);

        }
        if(strcmp(cmd,"POP") == 0){
                if(queueEmpty()) printf("NULL\n");
                else{
            int v = pop();
            printf("%d\n", v);
        }}}
        return 0;
}



