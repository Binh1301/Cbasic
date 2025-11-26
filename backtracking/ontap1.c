#include <stdio.h>
int x[100];
int n;
int check(int v, int k){
    if ( k == 1) return 1;
    else if ( k > 1){
        if( v == 1 && x[k - 1 ] == 1) return 0;
        else return 1;
    }
}
int solution(){
    for(int i = 1; i <= n; i++){
        printf("%d", x[i]);
    }
    printf("\n");
}
int Try( int k ){
    for( int v = 0; v < 2; v++ ){
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

