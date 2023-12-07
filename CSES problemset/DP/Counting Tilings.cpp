/*Your task is to count the number of ways you can fill an n x m grid using 1 x 2 and 2 x 1 tiles.
Input
The only input line has two integers n and m.
Output
Print one integer: the number of ways modulo 10^9+7.
Constraints

1 <= n <= 10
1 <= m <= 1000

Example
Input:
4 7

Output:
781

sol: https://www.youtube.com/watch?v=lPLhmuWMRag&ab_channel=KartikArora
*/
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int n, m;
// dp[col][mask] = # of ways to fill board upto column col such that the col has configuration mask,
// where mask represents the rows which are occupied
int dp[1001][1<<10];

void generate_next_masks(int row, int curr_mask, int next_mask, vector<int> &next_masks) {
    if (row == n) {
        next_masks.push_back(next_mask);
        return;
    }
    // if the row is already set, solve for next row
    if (curr_mask>>row&1) generate_next_masks(row+1, curr_mask, next_mask, next_masks);
    else {
        // if row is not set, we can place 1x2 tile horizontally, and this will lead 
        // to the next mask with the row'th bit set
        generate_next_masks(row+1, curr_mask, next_mask | (1<<row), next_masks);
        // if row and row+1 are not set, we can place 2x1 tile vertically, and this will 
        // lead to the next mask with row'th and row'th bit as 0
        if (row + 1 < n and (curr_mask&(1<<(row+1))) == 0)
            generate_next_masks(row+2, curr_mask, next_mask, next_masks);
    }
}

int solve(int col, int mask) {
    if (col == m) {
        return mask == 0;
    }
    if (dp[col][mask] != -1) return dp[col][mask];
    vector<int> next_masks;
    generate_next_masks(0, mask, 0, next_masks);

    int ans = 0;
    for (int next_mask: next_masks) {
        ans = (ans + solve(col+1, next_mask)) % mod;
    }

    return dp[col][mask] = ans;
}

int main() {
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout<< solve(0, 0);
}