

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    char s[10];
    struct Node* next;
}Node;
Node* tail_1 = NULL;
Node* head_1 = NULL;
Node* tail_2 = NULL;
Node* head_2 = NULL;
Node* makeNode(char* s){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->s, s);
    p->next = NULL;
    return p;
}
Node* push_1( char* s){
    Node* r = makeNode(s);
    if(tail_1 == NULL && head_1 == NULL ){
        tail_1 =  head_1 = r;
    }else{
    tail_1->next = r;
    tail_1 = r;}
    return r;
}
Node* push_2( char* s){
    Node* r = makeNode(s);
    if(tail_2 == NULL && head_2 == NULL ){
        tail_2 =  head_2 = r;
    }
    else{
    tail_2->next = r;
    tail_2 = r;}
    return r;
}
int pop_1(char* out){
    if(tail_1 == NULL && head_1 == NULL) return -1;
    Node* tmp = head_1;
    strcpy(out, tmp->s);
    head_1 = head_1->next;
    if(head_1 == NULL) tail_1 = NULL;
    free(tmp);
    return 1;
}
int pop_2(char* out){
    if(tail_2 == NULL && head_2 == NULL) return -1;
    Node* tmp = head_2;
    strcpy(out, tmp->s);
    head_2 = head_2->next;
    if(head_2 == NULL) tail_2 = NULL;
    free(tmp);
    return 1;
}

int main(){
    while(1){
        char cmd[10];
        scanf("%s", cmd);
        if(strcmp(cmd, "#") == 0) break;
        if(strcmp(cmd, "ENQUEUE") == 0){
            int c;
            char name[10];
            scanf("%d", &c);
            scanf("%s", name);
            if(c == 0){
                Node* r = push_1(name);
            }
            if(c == 1){
                Node* r = push_2(name);
            }
        }
        if(strcmp(cmd, "DEQUEUE") == 0){
            int c;
            char name[10];
            scanf("%d", &c);
            if(c == 0){
                if(pop_1(name) == 1) printf("WELCOME %s\n", name);
                else  printf("NULL");
            } else {
                if(pop_2(name) == 1) printf("WELCOME %s\n", name);
                else  printf("NULL");
            }
        }
    }

    return 0;


}

