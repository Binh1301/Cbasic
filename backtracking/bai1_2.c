#include <stdio.h>
int x[100];
int n;
int m;
int Q;
int cnt = 0;
int sum = 0;

void solution(){
    cnt++;
}
void Try( int k, int solan ){
    if( solan == n){
        if(sum == Q) solution();
        return;
    }
    for( int v = k; v < m ; v++ ){
        if(sum + x[v] <= Q){
        sum += x[v];
        Try(v + 1, solan + 1);
        sum -= x[v];
        }
    }

}
int main(){
    scanf("%d %d %d", &m,&n,&Q);
    for(int i = 0; i < m; i++){
        scanf("%d", &x[i]);
    }
    Try(0,0);
    printf("%d", cnt);
    return 0;
}



