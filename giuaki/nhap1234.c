#include <stdio.h>

int n, m;
int a[1000];
int x[1000];
int max = 0;

int check(){
    int sum = 0;
    for(int i = 1; i <= n; i++)
        sum += a[i] * x[i];
    return sum == m;
}

void solution(){
    int tich = 1;
    for(int i = 1; i <= n; i++)
        tich *= a[i];   // nếu đây là ý bạn
    if(tich > max) max = tich;
}

void Try(int k){
    for(int v = 0; v <= m; v++){
        x[k] = v;
        if(k == n){
            if(check()) solution();
        } else Try(k+1);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    Try(1);

    if(max == 0) printf("None");
    else printf("%d", max);
    return 0;
}

