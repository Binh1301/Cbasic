#include <stdio.h>
int r,c;
int count;
int X[10][10];
int mark_r[9][10];
int mark_c[9][10];
int mark_s[3][3][10];
void init(){
    for(int v = 1; v <= 9; v++){
        for(int r = 0; r <= 8; r++)
        mark_r[r][v] = 0;
    for(int c = 0; c <= 8; c++)
        mark_c[c][v] = 0;
    for(int i = 0; i <= 2; i++)
        for(int j = 0; j <= 2; j++) mark_s[i][j][v] = 0;

}
}
int check(int v,int r, int c){
    if(mark_r[r][v]) return 0;
    if(mark_c[c][v]) return 0;
    if(mark_s[r/3][c/3][v]) return 0;
    return 1;
}
void solution(){
    count++;
}
void try(int r, int c){
        if(X[r][c] > 0){
            if ( r == 8 && c == 8) solution();
            else {
                if( c == 8 ) try(r + 1, 0);
                else try (r, c + 1);
            }
            return;
        }
        for( int v = 1; v <= 9; v++){
            if(check(v, r,c)){
                X[r][c] = v;
                mark_r[r][v] = 1;
                mark_c[c][v] = 1;
                mark_s[r/3][c/3][v] = 1;
                if( r == 8 && c == 8) solution();
                else{
                    if( c == 8 ) try(r + 1, 0);
                else try (r, c + 1);
                }
                mark_r[r][v] = 0;
                mark_c[c][v] = 0;
                mark_s[r/3][c/3][v] = 0;
                X[r][c] = 0;

            }
        }
}
int main(){
    init();
    for(int r = 0;r <= 8; r++){
            for(int c = 0; c <= 8; c++){
                int v;
                scanf("%d",&v);
                X[r][c] = v;
                if(v > 0){
                        mark_r[r][v] = 1; mark_c[c][v] = 1;
                mark_s[r/3][c/3][v] = 1;
}
}
}
count = 0;
try(0,0);
printf("%d",count);
return 0;
}
