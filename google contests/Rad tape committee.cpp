/*You are the head of the Department of Redundancy Reduction and Superfluity Shrinkage. 
Currently, the department cannot agree on whether there is too much "red tape" 
(inefficiency) in the department itself. They have asked you to form a Red Tape Committee to vote on the issue.

The department has N members. For each member, you know the probability Pi that that member will vote "Yes". 
If a member does not vote "Yes", they necessarily vote "No"; 
nobody abstains.

You must choose exactly K members to be on the committee. The department rules dictate 
that K must be an even number to allow for ties, which are seen as part of a healthy bureaucracy.

If you choose committee members to maximize the probability of a tie, what is that probability?

Input

The first line of the input gives the number of test cases, T. T test cases follow; each consists of two lines. 
The first line of a test case consists of two integers N and K, the sizes of the department and the committee. 
The second line of a test case consists of N decimal values Pi; each has exactly two decimal places of precision 
and represents the probability that the i-th department member will vote "Yes".

Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) 
and y is a floating-point number: the maximum possible probability of a tie. y will be considered correct 
if it is within an absolute or relative error of 10-6 of the correct answer. See the FAQ for an explanation of 
what that means, and what formats of real numbers we accept.

Limits

1 = T = 100.
2 = K = N.
K is even.
0.00 = each Pi = 1.00.
Small dataset

2 = N = 16.
Large dataset

2 = N = 200.
Sample


Input 
 	
Output 
 
3
2 2
0.50 0.50
4 2
0.00 0.00 1.00 1.00
3 2
0.75 1.00 0.50

Case #1: 0.5
Case #2: 1.0
Case #3: 0.5
In sample case #1, you must use the only two available department members to form the committee. 
That committee will tie only if the two committee members vote differently, 
which will happen half the time. (Without loss of generality, choose the vote of the first. 
Then the probability that the second will vote the other way is 0.5.)

In sample case #2, the best strategy is to pick one of the members with "Yes" probability 0.00 and 
one of the members with "Yes" probability 1.00. This guarantees a tie.

In sample case #3, suppose that we pick the two members with "Yes" probabilities of 0.50 and 0.75. 
A tie will happen if the first one votes "Yes" and the second one votes "No" (probability 0.5 * 0.25 = 0.125), 
or if the first one votes "No" and the second one votes "Yes" (probability 0.5 * 0.75 = 0.375). 
So the total probability of a tie is 0.125 + 0.375 = 0.5. Choosing the two members with "Yes" 
probabilities of 0.50 and 1.00 would also make the tie probability 0.5, since the 1.00 member will vote "Yes" 
and the 0.50 member must vote "No". Choosing the two members with "Yes" probabilities of 0.75 and 1.00 
would make the tie probability only 0.25, since the 1.00 member 
will vote "Yes" and the 0.75 member must vote "No". So 0.5 is the best we can do.*/
#include <bits/stdc++.h>

using namespace std;

double p[12345];
double f[444][444];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%lf", p + i);
    }
    sort(p, p + n);
    double ans = 0.0;
    for (int take = 0; take <= k; take++) {
      vector <double> q;
      for (int i = 0; i < take; i++) {
        q.push_back(p[i]);
      }
      for (int i = 0; i < k - take; i++) {
        q.push_back(p[n - 1 - i]);
      }
      for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= i; j++) {
          f[i][j] = 0.0;
        }
      }
      f[0][0] = 1.0;
      for (int i = 0; i < k; i++) {
        for (int j = 0; j <= i; j++) {
          f[i + 1][j] += f[i][j] * (1.0 - q[i]);
          f[i + 1][j + 1] += f[i][j] * q[i];
        }
      }
      ans = max(ans, f[k][k / 2]);
    }
    printf("%.17f\n", ans);
  }
  return 0;
}
