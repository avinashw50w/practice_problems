#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
vector<int> G[maxn];

ll mul(ll a, ll b) {
    return (a * b) % mod;
}

pair<ll,ll> dfs(int a, int par) {
    
    ll all_white = 1;
    ll some_black = 0;

    for (int b: G[a]) {
        if (b == par) continue;
        pair<ll,ll> p = dfs(b, a);
        // p.first - no of ways to color the subtree rooted at b such that b is colored black
        // p.second - no of ways to color the subtree rooted at b such that b is colored white
        ll tmp_white = all_white;
        // a will be colored black iff all its children are colored white
        all_white = mul(all_white, p.second);
        // a will be colored white if 0 or more of its children are colored black
        some_black = (mul(tmp_white, p.first) + mul(some_black, p.first + p.second)) % mod;
    }

    return { all_white, (all_white + some_black) % mod };
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;

    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b; 
        G[a].push_back(b);
        G[b].push_back(a);
    }

    pair<ll,ll> p = dfs(1, -1);

    cout << ((p.first + p.second) % mod )<< "\n";
}