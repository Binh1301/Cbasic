#include <stdio.h>
#define N 100
int n;
int m;
int x[100];
int mark[100];
int markD1[100];
int markD2[100];
int cnt;
int check(int v, int k){
    if(mark[v] == 1) return 0;
    if(markD1[n + k - v] == 1) return 0;
    if(markD2[k + v] == 1) return 0;
    return 1;
}
void Try(int k){
    if(x[k] > 0){
        if(k == n) cnt++;
        else Try(k+1);
        return;
    }
    for(int r = 1; r <= n; r++){
        if(check(r,k)){
                x[k] = r; mark[r] = 1;
                markD1[n+ k - r] = 1;
                markD2[k + r] = 1;
                if(k == n) cnt += 1;
                else Try(k+1);
                x[k] = 0;
                mark[r] = 0;
                markD1[n+ k - r] = 0;
                markD2[k + r] = 0;

        }
    }
}


void input(){
    for(int i = 1; i < N; i++) mark[i] = 0;
    for(int i = 0; i < 2*N; i++){ markD1[i] = 0; markD2[i] = 0; }

    scanf("%d",&n);
    scanf("%d",&m);

    for(int i = 1; i <= n; i++) x[i] = 0;

    for(int j = 1; j <= m; j++){
        int r, c;
        scanf("%d %d", &r, &c);

        x[c] = r;                        // ✔ cột c đặt queen ở hàng r
        mark[r] = 1;                     // ✔ đánh dấu hàng r
        markD1[n + c - r] = 1;           // ✔ đường chéo chính
        markD2[c + r] = 1;               // ✔ đường chéo phụ
    }
}


int main(){
    input();
    cnt = 0;
    Try(1);
    printf("%d",cnt);
    return 0;
}


