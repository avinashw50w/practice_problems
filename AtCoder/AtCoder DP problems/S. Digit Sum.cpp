#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void add_self(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int  main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string k; 
    int D;
    cin >> k >> D;

    // dp[sum][tight] - no of digits chosen such that the sum of digits modulo D is 'sum'
    // and tight indicates whether we have chosen some digit less than in K
    vector<vector<int>> dp(D, vector<int> (2));
    dp[0][0] = 1;
    int len = k.length();

    for (int where = 0; where < len; ++where) {
        vector<vector<int>> new_dp(D, vector<int> (2));

        for (int sum = 0; sum < D; ++sum) {
            for (int tight : {0, 1}) {
                for (int digit = 0; digit <= 9; ++digit) {
                    if (digit > k[where] - '0' and !tight) break;
                    add_self(new_dp[(sum + digit) % D][tight || (digit < k[where] - '0')], dp[sum][tight]);
                }
            }
        }
        dp = new_dp;
    }
    int ans = (dp[0][true] + dp[0][false]) % mod;
    --ans;
    if (ans < 0) ans += mod;

    cout << ans << "\n";
}