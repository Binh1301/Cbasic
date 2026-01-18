#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char code[9];
    int score;
} Sinhvien;

Sinhvien ds[100000];
int cnt = 0;

int cmp(const void *a, const void *b) {
    Sinhvien *x = (Sinhvien *)a;
    Sinhvien *y = (Sinhvien *)b;
    return y->score - x->score;
}

int main() {
    int n;
    scanf("%d", &n);

    while (1) {
        char tmp[20];
        scanf("%s", tmp);
        if (strcmp(tmp, "#") == 0) break;

        strcpy(ds[cnt].code, tmp);
        scanf("%d", &ds[cnt].score);
        cnt++;
    }

    qsort(ds, cnt, sizeof(Sinhvien), cmp);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", ds[i].code, ds[i].score);
    }

    return 0;
}
