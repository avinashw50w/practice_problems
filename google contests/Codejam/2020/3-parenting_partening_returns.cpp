/*Cameron and Jamie have a list of N activities to take care of during the day. Each activity happens during a specified interval during the day. They need to assign each activity to one of them, so that neither of them is responsible for two activities that overlap. An activity that ends at time t is not considered to overlap with another activity that starts at time t.

For example, suppose that Jamie and Cameron need to cover 3 activities: one running from 18:00 to 20:00, another from 19:00 to 21:00 and another from 22:00 to 23:00. One possibility would be for Jamie to cover the activity running from 19:00 to 21:00, with Cameron covering the other two. Another valid schedule would be for Cameron to cover the activity from 18:00 to 20:00 and Jamie to cover the other two. Notice that the first two activities overlap in the time between 19:00 and 20:00, so it is impossible to assign both of those activities to the same partner.

Given the starting and ending times of each activity, find any schedule that does not require the same person to cover overlapping activities, or say that it is impossible.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with a line containing a single integer N, the number of activities to assign. Then, N more lines follow. The i-th of these lines (counting starting from 1) contains two integers Si and Ei. The i-th activity starts exactly Si minutes after midnight and ends exactly Ei minutes after midnight.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is IMPOSSIBLE if there is no valid schedule according to the above rules, or a string of exactly N characters otherwise. The i-th character in y must be C if the i-th activity is assigned to Cameron in your proposed schedule, and J if it is assigned to Jamie.

1 ≤ T ≤ 100.
0 ≤ Si < Ei ≤ 24 × 60
2 ≤ N ≤ 1000

Input 
4
3
360 480
420 540
600 660
3
0 1440
1 3
2 4
5
99 150
1 100
100 301
2 5
150 250
2
0 720
720 1440

Output
Case #1: CJC
Case #2: IMPOSSIBLE
Case #3: JCCJJ
Case #4: CC
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (int i = (a); i < (b); ++i)

void solve() {
    int n; cin >> n;
    vector<pair<pair<int,int>,int>> v;
    
    rep(i, 0, n) {
        int s,e;
        cin >> s >> e;
        v.push_back({{s, e}, i});
    }
    
    sort(v.begin(), v.end());
    
    char ans[n];
    int A = 0, B = 0;
    for (auto e: v) {
        int start = e.first.first;
        int end = e.first.second;
        int idx = e.second;
        
        if (A <= start) {
            A = end;
            ans[idx] = 'C';
        }
        else if (B <= start) {
            B = end;
            ans[idx] = 'J';
        }
        else {
            puts("IMPOSSIBLE");
            return;
        }
    }
    ans[n] = '\0';
    puts(ans);
}

int main() {
    int t, caset = 0; cin >> t;
    while (t--) {
        printf("Case #%d: ", ++caset);
        solve();
    }
}

