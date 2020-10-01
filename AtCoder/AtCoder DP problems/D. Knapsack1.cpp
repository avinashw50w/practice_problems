#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void max_self(ll &a, ll b) {
    a = max(a, b);
}

int main() {
    int N, W;
    scanf("%d%d", &N, &W);

    vector<ll> dp(W+1);
    // dp[i] - the maximum value obtained by taking items of weight exactly i
    int value, weight;

    for (int item = 0; item < N; ++item) {
        scanf("%d%d", &weight, &value);

        for (int w = W; w >= weight; --w)
            max_self(dp[w], dp[w-weight] + value);
    }

    printf("%lld\n", dp[W]);
}