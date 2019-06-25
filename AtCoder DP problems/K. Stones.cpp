#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int main() {

    int N, K;
    scanf("%d%d", &N, &K);

    vector<int> a(N), dp(K+1);

    for (int &x: a) {
        scanf("%d", &x);
        dp[x] = 1;
    }

    for (int k = 1; k <= K; ++k) {
        for (int x: a) {
            if (k - x >= 0 and !dp[k-x]) {
                dp[k] = 1;
            }
        }
    }

    if (dp[K] == 1) printf("First\n");
    else printf("Second\n");
}