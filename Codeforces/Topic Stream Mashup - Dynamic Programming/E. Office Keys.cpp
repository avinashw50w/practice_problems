int solve() {
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> a, b;
    for (int &x: a) cin >> x;
    for (int &x: b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    const int inf = 1e9 + 7;
    int dp[k+1][n+1];
    fill(&dp[0][0], &dp[k][0], inf);

    dp[0][0] = 0;

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j <= n; ++j) {
            // don't assign key i to person j
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            // assign the ith key to jth person
            if (j < n) 
                dp[i+1][j+1] = min(dp[i+1][j+1], max(dp[i][j], abs(a[j] - b[i]) + abs(b[i] - p)));
        }
    }

    return dp[k][n];
}