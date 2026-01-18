#include <stdio.h>
#include <stdlib.h>


int btimkiem (int a[],int L, int R, int k)
{
    if (L>R) return -1;
    if (L==R)
    {
        if (a[L] == k) return L;
        else return -1;
    }
    int m=(L+R)/2;
    if (a[m] == k) return m;
    if (a[m] < k)
        return btimkiem(a, m+1, R, k);
    return btimkiem(a, L, m-1, k);
}

int main()
{
    int arr[] = {1, 1, 3, 5, 9};
    printf("%d", btimkiem(arr, 0, 4, 3));
    return 0;
}
