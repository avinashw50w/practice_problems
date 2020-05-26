/*You have just received the best gift ever: an Expogo stick. You can stand on it and use it to make increasingly large jumps.

You are currently standing on point (0, 0) in your infinite two-dimensional backyard, and you are trying to reach a goal point (X, Y), with integer coordinates, in as few jumps as possible. You must land exactly on the goal point; it is not sufficient to pass over it on a jump.

Each time you use your Expogo stick to jump, you pick a cardinal direction: north, south, east, or west. The i-th jump with your Expogo stick moves you 2^(i-1) units in the chosen direction, so your first jump takes you 1 unit, your second jump takes you 2 units, your third jump takes you 4 units, and so on.

Given a goal point (X, Y), determine whether it is possible to get there, and if so, demonstrate how to do it using as few jumps as possible.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each consists of a single line with two integers X and Y: the coordinates of the goal point.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is IMPOSSIBLE if the goal point cannot be reached. Otherwise, y must be a string of one or more characters, each of which is either N (north), S (south), E (east), or W (west), representing the directions of the jumps that you will make, in order. This sequence of jumps must reach the goal point at the end of the final jump, and it must be as short as possible.

Limits
Time limit: 20 seconds per test set.
Memory limit: 1GB.
(X, Y) ≠ (0, 0).

Test set 3 (Visible Verdict)
1 ≤ T ≤ 100.
-109 ≤ X ≤ 109.
-109 ≤ Y ≤ 109.

We can notice that every position with an even (X + Y) (apart from the origin) — hereafter an "even" position — seems to be unreachable. We can prove to ourselves that this is true: our initial X and Y coordinates of (0, 0) are both even, but only the first of our possible jumps (the 1-unit one) is of an odd length, and all jumps after that are of even lengths. So there is no way to reach any other "even" position starting from the origin, no matter how much jumping we do.
We can find that all "odd" positions, on the other hand, can be reached using no more than 3 moves.*/

#include <bits/stdc++.h>

const int MX = 200005;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
string dir = "ESWN";

struct Solver {
  void solve() {
    ll x, y;
    cin >> x >> y;
    auto f = [&](ll x, ll y) {
      return abs(x) + abs(y);
    };
    if (f(x, y) % 2 == 0) { puts("IMPOSSIBLE"); return; }
    int s = 0;
    // find no of jumps: 1 + 2 + 4 + ... 2^(s-1) = 2^s -1
    while ((1ll << s) - 1 < f(x, y)) ++s;
    string ans;
    for (int i = s - 1; i >= 0; --i) {
      ll l = 1ll << i;
      rep(v, 4) {
        ll nx = x + dx[v] * l, ny = y + dy[v] * l;
        if (f(nx, ny) <= l - 1) {
          x = nx; y = ny;
          // dir : E S W N
          // v   : 0 1 2 3
          // v^2 : 2 3 0 1
          ans += dir[v ^ 2];
          break;
        }
      }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  }
};

int main() {
  int ts;
  scanf("%d", &ts);
  rrep(ti, ts) {
    Solver solver;
    printf("Case #%d: ", ti);
    solver.solve();
  }
  return 0;
}

////////////////////////////////////////////

string smin(string a, string b) {
  if (a.size() < b.size()) return a;
  else return b;
}

string solve(int x, int y) {
  if (x == 0 && y == 0) return 0;
  if (x == 0 && y == 1) return "S";
  if (x == 0 && y == -1) return "N";
  if (x == 1 && y == 0) return "E";
  if (x == -1 && y == 0) return "W";
  if ((x & 1) == (y & 1)) return "IMPOSSIBLE";
  if (x & 1)
    return smin("E" + solve((x - 1) / 2, y / 2), "W" + solve((x + 1) / 2, y / 2));
  else
    return smin("S" + solve(x / 2, (y - 1) / 2), "N" + solve(x / 2, (y + 1) / 2));
}

void solveCase() {
  int res = 0;

  int x = getNum();
  int y = getNum();

  string sol = solve(x, -y);

  if (sol.size() > 60) sol = "IMPOSSIBLE";

  printf("Case #%d: %s\n", cnum, sol.c_str());
}

#define P 1000000007

int main() {

  if (!MANYTESTS) Tests = 1;
  else Tests = getNum();

  for (cnum = 1; cnum <= Tests; cnum++)
    solveCase();

  // finish
  return 0;
}



















