#include <stdio.h>
int x[100];
int n;
int m;
int check(int v, int k){
    if(k < n) return 1;
    else if( k == n){
        int sum = v;
        for(int i = 1; i < k; i++){
            sum += x[i];
        }
        if(sum == m) return 1;
        else return 0;
    }
    else return 0;
}
int solution(){
    for(int i = 1; i <= n; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
}
int Try( int k ){
    for( int v = 1; v <= m ; v++ ){
        if(check(v, k)){
           x[k] = v;
           if(k == n) solution();
           else Try( k + 1 );
        }
    }

}
int main(){
    scanf("%d", &n );
    scanf("%d", &m);
    Try(1);
    return 0;
}


