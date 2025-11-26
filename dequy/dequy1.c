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
