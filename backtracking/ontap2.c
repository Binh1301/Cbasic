#include <stdio.h>
int x[100];
int n;
int sum_1(int n){
    int sum = 0;
    for(int i = 0; i <= n; i++){
            sum += i;
    }
    return sum;
}
int check(int v, int k){
    int sum_n = sum_1(k);
    for(int i = 1; i < k; i++){
        if(x[i] == v) return 0;
    }
    return 1;
}
int solution(){
    for(int i = 1; i <= n; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
}
int Try( int k ){
    for( int v = 1; v <= n ; v++ ){
        if(check(v, k)){
           x[k] = v;
           if(k == n) solution();
           else Try( k + 1 );
        }
    }
}
int main(){
    scanf("%d", &n );
    Try(1);
    return 0;
}


