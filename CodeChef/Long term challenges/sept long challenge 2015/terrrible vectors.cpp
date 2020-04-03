#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,i,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int p=n*n;
		int arr[p];
		for(i=0;i<p;i++)
		arr[i]=1;
		for(i=0;i<p;i++){
			if((i%n)!=(i/n)){
				arr[p-1]=-1;
			}
		}
		printf("YES\n");
		for(i=0;i<p;i++)
		printf("%d ",arr[i]);
		printf("\n");
	}
	return 0;
}
