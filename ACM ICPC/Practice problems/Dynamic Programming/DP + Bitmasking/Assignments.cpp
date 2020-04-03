/*Your task will be to calculate number of different assignments of n different topics to n students such that everybody gets exactly one topic he likes.

Input

First line of input contains number of test cases c (1<=c<=80). Each test case begins with number of students n (1<=n<=20). Each of the next n lines contains n 
integers describing preferences of one student. 1 at the ith position means that this student likes ith topic, 0 means that he definitely doesn't want to take it.

Output

For each test case output number of different assignments (it will fit in a signed 64-bit integer).

Example

Input:
3
3
1 1 1
1 1 1
1 1 1  */

// note that the top down approach times out in spoj // 
// so we are using bottom up approach //
int n;
int a[21][21];

ll dp[(1<<20)];

ll solve(int n){
	mset(dp,0);
	dp[0] = 1;  // ways to assign 0 books to 0 students is 1
	// iterate over every set of students:
	for(int mask=1; mask<(1<<n); ++mask){
		// count the number of students in the current set:
		int k = __builtin_popcount(mask);
		// one by one assign the books to 
		for(int i=0;i<n;++i){
			// if the kth student prefers the ith book and has not been assigned this book:
			if(a[k][i] == 1 and (mask & (1<<i)) == 0)
				dp[mask | (1<<i)] += dp[mask];
		}
	}
	return dp[(1<<n)-1];
}
int main() {
	caset{
		si(n);
	
		rep(i,0,n){
			rep(j,0,n){
				si(a[i][j]);
			}
		}
		cout << solve(n) << endl;
	}

	return 0;
}
