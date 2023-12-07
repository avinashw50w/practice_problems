/*You are given a map of a labyrinth, and your task is to find a path from start to end. You can walk 
left, right, up and down.
Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the labyrinth. Each character is . (floor), # (wall), A 
(start), or B (end). There is exactly one A and one B in the input.
Output
First print "YES", if there is a path, and "NO" otherwise.
If there is a path, print the length of the shortest such path and its description as a string consisting 
of characters L (left), R (right), U (up), and D (down). You can print any valid solution.
Constraints

1 <= n,m <= 1000

Example
Input:
5 8
########
#.A#...#
#.##.#B#
#......#
########

Output:
YES
9
LDDRRRRRU

IDEA: use bfs to find the shortest path and keep track of the direction to backtrack the path.*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
string mat[maxn], path[maxn];
int dir[maxn][maxn];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char dc[4] = {'D', 'R', 'U', 'L'};

int main() {
    int n, m;
    cin >> n >> m;

    int si, sj, ti, tj;

    queue<array<int,2>> q;
    for (int i = 0; i < n; ++i) {
        cin >> mat[i];

        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 'A') si = i, sj = j;
            if (mat[i][j] == 'B') ti = i, tj = j, mat[i][j] = '.';
        }
        path[i] = string(m, 0);
    }
    
    q.push({si, sj});

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i<4; ++i) {
            int nx = x+dx[i], ny=y+dy[i];
            if (nx>=0 and nx<n and ny>=0 and ny<m and mat[nx][ny] == '.') {
                q.push({nx, ny});
                mat[nx][ny] = '#';
                path[nx][ny] = dc[i];
                dir[nx][ny] = i;
            }
        }
    }

    if (path[ti][tj]) {
        cout << "YES\n";
        string t;
        while (!(ti == si and tj == sj)) {
            t += path[ti][tj];
            // u->d, d->u, l->r, r->l
            int prev = dir[ti][tj] ^ 2;
            ti += dx[prev];
            tj += dy[prev];
        }
        reverse(t.begin(), t.end());
        cout << t.size() <<'\n';
        cout<< t;
    } else {
        cout <<"NO\n";
    }
}