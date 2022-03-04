/*You are given a two-dimensional integer matrix containing 0s and 1s where 0 represents water 
and 1 represents land. Return a new matrix of the same dimensions where we increase the height 
of every land cell as much as possible given that:

The height of any water cell stays 0
Any cell can differ by at most 1 unit of height between neighboring cells (up, down, left, right)
You can assume there is at least one water cell.

Constraints

n, m ≤ 250 where n and m are the number of rows and columns in matrix
Example 1
Input
matrix = [
    [0, 1, 0],
    [1, 1, 1],
    [1, 1, 1]
]
Output
[
    [0, 1, 0],
    [1, 2, 1],
    [2, 3, 2]
]

IDEA: use multi-source bfs. 
take all 0's as the source and insert them into queue. Then do a bfs
On first encountering a 1, update its distance*/

vector<vector<int>> solve(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    const int dx[4] = { 1, 0, -1, 0 };
    const int dy[4] = { 0, 1, 0, -1 };
    int dist[n][m];
    memset(dist, -1, sizeof(dist));

    queue<array<int,2>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 0) {
                q.push({ i, j });
                dist[i][j] = 0;
            }
        }
    }

    while (q.size()) {
        auto top = q.front(); q.pop();
        int x = top[0], y = top[1];
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 and ny >= 0 and nx < n and ny < m 
                and mat[nx][ny] == 1 and dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 1) mat[i][j] = dist[i][j];
        }
    }
    return mat;
}