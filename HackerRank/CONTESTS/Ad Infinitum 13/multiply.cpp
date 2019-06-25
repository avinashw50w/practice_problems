#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define MAX 1001
using namespace std;

ll factors[MAX]={0};
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
void factorize(ll n) {
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n != 1) {
        factors[n]++;
    }
}

int main(){
	ll n,q,x;
	cin>>n>>q;
	factorize(n);
	
	while(q--){
		cin>>x;
		factorize(x);
		ll denum=1,num=1,rden;
		for(int i=2;i<MAX;i++){
			if(factors[i]){
				denum = (denum*(i-1))%mod; 
				num = ((num%mod)*((modpow(i,(factors[i]+1),mod)%mod)-1))%mod;
			}
		}
		rden=modpow(denum,mod-2,mod);
		ll ans=(num*rden)%mod;
	cout<<ans%mod<<"\n";
	}
//	for(int i=0;i<20;i++) cout<<factors[i]<<" ";
	return 0;
}
