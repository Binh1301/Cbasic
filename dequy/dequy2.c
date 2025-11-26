#include <stdio.h>
void convert(int N){
    if (N == 0) return;
    convert(N/2);
    int b = N % 2;
    printf("%d", b);
}
int main(){
    int a;
    scanf("%d", &a);
    convert(a);
    return 0;

}

