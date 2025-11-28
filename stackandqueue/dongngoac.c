#include <stdio.h>
#include <string.h>

#define MAX 1000006

char stack[MAX];
int top = -1;

int isValid(char* s) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;   // push
        } else {
            if (top == -1) return 0; // stack rỗng, gặp dấu đóng
            char open = stack[top];
            if ((c == ')' && open == '(') ||
                (c == ']' && open == '[') ||
                (c == '}' && open == '{')) {
                top--;  // pop
            } else {
                return 0; // không khớp
            }
        }
    }
    return top == -1; // nếu stack rỗng → đúng
}

int main() {
    char s[MAX];
    scanf("%s", s);
    printf("%d\n", isValid(s));
    return 0;
}

