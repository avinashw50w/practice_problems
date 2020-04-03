// for undirected graph //
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
typedef  pair<int,ll> pii;
typedef vector<int> vi;
const ll oo (1LL<<55);
#define miii unordered_map < int , unordered_map < int , int > > 
vector<ll> dist;
struct comp{
	int operator()(const pii &a,const pii &b){ return a.second>b.second; }
};
void dijkstra(miii G,int s,int n){
	dist[s]=0;
	priority_queue<pii,vector<pii>,comp> q;
	q.push(pii(s,0));
	while(!q.empty()){
		int u=q.top().first; q.pop();
		for(auto &c:G[u]){
			int v=c.first , w=c.second;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				q.push(pii(v,dist[v]));
			}
		}
	}
	for(int i=1;i<=n;i++){
        if(i!=s)
		cout<<(dist[i]==oo?-1:dist[i])<<" ";
	}
}
int main(){
	int t;cin>>t;
	while(t--){
		int n,m; cin>>n>>m;
		miii G;
		dist.assign(n+1,oo);
		while(m--){
			int x,y,w;
			cin>>x>>y>>w;
			if(G[x].find(y)==G[x].end()) 
				G[x][y]=w;
			else
				G[x][y]=min(G[x][y],w);
			
			if(G[y].find(x)==G[y].end()) 
				G[y][x]=w;
			else
				G[y][x]=min(G[y][x],w);
			
		}
		int s;cin>>s;
		dijkstra(G,s,n);
		cout<<endl;
	}
	return 0;
}