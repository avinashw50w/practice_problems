// find the nth lucky no. A lucky no is which has atleast 3 distinct prime factors.

#include<bits/stdc++.h>
#define ll long long int
#define max 10000
using namespace std;
int lucky;
int prime_factor[max+1]={0};
void generate(){
	for(int i=2;i*i<=max;i++){
		if(!prime_factor[i]){
			for(int j=i*i;j<=max;j+=i) prime_factor[j]=i;
		}
	}
	for(int i=2;i<=max;i++){
		if(!prime_factor[i]) prime_factor[i]=i;
	}
}
void factorize(int n){
	bool mark[max+1];
	for(int i=0;i<=max;i++) mark[i]=false;
	while(n!=1){
		mark[prime_factor[n]]=true;
		n/=prime_factor[n];
	}
	int cnt=0;
	for(int i=0;i<=max;i++){
		if(mark[i]) cnt++;
	}
	if(cnt>=3) lucky++;
}

int main(){
	generate();
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		lucky=0;
		int i=30;
		while(lucky!=n){
			factorize(i);
			i++;
		}
		cout<<i-1<<endl;		
	}
	return 0;
}
