/*There are n people who want to get to the top of a building which has only one elevator. You know the 
weight of each person and the maximum allowed weight in the elevator. What is the minimum number of 
elevator rides?
Input
The first input line has two integers n and x: the number of people and the maximum allowed weight in the elevator.
The second line has n integers w_1,w_2,...,w_n: the weight of each person.
Output
Print one integer: the minimum number of rides.
Constraints

1 <= n <= 20
1 <= x <= 10^9
1 <= w_i <= x

Example
Input:
4 10
4 8 6 1

Output:
2*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;

int main() {
    int n, x; 
    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    pair<int, int> dp[1<<n]; // {rides, weight}

    dp[0] = {0, x+1};

    for (int mask = 1; mask < (1<<n); ++mask) {
        dp[mask] = {inf, 0};
        for (int i = 0; i < n; ++i) {
            if (mask>>i&1) {
                auto [rides, weight] = dp[mask^(1<<i)];
                if (weight + w[i] > x) {
                    rides++;
                    weight = min(weight, w[i]);
                }
                else weight += w[i];

                dp[mask] = min(dp[mask], {rides, weight});
            }
        }
    }

    cout<< dp[(1<<n)-1].first;
}