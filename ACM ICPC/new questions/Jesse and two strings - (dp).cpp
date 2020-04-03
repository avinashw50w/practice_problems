#include <bits/stdc++.h>
using namespace std;

int dp1[1010][1010], dp2[1010][1010];
string A, B;

int lps(string s, int dp[][1010]) {
	memset(dp, 0, sizeof(dp));
	int n = s.size();
	for(int len = n; len >= 1; --len) {
		for(int i = 1; i+len-1 <= n; ++i) {
			int j = i+len-1;
			dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j+1]));
			if(s[i-1] == s[j-1])
				dp[i][j] = max(dp[i][j], dp[i-1][j+1] + 1 + (i != j));
		}
	}
	int ans = 0;
	for(int i=1; i<=n; ++i) ans = max(ans, dp[i][i]);
	return ans;
}

int solve() {

	int n = lps(A, dp1);
	int m = lps(B, dp2);

	if(n%2 == 0 or m%2 == 0) return n + m;

	vector<int> va(26,0), vb(26,0);
	for(int i=1; i<=A.size(); ++i) if(dp1[i][i] == n) va[A[i-1]-'a'] = 1;
	for(int i=1; i<=B.size(); ++i) if(dp2[i][i] == m) vb[B[i-1]-'a'] = 1;

	for(int i = 0; i < 26; ++i) 
	if(va[i] and vb[i]) return n + m;
	
	return  n + m - 1;
}

int main() {

	int t; cin>>t;
	while(t--) {
		cin >> A >> B;
		
		cout << solve() << endl;
		
	}
}