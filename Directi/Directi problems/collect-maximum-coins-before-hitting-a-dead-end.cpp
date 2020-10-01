/*Collect maximum coins before hitting a dead end
Given a character matrix where every cell has one of the following values.

'C' -->  This cell has coin

'#' -->  This cell is a blocking cell. 
         We can not go anywhere from this.

'E' -->  This cell is empty. We don't get
         a coin, but we can move from here.  
Initial position is cell (0, 0) and initial direction is right.

Following are rules for movements across cells.

If face is Right, then we can move to below cells

Move one step ahead, i.e., cell (i, j+1) and direction remains right.
Move one step down and face left, i.e., cell (i+1, j) and direction becomes left.
If face is Left, then we can move to below cells

Move one step ahead, i.e., cell (i, j-1) and direction remains left.
Move one step down and face right, i.e., cell (i+1, j) and direction becomes right.
Final position can be anywhere and final direction can also be anything. The target is to collect maximum coins.
The above problem can be recursively defined as below:

maxCoins(i, j, d):  Maximum number of coins that can be 
                    collected if we begin at cell (i, j)
                    and direction d.
                    d can be either 0 (left) or 1 (right)
*/

int solve(int mat[][C], int dp[][C][2], int i, int j, int dir) {

	if (!valid(i, j) or mat[i][j] == '#') return 0;

	if (dp[i][j][dir] != -1) return dp[i][j][dir];

	dp[i][j][dir] = (mat[i][j] == 'C') ? 1 : 0;

	if(dir == 1) 
		dp[i][j][dir] += max(solve(mat, dp, i, j+1, 1), solve(mat, dp, i+1, j, 0));

	if(dir == 0)
		dp[i][j][dir] += max(solve(mat, dp, i, j-1, 0), solve(mat, dp, i+1, j, 1));

	return dp[i][j][dir];
}

int maxCoins(int mat[R][C]) {
	
	int dp[R][C][2];
	memset(dp, -1, sizeof(dp));

	// As per the question initial cell is (0, 0) and direction
    // is right
	solve(mat, dp, 0, 0, 1)
}

