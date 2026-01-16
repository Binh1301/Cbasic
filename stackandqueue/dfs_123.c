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
