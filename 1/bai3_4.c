
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int timkiem(int a[], int n, int k){
    int min;
    if(a[0] > k) min = a[0] - k;
    else min = k - a[0];

    for(int i = 1; i < n; i++){
        int diff;
        if(a[i] > k) diff = a[i] - k;
        else diff = k - a[i];

        if(diff < min)
            min = diff;
    }
    return min;
}

int main(){
    int n;
    scanf("%d", &n);
    int a[100];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    while(1){
        char cmd[100];
        scanf("%s", cmd);
        if(strcmp(cmd, "#") == 0) break ;
        if(strcmp(cmd, "SEARCH") == 0){
                int k;
        scanf("%d", &k);
        int b = timkiem(a,n,k);
        printf("%d", b);
        printf("\n");
        }

    }
    return 0;


}

