// find the subarray whose sum is divisible by K.
/*One way to solve this would be to compute a prefix sum array and compute all values mod K. This can be done like this -

prefix [i] = (prefix [i -1] + arr [i]) % K
Then this problem reduces to finding two indices i and j such that prefix[i] is equal to prefix [j]. This can be done in O(n) using a hash map.*/

void solve(int arr[], int N, int K) {

	map<int, int> M;
	int prefix = 0;

	REP(i, 0, N) {
		prefix = (prefix + arr[i]) % K;

		if (M.find(prefix) != m.end())
			printf("One such subarray is : %d %d\n", M[prefix], i);

		else M[prefix] = i;
	}
}