#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; scanf("%d",&n);
		int a,flag=0;
		for(int i=1;i<=n;i++){
			cin>>a;
			if(abs(a[i]-i)>1)	
			flag=1;
		
		}
		if(flag==1)
		cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
