#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

int cmp (const void* ptr1, const void* ptr2)
{
    int* x = (int*)ptr1;
    int* y = (int*)ptr2;
    return *x - *y;
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
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

