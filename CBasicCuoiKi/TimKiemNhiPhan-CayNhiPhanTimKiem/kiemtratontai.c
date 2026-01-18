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


void check(int k)
{
    if (k==-1) printf("0\n");
    else printf("1\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmp);
    for (int i = 0; i< n; i++) printf("%d", arr[i]);
    printf("\n");
    while (1)
    {
        char line[10];
        scanf("%s", line);
        if (strcmp(line, "#")==0) break;
        if (strcmp(line, "check")==0)
        {
            int y;
            scanf("%d", &y);
            check(btimkiem(arr, 0, n-1, y));
        }
    }
    return 0;
}