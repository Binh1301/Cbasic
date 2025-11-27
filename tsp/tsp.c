#include <stdio.h>
int n;
int d[100][100];
int x[100];
int mark[100];
int f;
int f_min;
int Cm;
int min[100];
int m;
int a[100];
int P[25][25];
int bestRoute[25];
int check(int v){
    if(mark[v] == 1) return 0;
    return 1;
}
int precedenceOK(int v, int k) {
    for (int y = 1; y <= n; y++) {
        if (P[v][y] && mark[y]) return 0;  }

    for (int x_ = 1; x_ <= n; x_++) {
        if (P[x_][v] && !mark[x_]) return 0;  }

    return 1;
}
void try(int k) {
    for (int v = 1; v <= n; v++) {
        if (!mark[v] && precedenceOK(v, k)) {
            x[k] = v;
            mark[v] = 1;
            f += d[x[k-1]][v];

            if (k == n) {
                int total = f + d[x[n]][x[1]];
                if (total < f_min) {
                    f_min = total;
                    for (int i = 1; i <= n; i++)
                        bestRoute[i] = x[i];
                }
            } else if (f + Cm * (n - k + 1) < f_min) {
                try(k + 1);
            }

            mark[v] = 0;
            f -= d[x[k-1]][v];
        }
    }
}
void input(){
    scanf("%d",&n);

    Cm = 10000000;
    for(int i = 1; i <= n; i++){
            for(int j =1; j <= n; j++){
                scanf("%d",&d[i][j]);
    if(i != j && d[i][j] < Cm) Cm = d[i][j];
    }
    }
    scanf("%d", &m);
     for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            P[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        P[x][y] = 1;
    }

    }
int main(){
    input();
    for(int v = 1; v <= n; v++) mark[v] = 0;
    x[1] = 1;
    mark[1] = 1;
    f = 0;
    f_min = 10000000;
    for (int s = 1; s <= n; s++) {
        for (int i = 1; i <= n; i++) mark[i] = 0;
        x[1] = s;
        mark[s] = 1;
        f = 0;
        try(2);
    }
    printf("%d\n", n);
    for (int i = 1; i <= n; i++)
        printf("%d ", bestRoute[i]);


    return 0;
}
