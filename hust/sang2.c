#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
     char msv[6];  // mã khách
    char ten[31];  // tên khách
    float dtb;  // hạng
    struct Node *next;
}Node;
Node* head;
Node* makeNode(char msv[], char ten[], float dtb){
    Node* r = (Node*)malloc(sizeof(Node));
    strcpy(r->msv,msv);
    strcpy(r->ten,ten);
    r->dtb = dtb;
    r->next = NULL;
    return r;
}
Node* insert(char msv[], char ten[], float dtb){
    Node* r = makeNode(msv, ten, dtb);
    if(head == NULL) head = r;
    else{
    r->next = head;
    head = r;}
    return r;
}
void pop(char level[]){
    Node *cur = head, *prev = NULL;

    while(cur != NULL){
        if(strcmp(cur->msv, level) == 0){
            Node* tmp = cur;
            if(prev == NULL){
                head = cur->next;
                cur = head;
            } else {
                prev->next = cur->next;
                cur = cur->next;
            }
            free(tmp);
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
}

void clear(){
    Node* cur = head;
    while(cur != NULL){
        Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    head = NULL;
}
void max(){
    if(head == NULL){
        printf("0\n");
        return;
    }
    float max = 0;
    Node* cur = head;
    while(cur != NULL){
        if(cur->dtb > max) max = cur->dtb;
        cur = cur->next;
    }
    printf("%.1f\n", max);
}
void avg(){
    if(head == NULL){
        printf("0\n");
        return;
    }
    float tong = 0;
    float count = 0;
    Node* cur = head;
    while(cur != NULL){
        tong = tong + cur->dtb;
        count++;
        cur = cur->next;
    }
    printf("%.2f\n", tong / count);
}
void print_1(){
    if(head == NULL){
        printf("NULL\n");
        return;
    }
    Node* cur = head;
    while(cur != NULL){
        printf("%s %s %.1f\n", cur->msv, cur->ten, cur->dtb);
        cur = cur->next;
    }
}



int main(){
    while(1){
        char cmd[8];
        scanf("%s", cmd);
        if(strcmp(cmd,"*") == 0) break;
        if(strcmp(cmd,"CreateList") == 0){
            clear();
        }
        if(strcmp(cmd,"Insert") == 0){
            char msv[6];  // mã khách
    char ten[31];  // tên khách
    float dtb;  // hạng
            scanf("%s %s %f", msv, ten,&dtb);
            Node* r = insert(msv,ten,dtb);
        }
        if(strcmp(cmd,"Print") == 0){
            print_1();
        }
        if(strcmp(cmd,"Max") == 0){
            max();
        }
        if(strcmp(cmd,"Avg") == 0){
            avg();
        }
        if(strcmp(cmd,"Delete") == 0){
            char msv[6];
            scanf("%s", msv);
            pop(msv);
        }


    }


}

