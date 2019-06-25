/*Colonel Oliver and his battalion were in midst of a battle against an extraterrestrial species Zomni. The Colonel has to win the battle at any cost to save all of humanity. He was short of soldiers, however, he had a very powerful weapon bazooka which could be used only once during the war.

The Zomni army was divided into small troops scattered at different locations (which can be contained in a N x M battle ground). The bazooka, once launched on some troop is capable of killing all the Zomnis of that troop at a time but cannot harm any Zomni soldier in other troops.

The war is coming to an end and the Colonel is about to lose. He has only one bazooka but something he knows for sure is that if he is able to kill the maximum possible soldiers with this bazooka, he and his soldiers definitely have a chance of winning the battle.

So, the Colonel seeks your help in finding out the maximum number of Zomnis he can kill in one strike of the bazooka and also the total number of Zomni troops gathered against them so that he can divide his battalion efficiently (the troop killed by the bazooka should also be included).

Two Zomni soldiers belong to the same troop if they are at adjacent positions in the battle ground. Therefore, any soldier who is not at some boundary of the battle ground can have a maximum of 8 adjacent soldiers.

INPUT:
First line contains single integer T, the number of test cases. First line of each test case contains two space separated integers N and M (size of the battle ground), followed by N lines containing M integers 0 or 1 where 0 means an empty space and 1 means a Zomni soldier.

OUTPUT:
For every test case, output two space separated integers X and Y where X is the number of Zomni troops and Y is the maximum number of Zomnis that can be killed by a single strike of the bazooka.

CONTSTRAINTS:
1 ≤ T ≤ 10
1 ≤ N,M ≤ 1000*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)

const int maxn = 1000+5;
int N, M;
int vis[maxn][maxn];
int mat[maxn][maxn];

int dx[] = {0,1,0,-1,1,1,-1,-1};
int dy[] = {1,0,-1,0,-1,1,-1,1};

bool isSafe(int x, int y) {
    return (x >= 0 and x < N and y >= 0 and y < M and mat[x][y] == 1);
}

void dfs(int x, int y, int &cnt){
    vis[x][y] = 1;
    cnt++;
    rep(i, 0, 8) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!isSafe(nx, ny)) continue;
        if(!vis[nx][ny])
            dfs(nx, ny, cnt);
    }
}

int main() {
    int t; cin>> t;
    while(t--) {
        cin >> N >> M;
        
        rep(i,0,N) rep(j,0,M) cin>>mat[i][j];
        
        memset(vis,0,sizeof(vis));
        
        int ans1 = 0, ans2 = 0;
        rep(i,0,N)
        rep(j,0,M)
        {
            int cnt = 0;
            if(!vis[i][j] and mat[i][j] == 1) { ans1++; dfs(i, j, cnt); }
           
            ans2 = max(ans2, cnt);
        }
        
        cout << ans1 << " " << ans2 << endl;
    }
}
