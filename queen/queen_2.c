#include <stdio.h>
#define N 100
int n;
int x[N];
int mark[N];
int markD1[N];
int markD2[N];
int count;

int check(int v, int k){
    if(mark[v] == 1) return 0;
    if(markD1[n - k + v]) return 0;
    if(markD2[k + v]) return 0;
    return 1;
}
void solution(){
    count++;
}
void try(int k){
    if(x[k] > 0){
        if(k == n) solution();
        else try(k+1);
    }
    for(int v = 1; v <= n; v++){
        if(check(v,k)){
            x[k] = v;
            mark[v] = 1;
            markD1[n - k + v] = 1;
            markD2[k + v] = 1;
            if( k == n ) solution();
            else try(k+1);
            mark[v] = 0;
            markD1[n - k + v] = 0;
            markD2[k + v] = 0;
            x[k] = 0;

        }
    }
}
void input(){
    for(int i = 0; i < N; i++)
        mark[i] = 0;
    for(int j = 0; j < 2 * N; j++) {markD1[j] = 0; markD2[j] = 0;}
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) x[i] = 0;
    for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int e;
                scanf("%d", &e);
                if(e == 1){
                x[j] = i;
                mark[i] = 1;
                markD1[n - j + i] = 1;
                markD2[j + i] = 1;
            }
            }

    }


}
int main(){
    input();
    count = 0;
    try(0);
    printf("%d", count);
    return 0;




}
