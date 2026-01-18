#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    int value;
    struct Node* next;
}Node;
Node* tail_1 = NULL;
Node* head_1 = NULL;
Node* tail_2 = NULL;
Node* head_2 = NULL;
Node* makeNode(int v){
    Node* r = (Node*)malloc(sizeof(Node));
    r->value = v;
    r->next = NULL;
    return r;
}
Node* push_1(int v){
    Node* r = makeNode(v);
    if(head_1 == NULL && tail_1 == NULL) head_1 = tail_1 = r;
    else{
    tail_1->next = r;
    tail_1 = r;}
    return r;
}
Node* push_2(int v){
    Node* r = makeNode(v);
    if(head_2 == NULL && tail_2 == NULL) head_2 = tail_2 = r;
    else{
    tail_2->next = r;
    tail_2 = r;}
    return r;
}
Node* pushhead_1(int v){
     Node* r = makeNode(v);
    if(head_1 == NULL && tail_1 == NULL) head_1 = tail_1 = r;
    else{
    r->next = head_1;
    head_1 = r;}
    return r;
}
Node* pushhead_2(int v){
    Node* r = makeNode(v);
    if(head_2 == NULL && tail_2 == NULL) head_2 = tail_2 = r;
    else{
    r->next = head_2;
    head_2 = r;}
    return r;
}


int main(){
    int count_1 = 0;
    int count_2 = 0;
    while(1){
        char c[2];
        scanf("%s", c);
        if(strcmp(c, "#") == 0) break;
        if(strcmp(c, "A") == 0){
            int id, value;
            scanf("%d %d", &id,&value);
            if(id == 1){
                Node* r = push_1(value);
                count_1 += 1;
            }
            else if(id == 2){
                Node* r = push_2(value);
                count_2 += 1;
            }

        }
        if(strcmp(c, "I") == 0){
            int id, value;
            scanf("%d %d", &id,&value);
            if(id == 1){
                Node* r = pushhead_1(value);
                count_1 += 1;
            }
            else if(id == 2){
                Node* r = pushhead_2(value);
                count_2 += 1;
            }

        }

    }
    if( count_1 > count_2){
        Node* cur_2 = head_2;
        Node* cur_1 = head_1;
        while(cur_2 != NULL){
            printf("%d %d ", cur_1->value, cur_2->value);
            cur_2 = cur_2->next;
            cur_1 = cur_1->next;
        }
        while(cur_1 != NULL){
            printf("%d ", cur_1->value);
            cur_1 = cur_1->next;
        }
    }
    if( count_1 < count_2){
        Node* cur_2 = head_2;
        Node* cur_1 = head_1;
        while(cur_1 != NULL){
            printf("%d %d ", cur_1->value, cur_2->value);
            cur_2 = cur_2->next;
            cur_1 = cur_1->next;
        }
        while(cur_2 != NULL){
            printf("%d ", cur_2->value);
            cur_2 = cur_2->next;
        }
    }
    if(count_1 == count_2){
        Node* cur_2 = head_2;
        Node* cur_1 = head_1;
        while(cur_1 != NULL){
            printf("%d %d ", cur_1->value, cur_2->value);
            cur_2 = cur_2->next;
            cur_1 = cur_1->next;
        }
    }

    return 0;
}


