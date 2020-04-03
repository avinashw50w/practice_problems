/*Queen of westeros is known for her dragons and magic. To control her dragons she speaks random but powerful words. 
The strength of her words can be predicted by a strange rule. Rule : Strength of a word is sum of square of size of palindromic substrings 
in the word. To recall the definition of palindrome, palindrome is a word which reads same when read forward and backward. 
For example, word "abaa" has 6 palindromic substrings. "aba","aa","a","b","a","a" with sizes 3,2,1,1,1,1 respectively. 
Their squares are 9,4,1,1,1,1. Hence total strength is 17. Given a queens word ind its strength.*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)

typedef long long ll;

bool dp[1001][1001];

ll solve(string s) {

	int n = s.size();

	memset(dp, false, sizeof(dp));

	rep(i, 0, n) dp[i][i] = true;

	rep(len, 2, n+1) {
		rep(i, 0, n-len+1) {
			int j = i + len - 1;

			if(s[i] == s[j] and len == 2) dp[i][j] = true;

			else if(s[i] == s[j] and dp[i+1][j-1] == true) dp[i][j] = true;
		}
	}

	ll ans = 0LL;

	rep(i, 0, n+1) 
	rep(j, 0, n+1) 
		if(dp[i][j] == true) 
			ans += (j-i+1)*(j-i+1);
		
	return ans;
}

int main() {

	string s;
	int t; cin>>t;

	while(t--) {

		cin >> s;
		cout << solve(s) << endl;
	}
}