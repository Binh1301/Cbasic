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
