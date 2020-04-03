#include<bits/stdc++.h>
using namespace std;l
#define max 5000000
bool isprime[max+2],ishypo[max+2];
vector<int> primes;

void sieve(){
	memset(isprime,true,sizeof(isprime));
	isprime[0]=isprime[1]=false; isprime[2]=true;
	for(int i=2;i*i<=max;i++){
		if(isprime[i]){
			for(int j=i*i;j<=max;j+=i) isprime[j]=false;
		}
	}
	for(int i=2;i<=max;i++){
		if(isprime and i%4==1) primes.push_back(i);
	}
	for(int i=0;i<primes.size();i++){
		int p=primes[i];
		for(int j=p;j<=max;j+=p) ishypo[j]=true;
	}
}
int main(){
	int t; cin>>t;
	sieve();
	while(t--){
		int n; cin>>n;
		if(ishypo[n]) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
