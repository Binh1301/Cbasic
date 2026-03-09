#1
#include <stdio.h>
int x[100];
int n;
int m;
int Q;
int cnt = 0;
int sum = 0;

void solution(){
    cnt++;
}
void Try( int k, int solan ){
    if( solan == n){
        if(sum == Q) solution();
        return;
    }
    for( int v = k; v < m ; v++ ){
        if(sum + x[v] <= Q){
        sum += x[v];
        Try(v + 1, solan + 1);
        sum -= x[v];
        }
    }

}
int main(){
    scanf("%d %d %d", &m,&n,&Q);
    for(int i = 0; i < m; i++){
        scanf("%d", &x[i]);
    }
    Try(0,0);
    printf("%d", cnt);
    return 0;
}



#2
#include <stdio.h>

int x[100];
int n;

// Hàm kiểm tra chuỗi đã chứa 111 chưa
int has_111() {
    for(int i = 3; i <= n; i++){
        if(x[i] == 1 && x[i-1] == 1 && x[i-2] == 1) return 1;
    }
    return 0;
}

void solution(){
    if(has_111()){ // chỉ in những chuỗi có 111
        for(int i = 1; i <= n; i++){
            printf("%d", x[i]);
        }
        printf("\n");
    }
}

void Try(int k){
    for(int v = 0; v <= 1; v++){
        x[k] = v;
        if(k == n) solution();
        else Try(k + 1);
    }
}

int main(){
    scanf("%d", &n);
    Try(1);
    return 0;
}
#3
#include <stdio.h>

int a[10005];
int m, n, Q;
int cnt = 0;
int sum = 0;

void solution(){
    cnt++;
}

void Try(int pos, int k) {
    // pos: vị trí bắt đầu duyệt
    // k: số phần tử đã chọn

    if (k == n) {
        if (sum == Q) solution();
        return;
    }

    for (int i = pos; i < m; i++) {
        if (sum + a[i] <= Q) {
            sum += a[i];
            Try(i + 1, k + 1);
            sum -= a[i];   // backtrack
        }
    }
}

int main(){
    scanf("%d %d %d", &m, &n, &Q);
    for(int i = 0; i < m; i++){
        scanf("%d", &a[i]);
    }

    Try(0, 0);
    printf("%d", cnt);
    return 0;
}
#4

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
#5
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
#6
#include <stdio.h>
#define N 20
int n;
int x[N];
int mark[N];
int check( int v, int k){
    return mark[v] == 0;
}

void solution(){
    for( int i = 1; i <= n; i++){
        printf("%d ", x[i]);
    }

    printf("\n");
}
void Try(int k){
    for(int v = 1; v<= n; v++){
        if(check(v,k)){
                x[k] = v;
                mark[v] = 1;
                if( k == n) solution();
                else Try(k + 1);
                mark[v] = 0;
        }
    }


}
int main(){
scanf("%d",&n);
for(int v = 1; v <= n; v++) mark[v] = 0;
Try(1);
return 0;
}
#7
#include <stdio.h>
int x[100];
int n;
int m;
int check(int v, int k){
    if(k < n) return 1;
    else if( k == n){
        int sum = v;
        for(int i = 1; i < k; i++){
            sum += x[i];
        }
        if(sum == m) return 1;
        else return 0;
    }
    else return 0;
}
int solution(){
    for(int i = 1; i <= n; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
}
int Try( int k ){
    for( int v = 1; v <= m ; v++ ){
        if(check(v, k)){
           x[k] = v;
           if(k == n) solution();
           else Try( k + 1 );
        }
    }

}
int main(){
    scanf("%d", &n );
    scanf("%d", &m);
    Try(1);
    return 0;
}
#8
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
#9
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

