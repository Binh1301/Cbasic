#include <stdio.h>

int n;
int x[20];
int mark[20];
char c;

int check(int v, int k){
    return 1;
}
void solution(){
    printf("%c", c);
    for(int i = 1; i <= n; i++)
        printf("%d",x[i]);
    printf("\n");

}
int Try(int k ){
    for(int v = 1; v <= 5; v = v + 2){
        if( check(v ,k )){
            x[k] = v;
            if( k == n ) solution();
            else Try(k + 1);
        }
    }
}
int main(){

    scanf("%c", &c);
    scanf("%d",&n);
    for(int v = 1; v <= n; v++) mark[v] = 0;
    Try(1);
    return 0;
}

