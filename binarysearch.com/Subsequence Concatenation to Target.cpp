/*Given strings source and target, return the minimum number of subsequences of source we can form such that their concatenation equals target. If it's not possible, return -1.

Constraints

n ≤ 100,000 where n is the length of source
Example 1
Input
source = "abc"
target = "abcbcc"
Output
3
Explanation
We can have the following subsequences of source: "abc" + "bc" + "c"*/
int solve(string source, string target) {
    int n = source.length(), m = target.length();
    vector<vector<int>> pos(26);
    for (int i = 0; i < n; ++i) {
        pos[source[i]-'a'].push_back(i);
    }

    int j = 0, minPos = -1, cnt = 0;
    while (j < m) {
        char c = target[j]-'a';
        if (pos[c].empty()) return -1;
        int k = upper_bound(pos[c].begin(), pos[c].end(), minPos) - pos[c].begin();
        if (k < pos[c].size()) {
            minPos = pos[c][k];
            j++;
        }
        else {
            cnt++;
            minPos = -1;
        }
    }

    return cnt + 1;
}