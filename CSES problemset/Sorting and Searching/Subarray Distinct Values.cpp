#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    unordered_map<int, int> mp;
    long long ans = 0;
    for (int st = 0, end = 0; end < n; ++end) {
        mp[a[end]]++;
        while (st < end and mp.size() > k) {
            mp[a[st]]--;
            if (!mp[a[st]]) mp.erase(a[st]);
            st++;
        }
        ans += end - st + 1LL;
    }
    cout << ans << "\n";
}