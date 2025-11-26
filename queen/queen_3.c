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
