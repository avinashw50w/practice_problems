#include<stdio.h>
#include<stdlib.h>
#define getcx getchar_unlocked
inline int input(){
	int n =0;
	char ch = getcx();
	while(ch<33)
	ch=getcx();
	while(ch>=33){
		n = (n<<3) + (n<<1) + (ch-'0');
		ch = getcx();
	}
	return n;
};

int main(){
	int i,j,T,max,N;
	int A[100][100],sum[100][100];
	T = input();
	while(T--){
		N = input();
		A[0][0] = input();
		sum[0][0] = A[0][0];
		max = sum[0][0];
		for(i=1;i<N;i++)
		for(j=0;j<=i;j++){
			A[i][j] = input();
			if(j==0)
			sum[i][j] = sum[i-1][j] + A[i][j];
			else if(i==j)
			sum[i][j] = sum[i-1][j-1] + A[i][j];
			else{
				if(sum[i-1][j] > sum[i-1][j-1])
				sum[i][j] = sum[i-1][j] + A[i][j];
				else
				sum[i][j] = sum[i-1][j-1] + A[i][j];
			}
			if(sum[i][j] > max)
			max = sum[i][j];
		}
		printf("%d\n",max);
	}
	return 0;
}
