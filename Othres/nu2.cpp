#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int a[n+2],visited[n+2];
ll ans=0;

void mark(int i,int n){
	ll sum=0;
	for(int j=i;j<=n;j+=i){
		visited[j]=1;
		sum+= a[j]
	}
	if(sum>ans) ans=sum;
}
ll sieve(int n){
	ans=0;
	if(n>=2){
		for(int i=2;i<=n;i++){
			if(!visited[i])
			mark(i,n);
		}
	}
	return ans;
}
int main(){
	int t; cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(visited,0,sizeof(visited));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++) cin>>a[i];
		ans = sieve(n);
		cout<<ans<<endl;
	}
	return 0;
}
