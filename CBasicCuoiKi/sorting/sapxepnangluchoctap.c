#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char id[11];
    int grade;
} student;

int cmp(const void* a, const void* b)
{
    const student *x = (const student *)a;
    const student *y = (const student *)b;
    return strcmp(x->id, y->id); 
}

int main()
{
    int n;
    scanf("%d", &n);

    student arr[n];

    for (int i = 0; i < n; i++)
        scanf("%s %d", arr[i].id, &arr[i].grade);

    qsort(arr, n, sizeof(student), cmp);

    for (int i = 0; i < n; i++)
        printf("%s %d\n", arr[i].id, arr[i].grade);

    return 0;
}
