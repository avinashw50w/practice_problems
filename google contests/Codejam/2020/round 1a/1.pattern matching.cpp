/*Many terminals use asterisks (*) to signify "any string", including the empty string. For example, when listing files matching BASH*, a terminal may list BASH, BASHER and BASHFUL. For *FUL, it may list BEAUTIFUL, AWFUL and BASHFUL. When listing B*L, BASHFUL, BEAUTIFUL and BULL may be listed.

In this problem, formally, a pattern is a string consisting of only uppercase English letters and asterisks (*), and a name is a string consisting of only uppercase English letters. A pattern p matches a name m if there is a way of replacing every asterisk in p with a (possibly empty) string to obtain m. Notice that each asterisk may be replaced by a different string.

Given N patterns, can you find a single name of at most 104 letters that matches all those patterns at once, or report that it cannot be done?

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with a line with a single integer N: the number of patterns to simultaneously match. Then, N lines follow, each one containing a single string Pi representing the i-th pattern.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is any name containing at most 10^4 letters such that each Pi matches y according to the definition above, or * (i.e., just an asterisk) if there is no such name.

Limits
Time limit: 20 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.
2 ≤ N ≤ 50.
2 ≤ length of Pi ≤ 100, for all i.
Each character of Pi is either an uppercase English letter or an asterisk (*), for all i.
At least one character of Pi is an uppercase English letter, for all i.
Sample

Input
2
5
*CONUTS
*COCONUTS
*OCONUTS
*CONUTS
*S
2
*XZ
*XYZ

Output
Case #1: COCONUTS
Case #2: *
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<string> str(n);

    for (int i = 0; i < n; ++i) cin >> str[i];

    string prefix = "", suffix = "";
    vector<string> sub;
    bool ok = true;

    for (string &s : str) {
        int last = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                // find the larget common prefix and suffix until the first * occurence
                if (last == -1) {
                    string other_prefix = s.substr(0, i);
                    if (other_prefix.size() > prefix.size()) swap(prefix, other_prefix);
                    if (prefix.substr(0, other_prefix.size()) != other_prefix) {
                        ok = false;
                        break;
                    }
                }
                else {
                    // add the substring starting from the index (prev * + 1) to the (current * - 1)
                    sub.push_back(s.substr(last + 1, i - last - 1));
                }
                last = i;
            }
        }

        if (!ok) break;

        string other_suffix = s.substr(last + 1);
        if (other_suffix.size() > suffix.size()) swap(suffix, other_suffix);

        if (suffix.substr(suffix.size() - other_suffix.size()) != other_suffix) {
            ok = false;
            break;
        }
    }

    if (!ok) cout << '*' << endl;
    else {
        cout << prefix;
        for (auto s : sub) cout << s;
        cout << suffix;

        cout << endl;
    }

}

int main() {

    int t; cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        cout << "Case #" << tt << ": ";
        solve();
    }
}