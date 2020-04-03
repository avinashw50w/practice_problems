#include <bits/stdc++.h>
#define vi vector<int> 
using namespace std;
vi dist;
vi *G;
struct comp{
	int operator()(const int &a,const int &b){ return dist[a]>dist[b];}
};
int main(){
	int t; cin>>t;
	while(t--){
		int n,m; cin>>n>>m;
		G= new vi[n+1];
		int m1=m;
		int x,y;
		while(m1--){
			cin>>x>>y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		int s; cin>>s;
		dist=vi(n+1,-1);
		dist[s]=0;
		priority_queue<int,vi,comp> Q;
		Q.push(s);
		while(!Q.empty()){
			int u=Q.top(); Q.pop();
			for(auto &v : G[u]){
				if(dist[v]==-1 || dist[v]> dist[u]+1){
					dist[v]=dist[u]+1;
					Q.push(v);
				}
			}
		}

		for(int i=1;i<=n;i++){
			if(i!=s){
				cout<<((dist[i]==-1)? -1 : dist[i]*6 )<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}