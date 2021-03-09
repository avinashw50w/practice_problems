/*You are given an array containing n positive integers.

Your task is to divide the array into k subarrays so that the maximum sum in a subarray is as small as possible.

Input

The first input line contains two integers n and k: the size of the array and the number of subarrays in the division.

The next line contains n integers x1,x2,…,xn: the contents of the array.

Output

Print one integer: the maximum sum in a subarray in the optimal division.

Constraints
1≤n≤2⋅105
1≤k≤n
1≤xi≤109
Example

Input:
5 3
2 4 7 3 5

Output:
8
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5;

int n, k, a[maxn];

int main() {

    cin >> n >> k;
    int mx = -1e9;
    for (int i = 0; i < n; ++i) cin >> a[i], mx = max(mx, a[i]);

    ll l = (ll)mx, r = 1e18;
    while (l < r) {
        ll mid = (l + r) / 2;
        ll sum = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (sum + a[i] > mid) {
                cnt++;
                sum = 0;
            }
            sum += a[i];
        }
        cnt++;

        if (cnt <= k) r = mid;
        else l = mid + 1;
    }

    cout << l << "\n";
}