#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    int value;
    struct Node* next;
}Node;
Node* tail = NULL;
Node* head = NULL;
Node* makeNode(int v){
    Node* r = (Node*)malloc(sizeof(Node));
    r->value = v;
    r->next = NULL;
    return r;
}
int check_exit(int v){
    Node* cur = head;
    while(cur != NULL){
        if(cur->value == v) return 0;
        cur = cur->next;
    }
    return 1;
}
Node* push(int v){
    if(check_exit(v) == 1 && v >= 0){
    Node* r = makeNode(v);
    if(head == NULL && tail == NULL) head = tail = r;
    else{
    tail->next = r;
    tail = r;}
    return r;}
}

Node* pushhead(int v){
    if(check_exit(v) == 1 && v >= 0){
    Node* r = makeNode(v);
    if(head == NULL && tail == NULL) head = tail = r;
    else{
    r->next = head;
    head = r;}
    return r;}
}
void in_0(){
    Node* cur = head;
    while(cur != NULL){
        printf("%d ", cur->value);
        cur = cur->next;
    }
}
void in_1(){
    Node* cur_1 = head;
    Node* cur_2 = head;
    while(cur_1 != NULL){
        if(cur_1->value % 2 == 0)
        printf("%d ", cur_1->value);
        cur_1 = cur_1->next;
    }
    while(cur_2 != NULL){
        if(cur_2->value % 2 == 1)
        printf("%d ", cur_2->value);
        cur_2 = cur_2->next;
    }
}
int main(){
    while(1){
        char c[20];
        scanf("%s", c);
        if(strcmp(c, "Print") == 0) {
                int k;
                scanf("%d", &k);
                if(k == 0)in_0();
                if(k == 1)in_1();
        break;}
        if(strcmp(c, "InsertTail") == 0){
            int value;
            scanf("%d", &value);
            Node* r = push(value);
        }
        if(strcmp(c, "InsertHead") == 0){
                int value;
            scanf("%d", &value);
            Node* r = pushhead(value);
        }

    }
    return 0;
}


