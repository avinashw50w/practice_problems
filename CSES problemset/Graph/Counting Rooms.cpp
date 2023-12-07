/*You are given a map of a building, and your task is to count the number of its rooms. The size of the 
map is n xm squares, and each square is either floor or wall. You can walk left, right, up, and 
down through the floor squares.
Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).
Output
Print one integer: the number of rooms.
Constraints

1 <= n,m <= 1000

Example
Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3

IDEA: find connected components in a matrix */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
string mat[maxn];
int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y) {
    mat[x][y] = '#';
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 and nx < n and ny >= 0 and ny < m and mat[nx][ny] == '.')
            dfs(nx, ny);
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> mat[i];
    }
    int rooms = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == '.') {
                rooms++;
                dfs(i, j);
            }
        }
    }
    cout<< rooms;
}
