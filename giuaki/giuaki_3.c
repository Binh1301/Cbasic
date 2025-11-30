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
