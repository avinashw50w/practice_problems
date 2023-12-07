/*There is a list of n numbers and two players who move alternately. On each move, a player removes 
either the first or last number from the list, and their score increases by that number. Both players try 
to maximize their scores.
What is the maximum possible score for the first player when both players play optimally?
Input
The first input line contains an integer n: the size of the list.
The next line has n integers x_1,x_2,\ldots,x_n: the contents of the list.
Output
Print the maximum possible score for the first player.
Constraints

1 <= n <= 5000
-10^9 <= x_i <= 10^9

Example
Input:
4
4 5 1 3

Output:
8*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000, inf = 1e9;
typedef long long ll;
ll dp[maxn][maxn];
ll score[maxn];

ll solve(int l, int r) {
    if (l == r) return score[l];
    if (l+1 == r) return max(score[l], score[r]);
    if (dp[l][r] != -1) return dp[l][r];
    ll op1 = score[l] + min(solve(l+2, r), solve(l+1, r-1));
    ll op2 = score[r] + min(solve(l, r-2), solve(l+1, r-1)) ;
    return dp[l][r] = max(op1, op2);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> score[i];
    }
    memset(dp, -1, sizeof(dp));
    cout<< solve(0, n-1);
}