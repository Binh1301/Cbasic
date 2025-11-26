#include <stdio.h>
int n, m;
int a[1000];
int x[1000];
int max = 0;
int check(int k, int v){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += a[i] * x[i];
    }
    if(sum == m) return 1;
    else return 0;
}
void solution(int k, int v){
    if(check(k, v)){
            int tich = 1;
        for(int i = 1; i <= n; i++){

            tich = tich * x[i];
        }
        if(tich > max) max = tich;
    }
}
int try(int k){
    for(int v = 0; v <= m; v++){
        x[k] = v;
        if(k == n) solution(k,v);
        else try(k+1);
}}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    try(1);
    if(max == 0) printf("None");
    else  printf("%d", max);
    return 0;

}

