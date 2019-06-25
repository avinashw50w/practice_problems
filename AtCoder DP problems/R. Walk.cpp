#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
int n;

void add_self(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int mul(int a, int b) {
    return (ll)a * b % mod;
}

struct M {
    vector<vector<int>> a;
    M() {
        a.resize(n, vector<int>(n));
    }

    M operator*(const M &b) {
        M res;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    add_self(res.a[i][j], mul(a[i][k], b.a[k][j]));
                }
            }
        }

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll k;

    cin >> n >> k;
    
    M a;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cin >> a.a[i][j];
    }

    M ans;
    for (int i = 0; i < n; ++i)
        ans.a[i][i] = 1;

    while (k) {
        if (k & 1) ans = ans * a;
        a = a * a;
        k >>= 1;
    }

    int total = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) 
            add_self(total, ans.a[i][j]);
    }

    cout << total << endl;
}