/*Leha likes traveling a lot. In particular he likes discovering new routes in his world which he calls a tree-world.

Leha's world is a connected tree of N vertices, so there is a unique path between any pair of vertices a and b. Every day Leha chooses some 
new pair of vertices and walks along this route. Sometimes he notices that he has already been in some vertices during his previous walks. 
So now for each new route that he takes, he is interested in knowing how many previous routes does it intersect? Two routes are considered 
to be intersecting with each other, if they have at least one common vertex.

Input

The first line contains one integer N denoting the number of vertices in the tree. Vertices are enumerated from 1 to N.

The following N-1 describe the edges of the tree. Each of these lines contains two space separated integers u, v denoting that there is an 
edge between vertex u and v.

The next line contains an integer Q denoting the number of days Leha is traveling. Each of next Q lines contains two space separated integers 
u, v denoting the start and finish vertices of the corresponding route.
Output
For each day output one integer on a separate line - the number of previous routes it intersects with.
Input:
5
1 2
1 3
3 4
3 5
4
4 5
4 2
1 3
1 2

Output:
0
1
2
2
Explanation

Day 1. As there is no previous route, the route from 4 to 5 can't intersect with any round. Hence answer is 0.

Day 2. Route from 4 to 2 intersects with route 1 (at vertices 3 and 4), So the answer is 1.

Day 3. Route from 1 to 3: intersects with both the previous routes. Hence answer is 2.

Day 4. Route from 1 to 2: intersects with route 2 and 3. Hence answer is 2.*/

/*PROBLEM:
You are given a tree consisting of nn node. Each time, you want to insert a route from node uu to vv in the tree. Before inserting the route,
 you want to find the number of already inserted routes which intersect with the current route. Two routes are said to be intersecting with 
 each other, if they have at least one node in common.

QUICK EXPLANATION
Let us suppose we want to insert a route from node uu to vv. Let lca(u,v)=wlca(u,v)=w. We can categorise the already inserted routes which 
intersect with this route into one of the below two categories.

The routes (u′,v′)(u′,v′) s.t. their lca w′w′ is a strict ancestor of ww.
The routes (u′,v′)(u′,v′) s.t. their lca w′w′ lies inside the subtree rooted at ww.
We can find number of routes in each of the categories by finding sum of all the nodes in a subtree.

The routes (u′,v′)(u′,v′) s.t. their lca w′w′ is a strict ancestor of ww. This means that only one of the u′u′ or v′v′ will lie inside the 
subtree rooted at ww. Both can not lie inside as in that case their lca won't be a strict ancestor of ww. Both can't lie outside as their 
route won't intersect with route u,vu,v. For finding this information, let us maintain a value PP for each node. We update the array PP in 
the following way. When we add a route from uu to vv. We add 1 in P[u]P[u] and P[v]P[v], and subtract 2 from P[w]P[w]. While answering a 
query for route u,vu,v, we can find the routes of category 1 and 2 using PP values as follows. We can find count of such u′u′'s or v′v′'s by 
finding sum of PP values of all the nodes in the subtree of ww.

The routes (u′,v′)(u′,v′) s.t. their lca w′w′ lies inside the subtree rooted at ww. In this case, it is necessary that their lca w′w′ will 
lie in the route (u,v)(u,v). It means that we can uniquely identify the routes with their lca values. So, finding number of routes in this 
category will be same as finding number of lca values of previous routes which lie on the route (u,v)(u,v). Let intime[i]intime[i] denote the 
enter time of dfs for node ii and outtimeouttime denote the exit time of the dfs. Suppose we want to add +val at some node x, then we can do 
+val at intime[x]intime[x] and - val at outtime[x]outtime[x]. Then the sum sum of path from root to vertex xx will be equal to prefix sum of 
values up to intime[x]intime[x]. Using this information, we can find sum of values on a path too

Finding sum of values of all the nodes of subtree can be done by linearising the tree into an array such that the subtree corresponds to a 
consecutive interval. It can be done by finding pre order of the tree. After that the problem reduces into an array point update and finding 
sum of elements in some range of the array which can be done using BIT or segment tree.*/

#include<bits/stdc++.h>
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define si(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define pi(x) printf("%d\n",x)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end(); it++)

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

const int mod = 1000000007;
inline void add(int &x, int y){x+=y; if(x>=mod)x-=mod; if(x<0)x+=mod;}
inline int mul(int x, int y){ return ((LL)x * y)%mod;}
int gcd(int a, int b){ if(b)return gcd(b,a%b); return a;}
int power(int a ,int p){int ret = 1; while(p){if(p&1)ret=mul(ret,a); a=mul(a,a); p/=2;}return ret;}
int phi(int n){ int ret=n; int i = 2; 
    if(n%i==0){ ret-=ret/i; while(n%i==0)n/=i;}
    for(i=3; i*i<=n; i++)if(n%i==0){ ret-=ret/i; while(n%i==0)n/=i;}
    if(n>1)ret-=ret/n;return ret;
}

const int N = 200000;
const int LG = 19;
int tim;

int depth[N+1], parent[LG][N+1], out[N+1];

int in[N];
VI edge[N];
int n;


void dfs(int x, int d, int p)
{
    in[x] = ++tim;
    parent[0][tim] = in[p]; 
    depth[tim] = d; 
    for(auto y : edge[x])
        if(y != p)
            dfs(y,d+1,x);
    out[in[x]] = tim;
}

int lca(int x, int y)
{
    if(depth[x] < depth[y])swap(x,y);
    int d = depth[x] - depth[y]; 
    int l =0; 
    while(d>0){
        if(d&1) x = parent[l][x];
        d/=2; l++;
    }
    if(x==y)return x; 
    for(int l = LG-1; l>=0; l--){
        if(parent[l][x]==parent[l][y])continue; 
        x = parent[l][x]; y = parent[l][y];
    }
    return parent[0][x];
}

int BT1[N+1], BT2[N+1];
void update(int BT[], int x, int val)
{
    while(x<=n){BT[x] += val; x += (x & (-x));}
}
int query(int BT[], int id)
{
    int ret = 0;
    while(id>0)
    {
        ret += BT[id]; 
        id &= (id-1);
    }
    return ret;
}
int query(int BT[], int l, int r)
{
    return query(BT,r) - query(BT,l-1);
}

void input()
{
    si(n);
    assert(n>0);
    for(int i =0;  i<n-1; i++)
    {
        int x,y; 
        si(x); si(y);
        x--; y--; 
        edge[x].PB(y); 
        edge[y].PB(x);
    }
}

void preprocess()
{
    tim = 0;
    dfs(0,0,0);
    for(int l = 1; l<LG; l++)
        for(int i =1; i<=n; i++)
            parent[l][i] = parent[l-1][parent[l-1][i]];
}


int main(int argc, char** argv)
{
    input();
    preprocess();
   // for(int i=0;i<3;++i)

    int q; si(q); while(q--)
    {
        int a,b; si(a); si(b); a = in[a-1]; b = in[b-1];
        int l = lca(a,b);
        int ans =  query(BT1,l,out[l]);
     //   trace(a,b,l,ans);
        update(BT1, a, 1);
        update(BT1, b, 1);
        update(BT1, l, -2);
        
        ans += query(BT2,a) + query(BT2,b) - query(BT2,l) -  (l==1  ? 0 : query(BT2, parent[0][l]));
       // trace(ans);
        update(BT2,l,1);
        update(BT2,out[l]+1,-1);
        pi(ans);
    }
    return 0;	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<bits/stdc++.h>
 
#define MOD 1000000007
#define MAX 200005
#define ll long long
#define slld(t) scanf("%lld",&t)
#define sd(t) scanf("%d",&t)
#define pd(t) printf("%d\n",t)
#define plld(t) printf("%lld\n",t)
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define mp(a,b) make_pair(a,b)
#define FF first
#define SS second
#define pb(x) push_back(x)
#define vi vector<int>
#define vpii vector<pii >
#define vll vector<ll>
#define clr(x) memset(x,0,sizeof(x))
 
using namespace std;
 
// Why u not set TL for segT to pass :'(
 
vector<int> adj[MAX];
bool visited[MAX];
 
int st[MAX],en[MAX],st2[MAX],en2[MAX],F[MAX],L[MAX],global=0,tme=0; // F stores father of node and L stores depth of node
 
void dfs(int x){
    visited[x]=true;
    st[x]=++global;
    st2[x]=++tme;
    for(int i=0;i<adj[x].size();i++){
        if(!visited[adj[x][i]]) L[adj[x][i]]=1+L[x],dfs(adj[x][i]),F[adj[x][i]]=x;
    }
    en[x]=global;
    en2[x]=++tme;
}
 
int P[17][MAX];
 
void preLCA(int N){
    int i, j;
    
    for (i = 1; i <= N; i++)
        for (j = 0; 1 << j < N; j++)
            P[j][i] = -1;
   
    for (i = 1; i <= N; i++)
        P[0][i] = F[i];
   
    for (j = 1; 1 << j < N; j++)
        for (i = 1; i <= N; i++)
            if (P[j-1][i] != -1)
                P[j][i] = P[j - 1][P[j-1][i]];
}
 
int LCA(int p,int q){
    int tmp, log, i;
   
    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;
  
    for (log = 1; 1 << log <= L[p]; log++);
      log--;
   
    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = P[i][p];
   
    if (p == q)
        return p;
   
    for (i = log; i >= 0; i--)
        if (P[i][p] != -1 && P[i][p] != P[i][q])
              p = P[i][p], q = P[i][q];
   
    return F[p];
}
 
int BIT1[MAX];
 
void update1(const int &t,const int &i,const int &j,const int &update_index,const int &inc){
    // this much argument was not needed but just not in order to edit the pre-written code
    
    int index=update_index;
    int n=MAX-1;
    
    while(index<n){
        BIT1[index]+=inc;
        index = index + (index & (-index));
    }
}
 
int query1(const int &t,const int &i,const int &j,const int &ri,const int &rj){
    int n=MAX-1;
    int ans=0;
    int index=rj;
    while(index){
        ans+=BIT1[index];
        index = index - (index & (-index));
    }
    index=ri-1;
    while(index){
        ans-=BIT1[index];
        index = index - (index & (-index));
    }
    return ans;
}
 
int BIT2[MAX<<1];
 
void update2(const int &t,const int &i,const int &j,const int &update_index,const int &inc){
    // this much argument was not needed but just not in order to edit the pre-written code
    
    int index=update_index;
    int n=2*MAX-1;
    
    while(index<n){
        BIT2[index]+=inc;
        index = index + (index & (-index));
    }
}
 
int query2(const int &t,const int &i,const int &j,const int &ri,const int &rj){
    int n=2*MAX-1;
    int ans=0;
    int index=rj;
    while(index){
        ans+=BIT2[index];
        index = index - (index & (-index));
    }
    index=ri-1;
    while(index){
        ans-=BIT2[index];
        index = index - (index & (-index));
    }
    return ans;
}
 
int main(){
    int N;sd(N);
    
    for(int i=1;i<N;i++){
        int u,v;
        sd(u);sd(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    clr(visited);
    F[1]=-1; L[1]=0;
    dfs(1);
    preLCA(N);
    
    int lim=N<<1;
    
    int Q;sd(Q);
    clr(BIT1);clr(BIT2);
    while(Q--){
        int u,v;sd(u);sd(v);
        int x=LCA(u,v);
        
        int ans=query1(1,1,N,st[x],en[x]);
        ans+=query2(1,1,lim,1,st2[u])-query2(1,1,lim,1,st2[x]);
        ans+=query2(1,1,lim,1,st2[v])-query2(1,1,lim,1,st2[x]);
        pd(ans);
        
        update1(1,1,N,st[u],1);
        update1(1,1,N,st[v],1);
        update1(1,1,N,st[x],-1);
        if(F[x]!=-1) update1(1,1,N,st[F[x]],-1);
        update2(1,1,lim,st2[x],1);
        update2(1,1,lim,en2[x],-1);
    }
} 