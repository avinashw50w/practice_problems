/*You have n coins with certain values. Your task is to find all money sums you can create using these coins.
Input
The first input line has an integer n: the number of coins.
The next line has n integers x_1,x_2,...,x_n: the values of the coins.
Output
First print an integer k: the number of distinct money sums. After this, print all possible sums in increasing order.
Constraints

1 <= n <= 100
1 <= x_i <= 1000

Example
Input:
4
4 2 5 2

Output:
9
2 4 5 6 7 8 9 11 13*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int dp[maxn*(maxn+1)/2 + 1];

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        sum += coins[i];
    }

    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = sum; j >= coins[i]; --j) {
            dp[j] |= dp[j-coins[i]];
        }
    }
    vector<int> res;
    int total = 0;
    for (int i = 1; i <= sum; ++i) {
        if (dp[i]) {
            total++;
            res.push_back(i);
        }
    }

    cout << total << '\n';
    for (int e: res) cout<<e<<" ";
}