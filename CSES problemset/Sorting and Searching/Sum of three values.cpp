/*You are given an array of n integers, and your task is to find three values (at distinct positions) whose sum is x.

Input

The first input line has two integers n and x: the array size and the target sum.

The second line has n integers a1,a2,…,an: the array values.

Output

Print three integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.

Constraints
1≤n≤5000
1≤x,ai≤109
Example

Input:
4 8
2 7 5 1

Output:
1 3 4*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5;

int n, x;
array<int, 2> a[maxn];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0], a[i][1] = i + 1;
    }
    sort(a, a + n);
    for (int i = 0; i < n - 2; ++i) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            if (a[i][0] + a[l][0] + a[r][0] == x) {
                cout << a[i][1] << " " << a[l][1] << " " << a[r][1];
                return 0;
            }
            if (a[i][0] + a[l][0] + a[r][0] < x) l++;
            else r--;
        }
    }

    cout << "IMPOSSIBLE\n";
}