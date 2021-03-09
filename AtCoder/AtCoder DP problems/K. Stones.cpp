/*There is a set A = {a1, a2, ..., an} consisting of N positive integers.
Taro and Jiro will play the following game against each other.

Initially, we have a pile consisting of K stones.
The two players perform the following operation alternately, starting from Taro:
Choose an element x in A, and remove exactly x stones from the pile.
A player loses when he becomes unable to play. Assuming that both players play optimally, determine the winner.

Constraints:
1 ≤ N ≤ 100
1 < K < 10^5
1 <= a1 < a2 < a3 ... < an <= K
All values in input are integers.*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int main() {

    int N, K;
    scanf("%d%d", &N, &K);
    // dp[i] = true if the first player wins and there are i stones left
    vector<int> a(N), dp(K + 1);

    for (int &x : a) {
        scanf("%d", &x);
        dp[x] = 1;
    }

    for (int k = 1; k <= K; ++k) {
        for (int x : a) {
            if (k - x >= 0 and !dp[k - x]) {
                dp[k] = 1;
            }
        }
    }

    if (dp[K] == 1) printf("First\n");
    else printf("Second\n");
}