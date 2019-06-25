#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	char str[101][101];
	int l,c;
	while(t--){
		scanf("%d %d",&l,&c);
		for(int i=0;i<l;i++){
			for(int j=0;j<c;j++){
				if(i%2==0){
				if(j%2==0)
				printf("*");
				else printf(".");
			}
				else if(i%2!=0){
					if(j%2==0)
					printf(".");
					else printf("*");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
