#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void*a,const void*b){
    return *(int*)a - *(int*)b;
}
int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    int a[1000];
    int x[1000];
    for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            x[i] = a[i];}

    qsort(a,n,sizeof(int), cmp);
    for (int i = 0; i < n; i++){
        if(a[i] != x[i]) cnt++;}
    printf("%d", cnt);
    return 0;
}

