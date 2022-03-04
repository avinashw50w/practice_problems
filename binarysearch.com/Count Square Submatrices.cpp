/*Given a two-dimensional list of integers matrix containing 1s and 0s, return the total number of square submatrices with all 1 s.

Constraints

n, m ≤ 250 where n and m are the number of rows and columns in matrix.
Example 1
Input
matrix = [
    [1, 1, 0],
    [1, 1, 0]
]
Output
5*/
int solve(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 1) {
                dp[i+1][j+1] = 1 + min(dp[i+1][j], 
                                    min(dp[i][j+1], dp[i][j]));
                ans += dp[i+1][j+1];
            }
        }
    }

    return ans;
}