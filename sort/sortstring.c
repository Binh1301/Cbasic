#include <stdio.h>
#include <string.h>

#define MAXN 100000
#define MAXLEN 105

char s[MAXN][MAXLEN];

void swap(char a[], char b[]) {
    char temp[MAXLEN];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void quickSort(int left, int right) {
    if (left >= right) return;

    int i = left, j = right;
    char pivot[MAXLEN];
    strcpy(pivot, s[(left + right) / 2]);

    while (i <= j) {
        while (strcmp(s[i], pivot) < 0) i++;
        while (strcmp(s[j], pivot) > 0) j--;

        if (i <= j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    if (left < j) quickSort(left, j);
    if (i < right) quickSort(i, right);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }

    quickSort(0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%s\n", s[i]);
    }

    return 0;
}
