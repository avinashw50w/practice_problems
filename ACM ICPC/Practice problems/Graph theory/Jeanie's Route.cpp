/*Byteland has N cities (numbered from 1 to N) and N-1 bidirectional roads. It is guaranteed that there is a route from any 
city to any other city. Jeanie is a postal worker who must deliver K letters to various cities in Byteland. 
She can start and end her delivery route in any city. Given the destination cities for K letters and the 
definition of each road in Byteland, find and print the minimum distance Jeanie must travel to deliver all K letters. 
Note: The letters can be delivered in any order.

 

Input
The first line contains two space-separated integers, N (the number of cities) and K (the number of letters), respectively. 
The second line contains K space-separated integers describing the delivery city for each letter. Each line of the 
subsequent lines contains space-separated integers describing a road as ui,vi,di, where di is the distance (length) 
of the bidirectional road between cities ui and vi.

Output
Print the minimum distance Jeanie must travel to deliver all K letters.

Constraints
2<=K,N<=10^5  1<=di<10^3 it is weighted undirected acyclic graph

Example
Input:
5 3
1 3 4
1 2 1
2 3 2
2 4 2
3 5 3

Output:
6
 

Explanation
Jeanie has K letters she must deliver to cities 1,3 ,4 and in the following map of 
Byteland Optimal route=3>2>1>2>4 so distance travelled=6 ...*/

/*ans = (sum of edges Jeanie has to pass) x 2  -  (Maximum path len between any two nodes of the K nodes)*/

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define MA(x,y) ((x)>(y)?(x):(y))
using namespace std;
const int N=500002;
const int inf=1000000000;
int n,K,s[N],SUM,M;
bool f[N];
vector <int> v[N],d[N];

int input(){
    scanf("%d%d",&n,&K);
    for (int i=0,x;i<K;i++){
        scanf("%d",&x);
        s[x]=1;
        f[x]=1;
    }
    for (int i=1,x,y,z;i<n;i++){
        scanf("%d%d%d",&x,&y,&z);
        v[x].pb(y);
        v[y].pb(x);
        d[x].pb(z);
        d[y].pb(z);
    }
    return 0;
}

int go(int x,int from){
    int D1=-inf;
    int D2=-inf;

    for (int i=0;i<v[x].size();i++)
    if (v[x][i]!=from){
        D1=max(D1,go(v[x][i],x)+d[x][i]);
        if (D1>D2) swap(D1,D2);
        s[x]+=s[v[x][i]];
        if (0<s[v[x][i]] && s[v[x][i]]<K) SUM+=d[x][i];
    }

    if (D1>0) M=max(M,D1+D2);

    if (D2>0 && f[x]) M=max(M,D2);

    if (f[x]) D2=max(D2,0);

    return D2;
}

int sol(){
    go(1,1);
    
    printf("%d\n",SUM*2-M);
    return 0;
}

int main() {
    input();
    sol();
    return 0;
}

///////////////////////////////////////////////////////////////////

const int MAXN = 1e5;
vector<pair<int,int>> G[MAXN];
int S[MAXN], D[MAXN], city[MAXN];
int N, K;

int dfs(int u, int p) {
    int ret = 0;

    for(auto it: G[u]) {
        int v = it.first;
        int w = it.second;

        if(v != p) {
            D[v] = D[u] + w;
            ret += dfs(v, u);
            S[u] += S[v];

            if(S[v] > 0) ret += v;
        }
    }

    return ret;
}

int main() {
    cin >> N >> K;

    rep(i, 0, K) {
        cin >> city[i];
        city[i]--;
        S[city[i]] = 1;
    }

    rep(i, 1, N) {
        int a, b, c;
        G[--a].push_back(--b, c);
        G[b].push_back(a, c);
    }

    D[city[0]] = 0;

    int sum = dfs(city[0], -1);

    int x = 0;

    rep(i, 0, K)
        if(D[city[i]] > D[city[x]]) 
            x = i;

    memset(D, 0, sizeof(D));

    dfs(city[x], -1);

    int y = 0;

    rep(i, 0, K)
        if(D[city[i]] > D[city[y]])
            y = i;

    int ans = 2*sum - D[city[y]];

    cout << ans << endl;
}

/////////////////////////////////////////////////////////////////////

#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LN = 17;
int n , k;
int arr[N];
int a , b , c;
vector < pair < int , int > > v[N];
int dp[LN][N];
int depth[N], cnt[N], dist[N];
long long ans;
int start , finish;
bool onpath[N];
int dist1[N];

void dfs(int node , int baap){
    dp[0][node] = baap;
    for(auto it : v[node]){
        if(it.first != baap){
            depth[it.first] = depth[node] + 1;
            dist[it.first] = dist[node] + it.second;
            dfs(it.first , node);
        }
    }
}

inline int lca(int a , int b){
    if(depth[a] < depth[b]){
        swap(a , b);
    }
    int dif = depth[a] - depth[b];
    for(int i = 0 ; i < LN ; ++i){
        if(dif & (1 << i)){
            a = dp[i][a];
        }
    }
    if(a != b){
        for(int i = LN - 1 ; i >= 0 ; --i){
            if(dp[i][a] != dp[i][b]){
                a = dp[i][a];
                b = dp[i][b];
            }
        }
        a = dp[0][a];
    }
    return a;
}

inline int distt(int a , int b){
    int lc = lca(a , b);
    return dist[a] + dist[b] - (dist[lc] << 1);
}

inline void solve(){
    int d = 0;
    start = arr[1];
    finish = arr[1];
    for(int i = 2 ; i <= k ; ++i){
        int d1 = distt(arr[i] , start);
        int d2 = distt(arr[i] , finish);
        if(d1 >= d2 && d1 > d){
            finish = arr[i];
            d = d1;
        }
        else if(d2 > d){
            start = arr[i];
            d = d2;
        }
    }
    ans = d;
    int node = start;
    int lc = lca(start , finish);
    while(node != lc){
        onpath[node] = 1;
        node = dp[0][node];
    }
    node = finish;
    while(node != lc){
        onpath[node] = 1;
        node = dp[0][node];
    }
    onpath[lc] = 1;
}

bool dfs2(int node , int baap , int dis){
    if(onpath[node]){
        dis = 0;
    }
    dist1[node] = dis;
    bool ret = !!cnt[node];
    for(auto it : v[node]){
        if(it.first != baap){
            bool tmp = dfs2(it.first , node , dis + it.second);
            ret |= tmp;
            if(tmp && !(onpath[node] && onpath[it.first])){
                ans += it.second * 2LL;
            }
        }
    }
    return ret;
}

int main(){
    scanf("%d %d" , &n , &k);
    
    for(int i = 1 ; i <= k ; ++i){
        scanf("%d" , arr + i);
        ++cnt[arr[i]];
    }

    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d %d" , &a , &b , &c);
        v[a].emplace_back(make_pair(b , c));
        v[b].emplace_back(make_pair(a , c));
    }
    
    dp[0][1] = 0;
    depth[1] = 0;
    dist[1] = 0;
    
    dfs(1 , 0);
    
    for(int i = 1 ; i < LN ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    
    solve();
    dfs2(start , 0 , 0);
    printf("%lld\n" , ans);
}

/////////////////////////////////////////////////////////

