#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	int t;
	scanf("%d",&t);
	char str[100][6],phrase[50][350];
	int n,k,l;
	while(t--){
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;i++)
		scanf("%s",str[i]);
		for(int i=0;i<k;i++){
			scanf("%d",&l);
				fgets(phrase[i],l*5,stdin);
		}
		int a=0;
		while(a<n){
		for(int i=0;i<k;i++){
		
		if(strstr(str[a],phrase[i])) printf("YES ");	
		}
		a++;
		printf("NO ");
	}
	printf("\n");
}
return 0;
}
