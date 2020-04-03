#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int main(){
	int k,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&k);
		int d=k/25;
		if(k%25 == 0 and k){
			while(d--) printf("zyxwvutsrqponmlkjihgfedcba");
			printf("\n");
			continue;
		}
		
		for(int i='a'+k%25;i>='a';--i) printf("%c",i);
		while(d--) printf("zyxwvutsrqponmlkjihgfedcba");
		printf("\n");
	}
	
	return 0;
}