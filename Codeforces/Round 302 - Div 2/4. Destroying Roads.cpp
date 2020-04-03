/*In some country there are exactly n cities and m bidirectional roads connecting the cities. 
Cities are numbered with integers from 1 to n. If cities a and b are connected by a road, 
then in an hour you can go along this road either from city a to city b, or from city b to city a. 
The road network is such that from any city you can get to any other one by moving along the roads.

You want to destroy the largest possible number of roads in the country so that the remaining roads would 
allow you to get from city s1 to city t1 in at most l1 hours and get from city s2 to city t2 in at most l2 hours.

Determine what maximum number of roads you need to destroy in order to meet the condition of your plan. 
If it is impossible to reach the desired result, print -1.

Input
The first line contains two integers n, m (1 ≤ n ≤ 3000, ) — the number of cities and roads in the country, respectively.

Next m lines contain the descriptions of the roads as pairs of integers ai, bi (1 ≤ ai, bi ≤ n, ai ≠ bi). 
It is guaranteed that the roads that are given in the description can transport you from any city to any other one. 
It is guaranteed that each pair of cities has at most one road between them.

The last two lines contains three integers each, s1, t1, l1 and s2, t2, l2, respectively (1 ≤ si, ti ≤ n, 0 ≤ li ≤ n).

Output
Print a single number — the answer to the problem. If the it is impossible to meet the conditions, print -1.*/

#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int N = 5005;
int d[N][N];
vector < int > g[N];

int main() {
  memset(d, -1, sizeof d);
  int n, m;
  scanf("%d %d", &n, &m);

  for(int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--, b--;

    g[a].push_back(b);
    g[b].push_back(a);
  }

  for(int i = 0; i < n; i++) {
    queue < int > q;
    q.push(i);
    d[i][i] = 0;
    while (!q.empty()) {
      int s = q.front();
      q.pop();

      for(int j = 0; j < int(g[s].size()); j++) {
        int to =  g[s][j];
        if (d[i][to] == -1) {
          d[i][to] = d[i][s] + 1;
          q.push(to);
        }
      }
    }
  }
  int s[2], t[2], l[2];
  scanf("%d %d %d", &s[0], &t[0], &l[0]);
  scanf("%d %d %d", &s[1], &t[1], &l[1]);
  s[0]--, t[0]--, s[1]--, t[1]--;

  int ans = m + 1;
  for(int iter = 0; iter < 2; iter++){
    swap(s[0], t[0]);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        int v[] = {d[s[0]][i] + d[i][j] + d[j][t[0]], d[s[1]][i] + d[i][j] + d[j][t[1]]};
        if (v[0] <= l[0] && v[1] <= l[1]) {
          ans = min(ans, v[0] + v[1] - d[i][j]);
        }
      }
    }
  }

  if (d[s[0]][t[0]] <= l[0] && d[s[1]][t[1]] <= l[1]) {
    ans = min(ans, d[s[0]][t[0]] + d[s[1]][t[1]]); 
  }

  if (ans > m) {
    ans = -1;
  } else {
    ans = m - ans;
  }

  printf("%d\n", ans);
}