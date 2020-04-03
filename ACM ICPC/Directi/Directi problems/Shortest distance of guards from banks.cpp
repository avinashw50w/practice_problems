/*Find Shortest distance from a guard in a Bank
Given a matrix that is filled with ‘O’, ‘G’, and ‘W’ where ‘O’ represents open space, ‘G’ represents 
guards and ‘W’ represents walls in a Bank. Replace all of the O’s in the matrix with their shortest 
distance from a guard, without being able to go through any walls. 
Also, replace the guards with 0 and walls with -1 in output matrix.

Expected Time complexity is O(MN) for a M x N matrix.

Examples:

O ==> Open Space
G ==> Guard
W ==> Wall

Input: 
  O  O  O  O  G
  O  W  W  O  O
  O  O  O  W  O
  G  W  W  W  O
  O  O  O  O  G

Output:  
  3  3  2  1  0
  2 -1 -1  2  1
  1  2  3 -1  2
  0 -1 -1 -1  1
  1  2  2  1  0

The idea is to do BFS. We first enqueue all cells containing the guards and loop till queue is not empty. 
For each iteration of the loop, we dequeue the front cell from the queue and for each of its four adjacent cells, 
if cell is an open area and its distance from guard is not calculated yet, we update its distance and enqueue it. 
Finally after BFS procedure is over, we print the distance matrix.*/

const int MAXN = 100;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int N, M;
int mat[MAXN][MAXN], output[MAXN][MAXN];

bool valid(int x, int y) { return (x>=0 and x<R and y>=0 and y<C and mat[x][y] == 'O' and output[x][y] == -1); }

void bfs() {

	queue<tuple<int, int, int> > Q;

	REP(i, 0, N)
		REP(j, 0, M) {
			output[i][j] = -1;

			if(mat[i][j] == 'G') {
				output[i][j] = 0;
				Q.push(make_tuple(i, j, 0));
			}
		}

	int x, y, dist;

	while(!Q.empty()) {
		tie(x, y, dist) = Q.front();
		
		Q.pop();

		REP(i, 0, 4) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(!valid(nx, ny)) continue;

			output[nx][ny] = dist + 1;

			Q.push(make_tuple(nx, ny, dist + 1));
		}
	}

	print(output);
}

void print(int output[][MAXN]) {
	REP(i, 0, N) {
		REP(j, 0, M)
			cout << output[i][j] << " ";
		cout << endl;
	}
}

