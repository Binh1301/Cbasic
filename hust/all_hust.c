#1
#include <stdio.h>

typedef struct {
    float x;
    float y;
} vitri;

typedef struct {
    float x_1, y_1;
    float x_2, y_2;
} khung;

vitri ds[50000];
khung ds_1[5000];

int namtrong(float x, float y,
             float x1, float y1,
             float x2, float y2) {
    return (x1 < x && x < x2 && y2 < y && y < y1);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%f %f", &ds[i].x, &ds[i].y);
    }

    for (int i = 0; i < M; i++) {
        scanf("%f %f %f %f",
              &ds_1[i].x_1, &ds_1[i].y_1,
              &ds_1[i].x_2, &ds_1[i].y_2);
    }

    for (int i = 0; i < M; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (namtrong(ds[j].x, ds[j].y,
                         ds_1[i].x_1, ds_1[i].y_1,
                         ds_1[i].x_2, ds_1[i].y_2)) {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
#2
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
#3
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char fullname[101];
    int mssv;
} Student;

Student a[1000];
int n = 0;

/* so sánh để sort MSSV tăng dần */
int cmp(const void *x, const void *y){
    return (*(int*)x - *(int*)y);
}

int main(){
    char line[1000];
 
    while (fgets(line, sizeof(line), stdin)) {
        if (strstr(line, "end.") != NULL) break;

        char *token = strtok(line, ";");
        while (token != NULL) {
            char *comma = strchr(token, ',');
            if (comma != NULL) {
                *comma = '\0';
                strcpy(a[n].fullname, token);
                a[n].mssv = atoi(comma + 1);
                n++;
            }
            token = strtok(NULL, ";");
        }
    }

    /* ====== XỬ LÝ TRUY VẤN ====== */
    while (1) {
        char query[101];
        fgets(query, sizeof(query), stdin);
        query[strcspn(query, "\n")] = '\0';

        if (strcmp(query, "end.") == 0) break;

        int res[1000], cnt = 0;

        for (int i = 0; i < n; i++) {
            char *last = strrchr(a[i].fullname, ' ');
            char *name = (last != NULL) ? last + 1 : a[i].fullname;

            if (strcmp(name, query) == 0) {
                res[cnt++] = a[i].mssv;
            }
        }

        if (cnt == 0) {
            printf("Khong thay\n");
        } else {
            qsort(res, cnt, sizeof(int), cmp);
            for (int i = 0; i < cnt; i++) {
                if (i > 0) printf(",");
                printf("%d", res[i]);
            }
            printf("\n");
        }
    }

    return 0;
}

#4
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
    char word[50];
    int count;
} Word;

Word a[300];
int n = 0;

/* so sánh để sắp xếp alphabet */
int cmp(const void *x, const void *y){
    return strcmp(((Word*)x)->word, ((Word*)y)->word);
}

/* thêm hoặc tăng số lần xuất hiện */
void addWord(char *w){
    for(int i = 0; i < n; i++){
        if(strcmp(a[i].word, w) == 0){
            a[i].count++;
            return;
        }
    }
    strcpy(a[n].word, w);
    a[n].count = 1;
    n++;
}

int main(){
    char line[1000];
    char cur[50];
    int len = 0;

    /* đọc toàn bộ văn bản (không có dấu kết thúc) */
    while(fgets(line, sizeof(line), stdin)){
        for(int i = 0; line[i]; i++){
            if(isalpha((unsigned char)line[i])){
                cur[len++] = tolower((unsigned char)line[i]);
            } else {
                if(len > 0){
                    cur[len] = '\0';
                    addWord(cur);
                    len = 0;
                }
            }
        }
    }

    /* nếu dòng kết thúc bằng chữ */
    if(len > 0){
        cur[len] = '\0';
        addWord(cur);
    }

    /* sắp xếp alphabet */
    qsort(a, n, sizeof(Word), cmp);

    /* in kết quả */
    for(int i = 0; i < n; i++){
        printf("%s %d\n", a[i].word, a[i].count);
    }

    return 0;
}
#5
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
int cach = 0;
typedef struct Node{
    int key;
    struct Node* left;
    struct Node* right;
}Node;
Node* root;
Node* makeNode(int key){
    Node* p = (Node*)malloc(sizeof(Node));
    p->key = key;
    p->left = NULL;
    p->right = NULL;
    return p;
}
Node* findNode(Node* r,int key){
    if(r == NULL) return NULL;
    if(r->key == key) return r;
    if( r->key > key) return findNode(r->left, key);
    if( r->key < key) return findNode(r->right, key);
}
Node* insert(Node* r, int key){
    if(r == NULL) return makeNode(key);
    if(key < r->key)
        r->left = insert(r->left, key);
    else if(key > r->key)
        r->right = insert(r->right, key);
    return r;
}
Node* findA(Node* r, int n1, int n2){
    if(r == NULL) return NULL;
    Node* a = findNode(r , n1);
    Node* b = findNode(r , n2);
    if(r->key > n1 && r->key > n2){
    while( r->key > n1 && r->key > n2){
        r = r->left;
    }
    return r;}
    if(r->key < n1 && r->key < n2){
    while( r->key < n1 && r->key < n2){
        r = r->right;
    }
    return r;}
    return r;

}
int distance(Node* r,Node* a){

    if(r->key == a->key){
        int p = cach;
        cach = 0;
        return p;
    }
    if( r->key > a->key) {
        cach = cach + 1;
            return distance(r->left, a);}
    if( r->key < a->key) {
        cach = cach + 1;
            return distance(r->right, a);}
}

int main(){
    int n, n1, n2;
    scanf("%d", &n);
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        int key;
        scanf("%d", &key);
        root = insert(root, key);
    }
    scanf("%d %d", &n1,&n2);
    Node* a = findNode(root, n1);
    Node* b = findNode(root, n2);
    Node* c = findA(root, n1, n2);
    int a_1 = distance(c ,a);
    int b_1 = distance(c ,b);
    int tong = a_1 + b_1;
    printf("%d", tong);
    return 0;

}
#6


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


