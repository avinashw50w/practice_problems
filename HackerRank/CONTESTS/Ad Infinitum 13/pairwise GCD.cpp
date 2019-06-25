#include<bits/stdc++.h>
#define mod 1000000007
#define ll  long long int
#define MAX 100002
using namespace std;
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
ll A[MAX],B[204],freq[MAX]={0},g[MAX]={0};
int maxx,minn;
void sieve(){
	int t;
	for(int i=maxx;i>=1;i--){
		int cnt=0;
		int j=i;
		while(j<=maxx){
			if(freq[j]) cnt+=freq[j];
			j+=i;
		}
		if(cnt>1){
			t=cnt-1;
			g[i]=1;
		}
	}
}
int main(){
	ll n,m;
	cin>>n>>m;
	maxx=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&A[i]);
		freq[A[i]]++;
		if(A[i]>maxx) maxx=A[i];
	}
	sieve();
	for(int i=0)
	for(int i=0;i<=m;i++) cin>>B[i];
//	for(int i=0;i<20;i++)cout<<g[i]<<" ";
	ll sum=B[0],p;
	for(int j=0;j<=m;j++){
		p=0;
		for(int i=1;i<=n;i++){
			p+= ((g[i]%mod) * (modpow(i,j,mod)%mod))%mod;		
		}
		p = (B[j]*p)%mod;
	}
	sum=(sum+p)%mod;;
//	cout<<sum<<endl;
	return 0;
}
