#include <stdio.h>
int x[100];
int n;
int check(){
        for( int i = 3; i <= n; i++){
            if(x[i-1] == 1 && x[i-2] == 1 && x[i] == 1) return 1;
        }

    return 0;
}
void solution(){
    if(check()){
    for(int i = 1; i <= n; i++){
        printf("%d", x[i]);
    }
    printf("\n");
}}
int Try( int k ){
    for( int v = 0; v < 2; v++ ){

           x[k] = v;
           if(k == n) solution();
           else Try( k + 1 );

    }
}
int main(){
    scanf("%d", &n );
    Try(1);
    return 0;
}

