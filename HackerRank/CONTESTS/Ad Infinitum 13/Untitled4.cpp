#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll modpow(ll base, ll expo,ll m){       
  ll result = 1;

  while (expo){
    if (expo&1)
      result = (result*base)%m;

    expo >>=1 ;
    base = (base*base)%m;
  }

  return result;
}
int main(){
	ll a=modpow(10,13,mod);
	ll b=modpow(10,5,mod);
	ll c=modpow(2,(mod-2),mod);
	ll f=(b-1)%mod;
	ll q=modpow(1000000008,(mod-2),mod);
	ll h=(10*f)%mod;
	ll t=(h*q)%mod;
	ll r=((a-b)%mod*c%mod)%mod;
	cout<<(-2+mod)%mod;
	//cout<<c*6%mod;
	return 0;
}
