#1_2023
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[3];
int luu[100];
int count = 0;
void check(int n, int a[]){
    for(int i = 0; i < n; i++){
        if(a[i] != a[i+1]) count+= 1;
    }
}
typedef struct lando{
    int ngay;
    char s[10];
    int change;
}lando;
lando ds[100];
int max = 0;
int max_1(int a[]){
    for(int i = 0; i < 3; i++){
        if(a[i] > max) max = a[i];
    }
    return max;
}
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %s %d", &ds[i].ngay, ds[i].s, &ds[i].change);
        if(strcmp(ds[i].s, "Vang") == 0) a[1] = a[1] + ds[i].change;
        if(strcmp(ds[i].s, "Sind") == 0) a[0] = a[0] + ds[i].change;
        if(strcmp(ds[i].s, "Jersey") == 0) a[2] = a[2] + ds[i].change;
        luu[i] = max_1(a);
    }
    check(N, a);
    printf("%d", count);
    return 0;
}
#2_2023
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[100];
int x[100];
int cnt = 0;
int n, S;
int tong = 0;
void solution(){
    int tong_check = 0;
    for(int i = 0; i < n; i++){
        tong_check = tong_check + a[i] * x[i];
    }
    if(tong_check == S) cnt++;
    return;
}
int check(int k, int v){
    if(tong + v * a[k] > S) return 0;
    else return 1;

}
void Try(int k){
    for(int v = 0; v <= S / a[k]; v++){
        if(check(k, v)){
            x[k] = v;
            tong = tong + a[k] * x[k];
            if( k == n - 1) solution();
            else Try(k+1);
            tong = tong - a[k] * x[k];
        }
    }
}
int main(){
    scanf("%d %d", &n, &S);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    Try(0);
    printf("%d", cnt);
    return 0;
}

#3_2023
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



