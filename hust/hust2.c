#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
     char id[8];  // mã khách
    char name[21];  // tên khách
    char level[7];  // hạng
    struct Node *next;
}Node;
Node* head;
Node* tail;
Node* makeNode(char id[], char name[], char level[]){
    Node* r = (Node*)malloc(sizeof(Node));
    strcpy(r->id,id);
    strcpy(r->name,name);
    strcpy(r->level,level);
    r->next = NULL;
    return r;
}
Node* insert(char id[], char name[], char level[]){
    Node* r = makeNode(id, name, level);
    if(tail == NULL && head == NULL) tail = head = r;
    else{
    tail->next = r;
    tail = r;}
    return r;
}
void pop(char level[]){
    Node *cur = head, *prev = NULL;

    while(cur != NULL){
        if(strcmp(cur->level, level) == 0){
            Node* tmp = cur;

            if(prev == NULL){
                head = cur->next;
                cur = head;
            } else {
                prev->next = cur->next;
                cur = cur->next;
            }

            if(tmp == tail) tail = prev;
            free(tmp);
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
}

void pop_1(){
    if(head == NULL && tail == NULL) return;
    Node* tmp = head;
    head = head->next;
    if(head == NULL) tail = NULL;
    free(tmp);
    return;
}
void count_gold(){
    int cnt = 0;
    Node* cur = head;
    while(cur != NULL){
        if(strcmp(cur->level, "GOLD") == 0)
            cnt++;
        cur = cur->next;
    }
    if(cnt == 0) printf("NO GOLD\n");
    else printf("%d\n", cnt);
}
void clear(){
    Node* cur = head;
    while(cur != NULL){
        Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    head = tail = NULL;
}


void print_1(){
    if(head == NULL){
        printf("EMPTY\n");
        return;
    }
    Node* cur = head;
    while(cur != NULL){
        printf("%s %s %s\n", cur->id, cur->name, cur->level);
        cur = cur->next;
    }
}


int main(){
    while(1){
        char cmd[8];
        scanf("%s", cmd);
        if(strcmp(cmd,"#") == 0) break;
        if(strcmp(cmd,"Create") == 0){
            clear();
        }
        if(strcmp(cmd,"Insert") == 0){
            char id[8];
            char name[21];
            char level[7];
            scanf("%s %s %s", id, name,level);
            Node* r = insert(id,name,level);
        }
        if(strcmp(cmd,"Print") == 0){
            print_1();
        }
        if(strcmp(cmd,"Vip") == 0){
            pop("VIP");
        }
        if(strcmp(cmd,"Gold") == 0){
            count_gold();
        }
        if(strcmp(cmd,"Serve") == 0){
            pop_1();
        }


    }


}
