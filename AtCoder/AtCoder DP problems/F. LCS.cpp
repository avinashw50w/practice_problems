#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;

struct Node {
    int val;
    int x, y;

    Node (int _val, int _x, int _y) {
        val = _val;
        x = _x;
        y = _y;
    }
};

void max_self(Node &a, Node b) {
    if (a.val < b.val) {
        a = b;
    }
}

int is_first_row_col(Node node) {
    return (node.x == 0 || node.y == 0);
}

int main() {

    string s, t;
    cin >> s >> t;

    int n = s.length(), m = t.length();

    vector<vector<Node>> dp(n+1, vector<Node>(m+1, Node(-INF,0,0)));

    dp[0][0].val = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i] == t[j])  {
                max_self(dp[i+1][j+1], Node(1+dp[i][j].val, i, j));
            }

            max_self(dp[i+1][j], Node(dp[i][j].val, i, j));
            max_self(dp[i][j+1], Node(dp[i][j].val, i, j));
        }
    }

    Node node(0,0,0);

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            max_self(node, Node(dp[i][j].val, i, j));
        }
    }

    string ans = "";

    while (!is_first_row_col(node)) {
        int i = node.x;
        int j = node.y;
        Node prev = dp[i][j];
        
        if (prev.x == i-1 and prev.y == j-1) ans += s[i-1];

        node = prev;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;

}