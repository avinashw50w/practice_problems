/*An N-element permutation is an N-element sequence of distinct numbers from the set {1, 2, ...,n}. 
For example the sequence 2,1,4,5,3 is a 5-element permutation. P is an N-element permutation. 
Your task is to sort P in ascending order. But because it is very simple, I have a new rule for you. 
You have two sequences P and Q. P is an N-element permutation and Q is initially empty and formed by sorting P 
(i.e. finally Q = 1, 2, 3,... , N). You have to implement N steps to sort P. In the i-th step, 
P has N-i+1 remaining elements, Q has i-1 elements and you have to choose some x-th element 
(from the N-i+1 available elements) of P and put it to the left or to the right of Q. 
The cost of this step is equal to x * i. The total cost is the sum of costs of individual steps. 
After N steps, Q must be an ascending sequence. Your task is to minimize the total cost.

Input

The first line of the input file is T (T ≤ 10), the number of test cases. Then descriptions of T test cases follow. 
The description of each test case consists of two lines. The first line contains a single integer N (1 ≤ N ≤ 1000). 
The second line contains N distinct integers from the set {1, 2, .., N}, the N-element permutation P.

Output

For each test case your program should write one line, containing a single integer - the minimum total cost of sorting.

Example

N = 4
P = {4,1,3,2}
Step 1, Choose 3-rd, P={4,1,2}, Q={3} , Cost=3
Step 2, Choose 1-st, P={1,2}, Q={3,4} , Cost=2
Step 3, Choose 2-nd, P={1}, Q={2,3,4} , Cost=6
Step 4, Choose 1-st, P={}, Q={1,2,3,4}, Cost=4
The total cost is 15.
Another way to sort: 
Step 1, Choose 4-th, P={4,1,3}, Q={2} , Cost=4
Step 2, Choose 2-nd, P={4,3}, Q={1,2} , Cost=4
Step 3, Choose 2-nd, P={4}, Q={1,2,3} , Cost=6
Step 4, Choose 1-st, P={}, Q={1,2,3,4}, Cost=4
The total cost is 18.
Input:
1
4
4 1 3 2


Output:
15  */

/*Summary:
Sort a permutation of [1..N] by the following rule:
1. Start with P the permutation of [1..N], and Q an empty set [].
2. For each step i, we can choose any element in P and append it to beginning or end of Q. We incur cost i*x, where x is the position of 
the element in P at that time.
3. In the end Q must be in sorted ascending order.

Find the minimal cost possible to perform this operation.

Solution:
A nice problem! Before doing the usual DP on the string, we need to precompute the positions of elements in P after removing several elements 
to Q, and there is a nice pattern that makes this computation possible and very efficient. Let's say Q has endings i and j. Notice that elements 
from i to j are already in sorted order. We can either take i-1 or j+1 from P, and for each we can calculate its current position by observing 
that it is equal to the number of elements in i to j that are place behind i-1 or j+1 in the original array P. After computing the positions of
all elements given i or j, we can do a simple DP: minimal cost to build Q[i..j] is the minimum between cost to build Q[i..j-1] + cost of 
placing j, or cost to build Q[i+1..j] + cost of placing i.

before[i][j] = position of number i in P set, after numbers from i+1 to j are removed from set P

after[i][j] = position of number i in P set, after numbers from j to i-1 are removed from set P

*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1003;
int A[MAXN], pos[MAXN], dp[MAXN][MAXN], before[MAXN][MAXN], after[MAXN][MAXN];
int N;
void solve() {
	for(int i=1;i<=N;++i) 
		pos[A[i]] = i;

	for(int i=1;i<=N;++i) {
		before[i][i] = pos[i];
		for(int j=i+1;j<=N;++j)
			before[i][j] = before[i][j-1] - (pos[j] < pos[i]? 1 : 0);
	}

	for(int i=1;i<=N;++i) {
		after[i][i] = pos[i];
		for(int j=i-1;j>=1;--j)
			after[i][j] = after[i][j+1] - (pos[j] < pos[i]? 1 : 0);	
	}
	// when only one element is chosen from P set
	for(int i=1; i<=N; ++i)
		dp[i][i] = pos[i];
	// for each successive step
	for(int range = 1; range < N; ++range) {
		for(int i = 1; i+range <= N; ++i){
			int j = i + range;
			int step = range + 1;
			dp[i][j] = min( dp[i+1][j] + before[i][j] * step, dp[i][j-1] + after[j][i] * step);
		}
	}

	cout << dp[1][N] << endl;;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> N;
		for(int i=1;i<=N;++i) 
			cin >> A[i];

		solve();
	}
}
