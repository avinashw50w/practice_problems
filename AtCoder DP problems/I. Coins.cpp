#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    scanf("%d", &N);
    vector<double> p(N);

    // dp[i] : probability of getting i heads so far
    vector<double> dp(N+1);
    dp[0] = 1;
    double p_heads;

    for (int coins = 0; coins < N; ++coins) {
        scanf("%lf", &p_heads);
        for (int i = coins + 1; i >= 0; --i) {
            /*prob of getting i heads when no of coins are (coins+1) =
                prob of getting i-1 heads * prob of getting head +
                prob of getting i heads when no of coins are (coins) * prob of getting tail
             */
            dp[i] = dp[i-1] * p_heads + dp[i] * (1 - p_heads);
        }
    }

    double ans = 0;

    for (int head = 0; head <= N; ++head) {
        int tail = N - head;

        if (head > tail) ans += dp[head];
    }

    printf("%.10lf\n", ans);
}