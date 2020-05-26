/*Dr. Patel has N stacks of plates. Each stack contains K plates. Each plate has a positive beauty value, describing how beautiful it looks.

Dr. Patel would like to take exactly P plates to use for dinner tonight. If he would like to take a plate in a stack, he must also take all of the plates above it in that stack as well.

Help Dr. Patel pick the P plates that would maximize the total sum of beauty values.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing the three integers N, K and P. Then, N lines follow. The i-th line contains K integers, describing the beauty values of each stack of plates from top to bottom.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the maximum total sum of beauty values that Dr. Patel could pick.*/

#include <bits/stdc++.h>
using namespace std;

int a[51][31];

void solve() {
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> dp(p+1, 0); // dp[i] - maximum beauty value if no of plates taken are i

    for (int i = 0; i < n; ++i) {
        vector<int> ndp = dp;
        for (int j = 0, sum = 0; j < k; ++j) {
            cin >> a[i][j];
            sum += a[i][j];
            // use j+1 plates
            for (int l = 0; l+j+1 <= p; ++l) {
                ndp[l+j+1] = max(ndp[l+j+1], dp[l] + sum);
            }
        }

        dp = ndp;
    }

    cout << dp[p] << "\n";
}

int main() {

    int t; cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        cout << "Case #" << tt << ": ";
        solve();
    }
}


//////////////////////////////
// top down approach

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 55;
const int K = 35;

int n, k, p;
int a[N][K];
int cache[N][N * K];

int dp(int idx, int taken)
{
    if(taken == 0)
        return 0;
    if(taken < 0)
        return -2e9;
    if(idx > n)
        return 0;
    int &ans = cache[idx][taken];
    if(ans != -1)
        return ans;
    ans = 0;
    int val = 0;
    for(int i = 0; i <= k; i++)
    {
        val += a[idx][i];
        ans = max(ans, val + dp(idx + 1, taken - i));
    }
    return ans;
}

int32_t main()
{
    IOS;
    int t;
    cin >> t;
    int tc = 0; 
    while(t--)
    {
        memset(cache, -1, sizeof(cache));
        tc++;
        cin >> n >> k >> p;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= k; j++)
                cin >> a[i][j];
        int ans = dp(1, p);
        cout << "Case #" << tc << ": " << ans << endl;
    }   
    return 0;
}