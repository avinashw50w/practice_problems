/*A permutation of N distinct integers between 1 and N, both inclusive, is called a prime permutation of size N iff - 
for all i between 1 and N, the following condition holds:

The ith integer is the Xth smallest integer in the first i integers, where X is either 1 or a prime number.

Your task is to find out how many prime permutations are there of size N.

1 ≤ T ≤ 500,000
1 ≤ N ≤ 5,000,000

Input
The first line contains a single integer T, denoting the number of test cases. 
Then T lines follow, each containing a single integer N.

Output
For each test case, output a single line containing the number of prime permutations of size N. 
Since the answers can be very large, output each answer modulo 1,000,000,007.

Example
Input:
4
1
2
3
4

Output:
1
2
6
18*/

/*QUICK EXPLANATION
Let pperm[i] = the number of prime permutations of size i. Let's calculate pperm[i]. The last number (i.e., the i-th number) 
has to be the smallest number or the X-th smallest number for some prime number X. 
Therefore, we have (1 + primes[i]) choices for the last number, where primes[i] is the number of prime numbers 
not greater than i. The rest of the first i - 1 numbers can be permuted in any of the pperm[i-1] ways. In other words,

pperm[1] = 1
pperm[i] = (1 + primes[i]) × pperm[i-1]
The answer is pperm[N]. We can precompute the values of pperm[i] for all i between 1 and 5,000,000, inclusive, 
and then answer each test case in O(1) time.*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000000+2;
const int MOD = 1e9+7;

bool p[MAXN];
long long dp[MAXN];

void sieve()
{
	for(int i = 4; i <= MAXN; i += 2) p[i] = true;

	for(int i = 3; i*i <= MAXN; i += 2)
	{
		if(!p[i]) 
		{
			for(int j = i*i; j <= MAXN; j += i)
				p[j] = true;
		}
	}

	dp[1] = 1;
	long long cnt = 1;

	for(int i = 2; i <= MAXN; ++i)
	{
		if(!p[i]) {
			cnt++;
		}

		dp[i] = ((cnt % MOD) * dp[i-1]) % MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sieve();

	int T; cin >> T;
	int N;
	vector<int> v;

	while(T--) {
		cin >> N;
		v.push_back(dp[N]);
	}

	for(auto i: v) cout << i << "\n";
}