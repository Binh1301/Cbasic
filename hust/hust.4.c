#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
    char word[50];
    int count;
} Word;

Word a[300];
int n = 0;

/* so sánh để sắp xếp alphabet */
int cmp(const void *x, const void *y){
    return strcmp(((Word*)x)->word, ((Word*)y)->word);
}

/* thêm hoặc tăng số lần xuất hiện */
void addWord(char *w){
    for(int i = 0; i < n; i++){
        if(strcmp(a[i].word, w) == 0){
            a[i].count++;
            return;
        }
    }
    strcpy(a[n].word, w);
    a[n].count = 1;
    n++;
}

int main(){
    char line[1000];
    char cur[50];
    int len = 0;

    /* đọc toàn bộ văn bản (không có dấu kết thúc) */
    while(fgets(line, sizeof(line), stdin)){
        for(int i = 0; line[i]; i++){
            if(isalpha((unsigned char)line[i])){
                cur[len++] = tolower((unsigned char)line[i]);
            } else {
                if(len > 0){
                    cur[len] = '\0';
                    addWord(cur);
                    len = 0;
                }
            }
        }
    }

    /* nếu dòng kết thúc bằng chữ */
    if(len > 0){
        cur[len] = '\0';
        addWord(cur);
    }

    /* sắp xếp alphabet */
    qsort(a, n, sizeof(Word), cmp);

    /* in kết quả */
    for(int i = 0; i < n; i++){
        printf("%s %d\n", a[i].word, a[i].count);
    }

    return 0;
}
