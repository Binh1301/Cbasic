#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char value;
    struct Node* next;
} Node;

Node* top = NULL;

Node* makeNode(char x){
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = x;
    p->next = NULL;
    return p;
}

void push(char x){
    Node* p = makeNode(x);
    p->next = top;
    top = p;
}

bool stackEmpty(){
    return top == NULL;
}

char pop(){
    if(stackEmpty()) return '\0';
    Node* p = top;
    char x = p->value;
    top = top->next;
    free(p);
    return x;
}

bool match(char a, char b){
    return (a=='(' && b==')') ||
           (a=='[' && b==']') ||
           (a=='{' && b=='}');
}

bool check(char *s){
    for(int i = 0; s[i]; i++){
        char c = s[i];

        if(c=='(' || c=='[' || c=='{'){
            push(c);
        } else {
            if(stackEmpty()) return false;
            char a = pop();
            if(!match(a, c)) return false;
        }
    }
    return stackEmpty();
}

int main(){
    static char s[1000005];
    scanf("%s", s);

    printf("%d", check(s) ? 1 : 0);
    return 0;
}
