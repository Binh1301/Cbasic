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

