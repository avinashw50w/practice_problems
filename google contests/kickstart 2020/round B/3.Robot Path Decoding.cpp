/*Your country's space agency has just landed a rover on a new planet, which can be thought of as a grid of squares containing 109 columns (numbered starting from 1 from west to east) and 109 rows (numbered starting from 1 from north to south). Let (w, h) denote the square in the w-th column and the h-th row. The rover begins on the square (1, 1).

The rover can be maneuvered around on the surface of the planet by sending it a program, which is a string of characters representing movements in the four cardinal directions. The robot executes each character of the string in order:
N: Move one unit north.
S: Move one unit south.
E: Move one unit east.
W: Move one unit west.
There is also a special instruction X(Y), where X is a number between 2 and 9 inclusive and Y is a non-empty subprogram. This denotes that the robot should repeat the subprogram Y a total of X times. For example:
2(NWE) is equivalent to NWENWE.
3(S2(E)) is equivalent to SEESEESEE.
EEEE4(N)2(SS) is equivalent to EEEENNNNSSSS.

Since the planet is a torus, the first and last columns are adjacent, so moving east from column 109 will move the rover to column 1 and moving south from row 109 will move the rover to row 1. Similarly, moving west from column 1 will move the rover to column 109 and moving north from row 1 will move the rover to row 109. Given a program that the robot will execute, determine the final position of the robot after it has finished all its movements.

Input
The first line of the input gives the number of test cases, T. T lines follow. Each line contains a single string: the program sent to the rover.

Output
For each test case, output one line containing Case #x: w h, where x is the test case number (starting from 1) and w h is the final square (w, h) the rover finishes in.*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9;
const int maxn = 2001;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
string dir = "SENW";
string s;

pair<ll, ll> go(int lo, int hi) {
    int x = 0, y = 0;
    for (int i = lo; i <= hi; ++i) {

        if ('2' <= s[i] and s[i] <= '9') {
            int val = s[i] - '0';
            int token = 1, npos = i + 2;
            while (token) {
                if (s[npos] == '(') token++;
                else if (s[npos] == ')') token--;
                npos++;
            }

            pair<ll, ll> p = go(i + 2, npos - 2);
            p.first *= val;
            p.second *= val;

            x = (x + p.first) % MOD;
            y = (y + p.second) % MOD;

            i = npos - 1;
            continue;
        }

        for (int j = 0; j < 4; ++j) {
            if (s[i] == dir[j]) {
                x = (x + MOD + dx[j]) % MOD;
                y = (y + MOD + dy[j]) % MOD;
            }
        }
    }

    return {x, y};
}

void solve() {
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) dp[i][j] = { -1, -1};
    }

    pair<ll, ll> p = go(0, n - 1);

    ll x = p.first % MOD;
    ll y = p.second % MOD;

    cout << (x + 1) << " " << (y + 1) << "\n";
}

int main() {

    int t; cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        cout << "Case #" << tt << ": ";
        solve();
    }
}

/////////////////////////////
// simple one
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    int cc = 1;
    while (t--) {
        cout << "Case #" << cc++ << ": ";
        string s;
        cin >> s;
        ll mod = 1e9;
        ll x = 0, y = 0;
        vector<ll> mul = {1};
        for (char c : s) {
            if (c >= '2' && c <= '9')
                mul.push_back(mul.back() * (c - '0') % mod);
            else if (c == 'E') x = (x + mul.back()) % mod;
            else if (c == 'W') x = ((x - mul.back()) % mod + mod) % mod;
            else if (c == 'S') y = (y + mul.back()) % mod;
            else if (c == 'N') y = ((y - mul.back()) % mod + mod) % mod;
            else if (c == '(') continue;
            else if (c == ')') mul.pop_back();
            else assert(0);
        }
        cout << x + 1 << ' ' << y + 1 << endl;
    }
}
