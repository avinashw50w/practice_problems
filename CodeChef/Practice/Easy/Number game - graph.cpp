/*You are playing a game with a robot. The game starts with two integers: A and M. The robot makes exactly one move in the entire game, and it does so at the very beginning - it will remove exactly 1 digit from A and output it as the starting value (say X). Note that the value A remains intact. It is not changed by the robot. After the robot makes its moves, it is your turn. You can make an unlimited number of moves. In each move, you must remove exactly 1 digit from A and append it to X (to the right side of X). Again note that none of your moves change the value of A. You win if you can eventually make X a multiple of M (i.e. X mod M = 0). How many possible starting moves bot can make such that you are guaranteed to win assuming you play optimally?

Here is an example of a game: Suppose the numbers are A = 1003, M = 4. The robot can make four possible starting moves: 003 by removing 1st digit, 103 by removing 2nd or 3rd digit (both count as a separate possibilities even though the starting X will be same) or 100 by removing the 4th digit. Let us say the robot chooses 003 as the starting move. Then you can win by appending 100 (by removing the 4th digit) making X = 003100 which is divisible by 4.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows
The only line of each test case contains 2 integers A and M.
Output
For each test case, output a single line containing the number of possible first moves that the robot can make such that you can force a win.
Constraints
1 ≤ T ≤ 100
10 ≤ A < 10106 (i.e. The number of digits in A can be upto 106)
1 ≤ M ≤ 1000
The sum of number of digits of A over all test cases will not exceed 5 * 10^6


0
PROBLEM LINK:
Practice 
Contest

Author: Balajiganapathi S
Tester: Jingbo Shang 
Editorialist: Utkarsh Saxena

PROBLEM
Given 2 integers A and M. Construct a set S of all integers that can be obtained by deleting exactly one digit of A. 
Find number of integers in S such that concatenating zero or more integers from S to the right of it will give a multiple of M.

Constraints: 1≤A≤10106, 1≤M≤103
EXPLANATION
Let the number of digits in A be D. The number of elements in the set S will be D (repetitions are allowed). 
Since the final aim is to make a number X such that X≡0 mod M, it is better to calculate each operation mod M.

∴ Total number of distinct integers mod M in S can be atmost M. We can find the integer mod M made by deleting 
ith digit of A as Pi−1∗10N−i∗Si+1mod M. 
Here Pi = integer mod M represented by A[1..i], Si = integer mod M represented by A[i..N]
Denote S′ = The set of distinct integers mod M in S. Assume we have concatenated some elements of S to form an 
integer ≡X mod M. Adding one more integer Y∈S to the right of X. The new integer thus formed Z=X∗10N−1+Y mod M.

Thus for a given remainder X we can convert it to another integer with remainder Z by the above formula.

We can make a graph of M vertices for these transitions. The ith node denotes that there exists a set of integers 
in S when concatenated together given i mod M. There is a directed edge form node X to node Z if there exists a Y in S′ 
such that Z=X∗10N−1+Y mod M.

To answer the problem we need to find those nodes from which there is a path to node 0 and also are present in S′. 
This is equivalent to finding all those nodes that are reachable from 0 in the reverse graph (direction of edges reversed).

Time Complexity
Array Pi, Array Si and Set S′ can be calculated in O(N)
Graph can be developed in O(M2) time and space. Finding all reachable nodes from 0 will take another O(M2) time for bfs.*/

const int mx_len = 1000005, mx_m = 1004;
string a;
int M;
int preLeft[mx_len], preRight[mx_len], cnt[mx_m];
int ans;
int vis[mx_m];
int len;
int ten_len_1;

void dfs(int x) {
	if(vis[x]) return;
	ans += cnt[x];
	vis[x] = 1;

	for(int nxt = 1; nxt < M; ++nxt) if(!vis[nxt]) {
		// calculate req s.t. nxt * 10^(len-1) + req = x (mod M):
		int req = (x - nxt * ten_len_1 % M + M) % M;
		if(cnt[req] > 0) dfs(nxt); // req must be a possible move
	}
}

int main() {
	int t, sum_len = 0;
	cin >>  t;
	while(t--) {
		cin >> a >> M;
		len = a.length();
		sum_len += len;

		int sofar = 0;
		rep(i, 0, len) {
			sofar = (10 * sofar + a[i] - '0') % M;
			preLeft[i] = sofar;
		}

		sofar = 0;
		int p10 = 1;
		for(int i = len - 1; i >= 0; --i) {
			int d = a[i] - '0';
			sofar = (sofar + p10 * d) % M;
			preRight[i] = sofar;
			p10 = 10 * p10 % M;
		}

		p10 = 1;
		memset(cnt, 0, sizeof(cnt));
		for(int i = len - 1; i >= 0; --i) {
			int fromLeft = 0, fromRight = 0;
			if(i > 0) fromLeft = preLeft[i-1];
			if(i < len - 1) fromRight = preRight[i+1];
			int x = (fromLeft * p10 + fromRight) % M;
			++cnt[x];
			p10 = 10 * p10 % M;
		}

		ten_len_1 = modpow(10, len - 1, M);
		ans = 0;
		memset(vis, 0, sizeof(cnt));
		dfs(0);

		cout << ans << endl;
	}
    
    
	return 0;
}