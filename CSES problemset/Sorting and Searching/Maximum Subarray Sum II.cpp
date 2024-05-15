/*Given an array of n integers, your task is to find the maximum sum of values in a contiguous subarray with length between a and b.
Input
The first input line has three integers n, a and b: the size of the array and the minimum and maximum subarray length.
The second line has n integers x_1,x_2,...,x_n: the array values.
Output
Print one integer: the maximum subarray sum.
Constraints

1 <= n <= 2 \cdot 10^5
1 <= a <= b <= n
-10^9 <= x_i <= 10^9

Example
Input:
8 1 2
-1 3 -2 5 3 -5 2 2

Output:
8*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<long long> sum(n+1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> sum[i + 1];
        sum[i + 1] += sum[i];
    }

    set<array<long long, 2>> st;
    long long ans = -1e18;

    for (int i = 0; i <= n; ++i) {
        if (i >= a)
            st.insert({sum[i - a], i - a});
        if (st.size())
            ans = max(ans, sum[i] - (*st.begin())[0]);
        if (i >= b)
            st.erase({sum[i - b], i - b});
    }

    cout << ans << endl;
}