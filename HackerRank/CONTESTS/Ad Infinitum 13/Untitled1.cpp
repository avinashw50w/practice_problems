#include<bit/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;
ll phi(ll n){
	ll r=n;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) r-=r/i;
		while(n%i==0) n/=i;
	}
	if(n!=1) r-=r/n;
	return r;
}
ll modpow(ll a,ll b,ll m){
	if(b==0) return 1;
	ll x=modpow(a,b/2,m);
	x=(x*x)%m;
	if(b&1) x=(x*a)%m;
	return x;
}
