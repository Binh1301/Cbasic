
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sinhvien{
    int id;
    char s[10];
}sinhvien;
sinhvien ds[100];
int cmp(const void *a,const void *b){
    return ((sinhvien*)b)->id - ((sinhvien*)a)->id;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %s", &ds[i].id, ds[i].s);
    }
    qsort(ds,n,sizeof(sinhvien), cmp);
    for(int i = 0; i < n; i++){
        printf("%d %s", ds[i].id, ds[i].s);
        printf("\n");
    }
    return 0;
}
