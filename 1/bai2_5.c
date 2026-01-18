
#include <stdio.h>
#include <math.h>
int a[10000];
int sum = 1;

int khoangcach(int x, int y){
    int i = -2;
    while(1){
        if( i >= y){
                    sum = sum + abs( y - i / (-2));
                    break;}

        sum = sum + abs( i - i / (-2)) ;
        i = i * ( -2);

    }
    return sum;

}
int main(){
    int x,y;
    scanf("%d %d", &x,&y);
    int a = khoangcach(0 , y- x);
    printf("%d", a);
    return 0;


}

