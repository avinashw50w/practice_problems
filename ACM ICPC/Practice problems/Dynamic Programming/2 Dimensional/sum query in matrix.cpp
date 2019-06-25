
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m, Q, x, y;
	cin>>n>>m;
	
	int a, dp[n+1][m+1];
	
	memset(dp, 0 ,sizeof(dp));
	
	for(int i=1;i<=n;++i) 
		for(int j=1;j<=m;++j) {
			cin>>a;
			dp[i][j] = a + dp[i][j-1];
		}
	
	for(int i=1;i<=n;++i) 
		for(int j=1;j<=m;++j) 
			dp[i][j] += dp[i-1][j];
	
	cin>>Q;
	while(Q--) {
		cin>>x>>y;
		
		cout << dp[x][y] << endl;
	}
	
	
}