#include <stdio.h>
#include <string.h>

char arr[500][81];

void heapify(int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && strcmp(arr[l], arr[largest]) > 0)
        largest = l;

    if (r < n && strcmp(arr[r], arr[largest]) > 0)
        largest = r;

    if (largest != i) {
        char tmp[81];
        strcpy(tmp, arr[i]);
        strcpy(arr[i], arr[largest]);
        strcpy(arr[largest], tmp);

        heapify(n, largest);
    }
}

void heapSort(int n){

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    
    for (int i = n - 1; i > 0; i--) {
        char tmp[81];
        strcpy(tmp, arr[0]);
        strcpy(arr[0], arr[i]);
        strcpy(arr[i], tmp);

        heapify(i, 0);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%s", arr[i]);

    heapSort(n);

    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);

    return 0;
}

