/*Given an array of n integers, your task is to count the number of subarrays where the sum of values is divisible by n.

Input

The first input line has an integer n: the size of the array.

The next line has n integers a1,a2,…,an: the contents of the array.

Output

Print one integer: the required number of subarrays.

Constraints
1≤n≤2⋅105
−109≤ai≤109
Example

Input:
5
3 1 2 7 4

Output:
1*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5;

int main() {
    int n; cin >> n;
    map<ll, int> mp;
    ll sum = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        sum = (sum + a % n + n) % n;
        ans += sum == 0;
        ans += mp[sum];
        mp[sum]++;
    }

    cout << ans << "\n";
}