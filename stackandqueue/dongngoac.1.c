
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_t{
    int value;
    struct node_t* next;
} Node;
Node* top = NULL;
Node* makeNode(int v){
    Node* new = (Node*)malloc(sizeof(Node));
    new->value = v;
    new->next = NULL;
    return new;

}

int stackEmpty(){
    if(top == NULL) return 1;
    else return 0;
}
void push(int v){
    Node* p = makeNode(v);
    p->next = top;
    top = p;
}
int pop(){
    if(stackEmpty()){
        return -1;
    }
    Node* tmp = top;
    int v = top->value;
    top = top->next;
    free(tmp);
    return v;
}
int match(char a, char b){
    if(a == '(' && b == ')' ) return 1;
    if(a == '[' && b == ']' ) return 1;
    if(a == '{' && b == '}' ) return 1;
    return 0;
}
int check(char* s){
    for(int i = 0; i < strlen(s); i++){
        char c = s[i];
        if( c =='(' || c=='[' || c=='{'){
            push(c);
        } else {
            if(stackEmpty()) return 0;
            char a = pop();
            if(!match(a, c)) return 0;
        }
    }
    return stackEmpty();
}

int main(){
    char s[1000];
    scanf("%s", s);
    printf("%d", check(s) ? 1 : 0);
    return 0;
}
