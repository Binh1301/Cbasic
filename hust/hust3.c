#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char fullname[101];
    int mssv;
} Student;

Student a[1000];
int n = 0;

/* so sánh để sort MSSV tăng dần */
int cmp(const void *x, const void *y){
    return (*(int*)x - *(int*)y);
}

int main(){
    char line[1000];

    /* ====== NHẬP DANH SÁCH SINH VIÊN ====== */
    while (fgets(line, sizeof(line), stdin)) {
        if (strstr(line, "end.") != NULL) break;

        char *token = strtok(line, ";");
        while (token != NULL) {
            char *comma = strchr(token, ',');
            if (comma != NULL) {
                *comma = '\0';
                strcpy(a[n].fullname, token);
                a[n].mssv = atoi(comma + 1);
                n++;
            }
            token = strtok(NULL, ";");
        }
    }

    /* ====== XỬ LÝ TRUY VẤN ====== */
    while (1) {
        char query[101];
        fgets(query, sizeof(query), stdin);
        query[strcspn(query, "\n")] = '\0';

        if (strcmp(query, "end.") == 0) break;

        int res[1000], cnt = 0;

        for (int i = 0; i < n; i++) {
            char *last = strrchr(a[i].fullname, ' ');
            char *name = (last != NULL) ? last + 1 : a[i].fullname;

            if (strcmp(name, query) == 0) {
                res[cnt++] = a[i].mssv;
            }
        }

        if (cnt == 0) {
            printf("Khong thay\n");
        } else {
            qsort(res, cnt, sizeof(int), cmp);
            for (int i = 0; i < cnt; i++) {
                if (i > 0) printf(",");
                printf("%d", res[i]);
            }
            printf("\n");
        }
    }

    return 0;
}

