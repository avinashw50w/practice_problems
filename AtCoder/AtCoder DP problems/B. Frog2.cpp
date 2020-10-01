/**/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;

int main() {
    int N, K; 
    scanf("%d%d", &N, &K);

    vector<int> h(N), dp(N, INF);

    for (int &x: h)
        scanf("%d", &x);

    dp[0] = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j <= i+K; ++j) {
            if (j < N)
                dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
        }
    }

    printf("%d\n", dp[N-1]);
}