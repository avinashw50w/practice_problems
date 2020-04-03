#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
int isp[100000+5];
void sieve(){
	memset(isp,1,sizeof isp);
	isp[0]=isp[1]=0;
	for(ll i=2;i*i<=100002;i++){
		if(isp[i]){
			for(ll j=i*i;j<=100002;j+=i)
			isp[j] = 0;
		}
	}
}

int main(){
	sieve();
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		if(isp[n]) cout<<"yes\n";
		else cout<<"no\n";
	}
}
