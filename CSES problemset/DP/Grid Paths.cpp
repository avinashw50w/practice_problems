/*Consider an n×n grid whose squares may have traps. It is not allowed to move to a square with a trap.

Your task is to calculate the number of paths from the upper-left square to the lower-right square where you only can move right or down.

Input

The first input line has an integer n: the size of the grid.

After this, there are n lines that describe the grid. Each line has n characters: . denotes an empty cell, and * denotes a trap.

Output

Print the number of paths modulo 109+7.

Constraints
1≤n≤1000
Example

Input:
4
....
.*..
...*
*...

Output:
3*/
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n; cin >> n;
    string grid[n];
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) cin >> grid[i];

    dp[0][0] = grid[0][0] == '.';

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '.') {
                if (i) dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
                if (j) dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
            }
            else dp[i][j] = 0;
        }
    }
    cout << dp[n-1][n-1] << "\n";    
}