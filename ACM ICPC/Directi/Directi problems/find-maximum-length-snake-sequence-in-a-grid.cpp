/*Given a grid of numbers, find maximum length Snake sequence and print it. 
If multiple snake sequences exists with the maximum length, print any one of them.

A snake sequence is made up of adjacent numbers in the grid such that for each number, 
the number on the right or the number below it is +1 or -1 its value. For example, 
if you are at location (x, y) in the grid, you can either move right i.e. (x, y+1) 
if that number is ± 1 or move down i.e. (x+1, y) if that number is ± 1.

For example,

9, 6, 5, 2
8, 7, 6, 5
7, 3, 1, 6
1, 1, 1, 7

In above grid, the longest snake sequence is: (9, 8, 7, 6, 5, 6, 7)

The idea is to use Dynamic Programming. For each cell of the matrix, we keep maximum length of a snake which ends in current cell. 
The maximum length snake sequence will have maximum value. The maximum value cell will correspond to tail of the snake. 
In order to print the snake, we need to backtrack from tail all the way back to snake’s head.

Let T[i][i] represent maximum length of a snake which ends at cell (i, j), then for given matrix M, the DP relation is defined as –

T[0][0] = 0
T[i][j] = max(T[i][j], T[i][j – 1] + 1) if M[i][j] = M[i][j – 1] ± 1
T[i][j] = max(T[i][j], T[i – 1][j] + 1) if M[i][j] = M[i – 1][j] ± 1
*/

void findSnakeSequence(int mat[R][C]) {
	int dp[R][C];

	memset(dp, 0, sizeof(dp));

	int maxlen = 0;
	int max_row = 0;
	int max_col = 0;

	REP(i, 0, R) {
		REP(j, 0, C) {
			if(i == 0 and j == 0) continue;

			if(i > 0 and abs(mat[i][j] - mat[i-1][j]) == 1) {
				
				dp[i][j] = max(dp[i][j], dp[i-1][j] + 1);
				
				if(dp[i][j] > maxlen) {
					maxlen = dp[i][j];
					max_row = i;
					max_col = j;
				}
			}
		}

		if(j > 0 and abs(mat[i][j] - mat[i][j-1]) == 1) {

			dp[i][j] = max(dp[i][j], dp[i][j-1] + 1);

			if(dp[i][j] > maxlen) {
				maxlen = dp[i][j];
				max_row = i;
				max_col = j;
			}
		}
	}

	printSnakeSequence(dp, mat, max_row, max_col);
}


void printSnakeSequence(int dp[R][C], int mat[R][C], int i, int j) {

	list<pair<int, int> > path;

	path.push_front({i, j});

	while(dp[i][j] != 0) {

		if(i > 0 and dp[i][j] == dp[i-1][j] + 1) {
			path.push_front({i-1, j});
			i--;
		}

		else if(j > 0 and dp[i][j] == dp[i][j-1] + 1) {
			path.push_front({i, j-1});
			j--;
		}
	}

	for(auto p: path) {
		cout << mat[p.first][p.second] << " ";
	}
}

