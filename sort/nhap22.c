#include <stdio.h>
void quicksort(int a[], int l, int r){
    int i = l;
    int j = r;
    int p = a[ (l + r) / 2];
    while( i <= j){
        while(a[i] < p) i++;
        while(a[j] > p) j--;
        if( i <= j){
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }
    if(l < j) quicksort(a,l,j);
    if(i < r) quicksort(a,i,r);

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


    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++){
        if(a[i] != x[i]) cnt++;}
    printf("%d", cnt);
    return 0;
}
