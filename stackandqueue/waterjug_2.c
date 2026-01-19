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