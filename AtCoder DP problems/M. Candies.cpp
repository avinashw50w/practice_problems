#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

void add_self(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

void sub_self(int &a, int b) {
    a -= b;
    if (a < 0) a += mod;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    // dp[i] : no of ways to distribute such that we used i candies
    int dp[k+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int child = 0; child < n; ++child) {
        int candy_lmt;
        scanf("%d", &candy_lmt);

        vector<int> partial_sum(k+1);

        for (int used = k; used >= 0; --used) {
            int L = used + 1;
            int R = used + min(k-used, candy_lmt);

            if (L <= R) {
                add_self(partial_sum[L], dp[used]);
            }
            if (R+1 <= k) {
                sub_self(partial_sum[R+1], dp[used]);
            }
        }

        int sum = 0;

        for (int i = 0; i <= k; ++i) {
            add_self(sum, partial_sum[i]);
            add_self(dp[i], sum);
        }

    }
    
    printf("%d\n", dp[k]);
}