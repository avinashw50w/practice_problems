/*People working in MDCS (Microsoft Development Center Serbia) like partying. 
They usually go to night clubs on Friday and Saturday.

There are N people working in MDCS and there are N clubs in the city. Unfortunately, 
if there is more than one Microsoft employee in night club, level of coolness goes infinitely 
high and party is over, so club owners will never let more than one Microsoft employee enter 
their club in the same week (just to be sure).

You are organizing night life for Microsoft employees and you have statistics 
about how much every employee likes Friday and Saturday parties for all clubs.

You need to match people with clubs maximizing overall sum of their happiness 
(they are happy as much as they like the club), while half of people should go 
clubbing on Friday and the other half on Saturday.

Input
The first line contains integer N — number of employees in MDCS.

Then an N × N matrix follows, where element in i-th row and j-th column is an integer 
number that represents how much i-th person likes j-th club’s Friday party.

Then another N × N matrix follows, where element in i-th row and j-th column is an integer number 
that represents how much i-th person likes j-th club’s Saturday party.

2 ≤ N ≤ 20
N is even
0 ≤  level of likeness  ≤ 106
All values are integers
Output
Output should contain a single integer — maximum sum of happiness possible.

Examples
inputCopy
4
1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3
5 8 7 1
6 9 81 3
55 78 1 6
1 1 1 1
output
167
Note
Here is how we matched people with clubs:

Friday: 1st person with 4th club (4 happiness) and 4th person with 1st club (4 happiness).

Saturday: 2nd person with 3rd club (81 happiness) and 3rd person with 2nd club (78 happiness).

4+4+81+78 = 167*/
#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e9;

int friday[42][42];
int saturday[42][42];
int ans;
int n;
int a[42][42];
int u[42], v[42], p[42], way[42];
int minv[42];
bool used[42];

void dfs(int i, int fridays, int saturdays) {
  if (i == n + 1) {
    ans = max(ans, v[0]);
    return;
  }
  int old_u[21], old_v[21], old_p[21], old_way[21];
  for (int rot = 0; rot < 2; rot++) {
    if (rot == 0 && fridays == n / 2) {
      continue;
    }
    if (rot == 1 && saturdays == n / 2) {
      continue;
    }
    for (int j = 0; j < n; j++) {
      a[i][j + 1] = -(rot == 0 ? friday[i - 1][j] : saturday[i - 1][j]);
    }
  	for (int j = 0; j <= n; j++) {
  	  old_u[j] = u[j];
  	  old_v[j] = v[j];
  	  old_p[j] = p[j];
  	  old_way[j] = way[j];
  	}
  	p[0] = i;
  	int j0 = 0;
  	for (int j = 0; j <= n; j++) {
  	  minv[j] = INF;
  	  used[j] = false;
  	}
  	do {
  		used[j0] = true;
  		int i0 = p[j0],  delta = INF,  j1;
  		for (int j=1; j<=n; ++j)
  			if (!used[j]) {
  				int cur = a[i0][j]-u[i0]-v[j];
  				if (cur < minv[j])
  					minv[j] = cur,  way[j] = j0;
  				if (minv[j] < delta)
  					delta = minv[j],  j1 = j;
  			}
  		for (int j=0; j<=n; ++j)
  			if (used[j])
  				u[p[j]] += delta,  v[j] -= delta;
  			else
  				minv[j] -= delta;
  		j0 = j1;
  	} while (p[j0] != 0);
  	do {
  		int j1 = way[j0];
  		p[j0] = p[j1];
  		j0 = j1;
  	} while (j0);
  	dfs(i + 1, fridays + (rot == 0), saturdays + (rot == 1));
  	for (int j = 0; j <= n; j++) {
  	  u[j] = old_u[j];
  	  v[j] = old_v[j];
  	  p[j] = old_p[j];
  	  way[j] = old_way[j];
  	}
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", friday[i] + j);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", saturday[i] + j);
    }
  }
  for (int i = 0; i <= n; i++) {
    u[i] = v[i] = p[i] = way[i] = 0;
  }
  ans = 0;
  dfs(1, 0, 0);
  printf("%d\n", ans);
  return 0;
}