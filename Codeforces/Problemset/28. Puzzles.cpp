#include <iostream>
using namespace std;

int main() {
    int n, m, a[50], mn = INT_MAX;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) cin >> a[i];
    for (int i = 0; i < m-n+1; ++i) {
        int j = i+n-1;
        mn = min(mn, a[j]-a[i]);
    }

    cout << mn << endl;
}