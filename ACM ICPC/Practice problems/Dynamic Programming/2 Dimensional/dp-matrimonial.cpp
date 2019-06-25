/*You are working as a programmer in a matrimonial-company. Based on the information given by the customers they are classified in many types. The types of 
male and female are written on separate pages, there are two bundles, one of male information and other of female information. You are going through the pages 
sequentially, i.e. you pick a page from male bundle and other from female bundle then see if they match. If they do, you put them in an envelope, if not you 
either throw the male form or the female form and pick another from the opposite category and then check again, the same process is repeated until both the 
bundles are empty. If you have some supernatural power that you know all the types of all applications in both the bundles so that you can decide which form 
to throw away and which to keep, then find out the maximum number of matches that can be computed Warning: The two bundles have many applications. However, 
they are grouped based on their types. The types can be repeated any no of times.

Input: The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line contains two integers N and M. 
It is followed by a line containing 2 * N integers a1, A1, a2, A2, ..., aN, AN, and another line containing 2 * M integers b1, B1, b2, B2, ..., bM, BM. 
This means that the first bundle will have a1 no. of male applications of type A1, then a2 no. of male applications of type A2, etc., until it finishes with 
aN no. of male applications of type AN. Similarly, the second bundle will have b1 no. of female applications of type B1, followed by b2 no. of female 
applications of type B2, etc., until it finishes with bM no. of female applications of type BM. A couple can be matched if and only if they have the same 
type number.

Output: For each test case, output one line containing the largest number of couples that you can matched.

Limits: 1 <= T <= 100. 1 <= ai, bi <= 10^16. 1 <= Ai, Bi <= 100.*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll, ll> boy[101], girl[101];

ll dp[101][101];

int B, G;

ll solve(int x, int y) {
	if(x == B || y == G) return 0;

	if(dp[x][y] != -1) return dp[x][y];

	ll ret = 0LL;

	// Pick girl for boy x
	for(int i=y; i<=G; ++i) {
		if(girl[i].second == boy[x].second)
			ret = max(ret, min(girl[i].first, boy[x].first) + solve(x+1, i+1));
	}

	// Pick boy for girl y
	for(int i=x; i<=B; ++i) {
		if(boy[i].second == girl[y].second)
			ret = max(ret, min(boy[i].first, girl[y].first) + solve(i+1, y+1));
	}

	// Pick none
	ret = max(ret, solve(x+1, y+1));

	return dp[x][y] = ret;
}

int main() {
	int t; cin>>t;
	while(t--) {
		ll no, type;

		cin>>B>>G;

		for(int i=0;i<B;++i) {
			cin>>no>>type;
			boy[i] = make_pair(no, type);
		}

		for(int i=0;i<G;++i) {
			cin>>no>>type;
			girl[i] = make_pair(no, type);
		}		

		memset(dp, -1, sizeof dp);
		cout << solve(0, 0) << endl;
	}
	return 0;
}
