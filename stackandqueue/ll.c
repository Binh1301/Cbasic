

#include <stdio.h>
#include <string.h>
typedef struct {
    char name[30];
    char tel[15];
    char email[40];
} elementtype;
void removeNewline(char *s) {
    s[strcspn(s, "\n")] = '\0';
}

elementtype readData() {
    elementtype res;

    printf("name: ");
    fgets(res.name, sizeof(res.name), stdin);
    removeNewline(res.name);

    printf("tel: ");
    fgets(res.tel, sizeof(res.tel), stdin);
    removeNewline(res.tel);

    printf("email: ");
    fgets(res.email, sizeof(res.email), stdin);
    removeNewline(res.email);

    return res;
}

void printData(elementtype res) {
    printf("%15s\t%10s\t%20s\n", res.name, res.tel, res.email);
}
