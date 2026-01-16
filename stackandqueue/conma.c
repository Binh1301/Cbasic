
#include <stdio.h>
int grid[100][100];
int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(int x, int y, int m, int n, int grid[100][100]){
    grid[x][y] = 0;
    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if( nx >= 0 && ny >= 0 && grid[nx][ny] == 1)
            dfs(nx,ny,m,n,grid);
    }

}
int main(){
    int m,n;
    scanf("%d %d", &m,&n);
    for(int i = 0; i < m;i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &grid[i][j]);
        }
    }
    int count = 0;
    for(int i = 0; i < m;i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                count++;
                dfs(i,j,m,n,grid);
            }
        }
    }
    printf("%d\n", count);

}

