/*
A Matrix of cells is given. A cell may be desert (represented as 1) or forest (represented as 0).
Now every year all forests adjacent to desert convert to deserts.
You are supposed to find out how many forests
will be there after 'k' years (also give their location). */

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int R, C;

int mat[R][C], vis[R][C];

bool valid(int x, int y)  {
	return (x >= 0 and x<R and y >= 0 and y < C and !vis[x][y] and mat[x][y] == 0);
}

bool delimiter(pair<int, int> p) { return (p.first == -1 and p.second == -1); }

vector<pair<int, int>> solve(int K) {

	queue<pair<int, int>> Q;

	REP(i, 0, R)
	REP(j, 0, C)
	if (mat[i][j] == 1)
		Q.push({i, j});

	Q.push({ -1, -1});

	int cnt = 0;

	while (!Q.empty()) {

		bool flag = 0;

		while (!delimiter(Q.front())) {

			int x = Q.front().first;
			int y = Q.front().second;

			Q, pop();

			REP(i, 0, 4) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (!valid(nx, ny)) continue;

				mat[nx][ny] = 1;

				if (!flag) { flag = 1; cnt++; }

				Q.push({nx, ny});
			}
		}

		if (cnt == K) break;

		Q.pop();

		if (!Q.empty()) Q.push({ -1, -1});
	}

	vector<pair<int, int>> forest;

	REP(i, 0, R)
	REP(j, 0, C)
	if (mat[i][j] == 0)
		forest.push_back({i, j});

	return forest;
}