/*Minimum Cost To Make Two Strings Identical
Given two strings X and Y, and two values costX and costY. We need to find minimum cost required to make 
the given two strings identical. We can delete characters from both the strings. The cost of deleting a 
character from string X is costX and from Y is costY. Cost of removing all characters from a string is same.

Examples:

Input :  X = "abcd", Y = "acdb", costX = 10, costY = 20.
Output:  30
For Making both strings identical we have to delete 
character 'b' from both the string, hence cost will
be = 10 + 20 = 30.

Input :  X = "ef", Y = "gh", costX = 10, costY = 20.
Output:  60
For making both strings identical, we have to delete 2-2
characters from both the strings, hence cost will be =
 10 + 10 + 20 + 20 = 60.
We strongly recommend you to minimize your browser and try this yourself first.

This problem is a variation of Longest Common Subsequence ( LCS ). 
The idea is simple, we first find the length of longest common subsequence of strings X and Y. 
Now subtracting len_LCS with lengths of individual strings gives us number of characters to be removed to make them identical.

Cost of making two strings identical is SUM of following two
   1) Cost of removing extra characters (other than LCS) from X[]
  2) Cost of removing extra characters (other than LCS) from Y[]
Minimum Cost to make strings identical = costX * (m - len_LCS) + 
                                         costY * (n - len_LCS).  

m ==> Length of string X
m ==> Length of string Y
len_LCS ==> Length of LCS Of X and Y.
costX ==> Cost of removing a character from X[]
costY ==> Cost of removing a character from Y[]

Note that cost of removing all characters from a string
is same.  */

int LCS(string X, string Y) {
	int N = X.length();
	int M = Y.length();

	int dp[N+1][M+1];
	memset(dp, 0, sizof(dp));

	REP(i, 1, N)
		REP(j, 1, M) {
			if(X[i-1] == Y[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else 
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}

	return dp[N][M];
}

int findMinCost(string X, string Y, int costX, int costY) {

	int N = X.length();
	int M = Y.length();

	int lcs_len = LCS(X, Y);

	int cost = costX * (N - lcs_len) + costY * (M - lcs_len);

	return cost;
}

