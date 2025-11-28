#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t{
    int value;
    struct node_t* next;

}Node;
Node* tail = NULL;
Node* head = NULL;

Node* makeNewNode(int v){
    Node* new = (Node*)malloc(sizeof(Node));
    new->value = v;
    new->next = NULL;
    return new;
}
int queueEmpty(){
    return head == NULL; // vl
}
void push(int v){

    Node* p = makeNewNode(v);
    if(queueEmpty()){
        head = tail = p;
    }else{
    tail->next = p;
    tail = p;
}}
int pop(){
    if(queueEmpty()){
        return -1;
    }

    int v = head->value;
    Node* tmp;
    tmp = head;
    head = head->next;
    free(tmp);
    return v;
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

