#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1e3 + 3;

char grid[maxn][maxn];
ll dp[maxn][maxn];

void add_self(ll &a, ll b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

int main() {

    int H, W;
    scanf("%d%d", &H, &W);

    for (int i = 0; i < H; ++i) {
        scanf("%s", grid[i]);
    }

    dp[0][0] = 1;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == '.') {
                if (i-1 >= 0) add_self(dp[i][j], dp[i-1][j]);
                if (j-1 >= 0) add_self(dp[i][j], dp[i][j-1]);
            }
        }
    }

    printf("%lld\n", dp[H-1][W-1]);
}