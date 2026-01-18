
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    int key;
    struct Node* next;
}Node;
 Node* tail = NULL;
 Node* head = NULL;
Node* makeNode(int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->key = v;
    p->next = NULL;
    return p;
}
void push(int v){
    Node* p = makeNode(v);
    if(tail == NULL && head == NULL){
        tail = head = p;
    }
    tail->next = p;
    tail = p;
    return;
}
int pop(){
    if(tail == NULL && head == NULL){
        return -1;
    }
    int v = head->key;
    Node* tmp = head;
    head = head->next;
    free(tmp);
    return v;
}
int main(){
    while(1){
        char cmd[100];
        scanf("%s", cmd);
        if(strcmp(cmd, "#") == 0) break ;
        if(strcmp(cmd, "NEW") == 0){
                int n;
        scanf("%d", &n);
        push(n);
        }
        if(strcmp(cmd, "GET") == 0){
            int a = pop();
            printf("%d", a);
            printf("\n");
        }
    }
    return 0;


}

