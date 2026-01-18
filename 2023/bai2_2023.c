#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[100];
int x[100];
int cnt = 0;
int n, S;
int tong = 0;
void solution(){
    int tong_check = 0;
    for(int i = 0; i < n; i++){
        tong_check = tong_check + a[i] * x[i];
    }
    if(tong_check == S) cnt++;
    return;
}
int check(int k, int v){
    if(tong + v * a[k] > S) return 0;
    else return 1;

}
void Try(int k){
    for(int v = 0; v <= S / a[k]; v++){
        if(check(k, v)){
            x[k] = v;
            tong = tong + a[k] * x[k];
            if( k == n - 1) solution();
            else Try(k+1);
            tong = tong - a[k] * x[k];
        }
    }
}
int main(){
    scanf("%d %d", &n, &S);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    Try(0);
    printf("%d", cnt);
    return 0;
}

