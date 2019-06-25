#include <bits/stdc++.h>
#define INF 99999999
#define pb push_back
#define mp make_pair
using namespace std;
struct edge
{
int x,y;

int r,t;
};
vector< pair<int,int> >adj[9000];
vector<int> dijkstra(vector<int>d,int s,int n){
	d.clear();
	d.assign(n+1, INF);
	d[s]=0;
	set<pair<int,int> >q;
	q.clear();
	q.insert(mp(0,s));
	while(!q.empty())
	{
    	auto top = q.begin();
    	q.erase(top);
    	int u = top->second;
    	   for(auto &c : adj[u]) 
    	   {
        	    int v = c.second;
            	int cost = c.first;
          		if( (d[v] > (d[u]+cost))) 
            	{
            	     if( d[v]!=INF) 
            	     {
            	           q.erase(q.find(mp(d[v],v)));
            	     }
            	     d[v]=d[u]+cost;
            	     q.insert(mp(d[v], v));
            	}
       	}
	}
	return d;
}
int main()
{
int T,t,r,x,y,n,m,i,s,d;

cin>>T;

while(T--)
{
    cin>>n>>m;
    for(i=0;i<n+9;i++)
    adj[i].clear();
    vector<int>d1,d2;
    d1.resize(n+1);
    d2.resize(n+1);
    struct edge e[m+1];
    for(i=0;i<m;i++)
    {
        cin>>x>>y>>r>>t;
        e[i].x=x;
        e[i].y=y;
        e[i].r=r;
        e[i].t=t;
        adj[x].pb(mp(r,y));
        adj[y].pb(mp(r,x));
    }
    cin>>s>>d;
    d1=dijkstra(d1,s,n);
    d2=dijkstra(d2,d,n);
    int ans=d1[d];
    for(i=0;i<m;i++)
    {
        int x1,y1,r1,t1; 
        x1=e[i].x;
        y1=e[i].y;
        t1=e[i].t;
        ans=min(ans,d1[x1]+t1+d2[y1]);
        ans=min(ans,d1[y1]+t1+d2[x1]);
    }
    if(ans != INF)
    cout<<ans<<endl;
    else
    cout<<"-1\n";
}

return 0;
}
