/*Alice likes to shop online. The main reason is that she gets a lot of discounts! There are M online shops 
from where she purchases her items. The prices of the same item vary in both the shops. She needs to buy N 
items in all. And each she can buy each item in any one of the shops. All the shops offer certain discounts. 
If she buys the ith item in one shop, she gets a discount coupon for the i+1th item in the same shop. 
But if she purchases the i+1th item from a different shop, she cannot use the discount coupon.
For example, if she buys the ith item in Shop j and gets a discount of X rupees. Let the price of 
i+1th item be Y rupees in shop j and Z rupees in shop k. If she purchases the i+1th item from shop j 
she can use the discount coupon and hence, will have to pay Y-X rupees. If she purchases the i+1th item 
from shop k she cannot use the discount coupon and hence, will have to pay Z rupees.

Note: If the discount given is more than price of the item in the shop, 
i.e. if Y-X < 0, the item is given free but she does NOT get any money back.


Alice wants to spend as less as possible and wants your help. She starts buying from item 1 
and goes on till item N in that order. Your task is simple. Tell her the least amount to spend to get all the N items.

Input:
First line of input contains a single integer T, the number of test cases.

Each test case starts with a line consisting of two space separated integers N & M.
The next N lines consist of M space separated integers each. 
The jth number on the ith line denotes the price of ith item in the jth shop.

The next N lines consist of M space separated integers each. 
The jth number on the ith line denotes the value of discount coupon given after purchasing ith item in the jth shop.






Output:
For each test case, output on a separate line the least amount that has to be spent to get all the N items.




Constraints:
1 ≤ T ≤ 10
2 ≤ N, M ≤ 100000
0 ≤ Prices, Discounts ≤ 1000000
1 ≤ T * N * M ≤ 1000000

Example:
Input:

2
2 2
3 4
1 2
1 0
0 1
2 4
1 2 3 4
4 3 2 1
2 3 2 1
1 2 1 1


Output:

3
2*/
#include <bits/stdc++.h>
using namespace std;


#define REP(i,a,b) for(int i = a; i < b; ++i)
typedef long long ll;
const ll INF = (ll)1e8;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) {
        int N, M;
        cin >> N >> M;

        ll cost[N][M], disc[N][M], dp[N+1][M+1];

        REP(i, 0, N)
            REP(j, 0, M)
                cin >> cost[i][j];

        REP(i, 0, N)
            REP(j, 0, M)
                cin >> disc[i][j];

        ll prevCost = INF*INF, prevCost2;

        REP(i, 0, M) {
            dp[0][i] = cost[0][i];
            prevCost = min(prevCost, dp[0][i]);
        }

        REP(i, 1, N) {
            prevCost2 = INF*INF;
            REP(j, 0, M) {

                ll c = max(0LL, cost[i][j] - disc[i-1][j]);

                dp[i][j] = min(dp[i-1][j] + c, prevCost + cost[i][j]);

                prevCost2 = min(prevCost2, dp[i][j]);
            }
            prevCost = prevCost2;
        }

        ll ans = INF*INF;

        REP(i, 0, M)
            ans = min(ans, dp[N-1][i]);

        cout << ans << "\n";
    }
}