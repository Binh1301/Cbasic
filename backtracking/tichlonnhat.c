#include <stdio.h>

int x[100];
int n;
int m;
int a[100];
int tich = 1;
int max = 1;
int tong = 0;
int check(int k, int v){
    if(tong + a[k] * v > m) {
            return 0;

    }
    if (k == n - 1 && tong + a[k] * v != m)
    return 0;

    return 1;
}
void solution(){
    int prod = 1;
    for (int i = 0; i < n; i++)
        prod *= x[i];
    if (prod > max) max = prod;
}


void Try(int k){
    for(int v = 1; v <= m; v++){
        if(check(k ,v)){
            x[k] = v;
            tong += a[k] * v;
            if(k == n) solution();
            else Try(k + 1);
            tong -= a[k] * v;

        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    Try(0);
    printf("%d",max);
    return 0;

}
