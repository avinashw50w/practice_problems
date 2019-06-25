#include<stdio.h>
#include<stdlib.h>
#define getcx getchar_unlocked()
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
	int t,n,i,j;
	t=input();
	int min,arr;
	while(t--){
		n=input();
		min=input();
		for(i=1;i<n;i++){
			arr=input();
			if(arr<min)
			min=arr;
		}
		long long int cost=(long long int)min * (n-1);
		
printf("%lld\n",cost);
	}
	return 0;
}
