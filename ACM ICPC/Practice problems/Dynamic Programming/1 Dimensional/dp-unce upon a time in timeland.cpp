/*Our hero Mr X, is in critical condition, has very less time left.

Today's the inaugural day of a new time-bank. So they are giving away free time-amount worth 1000 years.

Bank released N slips, A[1], A[2], .... A[N]. Each slip has a time-amount(can be +ve as well as -ve).

A person can pick any number of slips(even none, or all of them, or some of them) out of the N slips. But bank introduced a restriction, they announced one more 
number K. Restriction is that, if a person picks a slip A[i], then the next slip that he can choose to pick will be A[i+K+1]. It means there should be a 
difference of atleast K between the indices of slips picked.

Now slip(s) should be picked in such a way that their sum results in maximum positive time-amount sum possible with the given restriction.

If you predict the maximum positive sum possible, then you win.

Mr X has asked for your help. Help him win the lottery, and make it quick!

Input Format:
First line of the test file contains single number T, the number of test cases to follow.
Each test case consists of two lines.
First line contains two numbers N and K , separated by a space. Second line contains the N numbers A[1], A[2] ..... A[N] separated by space.

Output Format:
For every test case, output in a single line the maximum positive sum possible, that is output for the case.

Constraints:
T ≤ 250
N ≤ 10000
-109 ≤ A[i] ≤ 109
0 ≤ K ≤ N-1 

SAMPLE INPUT 
2
10 1
1 2 -3 -5 4 6 -3 2 -1 2
10 2
1 2 -3 -5 4 6 -3 2 -1 2

SAMPLE OUTPUT 
12
10 */
/*Just like all dp problems we first need to define state here.

We take the state as f (idx) where f (idx) will tell us the current maximum until index idx.
Base case will be when f (idx >= N) which is 0 where N is length of the given cost array.

It is a knapsack style dp, where for every index we make a choice whether to take it or leave it.
If we leave it, next state will be f (idx + 1). If we take it, next state will be f (idx + K + 1) and we add the cost of ith item to the overall cost.

Recurrence:

f (idx) = max (f (idx + 1), cost [idx] + f (idx + K + 1))
f (idx) = 0 [idx >= N]  (base case)

Time Complexity: O (N)
Space Complexity: O (N)*/
#include <bits/stdc++.h>
using namespace std;

int n, k, cost[10000+1];
long long dp[10000+1];

long long solve(int idx) {
	if(idx >= n) return 0;

	if(dp[idx] != -1) return dp[idx];

	long long ret = max(solve(idx+1), cost[idx] + solve(idx+k+1));

	return dp[idx] = ret;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		 cin>>n>>k;

		 for(int i=0;i<n;++i) cin>>cost[i];

		 memset(dp, -1, sizeof(dp));

		 cout << solve(0) << endl;
	}
}