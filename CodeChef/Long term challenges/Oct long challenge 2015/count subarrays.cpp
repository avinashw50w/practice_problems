#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)  for(int i=0;i<(int)n;i++)
#define ll long long int
#if defined(_WIN64)
#define gc getchar
#else
#define gc getchar_unlocked
#endif
#define MAX 100000+2
inline int input(){
	register int x=0;
	char c = gc();
	while(c<'0' || c>'9')
	c = gc();
	while(c>='0' || c<='9'){
		x = (x<<3) + (x<<1) + c-'0';
		c = gc();
	}
	return x;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll cazzz=0;
		ll n;
		scanf("%lld",&n);
		ll a[n+2];
		rep(i,n) scanf("%lld",&a[i]);
		ll j=0;
		rep(i,n){
			j++;
			if(i!=n-1 and a[i]>a[i+1]){
			cazzz+= (j*(j+1))/2;
			j=0;
			}	
		}
		cazzz+=(j*(j+1))/2;
		printf("%lld\n",cazzz);
	}
	return 0;
}
