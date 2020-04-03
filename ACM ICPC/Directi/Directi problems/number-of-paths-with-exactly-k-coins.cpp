/*Number of paths with exactly k coins
Given a matrix where every cell has some number of coins. Count number of ways to reach bottom right from top left 
with exactly k coins. We can move to (i+1, j) and (i, j+1) from a cell (i, j).

Example:

Input:  k = 12
        mat[][] = { {1, 2, 3},
                    {4, 6, 5},
                    {3, 2, 1}
                  };
Output:  2
There are two paths with 12 coins
1 -> 2 -> 6 -> 2 -> 1
1 -> 2 -> 3 -> 5 -> 1

The above problem can be recursively defined as below:

pathCount(m, n, k):   Number of paths to reach mat[m][n] from mat[0][0] 
                      with exactly k coins

If (m == 0 and n == 0)
   return 1 if mat[0][0] == k else return 0
Else:
    pathCount(m, n, k) = pathCount(m-1, n, k - mat[m][n]) + 
                         pathCount(m, n-1, k - mat[m][n]) */

int mat[N][M];
int dp[N][M][K];

int pathCountRec(int n, int m, int k) {
	if(n < 0 or m < 0) return 0;

	if(n == 0 and m == 0) return (k == mat[n][m]);

	if(dp[n][m][k] != -1) return dp[n][m][k];

	dp[n][m][k] = pathCountRec(n-1, m, k - mat[n][m]) + pathCountRec(n, m-1, k - mat[n][m]);

	return dp[n][m][k];
}

int pathCount(int N, int M, int K) {
	memset(dp, -1, sizeof(dp));

	return pathCountRec(N-1, M-1, K);
}