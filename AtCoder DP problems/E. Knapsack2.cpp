/*There are N items, numbered 1 to N. For each i (1 <= i <= N), Item i has weight of wi and value vi 

Taro has decided to choose some of the N items and carry them home in a knapsack. The capacity of the knapsack is W, 
which means that the sum of the weights of items taken must be at most W.

Find the maximum possible sum of the values of items that Taro takes home.

Constraints
All values in input are integers.
1 <= N <= 100
1 <= W <= 10^9
1 <= wi <= W
1 <= vi <= 10^3
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18L + 5;

void min_self(ll &a, ll b) {
    a = min(a, b);
}

int main() {
    int N, W;
    scanf("%d%d", &N, &W);

    vector<int> weight(N), value(N);

    int max_val = 0;

    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &weight[i], &value[i]);
        max_val += value[i];
    }

    vector<ll> dp(max_val+1, INF);
    dp[0] = 0;
    // dp[i] - the minimum weight achievable by taking items of value exactly i

    for (int i = 0; i < N; ++i) {

        for (int v = max_val; v >= value[i]; --v)
            min_self(dp[v], dp[v-value[i]] + weight[i]);
    }

    ll ans = 0;

    for (ll i = 0; i <= max_val; ++i) {
        if (dp[i] <= W) ans = max(ans, i);
    }

    printf("%lld\n", ans);
}