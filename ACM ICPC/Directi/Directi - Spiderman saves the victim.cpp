/*
	               _            .                                 .x+=:.
	              u            @88>                              z`    ^%    .uef^"
	             88Nu.   u.    %8P      u.    u.                    .   <k :d88E
	      u     '88888.o888c    .     x@88k u@88c.       u        .@8Ned8" `888E
	   us888u.   ^8888  8888  .@88u  ^"8888""8888"    us888u.   .@^%8888"   888E .z8k
	.@88 "8888"   8888  8888 ''888E`   8888  888R  .@88 "8888" x88:  `)8b.  888E~?888L
	9888  9888    8888  8888   888E    8888  888R  9888  9888  8888N=*8888  888E  888E
	9888  9888    8888  8888   888E    8888  888R  9888  9888   %8"    R88  888E  888E
	9888  9888   .8888b.888P   888E    8888  888R  9888  9888    @8Wou 9%   888E  888E
	9888  9888    ^Y8888*""    888&   "*88*" 8888" 9888  9888  .888888P`    888E  888E
	"888*""888"     `Y"        R888"    ""   'Y"   "888*""888" `   ^"F     m888N= 888>
	 ^Y"   ^Y'                  ""                  ^Y"   ^Y'               `Y"   888
	                                                                             J88"
	                                                                             @%
	                                                                           :"
*/

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define all(o) (o).begin(),(o).end()
#define mset(a,o) memset((a),(o),sizeof(a))

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int M,N,X,Y,D;

int H[101][101], vis[101][101], dist[101][101];

bool safe(int a, int b, int x, int y) {
	return (x>=1 and x<=M and y>=1 and y<=N and abs(H[a][b] - H[x][y]) <= D);
}

void solve() {

	memset(dist, 0, sizeof(dist));
	memset(vis, 0, sizeof(vis));

	queue<pair<int,int>> Q;

	Q.push(make_pair(1,1));
	
	dist[1][1] = 0;
	vis[1][1] = 1;

	while(!Q.empty()){

		auto u = Q.front(); 

		int x = u.first;
		int y = u.second;

		Q.pop();

		rep(i,0,4) {
			
			int nx = x+dx[i];
			int ny = y+dy[i];

			if(!safe(x, y, nx, ny)) continue;

			if(vis[nx][ny]) continue;

			vis[nx][ny] = 1;

			dist[nx][ny] = dist[x][y] + 1;
			
			if(nx == X and ny == Y) break;

			Q.push(make_pair(nx, ny));
		}
	}

	cout << dist[X][Y]-1 << endl;
}



int main() {
	int t; cin>>t;

	while(t--) {

		cin>>M>>N>>X>>Y>>D;

		rep(i,1,M+1) rep(j,1,N+1) cin>>H[i][j];

		solve();
	}
}