#include <stdio.h>
#define N 100
int n;
int x[100]; // cot i
int mark[100]; // hang
int markD1[100];
int markD2[100];
int cnt;
int check(int v, int k){
    if(mark[v] == 1) return 0;
    if(markD1[n + k - v] == 1) return 0;
    if(markD2[k + v] == 1) return 0;
    return 1;
}
void printSolution() {
    for(int i = 1; i <= n; i++){
        printf("%d", x[i]);
        if(i < n) printf(" ");
    }
    printf("\n");
}
void Try(int k){
    if(x[k] > 0){
        if(k == n){
            printSolution();
            cnt++;
        }
        else Try(k+1);
        return;
    }
    for(int r = 1; r <= n; r++){
        if(check(r,k)){
                x[k] = r; mark[r] = 1;
                markD1[n+ k - r] = 1;
                markD2[k + r] = 1;
                if(k == n){
                        printSolution();
                cnt++;}
                else Try(k+1);
                x[k] = 0;
                mark[r] = 0;
                markD1[n+ k - r] = 0;
                markD2[k + r] = 0;

        }
    }
}


void input(){
    int r, c;
    for(int i = 1; i < N; i++) mark[i] = 0;
    for(int i = 0; i < 2*N; i++){ markD1[i] = 0; markD2[i] = 0; }
    scanf("%d %d %d",&n,&r, &c);
    for(int i = 1; i <= n; i++) x[i] = 0;
        x[c] = r;
        mark[r] = 1;
        markD1[n + c - r] = 1;
        markD2[c + r] = 1;

}


int main(){
    input();
    cnt = 0;
    Try(1);
    if(cnt == 0) printf("None\n");
    printf("%d", cnt);
    return 0;
}


