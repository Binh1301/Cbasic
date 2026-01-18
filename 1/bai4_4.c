#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXN 100000
#define MAXL 256

typedef struct {
    char ho[50];
    char ten[50];
} SV;

SV ds[MAXN];
int n = 0;

/* đổi chuỗi về chữ thường */
void toLower(char *s) {
    for (int i = 0; s[i]; i++)
        s[i] = tolower((unsigned char)s[i]);
}

/* loại bỏ '\n' và '\r' ở cuối dòng */
void trim(char *s) {
    int len = strlen(s);
    while (len > 0 && (s[len-1] == '\n' || s[len-1] == '\r')) {
        s[len-1] = '\0';
        len--;
    }
}

/* tách họ (từ đầu) và tên (từ cuối) */
void tachHoTen(char *line, char *ho, char *ten) {
    char tmp[MAXL];
    strcpy(tmp, line);

    char *token = strtok(tmp, " ");
    strcpy(ho, token);          // họ

    char *last = token;
    while ((token = strtok(NULL, " ")) != NULL) {
        last = token;
    }
    strcpy(ten, last);          // tên

    toLower(ho);
    toLower(ten);
}

int main() {
    char line[MAXL];

    /* đọc danh sách sinh viên */
    while (fgets(line, sizeof(line), stdin)) {
        trim(line);
        if (strcmp(line, "endlist") == 0) break;

        tachHoTen(line, ds[n].ho, ds[n].ten);
        n++;
    }

    /* xử lý truy vấn */
    while (fgets(line, sizeof(line), stdin)) {
        trim(line);
        if (strcmp(line, "endsearch") == 0) break;

        char ho[50], ten[50];
        tachHoTen(line, ho, ten);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(ds[i].ho, ho) == 0 &&
                strcmp(ds[i].ten, ten) == 0) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}

