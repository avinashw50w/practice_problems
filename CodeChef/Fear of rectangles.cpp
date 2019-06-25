#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#define gc getchar()
#define ll long long
using namespace std;
ll inp(){
	register int n = 0;
	char c=gc;
	while(c<'0' and c>'9') c=gc;
	while(c>='0' and c<='9'){
		n = (n<<3)+(n<<1)+c-'0';
		c=gc;
	}
	return n;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		vector<ll> a[1010];
		int j=0;
		ll x;
		for(int i=0;i<n;i++){
			for(int k=0;k<m;k++){
				scanf("%lld",&x);
				a[k+j].push_back(x);
			}
			j++;
		}
		for(int i=0;i<n+m;i++){
			for(int k=0;k<a[i].size();k++)
			printf("%lld ",a[i][k]);
		}
		printf("\n");
	}
	return 0;
	
}
