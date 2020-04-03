#include<bits/stdc++.h>
using namespace std;
#define dollars 1e9
int main(){
	long double money,p;
	int test,m;
	scanf("%d",&test);
	while(test--){
		scanf("%d %LF",&m,&p);
		money = dollars*((pow(-p,m)-1)/(-p-1));
		printf("%LF %LF\n",money,dollars-money);
	}
	return 0;
}
