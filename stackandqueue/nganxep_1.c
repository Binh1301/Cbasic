#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_t{
    int value;
    struct node_t* next;

}Node;
Node* top;

Node* makeNewNode(int v){
    Node* new = (Node*)malloc(sizeof(Node));
    new->value = v;
    new->next = NULL;
    return new;
}
int stackEmpty(){
    return top == NULL;
}
void push(int v){
    Node* p = makeNewNode(v);
    p->next = top;
    top = p;
}
int pop(){
    if(stackEmpty()){
        return -1;
    }
    int v = top->value;
    Node* tmp;
    tmp = top;
    top = top->next;
    free(tmp);
    return v;
}
int main(){
    char cmd[256];
    while(1){
        scanf("%s", cmd);
        if(strcmp(cmd,"#") == 0){
            break;
        }
        if(strcmp(cmd,"PUSH") == 0){
            int v;
            scanf("%d", &v);
            push(v);

        }
        if(strcmp(cmd,"POP") == 0){
                if(stackEmpty()) printf("NULL\n");
                else{
            int v = pop();
            printf("%d\n", v);
        }}}
        return 0;
}









