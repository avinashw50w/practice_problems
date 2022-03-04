/*You are given a two-dimensional integer matrix board containing 0s, 1s and 2s representing 
some n x n chessboard. Each 0 represents an empty cell, 1 represents the knight and 2 represents 
the king. There is at least one knight but exactly one king.

Given that the king stays still, return the minimum number of moves it would take for some knight to land on the king. If there's no solution, return -1. A knight can't land on another knight.

Constraints

2 ≤ n ≤ 500 where n is the number of rows and columns in board
1 ≤ t < n * n where t is the number of knights
k = 1 where k is the number of kings.
Example 1
Input
board = [
    [1, 0, 0, 0, 0],
    [0, 0, 0, 0, 0],
    [0, 0, 0, 0, 2],
    [1, 0, 0, 0, 0],
    [0, 0, 0, 0, 0]
]
Output
2*/

int solve(vector<vector<int>>& mat) {
    int n = mat.size();
    const int inf = 1e9 + 7;
    const int dx[8] = { 1, 1, -1, -1, 2, 2, -2, -2 };
    const int dy[8] = { 2, -2, 2, -2, 1, -1, 1, -1 };

    vector<vector<int>> dist(n, vector<int> (n, inf));
    queue<array<int,2>> q;
    int si, sj, di, dj;
    // push the king to the queue
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 2) {
                dist[i][j] = 0;
                q.push({ i, j });
                break;
            }
        }
    }

    while (q.size()) {
        auto top = q.front(); q.pop();
        int x = top[0], y = top[1];
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 and ny >= 0 and nx < n and ny < n 
            and mat[nx][ny] != 2 and dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                if (mat[nx][ny] == 1) return dist[nx][ny];
                q.push({ nx, ny });
            }
        }
    }

    return -1;
}