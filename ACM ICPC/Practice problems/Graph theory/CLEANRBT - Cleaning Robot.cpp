/*Here, we want to solve path planning for a mobile robot cleaning a rectangular room floor with furniture.

Consider the room floor paved with square tiles whose size fits the cleaning robot (1 × 1). There are 'clean tiles' and 'dirty tiles', 
and the robot can change a 'dirty tile' to a 'clean tile' by visiting the tile. Also there may be some obstacles (furniture) whose size 
fits a tile in the room. If there is an obstacle on a tile, the robot cannot visit it. The robot moves to an adjacent tile with one move.
 The tile onto which the robot moves must be one of four tiles (i.e., east, west, north or south) adjacent to the tile where the robot
  is present. The robot may visit a tile twice or more.

Your task is to write a program which computes the minimum number of moves for the robot to change all 'dirty tiles' to 'clean tiles', 
if ever possible.

Input

IThe input consists of multiple maps, each representing the size and arrangement of the room. A map is given in the following format.

w h
c11 c12 c13 ... c1w
c21 c22 c23 ... c2w
...
ch1 ch2 ch3 ... chw
The integers w and h are the lengths of the two sides of the floor of the room in terms of widths of floor tiles. w and h are less than 
or equal to 20. The character cyx represents what is initially on the tile with coordinates (x, y) as follows.

'.' : a clean tile
'*' : a dirty tile
'x' : a piece of furniture (obstacle)
'o' : the robot (initial position)

In the map the number of 'dirty tiles' does not exceed 10. There is only one 'robot'.

The end of the input is indicated by a line containing two zeros.

Output

For each map, your program should output a line containing the minimum number of moves. If the map includes 'dirty tiles' which 
the robot cannot reach, your program should output -1.

Example

Input:
7 5
.......
.o...*.
.......
.*...*.
.......
15 13
.......x.......
...o...x....*..
.......x.......
.......x.......
.......x.......
...............
xxxxx.....xxxxx
...............
.......x.......
.......x.......
.......x.......
..*....x....*..
.......x.......
10 10
..........
..o.......
..........
..........
..........
.....xxxxx
.....x....
.....x.*..
.....x....
.....x....
0 0

Output:
8
49
-1
*/

int geti(){ int x; si(x); return x; }
int gcd(int a, int b){ return (a == 0) ? b : (b == 0) ? a : (a%b == 0) ? b : gcd(b, a%b); }

int div_str(char s[], int a){
 int y = 0, ln = strlen(s);
 rep(i, 0, ln) y = ((y * 10) + (s[i] - '0')) % a;
 return y;
}

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

typedef pair<int, int>pii;
typedef pair<pii, int>piii;
pii src;
char grid[22][22];
int id, n, m;
int valid(int a, int b){ return (a >= 0 && b >= 0 && a < n && b < m && grid[a][b] != 'x'); }

void bfs()
{
 bool vist[22][22][1024]={};
 int lev = 1, x, y, z, a, b, c;
 queue<piii>que;
 que.push(mp(mp(src.first, src.second), 0));
 vist[src.first][src.second][0] = 1;
 while (que.size())
 {
  int s = que.size();
  while (s--)
  {
   x = que.front().first.first;
   y = que.front().first.second;
   z = que.front().second; que.pop();
   rep(i, 0, 4)
   {
    a = x + dx[i];
    b = y + dy[i];
    c = z;
    if (valid(a, b))
    {
     if (grid[a][b] >= '0' && grid[a][b] <= '9')  c |= (1 << grid[a][b] - '0');
     if (c == (1 << id) - 1){ printf("%d\n", lev ); return; }
     if (vist[a][b][c])continue;
     vist[a][b][c] = 1;
     que.push(mp(mp(a, b), c));
    }
   }
  }
  lev++;
 }
 printf("-1\n");
}
int main() {
 
 while (si2(m, n) > 0 && n && m)
 {
  id = 0;
  rep(i, 0, n)rep(j, 0, m){
   sc(grid[i][j]);
   if (grid[i][j] == 'o')src = mp(i, j);
   if (grid[i][j] == '*')grid[i][j] = id++ + 48;
  }
  bfs();
 }
 return 0;
}

///////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

#define Point pair<int, pair<int, int> >
#define X first
#define Y second.first
#define cost second.second
#define mp(a,b,c) make_pair(a, make_pair(b,c))

int R, C, N;
int sd [12][12];
int ind [12][2];
char grid[25][25];
int vis[25][25];

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int bfs(int n){
    queue<Point > q;
    memset(vis,0,sizeof vis);
    q.push(mp(ind[n][0], ind[n][1],0));
    int tbv = 0;
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        if (vis[p.X][p.Y]||grid[p.X][p.Y]=='x')
            continue;
        vis[p.X][p.Y] = 1;
        if (grid[p.X][p.Y]>='0'&&grid[p.X][p.Y]<='9'){
            sd[n][grid[p.X][p.Y]-'0'+1] = p.cost;
            tbv++;
        }
        if (grid[p.X][p.Y]=='o'){
            sd[n][0] = p.cost;
            tbv++;
        }
        for (int i=0;i<4;i++){
            int nx = p.X + dx[i],ny = p.Y + dy[i];
            if (nx>=0&&ny>=0&&nx<R&&ny<C&&grid[nx][ny]!='x'&&!vis[nx][ny])
                q.push(mp(nx,ny,p.cost+1));
        }
    }
    if (tbv==N)
        return 1;
    else return 0;
}

int dp[12][8000];


int minimize(int n, int bitmask){
    if (bitmask==(1<<N)-1)
        return 0;
    if (dp[n][bitmask]!=-1)
        return dp[n][bitmask];
    dp[n][bitmask] = 100000000;
    int nb = bitmask|(1<<n);
    for (int i=0;i<N;i++){
        if (!(bitmask&(1<<i)))
            dp[n][bitmask] = min(dp[n][bitmask], sd[n][i]+minimize(i,nb));
    }
    return dp[n][bitmask];
}


int compute (){
    for (int i=0;i<N;i++)
        if (!bfs(i))
            return -1;
    memset(dp, -1, sizeof dp);
    return minimize(0,0);
}

int main(){
    scanf("%d %d", &C, &R);
    while(!(!R&&!C)){
        N = 1;
        for (int i=0;i<R;i++){
            scanf("%s", grid[i]);
            for (int j=0;j<C;j++)
                if (grid[i][j]=='*'){
                    grid[i][j] = '0'+N-1;
                    ind[N][0] = i;
                    ind[N][1] = j;
                    N++;
                }
                else if (grid[i][j]=='o'){
                    ind[0][0] = i;
                    ind[0][1] = j;
                }
        }
        printf("%d\n",compute());
        scanf("%d %d", &C, &R);
    }
}