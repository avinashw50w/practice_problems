/*Maximum size square sub-matrix with all 1s
Given a binary matrix, find out the maximum size square sub-matrix with all 1s.

For example, consider the below binary matrix.

 
   0  1  1  0  1 
   1  1  0  1  0 
   0  1  1  1  0
   1  1  1  1  0
   1  1  1  1  1
   0  0  0  0  0
The maximum square sub-matrix with all set bits is

    1  1  1
    1  1  1
    1  1  1

 1) Construct a sum matrix S[R][C] for the given M[R][C].
     a)	Copy first row and first columns as it is from M[][] to S[][]
     b)	For other entries, use following expressions to construct S[][]
         If M[i][j] is 1 then
            S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1
         Else //If M[i][j] is 0
            S[i][j] = 0
2) Find the maximum entry in S[R][C]
3) Using the value and coordinates of maximum entry in S[i], print 
   sub-matrix of M[][]
For the given M[R][C] in above example, constructed S[R][C] would be:

   0  1  1  0  1
   1  1  0  1  0
   0  1  1  1  0
   1  1  2  2  0
   1  2  2  3  1
   0  0  0  0  0  */

int maxSubmatrix(int mat[N][M]) {

	int dp[N][M];
	
	memset(dp, 0, sizeof(dp));

	REP(i, 0, N) dp[i][0] = mat[i][0];

	REP(j, 0, M) dp[0][j] = mat[0][j];

	REP(i, 1, N) 
		REP(j, 1, M) 
			if(mat[i][j] == 1)
				dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));	// this can also be written as dp[i][j] = mat[i][j] + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));


	int maxSquareSize = INT_MIN;
	int posi, posj;

	REP(i, 0, N)
		maxSquareSize = max(maxSquareSize, *max_element(dp[i], dp[i] + M));

	return maxSquareSize;
}
