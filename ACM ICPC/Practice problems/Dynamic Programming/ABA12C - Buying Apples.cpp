#include <bits/stdc++.h>
#define ll long long int
#define MAX 100000
using namespace std;
void solve(int v[],int k){
	int dp[k+1];
	dp[0]=0;
	for(int i=1;i<=k;i++){
		int q=MAX;
		for(int j=1;j<=i;j++){
			if(v[i]!=-1)
			q=min(q,v[i]+dp[i-j]);
		}
			
		dp[i]=q;
	}
	if(dp[k]!=MAX)
	cout<<dp[k]<<endl;
	else cout<<-1<<endl;
}
int main() {
int t; cin>>t;
while(t--){
	int n,k; cin>>n>>k;
	int v[k+2];
	for(int i=1;i<=k;i++) {
		cin>>v[i];
	}
	solve(v,k);
}

	return 0;
}
