#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3000 + 2;
ll dp[maxn][maxn];
int a[maxn];

ll solve(int l, int r) {
    if (l > r) return 0;
    if (l == r) return a[l];
    ll &res = dp[l][r];
    if (res != -1) return res;

    ll op1 = a[l] + min(solve(l+2, r), solve(l+1, r-1));
    ll op2 = a[r] + min(solve(l, r-2), solve(l+1, r-1));

    res = max(res, max(op1, op2));
    return res;
}

int main() {

    int n;
    scanf("%d", &n);
    ll sum = 0L;

    for (int &x: a) {
        scanf("%d", &x);
        sum += x;
    }

    memset(dp, -1, sizeof(dp));

    cout << (2*solve(0, n-1) - sum);
}