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

