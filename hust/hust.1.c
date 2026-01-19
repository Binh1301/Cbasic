#include <stdio.h>

typedef struct {
    float x;
    float y;
} vitri;

typedef struct {
    float x_1, y_1;
    float x_2, y_2;
} khung;

vitri ds[50000];
khung ds_1[5000];

int namtrong(float x, float y,
             float x1, float y1,
             float x2, float y2) {
    return (x1 < x && x < x2 && y2 < y && y < y1);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%f %f", &ds[i].x, &ds[i].y);
    }

    for (int i = 0; i < M; i++) {
        scanf("%f %f %f %f",
              &ds_1[i].x_1, &ds_1[i].y_1,
              &ds_1[i].x_2, &ds_1[i].y_2);
    }

    for (int i = 0; i < M; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (namtrong(ds[j].x, ds[j].y,
                         ds_1[i].x_1, ds_1[i].y_1,
                         ds_1[i].x_2, ds_1[i].y_2)) {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
