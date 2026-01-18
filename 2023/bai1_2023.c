#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[3];
int luu[100];
int count = 0;
void check(int n, int a[]){
    for(int i = 0; i < n; i++){
        if(a[i] != a[i+1]) count+= 1;
    }
}
typedef struct lando{
    int ngay;
    char s[10];
    int change;
}lando;
lando ds[100];
int max = 0;
int max_1(int a[]){
    for(int i = 0; i < 3; i++){
        if(a[i] > max) max = a[i];
    }
    return max;
}
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %s %d", &ds[i].ngay, ds[i].s, &ds[i].change);
        if(strcmp(ds[i].s, "Vang") == 0) a[1] = a[1] + ds[i].change;
        if(strcmp(ds[i].s, "Sind") == 0) a[0] = a[0] + ds[i].change;
        if(strcmp(ds[i].s, "Jersey") == 0) a[2] = a[2] + ds[i].change;
        luu[i] = max_1(a);
    }
    check(N, a);
    printf("%d", count);
    return 0;
}
