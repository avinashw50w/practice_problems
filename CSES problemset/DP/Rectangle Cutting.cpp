/*Given an a x b rectangle, your task is to cut it into squares. On each move you can select a 
rectangle and cut it into two rectangles in such a way that all side lengths remain integers. What is the 
minimum possible number of moves?
Input
The only input line has two integers a and b.
Output
Print one integer: the minimum number of moves.
Constraints

1 <= a,b <= 500

Example
Input:
3 5

Output:
3*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 501, mod = 1e9+7, inf = 1e9+7;
int dp[maxn][maxn];

int main() {
    int a, b;
    cin >> a >> b;

    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (i != j) 
                dp[i][j] = inf;
            for (int k = 1; k < i; ++k) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            }
            for (int k = 1; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
            }
        }
    }
    cout<< dp[a][b];
}