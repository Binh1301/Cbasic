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