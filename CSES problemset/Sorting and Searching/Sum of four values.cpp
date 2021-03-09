/*You are given an array of n integers, and your task is to find four values (at distinct positions) whose sum is x.

Input

The first input line has two integers n and x: the array size and the target sum.

The second line has n integers a1,a2,…,an: the array values.

Output

Print four integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.

Constraints
1≤n≤1000
1≤x,ai≤109
Example

Input:
8 15
3 2 5 8 1 3 2 3

Output:
2 4 6 7*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1001;

int n, x;
array<int, 2> a[maxn];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        a[i][1] = i + 1;
    }

    map < ll, vector<array<int, 2>> > mp;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int val = x - (a[i][0] + a[j][0]);
            if (mp.count(val)) {
                for (auto p : mp[val]) {
                    int k = p[0], l = p[1];
                    if (i != k and i != l and j != k and j != l) {
                        cout << a[i][1] << " " << a[j][1] << " " << a[k][1] << " " << a[l][1];
                        return 0;
                    }
                }
            }

            mp[a[i][0] + a[j][0]].push_back({i, j});
        }
    }

    cout << "IMPOSSIBLE\n";
}