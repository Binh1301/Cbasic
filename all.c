#all_1
##1.4

#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a[100];
    int max = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(a[i] > max) max = a[i];
    }
    printf("%d", max);
    return 0;


}
## 2.4

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

##3.4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int timkiem(int a[], int n, int k){
    int min;
    if(a[0] > k) min = a[0] - k;
    else min = k - a[0];

    for(int i = 1; i < n; i++){
        int diff;
        if(a[i] > k) diff = a[i] - k;
        else diff = k - a[i];

        if(diff < min)
            min = diff;
    }
    return min;
}

int main(){
    int n;
    scanf("%d", &n);
    int a[100];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    while(1){
        char cmd[100];
        scanf("%s", cmd);
        if(strcmp(cmd, "#") == 0) break ;
        if(strcmp(cmd, "SEARCH") == 0){
                int k;
        scanf("%d", &k);
        int b = timkiem(a,n,k);
        printf("%d", b);
        printf("\n");
        }

    }
    return 0;


}

##4.4
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXN 100000
#define MAXL 256

typedef struct {
    char ho[50];
    char ten[50];
} SV;

SV ds[MAXN];
int n = 0;

/* đổi chuỗi về chữ thường */
void toLower(char *s) {
    for (int i = 0; s[i]; i++)
        s[i] = tolower((unsigned char)s[i]);
}

/* loại bỏ '\n' và '\r' ở cuối dòng */
void trim(char *s) {
    int len = strlen(s);
    while (len > 0 && (s[len-1] == '\n' || s[len-1] == '\r')) {
        s[len-1] = '\0';
        len--;
    }
}

/* tách họ (từ đầu) và tên (từ cuối) */
void tachHoTen(char *line, char *ho, char *ten) {
    char tmp[MAXL];
    strcpy(tmp, line);

    char *token = strtok(tmp, " ");
    strcpy(ho, token);          // họ

    char *last = token;
    while ((token = strtok(NULL, " ")) != NULL) {
        last = token;
    }
    strcpy(ten, last);          // tên

    toLower(ho);
    toLower(ten);
}

int main() {
    char line[MAXL];

    /* đọc danh sách sinh viên */
    while (fgets(line, sizeof(line), stdin)) {
        trim(line);
        if (strcmp(line, "endlist") == 0) break;

        tachHoTen(line, ds[n].ho, ds[n].ten);
        n++;
    }

    /* xử lý truy vấn */
    while (fgets(line, sizeof(line), stdin)) {
        trim(line);
        if (strcmp(line, "endsearch") == 0) break;

        char ho[50], ten[50];
        tachHoTen(line, ho, ten);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(ds[i].ho, ho) == 0 &&
                strcmp(ds[i].ten, ten) == 0) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}

##5.4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[100];
int x[100];
int n;
int max = 0;
int check_sum = 0;
int tong = 0;
int check(int k ,int v){
    if(tong + x[k] * v > n) return 0;
    return 1;
}
void solution(int k){
    int sum = 0;
    if( k == 2 ){
        for(int i = 0; i < 3; i++){
                sum = sum + a[i];
        }
        if(sum > max) max = sum;
    }
}
void Try(int k){
    for(int v = 0; v <= n ; v++){
        if(check(k, v)){
            a[k] = v;
            tong = tong + x[k] * v;
            if(k == 2) solution(k);
            else Try(k+1);
            tong = tong - x[k] * v;
        }
    }

}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < 3; i++){
        scanf("%d", &x[i]);
    }
    Try(0);
    printf("%d", max);
    return 0;


}

##1.5

#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a[100];
    int max = 0;
    for(int i = 0; i <= n; i = i + 2){
        if(i == 0) continue;


    printf("%d", i);
    printf("\n");
    }
    return 0;


}

##2.5

#include <stdio.h>
#include <math.h>
int a[10000];
int sum = 1;

int khoangcach(int x, int y){
    int i = -2;
    while(1){
        if( i >= y){
                    sum = sum + abs( y - i / (-2));
                    break;}

        sum = sum + abs( i - i / (-2)) ;
        i = i * ( -2);

    }
    return sum;

}
int main(){
    int x,y;
    scanf("%d %d", &x,&y);
    int a = khoangcach(0 , y- x);
    printf("%d", a);
    return 0;


}

##3.5


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

##4.5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char code[9];
    int score;
} Sinhvien;

Sinhvien ds[100000];
int cnt = 0;

int cmp(const void *a, const void *b) {
    Sinhvien *x = (Sinhvien *)a;
    Sinhvien *y = (Sinhvien *)b;
    return y->score - x->score;
}

int main() {
    int n;
    scanf("%d", &n);

    while (1) {
        char tmp[20];
        scanf("%s", tmp);
        if (strcmp(tmp, "#") == 0) break;

        strcpy(ds[cnt].code, tmp);
        scanf("%d", &ds[cnt].score);
        cnt++;
    }

    qsort(ds, cnt, sizeof(Sinhvien), cmp);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", ds[i].code, ds[i].score);
    }

    return 0;
}
##5.5
#include <stdio.h>

int n;
int x[20];
int mark[20];
char c;

int check(int v, int k){
    return 1;
}
void solution(){
    printf("%c", c);
    for(int i = 1; i <= n; i++)
        printf("%d",x[i]);
    printf("\n");

}
int Try(int k ){
    for(int v = 1; v <= 5; v = v + 2){
        if( check(v ,k )){
            x[k] = v;
            if( k == n ) solution();
            else Try(k + 1);
        }
    }
}
int main(){

    scanf("%c", &c);
    scanf("%d",&n);
    for(int v = 1; v <= n; v++) mark[v] = 0;
    Try(1);
    return 0;
}

#all_2023
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



#all_20231
#1_20231

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sinhvien{
    int id;
    char s[10];
}sinhvien;
sinhvien ds[100];
int cmp(const void *a,const void *b){
    return ((sinhvien*)b)->id - ((sinhvien*)a)->id;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %s", &ds[i].id, ds[i].s);
    }
    qsort(ds,n,sizeof(sinhvien), cmp);
    for(int i = 0; i < n; i++){
        printf("%d %s", ds[i].id, ds[i].s);
        printf("\n");
    }
    return 0;
}
#2_20231
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


#3_20231
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    char malop[9];
    char phong[7];
    struct Node* left ;
    struct Node* right;
}Node;
Node* root = NULL;
int count = 1;
Node* makeNode(char s1[], char s2[]){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->malop, s1);
    strcpy(p->phong, s2);
    p->left = NULL;
    p->right = NULL;
    return p;
}
int findNode(Node* r,char s1[]){
    if(r == NULL) return count - 1;
    int c = strcmp(r->malop, s1);
    if(c == 0){
        int tmp  = count;
        count = 0;
        return tmp;
    }
    if(c < 0){
            count += 1;
            return findNode(r->right, s1);}
    else {
        count += 1;
            return findNode(r->left, s1);}}

Node* insert(Node* r, char s1[], char s2[]){
    if( r == NULL) return makeNode(s1, s2);
    int c = strcmp(r->malop, s1);
    if(c == 0) return r;
    else if(c < 0)
        r->right = insert(r->right, s1, s2);
    else
        r->left = insert(r->left, s1, s2);

    return r;

}
int first = 1;
void inOrder(Node * r){
    if (r == NULL) return;
    inOrder(r->left);
    if(!first) printf(" ");
    printf("%s", r->malop);
    first = 0;
    inOrder(r->right);
}


int main(){
    while(1){
        char c[20];
        scanf("%s", c);
        if(strcmp(c, "#") == 0) break;
        if(strcmp(c, "insert") == 0){
            char malop[9], phong[7];
            scanf("%s", malop);
            scanf("%s", phong);
            root = insert(root, malop, phong);
        }if(strcmp(c, "inOrder") == 0){
            first = 1;
            inOrder(root);
            printf("!\n");
        }
        if(strcmp(c, "countStep") == 0){
            char malop[9];
            scanf("%s", malop);
            count = 1;
            int a = findNode(root,malop);
            printf("%d", a);

    }}
    return 0;
}



#4_20231
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char malop[8];
    char phong[7];
    struct Node* left;
    struct Node* right;
} Node;

Node* root = NULL;

Node* makeNode(char s1[], char s2[]){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->malop, s1);
    strcpy(p->phong, s2);
    p->left = p->right = NULL;
    return p;
}

Node* insert(Node* r, char s1[], char s2[]){
    if(r == NULL) return makeNode(s1, s2);

    int c = strcmp(r->malop, s1);
    if(c == 0) return r;
    else if(c < 0)
        r->right = insert(r->right, s1, s2);
    else
        r->left = insert(r->left, s1, s2);

    return r;
}

void inOrder(Node* r){
    if(r == NULL) return;
    inOrder(r->left);
    printf("%s ", r->malop);
    inOrder(r->right);
}

int main(){
    while(1){
        char cmd[20];
        scanf("%s", cmd);
        if(strcmp(cmd, "#") == 0) break;

        if(strcmp(cmd, "insert") == 0){
            char malop[8], phong[7];
            scanf("%s %s", malop, phong);
            root = insert(root, malop, phong);
        }
        else if(strcmp(cmd, "inOrder") == 0){
            inOrder(root);
            printf("\n");
        }
    }
    return 0;
}
#all_backtrack
#1
#include <stdio.h>
int x[100];
int n;
int m;
int Q;
int cnt = 0;
int sum = 0;

void solution(){
    cnt++;
}
void Try( int k, int solan ){
    if( solan == n){
        if(sum == Q) solution();
        return;
    }
    for( int v = k; v < m ; v++ ){
        if(sum + x[v] <= Q){
        sum += x[v];
        Try(v + 1, solan + 1);
        sum -= x[v];
        }
    }

}
int main(){
    scanf("%d %d %d", &m,&n,&Q);
    for(int i = 0; i < m; i++){
        scanf("%d", &x[i]);
    }
    Try(0,0);
    printf("%d", cnt);
    return 0;
}



#2
#include <stdio.h>

int x[100];
int n;

// Hàm kiểm tra chuỗi đã chứa 111 chưa
int has_111() {
    for(int i = 3; i <= n; i++){
        if(x[i] == 1 && x[i-1] == 1 && x[i-2] == 1) return 1;
    }
    return 0;
}

void solution(){
    if(has_111()){ // chỉ in những chuỗi có 111
        for(int i = 1; i <= n; i++){
            printf("%d", x[i]);
        }
        printf("\n");
    }
}

void Try(int k){
    for(int v = 0; v <= 1; v++){
        x[k] = v;
        if(k == n) solution();
        else Try(k + 1);
    }
}

int main(){
    scanf("%d", &n);
    Try(1);
    return 0;
}
#3
#include <stdio.h>

int a[10005];
int m, n, Q;
int cnt = 0;
int sum = 0;

void solution(){
    cnt++;
}

void Try(int pos, int k) {
    // pos: vị trí bắt đầu duyệt
    // k: số phần tử đã chọn

    if (k == n) {
        if (sum == Q) solution();
        return;
    }

    for (int i = pos; i < m; i++) {
        if (sum + a[i] <= Q) {
            sum += a[i];
            Try(i + 1, k + 1);
            sum -= a[i];   // backtrack
        }
    }
}

int main(){
    scanf("%d %d %d", &m, &n, &Q);
    for(int i = 0; i < m; i++){
        scanf("%d", &a[i]);
    }

    Try(0, 0);
    printf("%d", cnt);
    return 0;
}
#4

#include <stdio.h>
int x[100];
int n;
int check(int v, int k){
    if ( k == 1) return 1;
    else if ( k > 1){
        if( v == 1 && x[k - 1 ] == 1) return 0;
        else return 1;
    }
}
int solution(){
    for(int i = 1; i <= n; i++){
        printf("%d", x[i]);
    }
    printf("\n");
}
int Try( int k ){
    for( int v = 0; v < 2; v++ ){
        if(check(v, k)){
           x[k] = v;
           if(k == n) solution();
           else Try( k + 1 );
        }
    }
}
int main(){
    scanf("%d", &n );
    Try(1);
    return 0;
}
#5
#include <stdio.h>
int x[100];
int n;
int sum_1(int n){
    int sum = 0;
    for(int i = 0; i <= n; i++){
            sum += i;
    }
    return sum;
}
int check(int v, int k){
    int sum_n = sum_1(k);
    for(int i = 1; i < k; i++){
        if(x[i] == v) return 0;
    }
    return 1;
}
int solution(){
    for(int i = 1; i <= n; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
}
int Try( int k ){
    for( int v = 1; v <= n ; v++ ){
        if(check(v, k)){
           x[k] = v;
           if(k == n) solution();
           else Try( k + 1 );
        }
    }
}
int main(){
    scanf("%d", &n );
    Try(1);
    return 0;
}
#6
#include <stdio.h>
#define N 20
int n;
int x[N];
int mark[N];
int check( int v, int k){
    return mark[v] == 0;
}

void solution(){
    for( int i = 1; i <= n; i++){
        printf("%d ", x[i]);
    }

    printf("\n");
}
void Try(int k){
    for(int v = 1; v<= n; v++){
        if(check(v,k)){
                x[k] = v;
                mark[v] = 1;
                if( k == n) solution();
                else Try(k + 1);
                mark[v] = 0;
        }
    }


}
int main(){
scanf("%d",&n);
for(int v = 1; v <= n; v++) mark[v] = 0;
Try(1);
return 0;
}
#7
#include <stdio.h>
int x[100];
int n;
int m;
int check(int v, int k){
    if(k < n) return 1;
    else if( k == n){
        int sum = v;
        for(int i = 1; i < k; i++){
            sum += x[i];
        }
        if(sum == m) return 1;
        else return 0;
    }
    else return 0;
}
int solution(){
    for(int i = 1; i <= n; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
}
int Try( int k ){
    for( int v = 1; v <= m ; v++ ){
        if(check(v, k)){
           x[k] = v;
           if(k == n) solution();
           else Try( k + 1 );
        }
    }

}
int main(){
    scanf("%d", &n );
    scanf("%d", &m);
    Try(1);
    return 0;
}
#8
#include <stdio.h>
int x[100];
int n;
int check(){
        for( int i = 3; i <= n; i++){
            if(x[i-1] == 1 && x[i-2] == 1 && x[i] == 1) return 1;
        }

    return 0;
}
void solution(){
    if(check()){
    for(int i = 1; i <= n; i++){
        printf("%d", x[i]);
    }
    printf("\n");
}}
int Try( int k ){
    for( int v = 0; v < 2; v++ ){

           x[k] = v;
           if(k == n) solution();
           else Try( k + 1 );

    }
}
int main(){
    scanf("%d", &n );
    Try(1);
    return 0;
}
#9
#include <stdio.h>

int x[100];
int n;
int m;
int a[100];
int tich = 1;
int max = 1;
int tong = 0;
int check(int k, int v){
    if(tong + a[k] * v > m) {
            return 0;

    }
    if (k == n - 1 && tong + a[k] * v != m)
    return 0;

    return 1;
}
void solution(){
    int prod = 1;
    for (int i = 0; i < n; i++)
        prod *= x[i];
    if (prod > max) max = prod;
}


void Try(int k){
    for(int v = 1; v <= m; v++){
        if(check(k ,v)){
            x[k] = v;
            tong += a[k] * v;
            if(k == n) solution();
            else Try(k + 1);
            tong -= a[k] * v;

        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    Try(0);
    printf("%d",max);
    return 0;

}

#bst
#1
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



#2
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

typedef struct Node {
  int key;
  struct Node * leftChild;
  struct Node * rightChild;
}
Node;
Node * root;
Node * makeNode(int k) {
  Node * p = (Node * ) malloc(sizeof(Node));
  p -> key = k;
  p -> leftChild = NULL;
  p -> rightChild = NULL;
  return p;
}
Node * insert(Node * r, int k) {
  if (r == NULL) r = makeNode(k);
  else if (r -> key > k)
    r -> leftChild = insert(r -> leftChild, k);
  else if (r -> key < k)
    r -> rightChild = insert(r -> rightChild, k);
  return r;
}
void preOrder(Node * r) {
  if (r == NULL) return;
  printf("%d ", r -> key);
  preOrder(r -> leftChild);
  preOrder(r -> rightChild);
}
void postOrder(Node * r) {
  if (r == NULL) return;
  postOrder(r -> leftChild);
  postOrder(r -> rightChild);
  printf("%d ", r -> key);
}
Node * removeRoot(Node * r) {
  if (r == NULL) return NULL;
  if (r -> rightChild == NULL) {
    Node * tmp = r;
    r = r -> leftChild;
    free(tmp);
    return r;
  }
  Node * p = r -> rightChild;
  Node * pp = r;
  if (p -> leftChild == NULL) {
    r -> key = p -> key;
    Node * tmp = p;
    r -> rightChild = p -> rightChild;
    free(tmp);
    return r;
  }
  while (p -> leftChild != NULL) {
    pp = p;
    p = p -> leftChild;
  }
  pp -> leftChild = p -> rightChild;
  r -> key = p -> key;
  free(p);
  return r;
}
Node * removeNode(Node * r, int k) {
  if (r == NULL) return NULL;
  if (r -> key == k)
    return removeRoot(r);
  else if (r -> key < k)
    r -> rightChild = removeNode(r -> rightChild, k);
  else
    r -> leftChild = removeNode(r -> leftChild, k);
  return r;
}
int main() {
  root = NULL;
  while (1) {
    char cmd[256];
    scanf("%s", cmd);
    if (strcmp(cmd, "#") == 0) break;
    else if (strcmp(cmd, "insert") == 0) {
      int k;
      scanf("%d", & k);
      root = insert(root, k);
    } else if (strcmp(cmd, "remove") == 0) {
      int k;
      scanf("%d", & k);
      root = removeNode(root, k);
    } else if (strcmp(cmd, "preorder") == 0) {
      preOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "postorder") == 0) {
      postOrder(root);
      printf("\n");
    }
  }
  preOrder(root);
  printf("\n");
  return 0;
}
#3

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#define MAX 50
#define m 10000
typedef struct Node {
  char key[MAX];
  struct Node * leftChild;
  struct Node * rightChild;
}
Node;
Node * T[m];
Node * makeNode(char * k) {
  Node * p = (Node * ) malloc(sizeof(Node));
  strcpy(p -> key, k);
  p -> leftChild = NULL;
  p -> rightChild = NULL;
  return p;
}

int h(char * k) {
  int c = 0;
  for (int i = 0; i < strlen(k); i++)
    c = (c * 256 + k[i]) % m;
  return c;
}
Node * findBST(Node * r, char * k) {
  if (r == NULL) return NULL;
  int c = strcmp(r -> key, k);
  if (c == 0) return r;
  if (c < 0) return findBST(r -> rightChild, k);
  else return findBST(r -> leftChild, k);
}
Node * insertBST(Node * r, char * k) {
  if (r == NULL) return makeNode(k);
  if (strcmp(r -> key, k) < 0)
    r -> rightChild = insertBST(r -> rightChild, k);
  else
    r -> leftChild = insertBST(r -> leftChild, k);
  return r;
}
int find(char * k) {
  int i = h(k);
  Node * p = findBST(T[i], k);
  if (p == NULL) return 0;
  return 1;
}
int insert(char * k) { // put(k)
  int i = h(k);
  Node * p = findBST(T[i], k);
  if (p != NULL) return 0;
  T[i] = insertBST(T[i], k);
  return 1;
}
int main() {
  char k[MAX], cmd[20];
  while (1) {
    scanf("%s", k);
    if (strcmp(k, "*") == 0) break;
    insert(k); // put k into the hash table (+BST)
  }
  while (1) {
    scanf("%s", cmd);
    if (strcmp(cmd, "find") == 0) {
      scanf("%s", k);
      int ans = find(k);
      printf("%d\n", ans);
    } else if (strcmp(cmd, "insert") == 0) {
      scanf("%s", k);
      int ans = insert(k);
      printf("%d\n", ans);
    } else if (strcmp(cmd, "***") == 0) {
      break;
    }
  }
  return 0;
}
#4
#include <stdio.h>

#include <stdlib.h>

#define N 100001
int n;
int a[N];
int ok = 1;
typedef struct Node {
  int id;
  struct Node * leftChild;
  struct Node * rightChild;

}
Node;
Node * makeNode(int id) {
  Node * p = (Node * ) malloc(sizeof(Node));
  p -> id = id;
  p -> leftChild = NULL;
  p -> rightChild = NULL;
  return p;
}
Node * build(int start, int end) {
  if (start > end) return NULL;
  if (start == end) {
    return makeNode(a[start]);
  }
  Node * r = makeNode(a[start]);
  int i = start + 1;
  while (i <= end && a[i] < a[start]) i++;
  for (int j = i; j <= end; j++)
    if (a[j] < a[start]) {
      ok = 0;
      break;
    }

  r -> leftChild = build(start + 1, i - 1);
  r -> rightChild = build(i, end);
  return r;
}
void postOrder(Node * r) {
  if (r == NULL) return;
  postOrder(r -> leftChild);
  postOrder(r -> rightChild);
  printf("%d ", r -> id);
}
int main() {
  scanf("%d", & n);
  for (int i = 1; i <= n; i++) scanf("%d", & a[i]);
  ok = 1;
  Node * root = build(1, n);
  if (ok == 0) {
    printf("NULL");
    return 0;
  }
  postOrder(root);
  printf("\n");
  return 0;
}
#all_cay

#balancebanarytree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

#define MAX_NODES 50001

typedef struct Node {
    int id;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    int balanced; 
    int h;        
} INFO;

Node* nodes[MAX_NODES];
Node* root = NULL;

Node* makeNode(int id) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void addLeft(int u, int v) {
    if (nodes[u] != NULL || nodes[v] == NULL) return;
    if (nodes[v]->left != NULL) return;
    Node* p = makeNode(u);
    nodes[v]->left = p;
    nodes[u] = p;
}

void addRight(int u, int v) {
    if (nodes[u] != NULL || nodes[v] == NULL) return;
    if (nodes[v]->right != NULL) return;
    Node* p = makeNode(u);
    nodes[v]->right = p;
    nodes[u] = p;
}

INFO visit(Node *r) {
    if (r == NULL) {
        INFO i;
        i.balanced = 1;
        i.h = 0;
        return i;
    }
    INFO i1 = visit(r->left);
    INFO i2 = visit(r->right);
    INFO i;
    i.h = (i1.h > i2.h ? i1.h : i2.h) + 1;
    if (!i1.balanced || !i2.balanced || abs(i1.h - i2.h) > 1)
        i.balanced = 0;
    else
        i.balanced = 1;
    return i;
}

int main() {
    for (int i = 0; i < MAX_NODES; i++) nodes[i] = NULL;

    char cmd[20];
    while (scanf("%s", cmd)) {
        if (strcmp(cmd, "*") == 0) break;
        if (strcmp(cmd, "MakeRoot") == 0) {
            int u;
            scanf("%d", &u);
            root = makeNode(u);
            nodes[u] = root;
        } else if (strcmp(cmd, "AddLeft") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            addLeft(u, v);
        } else if (strcmp(cmd, "AddRight") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            addRight(u, v);
        }
    }

    INFO result = visit(root);
    if (result.balanced)
        printf("1 %d\n", result.h);
    else
        printf("0 %d\n", result.h);

    return 0;
}
#binarytravel
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node {
  int id;
  struct Node * leftChild;
  struct Node * rightChild;

}
Node;
Node * makeNode(int u) {
  Node * p = (Node * ) malloc(sizeof(Node));
  p -> leftChild = NULL;
  p -> rightChild = NULL;
  p -> id = u;
  return p;
}
Node * find(int u, Node * r) {
  if (r == NULL) return NULL;
  if (r -> id == u) return r;
  Node * p = find(u, r -> leftChild);
  if (p != NULL) return p;
  return find(u, r -> rightChild);
}
void addLeft(int u, int v, Node * r) {
  Node * p = find(v, r);
  if (p == NULL) return;

  if (p -> leftChild != NULL) return;
  Node * q = find(u, r);
  if (q != NULL) return;
    p -> leftChild = makeNode(u);
}


void addRight(int u, int v, Node *r) {
    Node * p = find(v, r);
    if (p == NULL) return;
    if (p -> rightChild != NULL) return;
    Node * q = find(u, r);
    if (q != NULL) return;
    p -> rightChild = makeNode(u);
}
void preOrder(Node * r) {
  if (r == NULL) return;
  printf("%d ", r -> id);
  preOrder(r -> leftChild);
  preOrder(r -> rightChild);
}

void inOrder(Node * r) {
  if (r == NULL) return;
  inOrder(r -> leftChild);
  printf("%d ", r -> id);
  inOrder(r -> rightChild);
}

void postOrder(Node * r) {
  if (r == NULL) return;
  postOrder(r -> leftChild);
  postOrder(r -> rightChild);
  printf("%d ", r -> id);
}
int main() {
  char cmd[100];
  Node * root = NULL;
  while (1) {
    scanf("%s", cmd);
    if (strcmp(cmd, "*") == 0) break;
    else if (strcmp(cmd, "MakeRoot") == 0) {
      int u;
      scanf("%d", & u);
      root = makeNode(u);
    } else if (strcmp(cmd, "AddLeft") == 0) {
      int u, v;
      scanf("%d%d", & u, & v);
      addLeft(u, v, root);
    } else if (strcmp(cmd, "AddRight") == 0) {
      int u, v;
      scanf("%d%d", & u, & v);
      addRight(u, v, root);
    } else if (strcmp(cmd, "InOrder") == 0) {
      inOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "PreOrder") == 0) {
      preOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "PostOrder") == 0) {
      postOrder(root);
      printf("\n");
    }
  }
}
#cay1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    int id;
    struct Node* leftmostchild;
    struct Node* rightSibling;
    struct Node* parent;
}Node;
Node* makeNode(int id){
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id;
    p->leftmostchild = NULL;
    p->rightSibling = NULL;
    p->parent = NULL;
    return p;

}
Node* find(Node* r, int u){
    if( r == NULL) return NULL;
    if( r->id == u) return r;
    Node* p = r->leftmostchild;
    while ( p != NULL){
        Node* q = find(p,u);
        if( q != NULL) return q;
        p = p->rightSibling;
    }
    return NULL;
}
void insert(Node* r, int u, int v){
    Node* p = find(r , v);
    if( p == NULL) return;
    Node* q = makeNode(u);
    if(p->leftmostchild == NULL){
        p->leftmostchild = q;
        q->parent = p;
        return;}
        Node* h = p->leftmostchild;
        while(h->rightSibling != NULL)
            h = h->rightSibling;
        h->rightSibling = q;
        q->parent = p;
    }
int depth(Node* r){
    Node* p = r;
    int d = 0;
    while(p != NULL){
        d += 1;
        p = p->parent;
    }
    return d;
}
int height(Node* r){
    int maxH = 0;
    if(r == NULL) return 0;
    for(Node* p = r->leftmostchild; p != NULL; p = p->rightSibling){
            int h = height(p);
            if(h > maxH) maxH = h;
}
return maxH + 1;
}

void freeTree(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftmostchild;
  while (p != NULL) {
    Node * np = p -> rightSibling;
    free(p);
    p = np;
  }
  free(r);
}
void solve() {
  Node * root = NULL;
  char cmd[50];
  while (1) {
    scanf("%s", cmd);
    if (strcmp(cmd, "*") == 0) break;
    else if (strcmp(cmd, "MakeRoot") == 0) {
      int id;
      scanf("%d", & id);
      root = makeNode(id);
    } else if (strcmp(cmd, "Insert") == 0) {
      int u, v;
      scanf("%d%d", & u, & v);
      insert(root, u, v);
    } else if (strcmp(cmd, "Height") == 0) {
      int id;
      scanf("%d", & id);
      Node * p = find(root, id);
      printf("%d\n", height(p));
    } else if (strcmp(cmd, "Depth") == 0) {
      int id;
      scanf("%d", & id);
      Node * p = find(root, id);
      int ans = depth(p);
      printf("%d\n", ans);
    }
  }
  freeTree(root);
}
int main() {
  solve();
}


#cay2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
  int id;
  struct Node* leftMostChild;
  struct Node* rightSibling;
}Node;
Node * makeNode(int u) {
  Node * p = (Node * ) malloc(sizeof(Node));
  p -> id = u;
  p -> leftMostChild = NULL;
  p -> rightSibling = NULL;
  return p;
}
Node * find(Node * r, int u) {
  if (r == NULL) return NULL;
  if (r -> id == u) return r;
  Node * p = r -> leftMostChild;
  while (p != NULL) {
    Node * q = find(p, u);
    if (q != NULL) return q;
    p = p -> rightSibling;
  }
  return NULL;
}
void insert(Node * r, int u, int v) {
  Node* p = find(r, v);
  if (p == NULL) return;
  Node * q = makeNode(u);
  if (p -> leftMostChild == NULL) {
    p -> leftMostChild = q;
    return;
  }
  Node * h = p -> leftMostChild;
  while (h -> rightSibling != NULL)
    h = h -> rightSibling;
  h -> rightSibling = q;
}

void preOrder(Node * r) {
  if (r == NULL) return;
  printf("%d ", r -> id);
  Node * p = r -> leftMostChild;
  while (p != NULL) {
    preOrder(p);
    p = p -> rightSibling;
  }
}

void inOrder(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftMostChild;
  inOrder(p);
  printf("%d ", r -> id);
  if (p == NULL) return;
  p = p -> rightSibling;
  while (p != NULL) {
    inOrder(p);
    p = p -> rightSibling;
  }
}

void postOrder(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftMostChild;

  while (p != NULL) {
    postOrder(p);
    p = p -> rightSibling;
  }
  printf("%d ", r -> id);
}
void freeTree(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftMostChild;
  while (p != NULL) {
    Node * np = p -> rightSibling;
    free(p);
    p = np;
  }
  free(r);
}
void solve() {
  Node * root = NULL;
  char cmd[50];
  while (1) {
    scanf("%s", cmd);
    if (strcmp(cmd, "*") == 0) break;
    else if (strcmp(cmd, "MakeRoot") == 0) {
      int id;
      scanf("%d", & id);
      root = makeNode(id);
    } else if (strcmp(cmd, "Insert") == 0) {
      int u, v;
      scanf("%d%d", & u, & v);
      insert(root, u, v);
    } else if (strcmp(cmd, "PreOrder") == 0) {
      preOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "InOrder") == 0) {
      inOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "PostOrder") == 0) {
      postOrder(root);
      printf("\n");
    }
  }
  freeTree(root);
}
int main() {
  solve();
}

#cay3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
  int id;
  struct Node* leftMostChild;
  struct Node* rightSibling;
}Node;
Node * makeNode(int u) {
  Node * p = (Node * ) malloc(sizeof(Node));
  p -> id = u;
  p -> leftMostChild = NULL;
  p -> rightSibling = NULL;
  return p;
}
Node * find(Node * r, int u) {
  if (r == NULL) return NULL;
  if (r -> id == u) return r;
  Node * p = r -> leftMostChild;
  while (p != NULL) {
    Node * q = find(p, u);
    if (q != NULL) return q;
    p = p -> rightSibling;
  }
  return NULL;
}
void insert(Node * r, int u, int v) {
  Node* p = find(r, v);
  if (p == NULL) return;
  Node * q = makeNode(u);
  if (p -> leftMostChild == NULL) {
    p -> leftMostChild = q;
    return;
  }
  Node * h = p -> leftMostChild;
  while (h -> rightSibling != NULL)
    h = h -> rightSibling;
  h -> rightSibling = q;
}

void preOrder(Node * r) {
  if (r == NULL) return;
  printf("%d ", r -> id);
  Node * p = r -> leftMostChild;
  while (p != NULL) {
    preOrder(p);
    p = p -> rightSibling;
  }
}

void inOrder(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftMostChild;
  inOrder(p);
  printf("%d ", r -> id);
  if (p == NULL) return;
  p = p -> rightSibling;
  while (p != NULL) {
    inOrder(p);
    p = p -> rightSibling;
  }
}

void postOrder(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftMostChild;

  while (p != NULL) {
    postOrder(p);
    p = p -> rightSibling;
  }
  printf("%d ", r -> id);
}
void freeTree(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftMostChild;
  while (p != NULL) {
    Node * np = p -> rightSibling;
    free(p);
    p = np;
  }
  free(r);
}
void solve() {
  Node * root = NULL;
  char cmd[50];
  while (1) {
    scanf("%s", cmd);
    if (strcmp(cmd, "*") == 0) break;
    else if (strcmp(cmd, "MakeRoot") == 0) {
      int id;
      scanf("%d", & id);
      root = makeNode(id);
    } else if (strcmp(cmd, "Insert") == 0) {
      int u, v;
      scanf("%d%d", & u, & v);
      insert(root, u, v);
    } else if (strcmp(cmd, "PreOrder") == 0) {
      preOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "InOrder") == 0) {
      inOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "PostOrder") == 0) {
      postOrder(root);
      printf("\n");
    }
  }
  freeTree(root);
}
int main() {
  solve();
}
#cay1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node {
  int id;
  struct Node * leftChild;
  struct Node * rightChild;

}
Node;
Node * makeNode(int u) {
  Node * p = (Node * ) malloc(sizeof(Node));
  p -> leftChild = NULL;
  p -> rightChild = NULL;
  p -> id = u;
  return p;
}
Node * find(int u, Node * r) {
  if (r == NULL) return NULL;
  if (r -> id == u) return r;
  Node * p = find(u, r -> leftChild);
  if (p != NULL) return p;
  return find(u, r -> rightChild);
}
void addLeft(int u, int v, Node * r) {
  Node * p = find(v, r);
  if (p == NULL) return;

  if (p -> leftChild != NULL) return;
  Node * q = find(u, r);
  if (q != NULL) return;
    p -> leftChild = makeNode(u);
}


void addRight(int u, int v, Node *r) {
    Node * p = find(v, r);
    if (p == NULL) return;
    if (p -> rightChild != NULL) return;
    Node * q = find(u, r);
    if (q != NULL) return;
    p -> rightChild = makeNode(u);
}
void preOrder(Node * r) {
  if (r == NULL) return;
  printf("%d ", r -> id);
  preOrder(r -> leftChild);
  preOrder(r -> rightChild);
}

void inOrder(Node * r) {
  if (r == NULL) return;
  inOrder(r -> leftChild);
  printf("%d ", r -> id);
  inOrder(r -> rightChild);
}

void postOrder(Node * r) {
  if (r == NULL) return;
  postOrder(r -> leftChild);
  postOrder(r -> rightChild);
  printf("%d ", r -> id);
}
int main() {
  char cmd[100];
  Node * root = NULL;
  while (1) {
    scanf("%s", cmd);
    if (strcmp(cmd, "*") == 0) break;
    else if (strcmp(cmd, "MakeRoot") == 0) {
      int u;
      scanf("%d", & u);
      root = makeNode(u);
    } else if (strcmp(cmd, "AddLeft") == 0) {
      int u, v;
      scanf("%d%d", & u, & v);
      addLeft(u, v, root);
    } else if (strcmp(cmd, "AddRight") == 0) {
      int u, v;
      scanf("%d%d", & u, & v);
      addRight(u, v, root);
    } else if (strcmp(cmd, "InOrder") == 0) {
      inOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "PreOrder") == 0) {
      preOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "PostOrder") == 0) {
      postOrder(root);
      printf("\n");
    }
  }
}
#cay2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 50001

typedef struct Node {
    int id;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    int balanced;
    int h;
} INFO;

Node* nodes[MAX_NODES];
Node* root = NULL;

Node* makeNode(int id) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void addLeft(int u, int v) {
    if (nodes[u] != NULL || nodes[v] == NULL) return;
    if (nodes[v]->left != NULL) return;
    Node* p = makeNode(u);
    nodes[v]->left = p;
    nodes[u] = p;
}

void addRight(int u, int v) {
    if (nodes[u] != NULL || nodes[v] == NULL) return;
    if (nodes[v]->right != NULL) return;
    Node* p = makeNode(u);
    nodes[v]->right = p;
    nodes[u] = p;
}

INFO visit(Node *r) {
    if (r == NULL) {
        INFO i;
        i.balanced = 1;
        i.h = 0;
        return i;
    }
    INFO i1 = visit(r->left);
    INFO i2 = visit(r->right);
    INFO i;
    i.h = (i1.h > i2.h ? i1.h : i2.h) + 1;
    if (!i1.balanced || !i2.balanced || abs(i1.h - i2.h) > 1)
        i.balanced = 0;
    else
        i.balanced = 1;
    return i;
}

int main() {
    for (int i = 0; i < MAX_NODES; i++) nodes[i] = NULL;

    char cmd[20];
    while (scanf("%s", cmd)) {
        if (strcmp(cmd, "*") == 0) break;
        if (strcmp(cmd, "MakeRoot") == 0) {
            int u;
            scanf("%d", &u);
            root = makeNode(u);
            nodes[u] = root;
        } else if (strcmp(cmd, "AddLeft") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            addLeft(u, v);
        } else if (strcmp(cmd, "AddRight") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            addRight(u, v);
        }
    }

    INFO result = visit(root);
    if (result.balanced)
        printf("1 %d\n", result.h);
    else
        printf("0 %d\n", result.h);

    return 0;
}
#familytree
#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 10
#define MAX_NAME 32

typedef struct Person {
    char name[MAX_NAME];
    struct Person* children[MAX_PEOPLE];
    int child_count;
} Person;

Person people[MAX_PEOPLE];
int people_count = 0;
int visited[MAX_PEOPLE];

/* tìm hoặc tạo người */
Person* get_person(const char* name) {
    for (int i = 0; i < people_count; i++)
        if (strcmp(people[i].name, name) == 0)
            return &people[i];

    strcpy(people[people_count].name, name);
    people[people_count].child_count = 0;
    return &people[people_count++];
}

/* đếm hậu duệ */
int count_descendants(Person* p) {
    int idx = p - people;
    if (visited[idx]) return 0;
    visited[idx] = 1;

    int count = 0;
    for (int i = 0; i < p->child_count; i++) {
        count += 1;
        count += count_descendants(p->children[i]);
    }
    return count;
}

/* đếm số thế hệ */
int count_generations(Person* p) {
    int idx = p - people;
    if (visited[idx]) return 0;
    visited[idx] = 1;

    int max_gen = 0;
    for (int i = 0; i < p->child_count; i++) {
        int gen = count_generations(p->children[i]);
        if (gen > max_gen)
            max_gen = gen;
    }
    return p->child_count ? max_gen + 1 : 0;
}

int main() {
    char child[MAX_NAME], parent[MAX_NAME];

    /* đọc cây gia đình */
    while (scanf("%s", child), strcmp(child, "***") != 0) {
        scanf("%s", parent);
        Person* p_parent = get_person(parent);
        Person* p_child  = get_person(child);
        p_parent->children[p_parent->child_count++] = p_child;
    }

    char cmd[MAX_NAME], param[MAX_NAME];

    /* xử lý truy vấn */
    while (scanf("%s", cmd), strcmp(cmd, "***") != 0) {
        scanf("%s", param);

        Person* p = NULL;
        for (int i = 0; i < people_count; i++) {
            if (strcmp(people[i].name, param) == 0) {
                p = &people[i];
                break;
            }
        }

        if (!p) {
            printf("0\n");
            continue;
        }

        memset(visited, 0, sizeof(visited));

        if (strcmp(cmd, "descendants") == 0)
            printf("%d\n", count_descendants(p));
        else if (strcmp(cmd, "generation") == 0)
            printf("%d\n", count_generations(p));
    }

    return 0;
}
#nhap
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char key;
    struct Node* left;
    struct Node* right;
} Node;

Node* makeNode(char key){
    Node* p = (Node*)malloc(sizeof(Node));
    p->key = key;
    p->left = p->right = NULL;
    return p;
}

Node* insert(Node* root, char key){
    if (root == NULL) return makeNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

Node* findMin(Node* root){
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, char key){
    if (root == NULL) return NULL;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void postOrder(Node* root){
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->key);
}

/* optional: free whole tree to avoid memory leak */
void freeTree(Node* root){
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(){
    Node* root = NULL;
    char cmd[20], key;

    while (1){
        if (scanf("%s", cmd) != 1) break;
        if (strcmp(cmd, "#") == 0) break;

        /* read key character (skipping whitespace) */
        if (scanf(" %c", &key) != 1) break;

        if (strcmp(cmd, "insert") == 0){
            root = insert(root, key);
        } else if (strcmp(cmd, "delete") == 0 || strcmp(cmd, "del") == 0){
            root = deleteNode(root, key);
        } else {
            /* nếu có lệnh khác: bỏ qua hoặc thông báo (ở đây ta bỏ qua) */
        }
    }

    if (root == NULL)
        printf("NULL\n");
    else {
        postOrder(root);
        printf("\n");
    }

    freeTree(root);
    return 0;
}

#treeheight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    int id;
    struct Node* leftmostchild;
    struct Node* rightSibling;
    struct Node* parent;
}Node;
Node* makeNode(int id){
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id;
    p->leftmostchild = NULL;
    p->rightSibling = NULL;
    p->parent = NULL;
    return p;

}
Node* find(Node* r, int u){
    if( r == NULL) return NULL;
    if( r->id == u) return r;
    Node* p = r->leftmostchild;
    while ( p != NULL){
        Node* q = find(p,u);
        if( q != NULL) return q;
        p = p->rightSibling;
    }
    return NULL;
}
void insert(Node* r, int u, int v){
    Node* p = find(r , v);
    if( p == NULL) return;
    Node* q = makeNode(u);
    if(p->leftmostchild == NULL){
        p->leftmostchild = q;
        q->parent = p;
        return;}
        Node* h = p->leftmostchild;
        while(h->rightSibling != NULL)
            h = h->rightSibling;
        h->rightSibling = q;
        q->parent = p;
    }
int depth(Node* r){
    Node* p = r;
    int d = 0;
    while(p != NULL){
        d += 1;
        p = p->parent;
    }
    return d;
}
int height(Node* r){
    int maxH = 0;
    if(r == NULL) return 0;
    for(Node* p = r->leftmostchild; p != NULL; p = p->rightSibling){
            int h = height(p);
            if(h > maxH) maxH = h;
}
return maxH + 1;
}

void freeTree(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftmostchild;
  while (p != NULL) {
    Node * np = p -> rightSibling;
    free(p);
    p = np;
  }
  free(r);
}
void solve() {
  Node * root = NULL;
  char cmd[50];
  while (1) {
    scanf("%s", cmd);
    if (strcmp(cmd, "*") == 0) break;
    else if (strcmp(cmd, "MakeRoot") == 0) {
      int id;
      scanf("%d", & id);
      root = makeNode(id);
    } else if (strcmp(cmd, "Insert") == 0) {
      int u, v;
      scanf("%d%d", & u, & v);
      insert(root, u, v);
    } else if (strcmp(cmd, "Height") == 0) {
      int id;
      scanf("%d", & id);
      Node * p = find(root, id);
      printf("%d\n", height(p));
    } else if (strcmp(cmd, "Depth") == 0) {
      int id;
      scanf("%d", & id);
      Node * p = find(root, id);
      int ans = depth(p);
      printf("%d\n", ans);
    }
  }
  freeTree(root);
}
int main() {
  solve();
}
#treetravel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
  int id;
  struct Node* leftMostChild;
  struct Node* rightSibling;
}Node;
Node * makeNode(int u) {
  Node * p = (Node * ) malloc(sizeof(Node));
  p -> id = u;
  p -> leftMostChild = NULL;
  p -> rightSibling = NULL;
  return p;
}
Node * find(Node * r, int u) {
  if (r == NULL) return NULL;
  if (r -> id == u) return r;
  Node * p = r -> leftMostChild;
  while (p != NULL) {
    Node * q = find(p, u);
    if (q != NULL) return q;
    p = p -> rightSibling;
  }
  return NULL;
}
void insert(Node * r, int u, int v) {
  Node* p = find(r, v);
  if (p == NULL) return;
  Node * q = makeNode(u);
  if (p -> leftMostChild == NULL) {
    p -> leftMostChild = q;
    return;
  }
  Node * h = p -> leftMostChild;
  while (h -> rightSibling != NULL)
    h = h -> rightSibling;
  h -> rightSibling = q;
}

void preOrder(Node * r) {
  if (r == NULL) return;
  printf("%d ", r -> id);
  Node * p = r -> leftMostChild;
  while (p != NULL) {
    preOrder(p);
    p = p -> rightSibling;
  }
}

void inOrder(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftMostChild;
  inOrder(p);
  printf("%d ", r -> id);
  if (p == NULL) return;
  p = p -> rightSibling;
  while (p != NULL) {
    inOrder(p);
    p = p -> rightSibling;
  }
}

void postOrder(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftMostChild;

  while (p != NULL) {
    postOrder(p);
    p = p -> rightSibling;
  }
  printf("%d ", r -> id);
}
void freeTree(Node * r) {
  if (r == NULL) return;
  Node * p = r -> leftMostChild;
  while (p != NULL) {
    Node * np = p -> rightSibling;
    free(p);
    p = np;
  }
  free(r);
}
void solve() {
  Node * root = NULL;
  char cmd[50];
  while (1) {
    scanf("%s", cmd);
    if (strcmp(cmd, "*") == 0) break;
    else if (strcmp(cmd, "MakeRoot") == 0) {
      int id;
      scanf("%d", & id);
      root = makeNode(id);
    } else if (strcmp(cmd, "Insert") == 0) {
      int u, v;
      scanf("%d%d", & u, & v);
      insert(root, u, v);
    } else if (strcmp(cmd, "PreOrder") == 0) {
      preOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "InOrder") == 0) {
      inOrder(root);
      printf("\n");
    } else if (strcmp(cmd, "PostOrder") == 0) {
      postOrder(root);
      printf("\n");
    }
  }
  freeTree(root);
}
int main() {
  solve();
}
#all_dequy
#1
#include <stdio.h>
int F(int a, int b){
    if( a == b ) return a;
    else if( a < b) return F(a, b - a);
    else return F(a - b, b);
}
int main(){
    int a,b;
    scanf("%d %d", &a,&b);
    int c = F(a,b);
    printf("%d", c);
    return 0;

}
#2  
#include <stdio.h>
void convert(int N){
    if (N == 0) return;
    convert(N/2);
    int b = N % 2;
    printf("%d", b);
}
int main(){
    int a;
    scanf("%d", &a);
    convert(a);
    return 0;

}

#3
#include <stdio.h>
#define P 1000000007
int M[1000][1000] = {0};
int C(int k, int n){
    if( k == 0 || k == n) M[k][n] = 1;
    else{
        if ( M[k][ n] == 0 ){
            M[ k][ n] = C(k-1,n-1) + C(k, n -1);
        }

    }
    return M[k][n];
}
int main(){

int k,n; scanf("%d %d",&k,&n); printf("%d",C(k,n));
return 0;

}


#all_giuaki
#1
#include <stdio.h>
int n, m;
int a[1000];
int x[1000];
int max = 0;
int check(int k, int v){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += a[i] * x[i];
    }
    if(sum == m) return 1;
    else return 0;
}
void solution(int k, int v){
    if(check(k, v)){
            int tich = 1;
        for(int i = 1; i <= n; i++){

            tich = tich * x[i];
        }
        if(tich > max) max = tich;
    }
}
int try(int k){
    for(int v = 0; v <= m; v++){
        x[k] = v;
        if(k == n) solution(k,v);
        else try(k+1);
}}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    try(1);
    if(max == 0) printf("None");
    else  printf("%d", max);
    return 0;

}

#2
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int x, y, dist;
} Node;

// Cấu trúc Queue
typedef struct NodeQueue {
    Node data;
    struct NodeQueue* next;
} NodeQueue;

NodeQueue* head = NULL;
NodeQueue* tail = NULL;

void push(Node v) {
    NodeQueue* p = (NodeQueue*)malloc(sizeof(NodeQueue));
    p->data = v;
    p->next = NULL;
    if (head == NULL) {
        head = tail = p;
    } else {
        tail->next = p;
        tail = p;
    }
}

Node pop() {
    Node res = {-1, -1, -1};
    if (head != NULL) {
        NodeQueue* tmp = head;
        res = head->data;
        head = head->next;
        free(tmp);
        if (head == NULL) tail = NULL;
    }
    return res;
}

int queueEmpty() {
    return head == NULL;
}

// Hướng di chuyển: Lên, Xuống, Trái, Phải
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m;
int maze[MAX][MAX];
int visited[MAX][MAX];

// Hàm BFS tìm đường đi ngắn nhất
int BFS(int r0, int c0, int r1, int c1) {
    // Reset visited array cho mỗi lần gọi BFS
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }

    // Nếu điểm xuất phát hoặc mục tiêu là tường (1) thì không đi được
    if (maze[r0][c0] == 1 || maze[r1][c1] == 1) {
        return -1;
    }

    Node start = {r0, c0, 0};
    push(start);
    visited[r0][c0] = 1;

    while (!queueEmpty()) {
        Node cur = pop();

        // Đã tìm thấy mục tiêu
        if (cur.x == r1 && cur.y == c1) {

            // Dọn dẹp hàng đợi trước khi trả về
            while(!queueEmpty()) {
                pop();
            }
            head = tail = NULL; // Đảm bảo queue trống

            return cur.dist;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                maze[nx][ny] == 0 && !visited[nx][ny]) {

                visited[nx][ny] = 1;
                Node next = {nx, ny, cur.dist + 1};
                push(next);
            }
        }
    }

    while(!queueEmpty()) {
        pop();
    }
    head = tail = NULL;

    return -1;
}

int main() {
    int r0, c0, r1, c1;
    if (scanf("%d %d %d %d %d %d", &n, &m, &r0, &c0, &r1, &c1) != 6) {

        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &maze[i][j]) != 1) {

                return 1;
            }
        }
    }
    int res = BFS(r0 - 1, c0 - 1, r1 - 1, c1 - 1);
    printf("%d\n", res);

    return 0;
}
#3
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{
    char key;
    struct Node* left;
    struct Node* right;

}Node;
Node* makeNode(char key){
    Node* new = (Node*)malloc(sizeof(Node));
    new->key = key;
    new->left = NULL;
    new->right = NULL;
    return new;
}
Node* find(Node* r, char key){
    if( r == NULL) return NULL;
    if( r->key == key ) return r;
    Node* p = r->left;
    while(p!= NULL){
        Node* q = find(p , key);
        if(q != NULL) return q;
        p = p->right;

    }
    return NULL;
}
Node* insert(Node* root, char key){
    if(root == NULL) return makeNode(key);
    if( key < root->key){
        root->left = insert(root->left, key);
    }else if ( key > root->key) root->right = insert(root->right, key);
    return root;
}
Node* findmin(Node* root){
    while(root->left != NULL)
        root = root->left;
    return root;
}
Node* deleteNode(Node* root, char key){
    if (root == NULL) return NULL;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findmin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->key);
}

int main() {
    Node* root = NULL;
    char s[10], key;

    while (1) {
        scanf("%s", s);
        if (strcmp(s,"#") == 0) break;

        scanf(" %c", &key);

        if (strcmp(s,"insert") == 0)
            root = insert(root, key);

        if (strcmp(s,"delete") == 0)
            root = deleteNode(root, key);
    }

    if (root == NULL)
        printf("NULL\n");
    else {
        postOrder(root);
        printf("\n");
    }
    return 0;
}
#4
#include <stdio.h>
#define N 100
int n;
int x[100]; // cot i
int mark[100]; // hang
int markD1[100];
int markD2[100];
int cnt;
int check(int v, int k){
    if(mark[v] == 1) return 0;
    if(markD1[n + k - v] == 1) return 0;
    if(markD2[k + v] == 1) return 0;
    return 1;
}
void printSolution() {
    for(int i = 1; i <= n; i++){
        printf("%d", x[i]);
        if(i < n) printf(" ");
    }
    printf("\n");
}
void Try(int k){
    if(x[k] > 0){
        if(k == n){
            printSolution();
            cnt++;
        }
        else Try(k+1);
        return;
    }
    for(int r = 1; r <= n; r++){
        if(check(r,k)){
                x[k] = r; mark[r] = 1;
                markD1[n+ k - r] = 1;
                markD2[k + r] = 1;
                if(k == n){
                        printSolution();
                cnt++;}
                else Try(k+1);
                x[k] = 0;
                mark[r] = 0;
                markD1[n+ k - r] = 0;
                markD2[k + r] = 0;

        }
    }
}


void input(){
    int r, c;
    for(int i = 1; i < N; i++) mark[i] = 0;
    for(int i = 0; i < 2*N; i++){ markD1[i] = 0; markD2[i] = 0; }
    scanf("%d %d %d",&n,&r, &c);
    for(int i = 1; i <= n; i++) x[i] = 0;
        x[c] = r;
        mark[r] = 1;
        markD1[n + c - r] = 1;
        markD2[c + r] = 1;

}


int main(){
    input();
    cnt = 0;
    Try(1);
    if(cnt == 0) printf("None\n");
    printf("%d", cnt);
    return 0;
    
}
#5

#include <stdio.h>

int n, m;
int a[1000];
int x[1000];
int max = 0;

int check(){
    int sum = 0;
    for(int i = 1; i <= n; i++)
        sum += a[i] * x[i];
    return sum == m;
}

void solution(){
    int tich = 1;
    for(int i = 1; i <= n; i++)
        tich *= a[i];   // nếu đây là ý bạn
    if(tich > max) max = tich;
}

void Try(int k){
    for(int v = 0; v <= m; v++){
        x[k] = v;
        if(k == n){
            if(check()) solution();
        } else Try(k+1);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    Try(1);

    if(max == 0) printf("None");
    else printf("%d", max);
    return 0;
}

#all_bam
#demsolan
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define N 1000001
typedef struct Node {
  char word[20];
  int occ;
  struct Node * leftChild;
  struct Node * rightChild;
}
Node;

Node * root;
char T[N];
int n;
void input() {
  n = 0;
  while (!feof(stdin)) {
    char c = fgetc(stdin);
    T[n] = c;
    n += 1;
  }
  T[n - 1] = '\0';
}
Node * makeNode(char * w) {
  Node * nod = (Node * ) malloc(sizeof(Node));
  strcpy(nod -> word, w);
  nod -> occ = 1;
  nod -> leftChild = NULL;
  nod -> rightChild = NULL;
  return nod;
}
Node * insert(Node * r, char * w) {
  if (r == NULL) return makeNode(w);
  int c = strcmp(r -> word, w);
  if (c == 0) {
    r -> occ += 1;
    return r;
  }
  if (c < 0)
    r -> rightChild = insert(r -> rightChild, w);
  else
    r -> leftChild = insert(r -> leftChild, w);
  return r;
}
int legal(char c) {
  return (c >= 'a' && c <= 'z' || c >= 'A' && c <=
    'Z' || c >= '0' && c <= '9');
}
void solve() {
  root = NULL;
  char word[30];
  int end = -1;
  for (int i = 0; i < n; i++) {
    if (legal(T[i])) {
      end++;
      word[end] = T[i];
    } else {
      if (end != -1) {
        word[end + 1] = '\0';
        root = insert(root, word);
      }
      end = -1;
    }
  }
}
void inOrder(Node * r) {
  if (r == NULL) return;
  inOrder(r -> leftChild);
  printf("%s %d\n", r -> word, r -> occ);
  inOrder(r -> rightChild);
}

int main() {
  input();
  solve();
  inOrder(root);
  return 0;
}
#hambam

#include <string.h>

#include <stdio.h>

#include <time.h>

#include <stdlib.h>

#define MAX 200
int n, m;
int hashCode(char * k) {
  int c = 0;
  for (int i = 0; i < strlen(k); i++) {
    c = (c * 256 + k[i]) % m;
  }
  return c;
}
void solve() {
  scanf("%d%d", & n, & m);
  char k[200];
  for (int i = 0; i < n; i++) {
    scanf("%s", k);
    int h = hashCode(k);
    printf("%d\n", h);
  }
}
int main() {
  solve();
  return 0;
}
#hangbam

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#define MAX 50
#define m 10000
typedef struct Node {
  char key[MAX];
  struct Node * leftChild;
  struct Node * rightChild;
}
Node;
Node * T[m];
Node * makeNode(char * k) {
  Node * p = (Node * ) malloc(sizeof(Node));
  strcpy(p -> key, k);
  p -> leftChild = NULL;
  p -> rightChild = NULL;
  return p;
}

int h(char * k) {
  int c = 0;
  for (int i = 0; i < strlen(k); i++)
    c = (c * 256 + k[i]) % m;
  return c;
}
Node * findBST(Node * r, char * k) {
  if (r == NULL) return NULL;
  int c = strcmp(r -> key, k);
  if (c == 0) return r;
  if (c < 0) return findBST(r -> rightChild, k);
  else return findBST(r -> leftChild, k);
}
Node * insertBST(Node * r, char * k) {
  if (r == NULL) return makeNode(k);
  if (strcmp(r -> key, k) < 0)
    r -> rightChild = insertBST(r -> rightChild, k);
  else
    r -> leftChild = insertBST(r -> leftChild, k);
  return r;
}
int find(char * k) {
  int i = h(k);
  Node * p = findBST(T[i], k);
  if (p == NULL) return 0;
  return 1;
}
int insert(char * k) { // put(k)
  int i = h(k);
  Node * p = findBST(T[i], k);
  if (p != NULL) return 0;
  T[i] = insertBST(T[i], k);
  return 1;
}
int main() {
  char k[MAX], cmd[20];
  while (1) {
    scanf("%s", k);
    if (strcmp(k, "*") == 0) break;
    insert(k); // put k into the hash table (+BST)
  }
  while (1) {
    scanf("%s", cmd);
    if (strcmp(cmd, "find") == 0) {
      scanf("%s", k);
      int ans = find(k);
      printf("%d\n", ans);
    } else if (strcmp(cmd, "insert") == 0) {
      scanf("%s", k);
      int ans = insert(k);
      printf("%d\n", ans);
    } else if (strcmp(cmd, "***") == 0) {
      break;
    }
  }
  return 0;
}
#hashinter
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50
#define m 10000

typedef struct Node {
    char key[MAX];
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* T[m];   

Node* makeNode(char* k) {
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->key, k);
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

int h(char* k) {
    int c = 0;
    for (int i = 0; i < strlen(k); i++)
        c = (c * 256 + k[i]) % m;
    return c;
}

Node* findBST(Node* r, char* k) {
    if (r == NULL) return NULL;
    int cmp = strcmp(r->key, k);
    if (cmp == 0) return r;
    if (cmp < 0) return findBST(r->rightChild, k);
    return findBST(r->leftChild, k);
}

Node* insertBST(Node* r, char* k) {
    if (r == NULL) return makeNode(k);
    if (strcmp(r->key, k) < 0)
        r->rightChild = insertBST(r->rightChild, k);
    else
        r->leftChild = insertBST(r->leftChild, k);
    return r;
}

int find(char* k) {
    int i = h(k);
    return (findBST(T[i], k) != NULL);
}

int insert(char* k) {
    int i = h(k);
    if (findBST(T[i], k) != NULL) return 0;
    T[i] = insertBST(T[i], k);
    return 1;
}

int main() {
    char k[MAX], cmd[20];

    for (int i = 0; i < m; i++)
        T[i] = NULL;

    while (1) {
        scanf("%s", k);
        if (strcmp(k, "*") == 0) break;
        insert(k);
    }

    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "find") == 0) {
            scanf("%s", k);
            printf("%d\n", find(k));
        } 
        else if (strcmp(cmd, "insert") == 0) {
            scanf("%s", k);
            printf("%d\n", insert(k));
        } 
        else if (strcmp(cmd, "***") == 0) {
            break;
        }
    }

    return 0;
}
#wordfrequency
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define N 1000001
typedef struct Node {
  char word[20];
  int occ;
  struct Node * leftChild;
  struct Node * rightChild;
}
Node;

Node * root;
char T[N];
int n;
void input() {
  n = 0;
  while (!feof(stdin)) {
    char c = fgetc(stdin);
    T[n] = c;
    n += 1;
  }
  T[n - 1] = '\0';
}
Node * makeNode(char * w) {
  Node * nod = (Node * ) malloc(sizeof(Node));
  strcpy(nod -> word, w);
  nod -> occ = 1;
  nod -> leftChild = NULL;
  nod -> rightChild = NULL;
  return nod;
}
Node * insert(Node * r, char * w) {
  if (r == NULL) return makeNode(w);
  int c = strcmp(r -> word, w);
  if (c == 0) {
    r -> occ += 1;
    return r;
  }
  if (c < 0)
    r -> rightChild = insert(r -> rightChild, w);
  else
    r -> leftChild = insert(r -> leftChild, w);
  return r;
}
int legal(char c) {
  return (c >= 'a' && c <= 'z' || c >= 'A' && c <=
    'Z' || c >= '0' && c <= '9');
}
void solve() {
  root = NULL;
  char word[30];
  int end = -1;
  for (int i = 0; i < n; i++) {
    if (legal(T[i])) {
      end++;
      word[end] = T[i];
    } else {
      if (end != -1) {
        word[end + 1] = '\0';
        root = insert(root, word);
      }
      end = -1;
    }
  }
}
void inOrder(Node * r) {
  if (r == NULL) return;
  inOrder(r -> leftChild);
  printf("%s %d\n", r -> word, r -> occ);
  inOrder(r -> rightChild);
}

int main() {
  input();
  solve();
  inOrder(root);
  return 0;
}
#all_hust
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


#all_linkedlist
#1
void insertAtTail(contact ct){
    node* new = makeNewNode(ct);      // ①
    if (root == NULL) {                // ②
        root = new;
        cur = new;
        prev = NULL;
        return;
    }
    node* p = root;                    // ③
    while (p->next != NULL) p = p->next; // ④
    p->next = new;                     // ⑤
    cur = new;
    prev = p;                          // ⑥
}
node * insertLastRecursive(node * root, contact ct) { // de quy
  if (root == NULL) {
    return makeNewNode(ct);
  }
  root -> next = insertLastRecursive(root -> next, ct);
  return root;
}
void main() {
  contact tmp;
  int i;
  for (i = 0; i < 2; i++) {
    tmp = readNode();
    root = insertLastRecursive(tmp);
    displayNode(root);
  }
}
#2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int elementtype;
struct node_t{
    elementtype element;
    struct node_t* next;
};

typedef struct node_t Node;
Node* root = NULL;
Node* cur = NULL;
Node* prev = NULL;
Node* makeNewNode(elementtype e){
    Node* new = (Node*)malloc(sizeof(Node));
    new->element = e;
    new->next = NULL;
    return new;
}
Node* find(Node* root, elementtype e){
    Node* p;
    for(p = root; p!= NULL; p = p->next){
        if(p->element == e) return p;
    }
    return NULL;
}
void insertAtTail(elementtype e){
    Node* new = makeNewNode(e);
    if(root == NULL){
        root = new;
        cur = new;
        prev = NULL;
        return;
    }
    Node* p = root;
    while(p->next != NULL) p = p->next;
    p->next = new;
    cur = new;
    prev = p;
}
Node * insertLastRecursive(Node* root, elementtype e){
    if(root == NULL){
        return makeNewNode(e);
    }
    root->next = insertLastRecursive(root->next,e);
    return root;
}
void insertAtHead(elementtype e){
    Node* new = makeNewNode(e);
    new->next = root;
    root = new;
    cur = root;
}
Node* removeNodeRecursive(Node* root, elementtype e){
    if(root == NULL) return NULL;
    if(root->element == e){
        Node* tmp = root;
        root = root->next;
        free(tmp);
        return root;
    }
    root->next = removeNodeRecursive(root->next, e);
    return root;
}
void freeList() {
    Node * to_free = root;
    while (to_free != NULL) {
      root = root -> next;
      free(to_free);
      to_free = root;
    }}
Node * addBefore(Node * root, elementtype u, elementtype v) {

  if (root == NULL) return NULL;
  if (find(root, u) != NULL) return root; // do nothing
  if (root -> element == v) {

    Node * q = makeNewNode(u);
    q -> next = root;
    return q;

  }
  root -> next = addBefore(root -> next, u, v);
  return root;

}
Node * addAfter(Node * root, elementtype u, elementtype v) {

  if (root == NULL) return NULL;
  if (root -> element == v) {

    Node * q = makeNewNode(u);
    q -> next = root -> next;
    root -> next = q;
    return root;

  }
  root -> next = addAfter(root -> next, u, v);
  return root;

}
Node * reverse(Node * root) {

  Node * p = root;
  Node * pp = NULL;
  Node * np = NULL;
  while (p != NULL) {

    np = p ->next;
    p->next = pp;
    pp = p;
    p = np;
  }
  return pp;

}
void traverseList(Node * root) {

  Node * p = root;
  while (p != NULL) {

    printf("%d ", p -> element);
    p = p -> next;
  }
  printf("\n");
}
void solve() {
    int n, i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        root = insertLastRecursive(root, k);
    }

    while (1) {
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0) break;

        if (strcmp(cmd, "addlast") == 0) {
            int k;
            scanf("%d", &k);
            if (find(root, k) == NULL)
                root = insertLastRecursive(root, k);
        }
        else if (strcmp(cmd, "addfirst") == 0) {
            int k;
            scanf("%d", &k);
            if (find(root, k) == NULL)
                insertAtHead(k);
        }
        else if (strcmp(cmd, "addafter") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            if (find(root, u) == NULL)
                root = addAfter(root, u, v);
        }
        else if (strcmp(cmd, "addbefore") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            if (find(root, u) == NULL)
                root = addBefore(root, u, v);
        }
        else if (strcmp(cmd, "remove") == 0) {
            int k;
            scanf("%d", &k);
            root = removeNodeRecursive(root, k);
        }
        else if (strcmp(cmd, "reverse") == 0) {
            root = reverse(root);
        }
    }
}

int main() {
    solve();
    traverseList(root);
    freeList();
    return 0;
}



#3
node * list_reverse(node * root) {
  node * cur, * prev;
  cur = prev = NULL;
  while (root != NULL) {

    cur = root;
    root = root -> next;
    cur -> next = prev;
    prev = cur;

  }
  return prev;
}
#4
void traversingList(node * root) {
  node * p;
  for (p = root; p != NULL; p = p -> next)
    displayNode(p);
}
#5
while (to_free != NULL) {
  root = root -> next;
  free(to_free);
  to_free = root;
}
#6
void insertAtHead(contact ct){
    node *new = makeNewNode(ct);
    new->next = root;
    root = new;
    cur = root;
}

void main(){
    contact tmp;
    int i;
    for( i = 0; i< 2; i++){
        tmp = readNode();
        insertAtHead(tmp);
        displayNode(root);
    }


}
#7
tmp = root;
while (tmp != NULL && tmp -> next != cur && cur != NULL)

  tmp = tmp -> next;

prev = tmp;
#8
void insertBeforeCurrent(contact e) {
  node_addr * new = makeNewNode(e);
  if (root == NULL) {
    /* if there is no element */
    root = new;
    cur = root;
    prev = NULL;

  } else {

    new -> next = cur;
    if (cur == root) {
      /* if cur pointed to first element */

      root = new; /* nut moi them vao tro thanh dau danh sach */

    } else prev -> next = new; // assume prev pointer always point to the previous node
    cur = new;

  }
}
#9
Node * removeNodeRecursive(Node * root, contact e) {

  if (root == NULL) return NULL;
  if (root -> el == e) {

    Node * tmp = root;
    root = root -> next;
    free(tmp);
    return root;

  }
  root -> next = removeNodeRecursive(root -> next, e);
  return root;

}
#10
void deleteFirstElement() {
  node * del = root;
  if (del == NULL) return;
  root = del -> next;
  free(del);
  cur = root;
  prev = NULL; //update prev � cur
}
#11
void deleteCurrentElement() {
    if (cur == NULL) return;
    if (cur == root) deleteFirstElement();
    else {
      prev -> next = cur -> next;
      free(cur);
      cur = prev -> next; // or cur = root;
    }
#all_queen
#1
#include <stdio.h>
#define N 100
int n;
int m;
int x[100];
int mark[100];
int markD1[100];
int markD2[100];
int cnt;
int check(int v, int k){
    if(mark[v] == 1) return 0;
    if(markD1[n + k - v] == 1) return 0;
    if(markD2[k + v] == 1) return 0;
    return 1;
}
void Try(int k){
    if(x[k] > 0){
        if(k == n) cnt++;
        else Try(k+1);
        return;
    }
    for(int r = 1; r <= n; r++){
        if(check(r,k)){
                x[k] = r; mark[r] = 1;
                markD1[n+ k - r] = 1;
                markD2[k + r] = 1;
                if(k == n) cnt += 1;
                else Try(k+1);
                x[k] = 0;
                mark[r] = 0;
                markD1[n+ k - r] = 0;
                markD2[k + r] = 0;

        }
    }
}


void input(){
    for(int i = 1; i < N; i++) mark[i] = 0;
    for(int i = 0; i < 2*N; i++){ markD1[i] = 0; markD2[i] = 0; }

    scanf("%d",&n);
    scanf("%d",&m);

    for(int i = 1; i <= n; i++) x[i] = 0;

    for(int j = 1; j <= m; j++){
        int r, c;
        scanf("%d %d", &r, &c);

        x[c] = r;                        // ✔ cột c đặt queen ở hàng r
        mark[r] = 1;                     // ✔ đánh dấu hàng r
        markD1[n + c - r] = 1;           // ✔ đường chéo chính
        markD2[c + r] = 1;               // ✔ đường chéo phụ
    }
}


int main(){
    input();
    cnt = 0;
    Try(1);
    printf("%d",cnt);
    return 0;
}


#2
#include <stdio.h>
#define N 100
int n;
int x[N];
int mark[N];
int markD1[N];
int markD2[N];
int count = 0;
void init(){
    for(int i = 0; i  <= N; i++) mark[i] = 0;
    for(int i = 0; i  <= 2*N; i++) markD1[i] = 0;
    for(int i = 0; i  <= 2*N; i++) markD2[i] = 0;
    scanf("%d", &n);
    for(int i = 0; i <=n ; i++){
        for(int j = 0; j <= n; j++){
            int e;
            scanf("%d", &e);
            if( e > 0 ){ mark[j] = i;
            markD2[ i + j] = 1;
            markD1[n + j - i ] = 1;}
        }
    }
}
void solution(){
    count++;
}
int check(int v, int k){
    if(mark[v] == 1) return 0;
    if(markD1[n + v - k] == 1) return 0;
    if(markD2[v + k] == 1) return 0;
    return 1;
}
void try(int k){
    if( x[k] > 0){
        if( k == 8 ) solution();
            else try(k+1);
    }
    for(int r = 1; r <= n; r++ ){
        if(check(r,k)){
            x[k] = r;
            mark[r] = 1;
            markD1[ n + r - k] = 1;
            markD2[ r + k ] = 1;
            if( k == 8) solution();
            else try(k+1);
            x[k] = 0;
            mark[r] = 0;
            markD1[ n + r - k] = 0;
            markD2[ r + k ] = 0;
        }
    }


}
int main(){
    init();
    count = 0;
    try(1);
    printf("%d",count);
    return 0;
}
#3
#include <stdio.h>
#define N 100
int n;
int x[N];
int mark[N];
int markD1[N];
int markD2[N];
int count;

int check(int v, int k){
    if(mark[v] == 1) return 0;
    if(markD1[n - k + v]) return 0;
    if(markD2[k + v]) return 0;
    return 1;
}
void solution(){
    count++;
}
void try(int k){
    if(x[k] > 0){
        if(k == n) solution();
        else try(k+1);
    }
    for(int v = 1; v <= n; v++){
        if(check(v,k)){
            x[k] = v;
            mark[v] = 1;
            markD1[n - k + v] = 1;
            markD2[k + v] = 1;
            if( k == n ) solution();
            else try(k+1);
            mark[v] = 0;
            markD1[n - k + v] = 0;
            markD2[k + v] = 0;
            x[k] = 0;

        }
    }
}
void input(){
    for(int i = 0; i < N; i++)
        mark[i] = 0;
    for(int j = 0; j < 2 * N; j++) {markD1[j] = 0; markD2[j] = 0;}
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) x[i] = 0;
    for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int e;
                scanf("%d", &e);
                if(e == 1){
                x[j] = i;
                mark[i] = 1;
                markD1[n - j + i] = 1;
                markD2[j + i] = 1;
            }
            }

    }


}
int main(){
    input();
    count = 0;
    try(0);
    printf("%d", count);
    return 0;




}
#4
#include <stdio.h>
int x[30],n,k,cot[30],xuoi[100],nguoc[100],fix[20];
int cnt=0;
void Try(int i){
	if (i==n+1){
	 	cnt++;
	 	return;
	}
	if (fix[i]){
		int j=x[i];
		if(cot[j]==0&&xuoi[i-j+n]==0&&nguoc[i+j-1]==0){
			cot[j]=1;xuoi[i-j+n]=1;nguoc[i+j-1]=1;
			Try(i+1);
			cot[j]=0;xuoi[i-j+n]=0;nguoc[i+j-1]=0;
		}
	}
	else {
		for (int j=1;j<=n;j++){
			if(cot[j]==0&&xuoi[i-j+n]==0&&nguoc[i+j-1]==0){
			x[i]=j;
			cot[j]=1;xuoi[i-j+n]=1;nguoc[i+j-1]=1;
			Try(i+1);
			cot[j]=0;xuoi[i-j+n]=0;nguoc[i+j-1]=0;
		}
		}
	}
}

int main(){
	scanf("%d %d",&n,&k);
	while (k--){
		int r,c;
		scanf("%d %d",&r,&c);
		x[r]=c;
		fix[r]=1;
	}
	Try(1);
	printf("%d",cnt);
}
#5
#include <stdio.h>
#define N 100
int n;
int m;
int x[100];
int mark[100];
int markD1[100];
int markD2[100];
int cnt;
int check(int v, int k){
    if(mark[v] == 1) return 0;
    if(markD1[n + k - v] == 1) return 0;
    if(markD2[k + v] == 1) return 0;
    return 1;
}
void Try(int k){
    if(x[k] > 0){
        if(k == n) cnt++;
        else Try(k+1);
        return;
    }
    for(int r = 1; r <= n; r++){
        if(check(r,k)){
                x[k] = r; mark[r] = 1;
                markD1[n+ k - r] = 1;
                markD2[k + r] = 1;
                if(k == n) cnt += 1;
                else Try(k+1);
                x[k] = 0;
                mark[r] = 0;
                markD1[n+ k - r] = 0;
                markD2[k + r] = 0;

        }
    }
}


void input(){

    for(int i = 1; i < N; i++) mark[i] = 0;
    for(int i = 0; i < 2*N; i++){ markD1[i] = 0; markD2[i] = 0; }
    scanf("%d",&n);
    scanf("%d", &m);
    for(int i = 1; i <= n; i++) x[i] = 0;
    for(int j = 1; j <= m; j++){
        int r,c;
        scanf("%d %d", &r, &c);
        mark[c] = 1;
        markD1[n + r - c] = 1;
        markD2[r + c] = 1;
        x[r] = c;
    }
}

int main(){
    input();
    cnt = 0;
    Try(1);
    printf("%d",cnt);
    return 0;
}

#all_sort
#checkexist
#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 200003  // số nguyên tố

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* hashTable[HASH_SIZE];

int hash(int x) {
    if (x < 0) x = -x;
    return x % HASH_SIZE;
}

int exists(int x) {
    int h = hash(x);
    Node* cur = hashTable[h];
    while (cur) {
        if (cur->key == x) return 1;
        cur = cur->next;
    }
    return 0;
}

void insert(int x) {
    int h = hash(x);
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = x;
    node->next = hashTable[h];
    hashTable[h] = node;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        if (exists(x)) {
            printf("1\n");
        } else {
            printf("0\n");
            insert(x);
        }
    }
    return 0;
}
#check
#include <stdio.h>

#define N 100001
int a[N];
int n;
void input() {
  scanf("%d", & n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", & a[i]);
  }
}
void swap(int i, int j) {
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}
void heapify(int i, int n) {
  int L = 2 * i;
  int R = 2 * i + 1;
  int maxIdx = i;
  if (L <= n && a[maxIdx] < a[L]) maxIdx = L;
  if (R <= n && a[maxIdx] < a[R]) maxIdx = R;
  if (maxIdx != i) {
    swap(i, maxIdx);
    heapify(maxIdx, n);
  }
}
void buildHeap() {
  for (int i = n / 2; i >= 1; i--) heapify(i, n);
}
void heapSort() {
  buildHeap();
  for (int i = n; i >= 2; i--) {
    swap(1, i);
    heapify(1, i - 1);
  }
}
int bSearch(int i, int j, int k) {
  if (i > j) return -1;
  if (i == j) {
    if (a[i] == k) return i;
    else return -1;
  }
  int m = (i + j) / 2;
  if (a[m] == k) return m;
  if (a[m] < k) return bSearch(m + 1, j, k);
  else return bSearch(i, m - 1, k);
}
int main() {
  input();
  heapSort();
  char cmd[30];
  while (1) {
    scanf("%s", cmd);
    if (strcmp(cmd, "#") == 0) break;
    else if (strcmp(cmd, "check") == 0) {
      int k;
      scanf("%d", & k);
      int i = bSearch(1, n, k);
      if (i > 0) i = 1;
      else i = 0;
      printf("%d\n", i);
    }
  }
  return 0;
}
#heapify
#include <stdio.h>
#include <string.h>

char arr[500][81];

void heapify(int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && strcmp(arr[l], arr[largest]) > 0)
        largest = l;

    if (r < n && strcmp(arr[r], arr[largest]) > 0)
        largest = r;

    if (largest != i) {
        char tmp[81];
        strcpy(tmp, arr[i]);
        strcpy(arr[i], arr[largest]);
        strcpy(arr[largest], tmp);

        heapify(n, largest);
    }
}

void heapSort(int n){

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    
    for (int i = n - 1; i > 0; i--) {
        char tmp[81];
        strcpy(tmp, arr[0]);
        strcpy(arr[0], arr[i]);
        strcpy(arr[i], tmp);

        heapify(i, 0);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%s", arr[i]);

    heapSort(n);

    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);

    return 0;
}

#1
#include <stdio.h>
void quicksort(int a[], int l, int r){
    int i = l;
    int j = r;
    int p = a[ (l + r) / 2];
    while( i <= j){
        while(a[i] < p) i++;
        while(a[j] > p) j--;
        if( i <= j){
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }
    if(l < j) quicksort(a,l,j);
    if(i < r) quicksort(a,i,r);

}
int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    int a[1000];
    int x[1000];
    for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            x[i] = a[i];}


    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++){
        if(a[i] != x[i]) cnt++;}
    printf("%d", cnt);
    return 0;
}
#qs
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void*a,const void*b){
    return *(int*)a - *(int*)b;
}
int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    int a[1000];
    int x[1000];
    for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            x[i] = a[i];}

    qsort(a,n,sizeof(int), cmp);
    for (int i = 0; i < n; i++){
        if(a[i] != x[i]) cnt++;}
    printf("%d", cnt);
    return 0;
}

#quick
#include <stdio.h>


void quicksort(int a[], int l, int r){
    int i = l;
    int j = r;
    int p = a[( l + r ) / 2];
    while(i <= j){
        while(a[i] < p) i++;
        while(a[j] > p) j--;
        if( i <= j){
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if(l < j) quicksort(a,l,j);
    if(i < r) quicksort(a,i,r);
}
int main() {
    int n;
    scanf("%d", &n);
    int a[1000];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
#quicksort\
#include <stdio.h>
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int a[], int l, int r){
    int pivot = a[r];
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(a[j] < pivot){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[r]);
    return i + 1;
}

void quicksort(int a[], int l,int r){
    if(l < r){
        int p = partition(a,l,r);
        quicksort(a,l,p-1);
        quicksort(a,p+1,r);
    }
}
int main(){
    int a[] = {5, 3, 8, 4, 2, 7, 1, 10};
    int n = sizeof(a)/sizeof(a[0]);
    quicksort(a, 0, n - 1);
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
#sort_candi
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char code[11];
    int score;
} candidate;

candidate a[100000];
int n = 0;

int cmp(const void *x, const void *y) {
    const candidate *a = x;
    const candidate *b = y;
    if (a->score < b->score) return 1;
    if (a->score > b->score) return -1;
    return 0;
}

int main() {
    char tmp[20];

    while (1) {
        if (scanf("%s", tmp) != 1) break;
        if (strcmp(tmp, "#") == 0) break;

        strcpy(a[n].code, tmp);
        scanf("%d", &a[n].score);
        n++;
    }

    qsort(a, n, sizeof(candidate), cmp);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", a[i].code, a[i].score);
    }

    return 0;
}
#sort
#include <stdio.h>

int exist[1000001];

int main() {
    int n, m, x;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        exist[x] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        if (exist[x] == 1) {
            cnt++;
            exist[x] = 2;
        }
    }

    printf("%d", cnt);
    return 0;
}
#sort1
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define N 100001
typedef struct Candidate {
  int score;
  char code[10];
}
Candidate;
int n;
Candidate * a[N];
void input() {
  char code[11];
  n = 0;
  while (1) {
    scanf("%s", code);
    if (strcmp(code, "#") == 0) break;
    int score;
    scanf("%d", & score);
    n++;
    a[n] = (Candidate * ) malloc(sizeof(Candidate));
    a[n] -> score = score;
    strcpy(a[n] -> code, code);
  }
}
void swap(int i, int j) {
  Candidate * t = a[i];
  a[i] = a[j];
  a[j] = t;
}
void heapify(int i, int n) {
  int L = 2 * i;
  int R = 2 * i + 1;
  int minIdx = i;
  if (L <= n && a[L] -> score < a[minIdx] -> score) minIdx = L;
  if (R <= n && a[R] -> score < a[minIdx] -> score) minIdx = R;
  if (minIdx != i) {
    swap(i, minIdx);
    heapify(minIdx, n);
  }
}
void buildHeap() {
  for (int i = n / 2; i >= 1; i--) heapify(i, n);
}
void sort() {
  buildHeap();
  for (int i = n; i >= 2; i--) {
    swap(1, i);
    heapify(1, i - 1);
  }
}
void print() {
  for (int i = 1; i <= n; i++) {
    printf("%s %d\n", a[i] -> code, a[i] -> score);
  }
}
int main() {
  input();
  sort();
  print();
  return 0;
}
#sortcandicate
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define N 100001
typedef struct Candidate {
  int score;
  char code[10];
}
Candidate;
int n;
Candidate * a[N];
void input() {
  char code[11];
  n = 0;
  while (1) {
    scanf("%s", code);
    if (strcmp(code, "#") == 0) break;
    int score;
    scanf("%d", & score);
    n++;
    a[n] = (Candidate * ) malloc(sizeof(Candidate));
    a[n] -> score = score;
    strcpy(a[n] -> code, code);
  }
}
void swap(int i, int j) {
  Candidate * t = a[i];
  a[i] = a[j];
  a[j] = t;
}
void heapify(int i, int n) {
  int L = 2 * i;
  int R = 2 * i + 1;
  int minIdx = i;
  if (L <= n && a[L] -> score < a[minIdx] -> score) minIdx = L;
  if (R <= n && a[R] -> score < a[minIdx] -> score) minIdx = R;
  if (minIdx != i) {
    swap(i, minIdx);
    heapify(minIdx, n);
  }
}
void buildHeap() {
  for (int i = n / 2; i >= 1; i--) heapify(i, n);
}
void sort() {
  buildHeap();
  for (int i = n; i >= 2; i--) {
    swap(1, i);
    heapify(1, i - 1);
  }
}
void print() {
  for (int i = 1; i <= n; i++) {
    printf("%s %d\n", a[i] -> code, a[i] -> score);
  }
}
int main() {
  input();
  sort();
  print();
  return 0;
}
#sortstring
#include <stdio.h>
#include <string.h>

#define MAXN 100000
#define MAXLEN 105

char s[MAXN][MAXLEN];

void swap(char a[], char b[]) {
    char temp[MAXLEN];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void quickSort(int left, int right) {
    if (left >= right) return;

    int i = left, j = right;
    char pivot[MAXLEN];
    strcpy(pivot, s[(left + right) / 2]);

    while (i <= j) {
        while (strcmp(s[i], pivot) < 0) i++;
        while (strcmp(s[j], pivot) > 0) j--;

        if (i <= j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    if (left < j) quickSort(left, j);
    if (i < right) quickSort(i, right);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }

    quickSort(0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%s\n", s[i]);
    }

    return 0;
}
#tongcheck
#include <stdio.h>

#define N 1000001
int a[N];
int n, Q;
void input() {
  scanf("%d%d", & n, & Q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", & a[i]);
  }
}
void swap(int i, int j) {
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}
void heapify(int i, int n) {
  int L = 2 * i;
  int R = 2 * i + 1;
  int maxIdx = i;
  if (L <= n && a[maxIdx] < a[L]) maxIdx = L;
  if (R <= n && a[maxIdx] < a[R]) maxIdx = R;
  if (maxIdx != i) {
    swap(i, maxIdx);
    heapify(maxIdx, n);
  }
}
void buildHeap() {
  for (int i = n / 2; i >= 1; i--) heapify(i, n);
}
void heapSort() {
  buildHeap();
  for (int i = n; i >= 2; i--) {
    swap(1, i);
    heapify(1, i - 1);
  }
}
int bSearch(int i, int j, int k) {
  if (i > j) return -1;
  if (i == j) {
    if (a[i] == k) return i;
    else return -1;
  }
  int m = (i + j) / 2;
  if (a[m] == k) return m;
  if (a[m] < k) return bSearch(m + 1, j, k);
  else return bSearch(i, m - 1, k);
}
int main() {
  input();
  heapSort();
  int cnt = 0;
  for (int i = 1; i <= n - 1; i++) {
    int idx = bSearch(i + 1, n, Q - a[i]);
    if (idx > -1) cnt = cnt + 1;
  }
  printf("%d", cnt);
  return 0;
}
#sapxepcackitu
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int cmp(const void* a, const void* b)
{
    return strcmp((const char*)a, (const char*)b);
}

int main()
{
    int n;
    scanf("%d", &n);
    char arr[n][100];
    for (int i = 0; i<n; i++)
    {
        scanf("%s", arr[i]);
    }
    qsort(arr, n, sizeof(arr[0]), cmp);
    for (int i = 0; i<n; i++)
    {
        printf("%s\n", arr[i]);
    }
    return 0;
}
#sapxepcacbanghi
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char id[11];
    int grade;
} student;

int cmp(const void* a, const void* b)
{
    const student *x = (const student *)a;
    const student *y = (const student *)b;
    return (int*)y->grade - (int*)x->grade;
}

int main()
{
    int capacity = 2;          
    int n = 0;               
    student *arr = malloc(capacity * sizeof(student));

    while (1) {
        char temp_id[11];
        int temp_grade;

        scanf("%s", temp_id);

        if (strcmp(temp_id, "#") == 0)
            break;

        scanf("%d", &temp_grade);

        if (n == capacity) {
            capacity *= 2;
            arr = realloc(arr, capacity * sizeof(student));
        }

        strcpy(arr[n].id, temp_id);
        arr[n].grade = temp_grade;
        n++;
    }

    qsort(arr, n, sizeof(student), cmp);

    for (int i = 0; i < n; i++)
        printf("%s %d\n", arr[i].id, arr[i].grade);

    free(arr);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char id[11];
    int grade;
} student;

int cmp(const void* a, const void* b)
{
    const student *x = (const student *)a;
    const student *y = (const student *)b;
    return strcmp(x->id, y->id); 
}

int main()
{
    int n;
    scanf("%d", &n);

    student arr[n];

    for (int i = 0; i < n; i++)
        scanf("%s %d", arr[i].id, &arr[i].grade);

    qsort(arr, n, sizeof(student), cmp);

    for (int i = 0; i < n; i++)
        printf("%s %d\n", arr[i].id, arr[i].grade);

    return 0;
}
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

int cmp (const void* ptr1, const void* ptr2)
{
    int* x = (int*)ptr1;
    int* y = (int*)ptr2;
    return *x - *y;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int dim;

int cmp(const void* a, const void* b)
{
    const int *v1 = (const int *)a;
    const int *v2 = (const int *)b;
    for (int i = 0; i < dim; i++) 
    {
        if (v1[i] != v2[i])
            return v1[i] - v2[i];
    }
    return 0;
}


int main()
{
    int n;
    scanf("%d%d", &n, &dim);
    int arr[n][dim];
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<dim; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    qsort(arr, n, sizeof(arr[0]), cmp);

    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<dim; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
#demtutrongcau
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char text[100];
    int count;
} Word;

int main()
{
    char line[512];
    Word tu[1000];
    int n = 0;

    while (fgets(line, sizeof(line), stdin) != NULL)
    {
        line[strcspn(line, "\n")] = '\0';
        int len = strlen(line);

        for (int i = 0; i < len; i++)
        {
            if (!isalpha(line[i]))
                line[i] = ' ';
            else
                line[i] = tolower(line[i]);
        }


        char* token = strtok(line, " ");
        while (token != NULL)
        {
            int found = 0;
            for (int i = 0; i < n; i++)
            {
                if (strcmp(tu[i].text, token) == 0)
                {
                    tu[i].count++;
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                strcpy(tu[n].text, token);
                tu[n].count = 1;
                n++;
            }

            token = strtok(NULL, " ");
        }
    }


    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(tu[i].text, tu[j].text) > 0)
            {
                Word tmp = tu[i];
                tu[i] = tu[j];
                tu[j] = tmp;
            }

    for (int i = 0; i < n; i++)
        printf("%s %d\n", tu[i].text, tu[i].count);

    return 0;
}
#sapxepcacsinhvien
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 64

int cmpStr(const void* a, const void* b) 
{
    return strcmp((char*)a, (char*)b);
}

typedef struct in4
{
    char ten[MAX];
    char mssv[MAX];
}in4;

in4 ds[1000];
int n = 0;

int cmpMSSV(const void* a, const void* b) 
{
    in4* x = (in4*)a;
    in4* y = (in4*)b;
    return strcmp(x->mssv, y->mssv);
}


void nhapchuoi()
{
    char line[256];
    while (1)
    {
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, "end.") == 0) break;
        char* sv = strtok(line, ";");
        while (sv != NULL) 
        {
            char* comma = strchr(sv, ',');
            if (comma != NULL) 
            {
                *comma = '\0';
                strcpy(ds[n].ten, sv);
                strcpy(ds[n].mssv, comma + 1);
                n++;
            }
            sv = strtok(NULL, ";");
        }
    }
}

char* layTen(char* hoten) 
{
    char* lastSpace = strrchr(hoten, ' ');
    if (lastSpace == NULL)
        return hoten;        
    return lastSpace + 1;    
}


void timTen() 
{
    char key[MAX];

    while (1) 
    {
        fgets(key, sizeof(key), stdin);
        key[strcspn(key, "\n")] = '\0';

        if (strcmp(key, "end.") == 0) break;

        int found = 0;
        for (int i = 0; i < n; i++) 
        {
            char* ten = layTen(ds[i].ten);
            if (strcmp(ten, key) == 0) 
            {
                printf("%s\n", ds[i].mssv);
                found = 1;
            }
        }
        if (!found)
            printf("Khong thay\n");
    }
}



int main() 
{
    nhapchuoi();
    timTen();
    qsort(ds, n, sizeof(in4), cmpMSSV);
    for (int i = 0; i < n; i++) 
    {
        printf("%s", ds[i].mssv);
        if (i < n - 1) printf(",");
    }
    return 0;
}

#all_stackqueue
#BFS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Graph using adjacency list
Node* adj[MAX];
int visited[MAX];

// Queue implementation
Node* head = NULL;
Node* tail = NULL;

Node* makeNewNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = v;
    newNode->next = NULL;
    return newNode;
}

int queueEmpty() {
    return head == NULL;
}

void push(int v) {
    Node* p = makeNewNode(v);
    if(queueEmpty()){
        head = tail = p;
    } else {
        tail->next = p;
        tail = p;
    }
}

int pop() {
    if(queueEmpty()) return -1;
    int v = head->value;
    Node* tmp = head;
    head = head->next;
    free(tmp);
    return v;
}

// Graph functions
Node* createGraphNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node* p = createGraphNode(v);
    p->next = adj[u];
    adj[u] = p;

    // For undirected graph, add reverse edge
    p = createGraphNode(u);
    p->next = adj[v];
    adj[v] = p;
}

// BFS function
void BFS(int start) {
    push(start);
    visited[start] = 1;

    while (!queueEmpty()) {
        int u = pop();
        printf("%d ", u);

        Node* p = adj[u];
        while (p != NULL) {
            if (!visited[p->value]) {
                push(p->value);
                visited[p->value] = 1;
            }
            p = p->next;
        }
    }
    printf("\n");
}

int main() {
    int n, m;
    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Nhap cac canh u v:\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("BFS bat dau tu dinh 0: ");
    BFS(0);

    return 0;
}

#bfs
#include <stdio.h>
#define MAX 1000
int N;
int visited[MAX][MAX];
int dist[MAX][MAX];

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1,  1, -2,  2,-2, 2,-1, 1};

typedef struct {
    int x, y;
} Point;

Point queue[MAX*MAX];
int front = 0, rear = 0;

int bfs(int r0, int c0, int r1, int c1) {
    front = rear = 0;
    queue[rear++] = (Point){r0, c0};
    visited[r0][c0] = 1;
    dist[r0][c0] = 0;

    while(front < rear) {
        Point p = queue[front++];
        if(p.x == r1 && p.y == c1) return dist[p.x][p.y];

        for(int i=0;i<8;i++){
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if(nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]){
                visited[nx][ny] = 1;
                dist[nx][ny] = dist[p.x][p.y] + 1;
                queue[rear++] = (Point){nx, ny};
            }
        }
    }
    return -1; // không thể đi (trong bài này luôn có thể)
}

int main() {
    int r0, c0, r1, c1;
    scanf("%d %d %d %d %d", &N, &r0, &c0, &r1, &c1);

    // reset visited và dist
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            visited[i][j] = 0, dist[i][j] = 0;

    int ans = bfs(r0, c0, r1, c1);
    printf("%d\n", ans);
    return 0;
}

#bfs_2

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

#conma


#include <stdio.h>
int grid[100][100];
int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(int x, int y, int m, int n, int grid[100][100]){
    grid[x][y] = 0;
    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if( nx >= 0 && ny >= 0 && grid[nx][ny] == 1)
            dfs(nx,ny,m,n,grid);
    }

}
int main(){
    int m,n;
    scanf("%d %d", &m,&n);
    for(int i = 0; i < m;i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &grid[i][j]);
        }
    }
    int count = 0;
    for(int i = 0; i < m;i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                count++;
                dfs(i,j,m,n,grid);
            }
        }
    }
    printf("%d\n", count);

}

#dfs

#include <stdio.h>
int grid[100][100];
int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(int x, int y, int m, int n, int grid[100][100]){
    grid[x][y] = 0;
    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if( nx >= 0 && ny >= 0 && grid[nx][ny] == 1)
            dfs(nx,ny,m,n,grid);
    }

}
int main(){
    int m,n;
    scanf("%d %d", &m,&n);
    for(int i = 0; i < m;i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &grid[i][j]);
        }
    }
    int count = 0;
    for(int i = 0; i < m;i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                count++;
                dfs(i,j,m,n,grid);
            }
        }
    }
    printf("%d\n", count);

}
#dfs_2
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int r, c, step;
} Node;

int dr[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int dc[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };

int visited[1000][1000];

int main() {
    int N, r0, c0, r1, c1;
    scanf("%d %d %d %d %d", &N, &r0, &c0, &r1, &c1);

    // Hàng đợi BFS
    Node queue[1000000];
    int front = 0, rear = 0;

    queue[rear++] = (Node){r0, c0, 0};
    visited[r0][c0] = 1;

    while (front < rear) {
        Node cur = queue[front++];

        // Nếu tới đích
        if (cur.r == r1 && cur.c == c1) {
            printf("%d", cur.step);
            return 0;
        }

        // Thử 8 hướng đi
        for (int i = 0; i < 8; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc]) {
                visited[nr][nc] = 1;
                queue[rear++] = (Node){nr, nc, cur.step + 1};
            }
        }
    }

    return 0;
}
#dfs
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct StackNode {
    int value;
    struct StackNode* next;
} StackNode;

// Stack functions
StackNode* top = NULL;

StackNode* makeNode(int v) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->value = v;
    newNode->next = NULL;
    return newNode;
}

int stackEmpty() {
    return top == NULL;
}

void push(int v) {
    StackNode* p = makeNode(v);
    p->next = top;
    top = p;
}

int pop() {
    if (stackEmpty()) return -1;
    int v = top->value;
    StackNode* temp = top;
    top = top->next;
    free(temp);
    return v;
}

// Graph using adjacency list
Node* adj[MAX];
int visited[MAX];

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node* p = createNode(v);
    p->next = adj[u];
    adj[u] = p;

    // For undirected graph, add the reverse edge
    p = createNode(u);
    p->next = adj[v];
    adj[v] = p;
}

void DFS(int start) {
    push(start);

    while (!stackEmpty()) {
        int u = pop();
        if (!visited[u]) {
            visited[u] = 1;
            printf("%d ", u);

            // Push neighbors to stack
            Node* p = adj[u];
            while (p != NULL) {
                if (!visited[p->value])
                    push(p->value);
                p = p->next;
            }
        }
    }
}

int main() {
    int n, m;
    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Nhap cac canh u v:\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("DFS bat dau tu dinh 0: ");
    DFS(0);
    printf("\n");

    return 0;
}

#dngoac
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char value;
    struct Node* next;
} Node;

Node* top = NULL;

Node* makeNode(char x){
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = x;
    p->next = NULL;
    return p;
}

void push(char x){
    Node* p = makeNode(x);
    p->next = top;
    top = p;
}

bool stackEmpty(){
    return top == NULL;
}

char pop(){
    if(stackEmpty()) return '\0';
    Node* p = top;
    char x = p->value;
    top = top->next;
    free(p);
    return x;
}

bool match(char a, char b){
    return (a=='(' && b==')') ||
           (a=='[' && b==']') ||
           (a=='{' && b=='}');
}

bool check(char *s){
    for(int i = 0; s[i]; i++){
        char c = s[i];

        if(c=='(' || c=='[' || c=='{'){
            push(c);
        } else {
            if(stackEmpty()) return false;
            char a = pop();
            if(!match(a, c)) return false;
        }
    }
    return stackEmpty();
}

int main(){
    static char s[1000005];
    scanf("%s", s);

    printf("%d", check(s) ? 1 : 0);
    return 0;
}
#dongngoac
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_t{
    int value;
    struct node_t* next;
} Node;
Node* top = NULL;
Node* makeNode(int v){
    Node* new = (Node*)malloc(sizeof(Node));
    new->value = v;
    new->next = NULL;
    return new;

}

int stackEmpty(){
    if(top == NULL) return 1;
    else return 0;
}
void push(int v){
    Node* p = makeNode(v);
    p->next = top;
    top = p;
}
int pop(){
    if(stackEmpty()){
        return -1;
    }
    Node* tmp = top;
    int v = top->value;
    top = top->next;
    free(tmp);
    return v;
}
int match(char a, char b){
    if(a == '(' && b == ')' ) return 1;
    if(a == '[' && b == ']' ) return 1;
    if(a == '{' && b == '}' ) return 1;
    return 0;
}
int check(char* s){
    for(int i = 0; i < strlen(s); i++){
        char c = s[i];
        if( c =='(' || c=='[' || c=='{'){
            push(c);
        } else {
            if(stackEmpty()) return 0;
            char a = pop();
            if(!match(a, c)) return 0;
        }
    }
    return stackEmpty();
}

int main(){
    char s[1000];
    scanf("%s", s);
    printf("%d", check(s) ? 1 : 0);
    return 0;
}
#dongngoac_1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_t{
    int value;
    struct node_t* next;
} Node;
Node* top = NULL;
Node* makeNode(int v){
    Node* new = (Node*)malloc(sizeof(Node));
    new->value = v;
    new->next = NULL;
    return new;

}

int stackEmpty(){
    if(top == NULL) return 1;
    else return 0;
}
void push(int v){
    Node* p = makeNode(v);
    p->next = top;
    top = p;
}
int pop(){
    if(stackEmpty()){
        return -1;
    }
    Node* tmp = top;
    int v = top->value;
    top = top->next;
    free(tmp);
    return v;
}
int match(char a, char b){
    if(a == '(' && b == ')' ) return 1;
    if(a == '[' && b == ']' ) return 1;
    if(a == '{' && b == '}' ) return 1;
    return 0;
}
int check(char* s){
    for(int i = 0; i < strlen(s); i++){
        char c = s[i];
        if( c =='(' || c=='[' || c=='{'){
            push(c);
        } else {
            if(stackEmpty()) return 0;
            char a = pop();
            if(!match(a, c)) return 0;
        }
    }
    return stackEmpty();
}

int main(){
    char s[1000];
    scanf("%s", s);
    printf("%d", check(s) ? 1 : 0);
    return 0;
}
#include <stdio.h>
#include <string.h>

#define MAX 1000006

char stack[MAX];
int top = -1;

int isValid(char* s) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;   // push
        } else {
            if (top == -1) return 0; // stack rỗng, gặp dấu đóng
            char open = stack[top];
            if ((c == ')' && open == '(') ||
                (c == ']' && open == '[') ||
                (c == '}' && open == '{')) {
                top--;  // pop
            } else {
                return 0; // không khớp
            }
        }
    }
    return top == -1; // nếu stack rỗng → đúng
}

int main() {
    char s[MAX];
    scanf("%s", s);
    printf("%d\n", isValid(s));
    return 0;
}
#hangdoi
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
#


#include <stdio.h>
#include <string.h>
typedef struct {
    char name[30];
    char tel[15];
    char email[40];
} elementtype;
void removeNewline(char *s) {
    s[strcspn(s, "\n")] = '\0';
}

elementtype readData() {
    elementtype res;

    printf("name: ");
    fgets(res.name, sizeof(res.name), stdin);
    removeNewline(res.name);

    printf("tel: ");
    fgets(res.tel, sizeof(res.tel), stdin);
    removeNewline(res.tel);

    printf("email: ");
    fgets(res.email, sizeof(res.email), stdin);
    removeNewline(res.email);

    return res;
}

void printData(elementtype res) {
    printf("%15s\t%10s\t%20s\n", res.name, res.tel, res.email);
}
#nganxep1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_t{
    int value;
    struct node_t* next;

}Node;
Node* top;

Node* makeNewNode(int v){
    Node* new = (Node*)malloc(sizeof(Node));
    new->value = v;
    new->next = NULL;
    return new;
}
int stackEmpty(){
    return top == NULL;
}
void push(int v){
    Node* p = makeNewNode(v);
    p->next = top;
    top = p;
}
int pop(){
    if(stackEmpty()){
        return -1;
    }
    int v = top->value;
    Node* tmp;
    tmp = top;
    top = top->next;
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
                if(stackEmpty()) printf("NULL\n");
                else{
            int v = pop();
            printf("%d\n", v);
        }}}
        return 0;
}
#nganxep_1


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_t{
    int value;
    struct node_t* next;
} Node;
Node* top;
Node* makeNode(int v){
    Node* new = (Node*)malloc(sizeof(Node));
    new->value = v;
    new->next = NULL;
    return new;

}
void initStack(){
    top = NULL;
}

int stackEmpty(){
    if(top == NULL) return 1;
    else return 0;
}
void push(int x){
    Node* p = makeNode(x);
    p->next = top;
    top = p;
}
int pop(){
    if(stackEmpty()){
        return -1;
    }
    int x = top->value;
    Node* p = top;
    top = top->next;
    free(p);
    return x;
}
int main() {
  char cmd[50];
  while (1) {
    scanf("%s", cmd);
    if (strcmp(cmd, "#") == 0) {
      break;
    } else if (strcmp(cmd, "PUSH") == 0) {
      int v;
      scanf("%d", & v);
      push(v);
    } else if (strcmp(cmd, "POP") == 0) {
      if (stackEmpty()) {
        printf("NULL\n");
      } else {
        int v = pop();
        printf("%d\n", v);
      }
    }
  }
  return 0;
}
#nhap
 #include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char key;
    struct Node* left;
    struct Node* right;
} Node;

Node* makeNode(char key){
    Node* p = (Node*)malloc(sizeof(Node));
    p->key = key;
    p->left = p->right = NULL;
    return p;
}

Node* insert(Node* root, char key){
    if (root == NULL) return makeNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

Node* findMin(Node* root){
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, char key){
    if (root == NULL) return NULL;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void postOrder(Node* root){
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->key);
}

/* optional: free whole tree to avoid memory leak */
void freeTree(Node* root){
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(){
    Node* root = NULL;
    char cmd[20], key;

    while (1){
        if (scanf("%s", cmd) != 1) break;
        if (strcmp(cmd, "#") == 0) break;

        /* read key character (skipping whitespace) */
        if (scanf(" %c", &key) != 1) break;

        if (strcmp(cmd, "insert") == 0){
            root = insert(root, key);
        } else if (strcmp(cmd, "delete") == 0 || strcmp(cmd, "del") == 0){
            root = deleteNode(root, key);
        } else {
            /* nếu có lệnh khác: bỏ qua hoặc thông báo (ở đây ta bỏ qua) */
        }
    }

    if (root == NULL)
        printf("NULL\n");
    else {
        postOrder(root);
        printf("\n");
    }

    freeTree(root);
    return 0;
}

#ship
#include <stdio.h>
#include <math.h>

#define MAXN 10000

int n;
long long D2;
int x[MAXN + 1], y[MAXN + 1];
int visited[MAXN + 1];
int dist[MAXN + 1];
int queue[MAXN + 1];

int main() {
    int D;
    scanf("%d %d", &n, &D);
    D2 = 1LL * D * D;

    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
        visited[i] = 0;
        dist[i] = -1;
    }

    // BFS
    int front = 0, back = 0;
    queue[back++] = 1;
    visited[1] = 1;
    dist[1] = 0;

    while (front < back) {
        int u = queue[front++];

        if (u == n) break;

        for (int v = 1; v <= n; v++) {
            if (!visited[v]) {
                long long dx = x[u] - x[v];
                long long dy = y[u] - y[v];
                if (dx * dx + dy * dy <= D2) {
                    visited[v] = 1;
                    dist[v] = dist[u] + 1;
                    queue[back++] = v;
                }
            }
        }
    }

    printf("%d\n", dist[n]);
    return 0;
}
#waterjug
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char cmd[20];
    int x, y;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

Node* newNode(char c[], int x, int y) {
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->cmd, c);
    p->x = x;
    p->y = y;
    p->next = NULL;
    return p;
}

void addCommand(char c[], int x, int y) {
    Node* p = newNode(c, x, y);
    if (head == NULL) head = tail = p;
    else {
        tail->next = p;
        tail = p;
    }
}

int main() {
    int a, b; 
    scanf("%d %d", &a, &b);

    while (1) {
        char op[20];
        scanf("%s", op);
        if (strcmp(op, "#") == 0) break;

        if (strcmp(op, "fill") == 0) {
            int x; scanf("%d", &x);
            addCommand(op, x, 0);
        }
        else if (strcmp(op, "empty") == 0) {
            int x; scanf("%d", &x);
            addCommand(op, x, 0);
        }
        else if (strcmp(op, "pour") == 0) {
            int x, y; scanf("%d %d", &x, &y);
            addCommand(op, x, y);
        }
    }

    int jug1 = 0, jug2 = 0;

    Node* cur = head;
    while (cur != NULL) {
        if (strcmp(cur->cmd, "fill") == 0) {
            if (cur->x == 1) jug1 = a;
            else jug2 = b;
        }
        else if (strcmp(cur->cmd, "empty") == 0) {
            if (cur->x == 1) jug1 = 0;
            else jug2 = 0;
        }
        else if (strcmp(cur->cmd, "pour") == 0) {
            int *from, *to, cap;
            if (cur->x == 1)  from = &jug1; 
            else from = &jug2; 

            if (cur->y == 1){
                    to = &jug1;
                    cap = a; 
                    }
            else{
                 to = &jug2; 
                 cap = b;
                }

            int canPour = cap - (*to);   
            if (*from <= canPour) {
                *to += *from;
                *from = 0;
            } else {
                *from -= canPour;
                *to = cap;
            }
        }
        cur = cur->next;
    }

    printf("%d %d\n", jug1, jug2);
    return 0;
}
#water_jug
#include <stdio.h>
#include <string.h>

#define MAX 905

typedef struct {
    int x, y, step;
} State;

int a, b, c;
int visited[MAX][MAX];
State queue[MAX * MAX];

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int bfs() {
    int front = 0, back = 0;
    queue[back++] = (State){0, 0, 0};
    visited[0][0] = 1;

    while (front < back) {
        State cur = queue[front++];
        int x = cur.x;
        int y = cur.y;
        int step = cur.step;

        if (x == c || y == c)
            return step;

        State next[6];

        // 1. Fill A
        next[0] = (State){a, y, step + 1};
        // 2. Fill B
        next[1] = (State){x, b, step + 1};
        // 3. Empty A
        next[2] = (State){0, y, step + 1};
        // 4. Empty B
        next[3] = (State){x, 0, step + 1};

        // 5. Pour A -> B
        int pour = (x < b - y) ? x : (b - y);
        next[4] = (State){x - pour, y + pour, step + 1};

        // 6. Pour B -> A
        pour = (y < a - x) ? y : (a - x);
        next[5] = (State){x + pour, y - pour, step + 1};

        for (int i = 0; i < 6; i++) {
            int nx = next[i].x;
            int ny = next[i].y;
            if (!visited[nx][ny]) {
                visited[nx][ny] = 1;
                queue[back++] = next[i];
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d %d", &a, &b, &c);

    if (c > a && c > b) {
        printf("-1\n");
        return 0;
    }

    if (c % gcd(a, b) != 0) {
        printf("-1\n");
        return 0;
    }

    memset(visited, 0, sizeof(visited));
    printf("%d\n", bfs());
    return 0;
}
#all_sudoku
#1
#include <stdio.h>
int X[9][10];
int mark_r[9][10];
int mark_c[9][10];
int mark_s[3][3][10];
int count = 0;
void solution(){
    count++;
}
int check( int r,int c, int v){
    if(mark_c[c][v]) return 0;
    if(mark_r[r][v]) return 0;
    if(mark_s[r][c][v]) return 0;
    return 1;
}
void init(){
    for(int v = 1; v <= 9; v++ ){
        for(int c = 0; c <= 8; c++) mark_c[c][v] = v;
        for(int r = 0; r <= 8; r++) mark_r[r][v] = v;
        for(int i = 0; i <= 2; i++)
            for(int j = 0; j = 2; j++) mark_s[i][j][v] = v;
    }
}
void try(int r,int c){
    if(X[r][c] > 0){
        if( c == 8 && r == 8 ) solution();
        else{
        if( c == 8 ) try(r+1, 0);
        else try(r , c + 1);
        return;
    }}
    for( int v = 1; v <= 9; v++){
        if(check(r,c,v)){
            X[r][c] = v;
            mark_r[r][v] = 1;
            mark_c[c][v] = 1;
            mark_s[r][c][v] = 1;
            if( r == 8 && c == 8) solution();
            else{
        if( c == 8 ) try(r+1, 0);
        else try(r , c + 1);

        }
        X[r][c] = 0;
            mark_r[r][v] = 0;
            mark_c[c][v] = 0;
            mark_s[r][c][v] = 0;
    }
}}

int main(){
    void init();
    for(int c = 0; c <= 8; c++ ){
        for(int r = 0; r <= 8; r++ ){
                int v;
            scanf("%d", &v);
            X[r][c] = v;
        }
    }
    try(0,0);
    printf("%d", count);
    return 0;

}
#2
#include <stdio.h>
int r,c;
int count = 0;
int X[10][10];
int mark_r[9][10];
int mark_c[9][10];
int mark_s[3][3][10];
void init(){
    for(int v = 1; v <= 9; v++){
        for(int r = 0; r <= 8; r++)
        mark_r[r][v] = 0;
    for(int c = 0; c <= 8; c++)
        mark_c[c][v] = 0;
    for(int i = 0; i <= 2; i++)
        for(int j = 0; j <= 2; j++) mark_s[i][j][v] = 0;

}
}
int check(int v,int r, int c){
    if(mark_r[r][v]) return 0;
    if(mark_c[c][v]) return 0;
    if(mark_s[r/3][c/3][v]) return 0;
    return 1;
}

void try(int r, int c){
    if(r == 9){
        count = 1;
        return;
    }

    int v = X[r][c];

    if(mark_r[r][v] > 1 || mark_c[c][v] > 1 || mark_s[r/3][c/3][v] > 1){
        return;
    }
    if(c == 8) try(r + 1, 0);
    else try(r, c + 1);
}

int main(){
    int n;
    int cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        init();
    for(int r = 0;r <= 8; r++){
            for(int c = 0; c <= 8; c++){
                int v;
                scanf("%d",&v);
                X[r][c] = v;
                if(v > 0){
                        mark_r[r][v] = 1; mark_c[c][v] = 1;
                mark_s[r/3][c/3][v] = 1;}}}
                count = 0;
                try(0,0);
                if(count > 0) printf("1");
                else printf("0");

    }

                return 0;
}

#3
#include <stdio.h>
int r,c;
int count;
int X[10][10];
int mark_r[9][10];
int mark_c[9][10];
int mark_s[3][3][10];
void init(){
    for(int v = 1; v <= 9; v++){
        for(int r = 0; r <= 8; r++)
        mark_r[r][v] = 0;
    for(int c = 0; c <= 8; c++)
        mark_c[c][v] = 0;
    for(int i = 0; i <= 2; i++)
        for(int j = 0; j <= 2; j++) mark_s[i][j][v] = 0;

}
}
int check(int v,int r, int c){
    if(mark_r[r][v]) return 0;
    if(mark_c[c][v]) return 0;
    if(mark_s[r/3][c/3][v]) return 0;
    return 1;
}
void solution(){
    count++;
}
void try(int r, int c){
        if(X[r][c] > 0){
            if ( r == 8 && c == 8) solution();
            else {
                if( c == 8 ) try(r + 1, 0);
                else try (r, c + 1);
            }
            return;
        }
        for( int v = 1; v <= 9; v++){
            if(check(v, r,c)){
                X[r][c] = v;
                mark_r[r][v] = 1;
                mark_c[c][v] = 1;
                mark_s[r/3][c/3][v] = 1;
                if( r == 8 && c == 8) solution();
                else{
                    if( c == 8 ) try(r + 1, 0);
                else try (r, c + 1);
                }
                mark_r[r][v] = 0;
                mark_c[c][v] = 0;
                mark_s[r/3][c/3][v] = 0;
                X[r][c] = 0;

            }
        }
}
int main(){
    init();
    for(int r = 0;r <= 8; r++){
            for(int c = 0; c <= 8; c++){
                int v;
                scanf("%d",&v);
                X[r][c] = v;
                if(v > 0){
                        mark_r[r][v] = 1; mark_c[c][v] = 1;
                mark_s[r/3][c/3][v] = 1;
}
}
}
count = 0;
try(0,0);
printf("%d",count);
return 0;
}
#all_tsp
#1
#include <stdio.h>
int n;
int d[100][100];
int x[100];
int mark[100];
int f;
int f_min;
int Cm;
int min[100];
int m;
int a[100];
int P[25][25];
int bestRoute[25];
int check(int v){
    if(mark[v] == 1) return 0;
    return 1;
}
int precedenceOK(int v, int k) {
    for (int y = 1; y <= n; y++) {
        if (P[v][y] && mark[y]) return 0;  }

    for (int x_ = 1; x_ <= n; x_++) {
        if (P[x_][v] && !mark[x_]) return 0;  }

    return 1;
}
void try(int k) {
    for (int v = 1; v <= n; v++) {
        if (!mark[v] && precedenceOK(v, k)) {
            x[k] = v;
            mark[v] = 1;
            f += d[x[k-1]][v];

            if (k == n) {
                int total = f + d[x[n]][x[1]];
                if (total < f_min) {
                    f_min = total;
                    for (int i = 1; i <= n; i++)
                        bestRoute[i] = x[i];
                }
            } else if (f + Cm * (n - k + 1) < f_min) {
                try(k + 1);
            }

            mark[v] = 0;
            f -= d[x[k-1]][v];
        }
    }
}
void input(){
    scanf("%d",&n);

    Cm = 10000000;
    for(int i = 1; i <= n; i++){
            for(int j =1; j <= n; j++){
                scanf("%d",&d[i][j]);
    if(i != j && d[i][j] < Cm) Cm = d[i][j];
    }
    }
    scanf("%d", &m);
     for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            P[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        P[x][y] = 1;
    }

    }
int main(){
    input();
    for(int v = 1; v <= n; v++) mark[v] = 0;
    x[1] = 1;
    mark[1] = 1;
    f = 0;
    f_min = 10000000;
    for (int s = 1; s <= n; s++) {
        for (int i = 1; i <= n; i++) mark[i] = 0;
        x[1] = s;
        mark[s] = 1;
        f = 0;
        try(2);
    }
    printf("%d\n", n);
    for (int i = 1; i <= n; i++)
        printf("%d ", bestRoute[i]);


    return 0;
}
#2
#include <stdio.h>

int n; // so thanh pho
int d[100][100];
int x[100];
int mark[100];
int f; // do dai cua lo trinh di duoc
int f_min; // do dai lo trinh ngan nhat (ky luc)
int Cm;
void Try(int k) {
  for (int v = 1; v <= n; v++) {
    if (mark[v] == 0) {
      x[k] = v;
      f = f + d[x[k - 1]][v];
      mark[v] = 1;
      if (k == n) {
        if (f_min > f + d[x[n]][x[1]])
          f_min = f + d[x[n]][x[1]];
      } else {
        if (f + Cm * (n - k + 1) < f_min)
          Try(k + 1);
      }
      mark[v] = 0;
      f = f - d[x[k - 1]][v];
    }
  }
}
void input() {
  scanf("%d", & n);
  Cm = 10000000;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", & d[i][j]);
      if (i != j && d[i][j] < Cm) Cm = d[i][j];
    }
  }
}
int main() {
  input();
  for (int v = 1; v <= n; v++) mark[v] = 0;
  x[1] = 1;
  mark[1] = 1;
  f = 0;
  f_min = 10000000;
  Try(2);
  printf("%d", f_min);
  return 0;
}
#3
#include <stdio.h>

int n;
int d[25][25];
int x[25], mark[25];
int route[10000][25]; // lưu các đường đi tối ưu
int cnt = 0;          // số đường đi tối ưu
int f, f_min, Cm;

void saveRoute() {
    for (int i = 1; i <= n; i++)
        route[cnt][i] = x[i];
    cnt++;
}

void Try(int k) {
    for (int v = 2; v <= n; v++) { // v bắt đầu từ 2 vì 1 đã cố định
        if (!mark[v]) {
            x[k] = v;
            mark[v] = 1;
            f += d[x[k-1]][v];

            if (k == n) {
                int total = f + d[x[n]][x[1]];
                if (total < f_min) {        // tìm thấy giá trị nhỏ hơn
                    f_min = total;
                    cnt = 0;              // reset danh sách
                    saveRoute();
                } else if (total == f_min) { // bằng f_min → thêm phương án
                    saveRoute();
                }
            } else if (f + Cm * (n - k + 1) < f_min) {
                Try(k + 1);
            }

            mark[v] = 0;
            f -= d[x[k-1]][v];
        }
    }
}

int main() {
    scanf("%d", &n);
    Cm = 10000000;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d", &d[i][j]);
            if (i != j && d[i][j] < Cm) Cm = d[i][j];
        }

    for (int i = 1; i <= n; i++) mark[i] = 0;

    x[1] = 1;        // luôn xuất phát từ 1
    mark[1] = 1;
    f = 0;
    f_min = 10000000;

    Try(2);

    printf("%d\n", f_min);
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d ", route[i][j]);
        printf("\n");
    }

    return 0;
}

