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


