#include <stdio.h>
#define N 100
int n;
int x[N];
int mark[N];
int markD1[N];
int markD2[N];
int count = 0;
void init(){
    for(int i = 0; i  <= N; i++) mark[i] = 0;
    for(int i = 0; i  <= 2*N; i++) markD1[i] = 0;
    for(int i = 0; i  <= 2*N; i++) markD2[i] = 0;
    scanf("%d", &n);
    for(int i = 0; i <=n ; i++){
        for(int j = 0; j <= n; j++){
            int e;
            scanf("%d", &e);
            if( e > 0 ){ mark[j] = i;
            markD2[ i + j] = 1;
            markD1[n + j - i ] = 1;}
        }
    }
}
void solution(){
    count++;
}
int check(int v, int k){
    if(mark[v] == 1) return 0;
    if(markD1[n + v - k] == 1) return 0;
    if(markD2[v + k] == 1) return 0;
    return 1;
}
void try(int k){
    if( x[k] > 0){
        if( k == 8 ) solution();
            else try(k+1);
    }
    for(int r = 1; r <= n; r++ ){
        if(check(r,k)){
            x[k] = r;
            mark[r] = 1;
            markD1[ n + r - k] = 1;
            markD2[ r + k ] = 1;
            if( k == 8) solution();
            else try(k+1);
            x[k] = 0;
            mark[r] = 0;
            markD1[ n + r - k] = 0;
            markD2[ r + k ] = 0;
        }
    }


}
int main(){
    init();
    count = 0;
    try(1);
    printf("%d",count);
    return 0;
}
