/*The country of elves is planning to hold an elimination tournament, and there are 2N elves who would like to take part. At the start of the tournament, they will be given unique ID numbers from 1 to 2N, and the Elf President will line them up in some order.

The tournament is a series of matches between two elves, and every match has one winner and one loser (there are no ties). In the first round, the first elf in the line competes against the second elf in the line, the third elf competes against the fourth elf, and so on. After the first round, the 2N-1 elves who lost leave the line, and the 2N-1 elves who won remain where they are. Then, the remaining elves play the second round in the same way: the first remaining elf in the line competes against the second remaining elf in the line, the third remaining elf competes against the fourth remaining elf, and so on. After N rounds, there will be only one elf remaining, and that elf is the winner.

M of the elves are sensitive, which means that they will be very sad if they have to compete in matches against their friends during the games. Specifically, the ith elf will be sad if they have to compete with their friends in the first Ki rounds. (Note that friendship is not necessarily mutual: if one elf considers another elf to be a friend, the other elf does not necessarily consider that elf to be a friend.)

The Elf President wants to know: is there a way to specify the initial positions of all 2N elves to guarantee that no elf will be sad, no matter what happens in the tournament?

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of one line with two integers N and M, then M sets of two lines each, in which the first line has integers Ei, Ki, and Bi for one elf, and the second has Bi integer ID numbers of that elf's friends.

Output

For each test case, output one line containing "Case #x: ", where x is the case number (starting from 1), followed by YES or NO.

Limits

1 ≤ T ≤ 200.
0 ≤ M ≤ 2N.
1 ≤ Ei ≤ 2N.
1 ≤ Ki ≤ N.
M ≤ sum(Bi) ≤ min(2 * M, 2N).

Small dataset

1 ≤ N ≤ 3.

Large dataset

N = 4.

Sample


Input 
 	
Output 
 
3
1 1
1 1 1
2
2 2
1 1 1
2
3 1 1
4
3 3
1 2 2
3 4
2 2 2
5 6
7 1 1
8

Case #1: NO
Case #2: YES
Case #3: YES
*/

#include <bits/stdc++.h>
using namespace std;

int g[330][330];
short dp[(1 << 16) + 10][10];
int n, m, N;
short f(int s, int dep) {
	if(dep == 0)
		return 1;
	short &ret = dp[s][dep];
	if(ret >= 0) return ret;
	for(int i = 0; i < N; ++i) if((1 << i) & s)
		for(int j = 0; j < i; ++j) if((1 << j) & s)
			if(g[i][j] >= dep) {
				return ret = 0;
			}
	ret = 0;
	int half = __builtin_popcount(s) >> 1;
	for(int i = s; i > 0 and ret == 0; i = (i - 1) & s) {
		if(__builtin_popcount(i) == half) {
			ret = f(i, dep - 1) & f(s & (~i), dep - 1);
		}
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase) {
		scanf("%d%d", &n, &m);
		N = 1 << n;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				g[i][j] = 0;
		for(int i = 0; i < m; ++i) {
			int e, k, b;
			scanf("%d%d%d", &e, &k, &b);
			e--;
			for(int j = 0; j < b; ++j) {
				int y;
				scanf("%d", &y);
				y--;
				if(k > g[e][y]) {
					g[e][y] = g[y][e] = k;
				}
			}
		}
		memset(dp, -1, sizeof dp);
		bool ans = f((1 << N) - 1, n);
		printf("Case #%d: %s\n", kase, ans ? "YES" : "NO");
	}
	return 0;
}