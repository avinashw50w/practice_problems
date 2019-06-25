/*Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.

The vacation consists of N days. For each i (1<= i <= N), Taro will choose one of the following activities and do it on the i-th day:

A: Swim in the sea. Gain ai points of happiness.
B: Catch bugs in the mountains. Gain bi points of happiness.
C: Do homework at home. Gain ci points of happiness.
As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

Find the maximum possible total points of happiness that Taro gains.

*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;

int main() {

    int N;
    scanf("%d", &N);

    // dp[i] - total points acquired when work i is done on the last day
    vector<int> dp(3);

    for (int day = 0; day < N; ++day) {
        vector<int> c(3);
        vector<int> new_dp(3, -INF);

        for (int i = 0; i < 3; ++i) scanf("%d", &c[i]);

        for (int i = 0; i < 3; ++i) // curr work done
            for (int j = 0; j < 3; ++j) { // next work that is to be done
                if (i != j)
                    new_dp[j] = max(new_dp[j], dp[i] + c[j]);
            }

        dp = new_dp;
    }

    printf("%d\n", max(dp[0], max(dp[1], dp[2])));
}