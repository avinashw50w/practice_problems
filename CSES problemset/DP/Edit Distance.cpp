/*The edit distance between two strings is the minimum number of operations required to transform one 
string into the other.
The allowed operations are:

Add one character to the string.
Remove one character from the string.
Replace one character in the string.

For example, the edit distance between LOVE and MOVIE is 2, because you can first replace L with M, and then add I.
Your task is to calculate the edit distance between two strings.
Input
The first input line has a string that contains n characters between A–Z.
The second input line has a string that contains m characters between A–Z.
Output
Print one integer: the edit distance between the strings.
Constraints

1 <= n,m <= 5000

Example
Input:
LOVE
MOVIE

Output:
2*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int slen = s.size(), tlen = t.size();
    int dp[slen + 1][tlen + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= slen; ++i) {
        dp[i][0] = i;
    }
    for (int i = 0; i <= tlen; ++i) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= slen; ++i) {
        for (int j = 1; j <= tlen; ++j) {
            if (s[i-1] == t[j-1]) 
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }
    cout<< dp[slen][tlen];
}