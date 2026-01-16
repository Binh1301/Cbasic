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
