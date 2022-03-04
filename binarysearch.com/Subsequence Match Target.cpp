/*Given a list of string words and a string s, return the number of strings in words that are subsequences of s.

Constraints

n ≤ 10,000 where n is the length of words
m ≤ 100,000 where m is the length of s
Example 1
Input
words = ["ac", "ad", "b"]
s = "abc"
Output
2*/
const int maxn = 1e5 + 2;
const int maxc = 26;
// dp[i][j] - store the position of char j for each position i of
// string s
int dp[maxn][maxc];

void precompute(string s) {
    int n = s.length();
    for (int i = 0; i < maxc; ++i) {
        dp[n][i] = maxn;
    }

    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < maxc; ++j) {
            dp[i][j] = dp[i+1][j];
        }
        dp[i][s[i]-'a'] = i;
    }
}

bool isSubsequence(string b) {
    for (int i = 0, pos = 0; i < (int)b.size(); ++i) {
        if (pos >= maxn) return false;
        if (dp[pos][b[i]-'a'] >= maxn) return false;
        else pos = dp[pos][b[i]-'a'] + 1; 
    }
    return true;
}

int solve(vector<string>& words, string s) {
    precompute(s);
    int cnt = 0;

    for (string word : words) {
        cnt += isSubsequence(word);
    }
    return cnt;
}