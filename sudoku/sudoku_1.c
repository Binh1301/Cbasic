#include <stdio.h>
int X[9][10];
int mark_r[9][10];
int mark_c[9][10];
int mark_s[3][3][10];
int count = 0;
void solution(){
    count++;
}
int check( int r,int c, int v){
    if(mark_c[c][v]) return 0;
    if(mark_r[r][v]) return 0;
    if(mark_s[r][c][v]) return 0;
    return 1;
}
void init(){
    for(int v = 1; v <= 9; v++ ){
        for(int c = 0; c <= 8; c++) mark_c[c][v] = v;
        for(int r = 0; r <= 8; r++) mark_r[r][v] = v;
        for(int i = 0; i <= 2; i++)
            for(int j = 0; j = 2; j++) mark_s[i][j][v] = v;
    }
}
void try(int r,int c){
    if(X[r][c] > 0){
        if( c == 8 && r == 8 ) solution();
        else{
        if( c == 8 ) try(r+1, 0);
        else try(r , c + 1);
        return;
    }}
    for( int v = 1; v <= 9; v++){
        if(check(r,c,v)){
            X[r][c] = v;
            mark_r[r][v] = 1;
            mark_c[c][v] = 1;
            mark_s[r][c][v] = 1;
            if( r == 8 && c == 8) solution();
            else{
        if( c == 8 ) try(r+1, 0);
        else try(r , c + 1);

        }
        X[r][c] = 0;
            mark_r[r][v] = 0;
            mark_c[c][v] = 0;
            mark_s[r][c][v] = 0;
    }
}}

int main(){
    void init();
    for(int c = 0; c <= 8; c++ ){
        for(int r = 0; r <= 8; r++ ){
                int v;
            scanf("%d", &v);
            X[r][c] = v;
        }
    }
    try(0,0);
    printf("%d", count);
    return 0;

}
