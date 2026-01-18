#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int btimkiem(int arr[], int L, int R, int k)
{
    if (L>R) return -1;
    if (L==R)
    {
        if (arr[L] == k) return L;
        else return -1;
    }
    int m = (L+R)/2;
    if (arr[m]==k) return m;
    if (arr[m]<k) return btimkiem(arr, m+1, R, k);
    return btimkiem(arr, L, m-1, k);
}

int cmp(const void* a, const void* b)
{
    int* x = (int*)a;
    int* y = (int*)b;
    return *x-*y;
}

int main()
{
    int n, Q;
    scanf("%d%d", &n, &Q);
    int arr[n];
    for (int i = 0; i<n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp);
    int cnt = 0;
    for (int i = 1; i<n-1; i++)
    {
        int idx = btimkiem(arr, i, n-1, Q-arr[i]);
        if (idx > -1) cnt++;
    }
    printf("%d", cnt);
    return 0;
}

