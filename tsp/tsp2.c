#include <stdio.h>

int n;
int d[25][25];
int x[25], mark[25];
int route[10000][25]; // lưu các đường đi tối ưu
int cnt = 0;          // số đường đi tối ưu
int f, f_min, Cm;

void saveRoute() {
    for (int i = 1; i <= n; i++)
        route[cnt][i] = x[i];
    cnt++;
}

void Try(int k) {
    for (int v = 2; v <= n; v++) { // v bắt đầu từ 2 vì 1 đã cố định
        if (!mark[v]) {
            x[k] = v;
            mark[v] = 1;
            f += d[x[k-1]][v];

            if (k == n) {
                int total = f + d[x[n]][x[1]];
                if (total < f_min) {        // tìm thấy giá trị nhỏ hơn
                    f_min = total;
                    cnt = 0;              // reset danh sách
                    saveRoute();
                } else if (total == f_min) { // bằng f_min → thêm phương án
                    saveRoute();
                }
            } else if (f + Cm * (n - k + 1) < f_min) {
                Try(k + 1);
            }

            mark[v] = 0;
            f -= d[x[k-1]][v];
        }
    }
}

int main() {
    scanf("%d", &n);
    Cm = 10000000;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d", &d[i][j]);
            if (i != j && d[i][j] < Cm) Cm = d[i][j];
        }

    for (int i = 1; i <= n; i++) mark[i] = 0;

    x[1] = 1;        // luôn xuất phát từ 1
    mark[1] = 1;
    f = 0;
    f_min = 10000000;

    Try(2);

    printf("%d\n", f_min);
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d ", route[i][j]);
        printf("\n");
    }

    return 0;
}

