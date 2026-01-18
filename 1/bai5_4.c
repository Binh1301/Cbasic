
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[100];
int x[100];
int n;
int max = 0;
int check_sum = 0;
int tong = 0;
int check(int k ,int v){
    if(tong + x[k] * v > n) return 0;
    return 1;
}
void solution(int k){
    int sum = 0;
    if( k == 2 ){
        for(int i = 0; i < 3; i++){
                sum = sum + a[i];
        }
        if(sum > max) max = sum;
    }
}
void Try(int k){
    for(int v = 0; v <= n ; v++){
        if(check(k, v)){
            a[k] = v;
            tong = tong + x[k] * v;
            if(k == 2) solution(k);
            else Try(k+1);
            tong = tong - x[k] * v;
        }
    }

}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < 3; i++){
        scanf("%d", &x[i]);
    }
    Try(0);
    printf("%d", max);
    return 0;


}

