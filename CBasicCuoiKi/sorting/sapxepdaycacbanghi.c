#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char id[11];
    int grade;
} student;

int cmp(const void* a, const void* b)
{
    const student *x = (const student *)a;
    const student *y = (const student *)b;
    return (int*)y->grade - (int*)x->grade;
}

int main()
{
    int capacity = 2;          
    int n = 0;               
    student *arr = malloc(capacity * sizeof(student));

    while (1) {
        char temp_id[11];
        int temp_grade;

        scanf("%s", temp_id);

        if (strcmp(temp_id, "#") == 0)
            break;

        scanf("%d", &temp_grade);

        if (n == capacity) {
            capacity *= 2;
            arr = realloc(arr, capacity * sizeof(student));
        }

        strcpy(arr[n].id, temp_id);
        arr[n].grade = temp_grade;
        n++;
    }

    qsort(arr, n, sizeof(student), cmp);

    for (int i = 0; i < n; i++)
        printf("%s %d\n", arr[i].id, arr[i].grade);

    free(arr);
    return 0;
}
