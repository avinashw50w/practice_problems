#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5;
int n, k;
array<ll, 2> med = {-1};
ll a[maxn];
set<array<ll, 2>> big, small;
ll sSum, bSum;

void fix() {
    int sz = 1 + small.size() + big.size();
    if (small.size() < (sz - 1) / 2) {
        small.insert(med);
        sSum += med[0];
        med = *big.begin();
        big.erase(med);
        bSum -= med[0];
    } else if (small.size() > (sz - 1) / 2) {
        big.insert(med);
        bSum += med[0];
        med = *--small.end();
        small.erase(med);
        sSum -= med[0];
    }
}

void add(array<ll, 2> x) {
    if (med[0] == -1) {
        med = x;
        return;
    }
    if (x < med) {
        small.insert(x);
        sSum += x[0];
    }
    else {
        big.insert(x);
        bSum += x[0];
    }

    fix();
}

void rem(array<ll, 2> x) {
    if (x == med) {
        med = *big.begin();
        big.erase(med);
        bSum -= med[0];
    }
    else if (x < med) {
        small.erase(x);
        sSum -= x[0];
    }
    else {
        big.erase(x);
        bSum -= x[0];
    }

    fix();
}
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i)  {
        cin >> a[i];
    }
    // for window of size 1, we just need to print the array
    if (k == 1) {
        for (int i = 0; i < n; ++i) {
            cout << 0 << " ";
        }
        return 0;
    }

    for (int i = 0; i < k-1; ++i) {
        add({a[i], i});
    }

    for (int i = k-1; i < n; ++i) {
        add({a[i], i});
        cout << (bSum - med[0] * big.size()) + (med[0] * small.size() - sSum) << " ";
        rem({a[i-k+1], i-k+1});
    }
}