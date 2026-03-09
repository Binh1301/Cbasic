#1
#include <stdio.h>
int F(int a, int b){
    if( a == b ) return a;
    else if( a < b) return F(a, b - a);
    else return F(a - b, b);
}
int main(){
    int a,b;
    scanf("%d %d", &a,&b);
    int c = F(a,b);
    printf("%d", c);
    return 0;

}
#2  
#include <stdio.h>
void convert(int N){
    if (N == 0) return;
    convert(N/2);
    int b = N % 2;
    printf("%d", b);
}
int main(){
    int a;
    scanf("%d", &a);
    convert(a);
    return 0;

}

#3
#include <stdio.h>
#define P 1000000007
int M[1000][1000] = {0};
int C(int k, int n){
    if( k == 0 || k == n) M[k][n] = 1;
    else{
        if ( M[k][ n] == 0 ){
            M[ k][ n] = C(k-1,n-1) + C(k, n -1);
        }

    }
    return M[k][n];
}
int main(){

int k,n; scanf("%d %d",&k,&n); printf("%d",C(k,n));
return 0;

}


