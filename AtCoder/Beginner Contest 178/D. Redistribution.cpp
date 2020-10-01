/*Given is an integer S.
Find how many sequences there are whose terms are all integers greater than or equal to 3,
and whose sum is equal to S. The answer can be very large, so output it modulo 10^9 + 7;
.*/

// simple knapsack
const int mod = 1e9 + 7;
int solve(int S) {
    vector<long long> dp(S + 1, 0);
    dp[0] = 1;

    for (int i = 3; i <= S; ++i) {
        for (int j = i; j <= S; ++j) dp[j] = (dp[j] + dp[j - i]) % mod;
    }
    return dp[S];
}