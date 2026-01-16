#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char code[11];
    int score;
} candidate;

candidate a[100000];
int n = 0;

int cmp(const void *x, const void *y) {
    const candidate *a = x;
    const candidate *b = y;
    if (a->score < b->score) return 1;
    if (a->score > b->score) return -1;
    return 0;
}

int main() {
    char tmp[20];

    while (1) {
        if (scanf("%s", tmp) != 1) break;
        if (strcmp(tmp, "#") == 0) break;

        strcpy(a[n].code, tmp);
        scanf("%d", &a[n].score);
        n++;
    }

    qsort(a, n, sizeof(candidate), cmp);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", a[i].code, a[i].score);
    }

    return 0;
}
