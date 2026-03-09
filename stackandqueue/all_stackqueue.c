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