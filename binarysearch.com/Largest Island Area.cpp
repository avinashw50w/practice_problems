/*You are given a two-dimensional integer matrix of 1s and 0s. A 1 represents land and 0 
represents water, so an island is a group of 1s that are neighboring whose perimeter is 
surrounded by water. You can assume that the edges of the matrix are surrounded by water.

Return the area of the largest island in matrix.

Constraints

n, m ≤ 250 where n and m are the number of rows and columns in matrix
Example 1
Input
matrix = [
    [0, 0, 0, 1, 1, 1, 1],
    [0, 0, 0, 0, 0, 0, 0],
    [0, 1, 1, 1, 1, 1, 0],
    [0, 0, 1, 1, 0, 0, 0],
    [0, 0, 0, 0, 0, 1, 1],
    [0, 0, 0, 0, 0, 0, 0]
]
Output
7
Explanation
The largest island in the center has an area of 7 units.*/
int vis[251][251], cnt;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(vector<vector<int>> &mat, int x, int y) {
    int n = mat.size(), m = mat[0].size();
    
    if (x < 0 or y < 0 and x >= n or y >= m or mat[x][y] == 0 or vis[x][y]) return;
    vis[x][y] = 1;
    cnt++;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        dfs(mat, nx, ny);
    }
}

int solve(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    memset(vis, 0, sizeof(vis));

    // remove islands connected to  corners
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((i == 0 or j == 0 or i == n-1 or j == m-1)
            and mat[i][j] == 1 and !vis[i][j])
                dfs(mat, i, j);
        }
    }

    int ans = 0;
    // count the remaining islands
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 1 and !vis[i][j]) {
                cnt = 0;
                dfs(mat, i, j);
                ans = max(ans, cnt);
            }
        }
    }

    return cnt;
}