/*You're given an array of N integer numbers.

The maximal sum of the array is the maximal sum of the elements of a nonempty consecutive subarray of this array. For example, the maximal 
sum of the array [1, -2, 3, -2, 5] is 6 because the sum of the subarray [3, -2, 5] is 6 and it is impossible to achieve greater subarray sum.

Now you're allowed to remove no more than one element from the given array. What is the maximal possible maximal sum of the resulting array 
you can achieve by doing so?

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains a single integer N denoting the number of elements in the given array.

The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output

For each test case, output a single line containing the maximal possible maximal sum of the array obtained by removing no more than one 
integer from the initial array.*/
/*PROBLEM:
Given an array A[1…N]A[1…N], what is the maximum subarray sum you can get by removing at most one element?

QUICK EXPLANATION:
For every position ii, compute the maximum subarray sum that ends in position ii. Call it E[i]E[i].
For every position ii, compute the maximum subarray sum that starts in position ii. Call it S[i]S[i].

Both can be done in O(N)O(N) using Kadane's algorithm/dynamic programming.

The answer is the largest among the following values:

The maximum in EE.
The maximum E[i−1]+S[i+1]E[i−1]+S[i+1] for every position 1<i<N  */

ll a[MAXN];

int main() {
	int t,n;
	si(t);
	while(t--){
		si(n);
		rep(i,0,n) sl(a[i]);

		ll prefix[n+2] = {}, suffix[n+2] = {};
		prefix[0] = a[0];
		suffix[n-1] = a[n-1];
		
		rep(i,1,n)
			prefix[i] = max(a[i], a[i] + prefix[i-1]);

		for(int i=n-2;i>=0;--i)
			suffix[i] = max(a[i], a[i] + suffix[i+1]);

		ll ans1 = -(1<<30);
		rep(i,1,n-1)
			ans1 = max(ans1, prefix[i-1] + suffix[i+1]);

		ll ans2 = *max_element(prefix, prefix+n);

		printf("%lld\n", max(ans1, ans2));
	}
	return 0;
}
