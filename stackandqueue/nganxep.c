
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_t{
    int value;
    struct node_t* next;
} Node;
Node* top;
Node* makeNode(int v){
    Node* new = (Node*)malloc(sizeof(Node));
    new->value = v;
    new->next = NULL;
    return new;

}
void initStack(){
    top = NULL;
}

int stackEmpty(){
    if(top == NULL) return 1;
    else return 0;
}
void push(int x){
    Node* p = makeNode(x);
    p->next = top;
    top = p;
}
int pop(){
    if(stackEmpty()){
        return -1;
    }
    int x = top->value;
    Node* p = top;
    top = top->next;
    free(p);
    return x;
}
int main() {
  char cmd[50];
  while (1) {
    scanf("%s", cmd);
    if (strcmp(cmd, "#") == 0) {
      break;
    } else if (strcmp(cmd, "PUSH") == 0) {
      int v;
      scanf("%d", & v);
      push(v);
    } else if (strcmp(cmd, "POP") == 0) {
      if (stackEmpty()) {
        printf("NULL\n");
      } else {
        int v = pop();
        printf("%d\n", v);
      }
    }
  }
  return 0;
}
