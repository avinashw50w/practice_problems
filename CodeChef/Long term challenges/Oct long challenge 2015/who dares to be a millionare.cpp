#include<bits/stdc++.h>
#define rep(i,a,b)  for(int i=(int)a;i<=(int)b;i++)
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string corrAns,chefAns;
		cin>>corrAns;
		cin>>chefAns;
		vector<int> W(n+1);
		rep(i,0,n) cin>>W[i];
		int count=0;
		rep(i,0,n-1){
			if(corrAns[i]==chefAns[i]) count++;
		}
		if(count==n) cout<<W[n]<<endl;
		else{
			int ans=0;
			rep(i,0,count) ans= max(ans,W[i]);
			cout<<ans<<endl;
		}
	}
	return 0;
}
