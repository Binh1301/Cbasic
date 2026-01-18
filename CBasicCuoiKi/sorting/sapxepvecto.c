#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int dim;

int cmp(const void* a, const void* b)
{
    const int *v1 = (const int *)a;
    const int *v2 = (const int *)b;
    for (int i = 0; i < dim; i++) 
    {
        if (v1[i] != v2[i])
            return v1[i] - v2[i];
    }
    return 0;
}


int main()
{
    int n;
    scanf("%d%d", &n, &dim);
    int arr[n][dim];
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<dim; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    qsort(arr, n, sizeof(arr[0]), cmp);

    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<dim; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}