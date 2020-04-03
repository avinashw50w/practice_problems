/* Problem : given an arrangement of oranges in a grid in which there are both fresh and rotten oranges.
   A rotten orange can rot an orange in its left,right,top and bottom position. Find the min time in which all oranges get rotten.
   0 - no orange
   1 - fresh orange
   2 - rotten orange
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
#define pii pair<int,int>

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int R=3, C=5;

int grid[R][C] = { {2, 1, 0, 2, 1},
                   {1, 0, 1, 2, 1},
                   {1, 0, 0, 2, 1} };

bool checkFreshOrange(){
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j)
			if(grid[i][j] == 1)
				return true;
	return false;
}

bool delimiter(pii s){
	return (s.first == -1 and s.second == -1);
}

bool isValid(int x, int y){
	return (x>=0 and x<R and y>=0 and y<C and grid[x][y]==1);
}

int RotOranges() {
	queue<pii> Q;
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j)
			if(grid[i][j] == 2)
				Q.push(pii(i,j));
	
	Q.push(pii(-1,-1));
	int ans = 0;
	while(!Q.empty()) {
		int rotten = 0;
		while(!delimiter(Q.front())) {
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();	
			for(int i=0;i<4;++i){
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(!isValid(nx,ny)) continue;
				grid[nx][ny] = 2;
				if(!rotten) ans++, rotten = 1;
				Q.push(pii(nx,ny));
			}
		}
		Q.pop();
		if(!Q.empty())
			Q.push(pii(-1,-1));
	}

	return checkFreshOrange()? -1 : ans;
}

int main(){
	cout << RotOranges();
	return 0;
}