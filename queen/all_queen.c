#1
#include <stdio.h>
#define N 100
int n;
int m;
int x[100];
int mark[100];
int markD1[100];
int markD2[100];
int cnt;
int check(int v, int k){
    if(mark[v] == 1) return 0;
    if(markD1[n + k - v] == 1) return 0;
    if(markD2[k + v] == 1) return 0;
    return 1;
}
void Try(int k){
    if(x[k] > 0){
        if(k == n) cnt++;
        else Try(k+1);
        return;
    }
    for(int r = 1; r <= n; r++){
        if(check(r,k)){
                x[k] = r; mark[r] = 1;
                markD1[n+ k - r] = 1;
                markD2[k + r] = 1;
                if(k == n) cnt += 1;
                else Try(k+1);
                x[k] = 0;
                mark[r] = 0;
                markD1[n+ k - r] = 0;
                markD2[k + r] = 0;

        }
    }
}


void input(){
    for(int i = 1; i < N; i++) mark[i] = 0;
    for(int i = 0; i < 2*N; i++){ markD1[i] = 0; markD2[i] = 0; }

    scanf("%d",&n);
    scanf("%d",&m);

    for(int i = 1; i <= n; i++) x[i] = 0;

    for(int j = 1; j <= m; j++){
        int r, c;
        scanf("%d %d", &r, &c);

        x[c] = r;                        // ✔ cột c đặt queen ở hàng r
        mark[r] = 1;                     // ✔ đánh dấu hàng r
        markD1[n + c - r] = 1;           // ✔ đường chéo chính
        markD2[c + r] = 1;               // ✔ đường chéo phụ
    }
}


int main(){
    input();
    cnt = 0;
    Try(1);
    printf("%d",cnt);
    return 0;
}


#2
#include <stdio.h>
#define N 100
int n;
int x[N];
int mark[N];
int markD1[N];
int markD2[N];
int count = 0;
void init(){
    for(int i = 0; i  <= N; i++) mark[i] = 0;
    for(int i = 0; i  <= 2*N; i++) markD1[i] = 0;
    for(int i = 0; i  <= 2*N; i++) markD2[i] = 0;
    scanf("%d", &n);
    for(int i = 0; i <=n ; i++){
        for(int j = 0; j <= n; j++){
            int e;
            scanf("%d", &e);
            if( e > 0 ){ mark[j] = i;
            markD2[ i + j] = 1;
            markD1[n + j - i ] = 1;}
        }
    }
}
void solution(){
    count++;
}
int check(int v, int k){
    if(mark[v] == 1) return 0;
    if(markD1[n + v - k] == 1) return 0;
    if(markD2[v + k] == 1) return 0;
    return 1;
}
void try(int k){
    if( x[k] > 0){
        if( k == 8 ) solution();
            else try(k+1);
    }
    for(int r = 1; r <= n; r++ ){
        if(check(r,k)){
            x[k] = r;
            mark[r] = 1;
            markD1[ n + r - k] = 1;
            markD2[ r + k ] = 1;
            if( k == 8) solution();
            else try(k+1);
            x[k] = 0;
            mark[r] = 0;
            markD1[ n + r - k] = 0;
            markD2[ r + k ] = 0;
        }
    }


}
int main(){
    init();
    count = 0;
    try(1);
    printf("%d",count);
    return 0;
}
#3
#include <stdio.h>
#define N 100
int n;
int x[N];
int mark[N];
int markD1[N];
int markD2[N];
int count;

int check(int v, int k){
    if(mark[v] == 1) return 0;
    if(markD1[n - k + v]) return 0;
    if(markD2[k + v]) return 0;
    return 1;
}
void solution(){
    count++;
}
void try(int k){
    if(x[k] > 0){
        if(k == n) solution();
        else try(k+1);
    }
    for(int v = 1; v <= n; v++){
        if(check(v,k)){
            x[k] = v;
            mark[v] = 1;
            markD1[n - k + v] = 1;
            markD2[k + v] = 1;
            if( k == n ) solution();
            else try(k+1);
            mark[v] = 0;
            markD1[n - k + v] = 0;
            markD2[k + v] = 0;
            x[k] = 0;

        }
    }
}
void input(){
    for(int i = 0; i < N; i++)
        mark[i] = 0;
    for(int j = 0; j < 2 * N; j++) {markD1[j] = 0; markD2[j] = 0;}
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) x[i] = 0;
    for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int e;
                scanf("%d", &e);
                if(e == 1){
                x[j] = i;
                mark[i] = 1;
                markD1[n - j + i] = 1;
                markD2[j + i] = 1;
            }
            }

    }


}
int main(){
    input();
    count = 0;
    try(0);
    printf("%d", count);
    return 0;




}
#4
#include <stdio.h>
int x[30],n,k,cot[30],xuoi[100],nguoc[100],fix[20];
int cnt=0;
void Try(int i){
	if (i==n+1){
	 	cnt++;
	 	return;
	}
	if (fix[i]){
		int j=x[i];
		if(cot[j]==0&&xuoi[i-j+n]==0&&nguoc[i+j-1]==0){
			cot[j]=1;xuoi[i-j+n]=1;nguoc[i+j-1]=1;
			Try(i+1);
			cot[j]=0;xuoi[i-j+n]=0;nguoc[i+j-1]=0;
		}
	}
	else {
		for (int j=1;j<=n;j++){
			if(cot[j]==0&&xuoi[i-j+n]==0&&nguoc[i+j-1]==0){
			x[i]=j;
			cot[j]=1;xuoi[i-j+n]=1;nguoc[i+j-1]=1;
			Try(i+1);
			cot[j]=0;xuoi[i-j+n]=0;nguoc[i+j-1]=0;
		}
		}
	}
}

int main(){
	scanf("%d %d",&n,&k);
	while (k--){
		int r,c;
		scanf("%d %d",&r,&c);
		x[r]=c;
		fix[r]=1;
	}
	Try(1);
	printf("%d",cnt);
}
#5
#include <stdio.h>
#define N 100
int n;
int m;
int x[100];
int mark[100];
int markD1[100];
int markD2[100];
int cnt;
int check(int v, int k){
    if(mark[v] == 1) return 0;
    if(markD1[n + k - v] == 1) return 0;
    if(markD2[k + v] == 1) return 0;
    return 1;
}
void Try(int k){
    if(x[k] > 0){
        if(k == n) cnt++;
        else Try(k+1);
        return;
    }
    for(int r = 1; r <= n; r++){
        if(check(r,k)){
                x[k] = r; mark[r] = 1;
                markD1[n+ k - r] = 1;
                markD2[k + r] = 1;
                if(k == n) cnt += 1;
                else Try(k+1);
                x[k] = 0;
                mark[r] = 0;
                markD1[n+ k - r] = 0;
                markD2[k + r] = 0;

        }
    }
}


void input(){

    for(int i = 1; i < N; i++) mark[i] = 0;
    for(int i = 0; i < 2*N; i++){ markD1[i] = 0; markD2[i] = 0; }
    scanf("%d",&n);
    scanf("%d", &m);
    for(int i = 1; i <= n; i++) x[i] = 0;
    for(int j = 1; j <= m; j++){
        int r,c;
        scanf("%d %d", &r, &c);
        mark[c] = 1;
        markD1[n + r - c] = 1;
        markD2[r + c] = 1;
        x[r] = c;
    }
}

int main(){
    input();
    cnt = 0;
    Try(1);
    printf("%d",cnt);
    return 0;
}

