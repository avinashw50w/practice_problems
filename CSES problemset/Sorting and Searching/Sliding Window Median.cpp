#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)  {
        cin >> a[i];
    }

    multiset<int> window(a.begin(), a.begin() + k);
    auto it = next(window.begin(), (k-1)/2);

    for (int i = k; ; ++i) {
        int median = k & 1 ? *it : min(*it, *next(it));
        cout << median << " ";

        if(i == n) break;

        window.insert(a[i]);
        
        if (a[i] < *it) 
            --it;

        if (a[i-k] <= *it)
            ++it;

        window.erase(window.lower_bound(a[i-k]));
    }
}

////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int n, k;
array<int, 2> med = {-1};
int a[maxn];
set<array<int, 2>> big, small;

void fix() {
    int sz = 1 + small.size() + big.size();
    if (small.size() < (sz - 1) / 2) {
        small.insert(med);
        med = *big.begin();
        big.erase(med);
    } else if (small.size() > (sz - 1) / 2) {
        big.insert(med);
        med = *--small.end();
        small.erase(med);
    }
}

void add(array<int, 2> x) {
    if (med[0] == -1) {
        med = x;
        return;
    }
    if (x < med) 
        small.insert(x);
    else
        big.insert(x);

    fix();
}

void rem(array<int, 2> x) {
    if (x == med) {
        med = *big.begin();
        big.erase(med);
    }
    else if (x < med)
        small.erase(x);
    else
        big.erase(x);

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
            cout << a[i] << " ";
        }
        return 0;
    }

    for (int i = 0; i < k-1; ++i) {
        add({a[i], i});
    }

    for (int i = k-1; i < n; ++i) {
        add({a[i], i});
        cout << med[0] << " ";
        rem({a[i-k+1], i-k+1});
    }
}