#include<bits/stdc++.h>
using namespace std;
int n;
int A[1002],B[1002][1002];
const int Bmax = 2005*2005

void solve(){
	sort(A,A+n);
	for(int i=0;i<n;i++)
	for(int j=A[i];j>=1;j--)
	B[i][A[i]/j] = j;
	
	for(int x=A[0];x>=1;x--){
		int ans=0;
		for(int i=0;i<n && ans<Bmax;i++)
		ans+=(B[i][x]>0?B[i][x]:Bmax);
		if(ans<Bmax){
			cout<<ans;
			return;
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>A[i];
	solve();
	return 0;
}
