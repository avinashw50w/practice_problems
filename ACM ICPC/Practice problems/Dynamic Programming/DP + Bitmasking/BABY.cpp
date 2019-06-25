/*A baby tries to solve the well-known eight-queen puzzle: the problem of placing eight chess queens on an 8×8 chessboard so that no two 
queens share the same row, column, or diagonal. The baby understands the concept of row and column quite well but diagonal is not very clear 
to her. As a result she succeeds placing eight queens on the board so that no two queens share the same row or column but there remains the 
possibility that some queens share the same diagonal.

Given baby's queens (a solution by the baby) and a valid eight-queen solution, it is possible to move baby's queens to positions of queens 
in the valid solution. Assume that in a single move, a queen can be moved one unit row-wise or column-wise into an unoccupied position.

Write a program to find the minimum number of moves required to move baby's queens to positions of queens in the valid solution. The program 
should be usable for a more general n -queen puzzle where n queens are placed on an n×n chessboard, 4 ≤ n ≤ 16 . Assume that rows and columns 
of the chessboard are numbered 1, 2,..., n .

Input

The input consists of multiple test cases.

Each case begins with a line containing the integer n .

Each of the next two lines contains a sequence of n integers. Integers in the first line represent column numbers of baby's queens appearing 
in rows 1, 2,..., n respectively. In the same way, the second line contains column numbers of queens in the given valid solution. A space 
separates two consecutive integers in the sequence.

A line containing a zero 0' as the first character follows the last case. 

Output

For each test case, print the minimum number of moves required.

Example

Sample Input
4 
1 2 3 4 
3 1 4 2 
4 
3 2 4 1 
3 1 4 2 
5 
5 3 1 4 2 
5 3 1 4 2 
5 
1 5 2 4 3 
3 1 4 2 5 
0

Sample Output
6 
2 
0 
8
*/

int dp[1<<17], a1[17], a2[17];
int n;

int solve(int mask) {
	int index = __builtin_popcount(mask);
	if(index == n) return 0;
	if(dp[mask] != -1) return dp[mask];
	int res = 100000;
	rep(i,0,n)
		if((mask & (1<<i)) == 0)
			res = min(res, abs(index - i) + abs(a1[index] - a2[i]) + solve(mask | (1<<i)));
	return dp[mask] = res;
}

int main() {
	while(si(n) and n) {
		rep(i,0,n) { si(a1[i]); --a1[i]; }
		rep(i,0,n) { si(a2[i]); --a2[i]; }

		memset(dp, -1, sizeof(dp));

		int ans = solve(0);
		printf("%d\n", ans);
	}
	return 0;
}

///////////////////////////////////////////////////
// or simply use the formula T(n) = 4*T(n-2) - T(n-4) //

T[0] = 1;
T[1] = 0;
T[2] = 3;
T[3] = 0;

rep(i,4, 31){
	T[i] = 4*T[i-2] - T[i-4];
}


