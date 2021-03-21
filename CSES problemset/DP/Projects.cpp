/*There are n projects you can attend. For each project, you know its starting and ending days and the amount of money you would get as reward. You can only attend one project during a day.

What is the maximum amount of money you can earn?

Input

The first input line contains an integer n: the number of projects.

After this, there are n lines. Each such line has three integers ai, bi, and pi: the starting day, the ending day, and the reward.

Output

Print one integer: the maximum amount of money you can earn.

Constraints
1≤n≤2⋅105
1≤ai≤bi≤109
1≤pi≤109
Example

Input:
4
2 4 4
3 6 6
6 8 2
5 7 3

Output:
7*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Project {
    int st, end, val;
    Project(int a, int b, int c) {
        st = a;
        end = b;
        val = c;
    }
};

int main() {
    int n; cin >>n;
    vector<Project> v;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(Project(a, b, c));
    }

    sort(v.begin(), v.end(), [](const Project &a, const Project &b) {
        return a.end < b.end;
    });

    set<array<int, 2>> dp;
    // dp[0] - end time of project
    // dp[1] - max cost so far
    dp.insert({ 0, 0 });
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        // find the first project whose end time is >= end time of the ith project
        auto it = dp.lower_bound({ v[i].st });
        // we take the previous project so that it's end time < end time of ith project
        --it;
        ans = max(ans, (*it)[1] + v[i].val);
        dp.insert({ v[i].end, ans });
    }

    cout << ans << "\n";
}