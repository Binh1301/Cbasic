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

