#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long int
using namespace std;
vi V(101010,0);
vi G[101010];

ll bfs(int s){
	V[s]=1;
	queue<int> q;
	q.push(s);
	ll res=1;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(auto &v:G[u]){
			if(!V[v]){
				V[v]=1;
				q.push(v);
				res++;
			}
		}
	}
	return res;
}

int main(){
	int n,k; cin>>n>>k;
	while(k--){
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	} 
	ll ans=0,sum=0;
	for(int i=0;i<n;i++){
		if(!V[i]){
			ll a=bfs(i);
			ans+= sum*a;
			sum+=a;
		}
	}
	cout<< ans <<endl;
}
