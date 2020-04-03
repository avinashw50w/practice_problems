/*You've been asked to organize a Rock-Paper-Scissors tournament. 
The tournament will have a single-elimination format and will run for N rounds; 2N players will participate.

Initially, the players will be lined up from left to right in some order that you specify. 
In each round, the first and second players in the lineup (starting from the left) 
will play a match against each other, and the third and fourth players in the lineup 
(if they exist) will play a match against each other, and so on; all of these matches 
will occur simultaneously. The winners of these matches will remain in the lineup, 
in the same relative order, and the losers will leave the lineup and go home. 
Then a new round will begin. This will continue until only one player remains in the lineup; 
that player will be declared the winner.

In each Rock-Paper-Scissors match, each of the two players secretly chooses one of 
Rock, Paper, or Scissors, and then they compare their choices. Rock beats Scissors, 
Scissors beats Paper, and Paper beats Rock. If one player's choice beats the other players's choice, 
then that player wins and the match is over. However, if the players 
make the same choice, then it is a tie, and they must choose again and keep playing until there is a winner.

You know that the players this year are stubborn and not very strategic. 
Each one has a preferred move and will only play that move in every match, regardless of what the 
opponent does. Because of this, if two players with the same move go up against each other, 
they will keep tying and their match will go on forever! If this happens, 
the tournament will never end and you will be a laughingstock.

This year, there are R players who prefer Rock, P players who prefer Paper, 
and S players who prefer Scissors. Knowing this, you want to create a lineup that guarantees 
that the tournament will go to completion and produce a single winner — 
that is, no match will ever be a tie. Your boss has asked you to produce a list of all such 
lineups (written in left to right order, with R, P, and S standing for players who prefer 
Rock, Paper, and Scissors, respectively), and then put that list in alphabetical order.

You know that the boss will lazily pick the first lineup on the list; what will that be? 
Or do you have to tell your boss that it is IMPOSSIBLE to prevent a tie?

Input

The first line of the input gives the number of test cases, T. 
T lines follow; each represents one test case. Each test case consists of four integers: N, R, P, and S, 
as described in the statement above.

Output

For each test case, output one line containing Case #x: y, where x is the test case number 
(starting from 1) and y is either IMPOSSIBLE or a string of length 2N representing 
the alphabetically earliest starting lineup that solves the problem. 
Every character in a lineup must be R, P, or S, and there must be R Rs, P Ps, and S Ss.

Limits

R + P + S = 2N.
0 ≤ R ≤ 2N.
0 ≤ P ≤ 2N.
0 ≤ S ≤ 2N.
Small dataset

1 ≤ T ≤ 25.
1 ≤ N ≤ 3.
Large dataset

1 ≤ T ≤ 75.
1 ≤ N ≤ 12.
Sample


Input 
  
Output 
 
4
1 1 1 0
1 2 0 0
2 1 1 2
2 2 0 2

Case #1: PR
Case #2: IMPOSSIBLE
Case #3: PSRS
Case #4: IMPOSSIBLE

*/
#include <bits/stdc++.h>

using namespace std;

const string IMP = "IMPOSSIBLE";

string go(int n, int p, int r, int s) {
  if (n == 0) {
    return (p > 0 ? "P" : (r > 0 ? "R" : "S"));
  }
  int x =  p + r - s;
  int y = -p + r + s;
  int z =  p - r + s;
  if (x < 0 || y < 0 || z < 0) {
    return IMP;
  }
  if (x % 2 != 0 || y % 2 != 0 || z % 2 != 0) {
    return IMP;
  }
  x /= 2;
  y /= 2;
  z /= 2;
  string res = go(n - 1, x, y, z);
  if (res == IMP) {
    return IMP;
  }
  string ans = "";
  for (int i = 0; i < (int) res.length(); i++) {
    char c = res[i];
    if (c == 'P') {
      ans += "PR";
    }
    if (c == 'R') {
      ans += "RS";
    }
    if (c == 'S') {
      ans += "PS";
    }
  }
  return ans;
}

string enhance(string s) {
  if (s == IMP) {
    return s;
  }
  int len = s.length();
  if (len == 1) {
    return s;
  }
  string x = s.substr(0, len / 2);
  string y = s.substr(len / 2);
  x = enhance(x);
  y = enhance(y);
  if (x > y) {
    swap(x, y);
  }
  return x + y;
}

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n, r, p, s;
    scanf("%d %d %d %d", &n, &r, &p, &s);
    printf("%s\n", enhance(go(n, p, r, s)).c_str());
  }
  return 0;
}
