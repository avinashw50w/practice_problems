/*Given an undirected weighted connected graph, it is required to find the Really Special SubTree in it. The Really Special SubTree is defined as a subgraph consisting of all the nodes in the graph and

There is only one exclusive path from a node to every other node.
The subgraph is of minimum overall weight (sum of all edges) among all such subgraphs.
While creating the Really Special SubTree, start by picking the edge with smallest weight. If there are edges of equal weight available at an instant, then the edge to be chosen first among them is the one with minimum value of sum of the following expression :
u + wt + v , where u and v are the node numbers of the corresponding edge and wt is the weight.
Even then if there is a collision, choose any one of them.
While doing the above, ensure that no cycle is formed while picking up edges.
Finally, you need to print the overall weight of the Christmas Tree so formed using above rules.*/

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
unordered_map<int,int> RANK,PARENT;

void makeset(int i){
    RANK[i] = 0;
    PARENT[i] = i;
}
int findset(int i){
    if(i==PARENT[i]) return i;
    return findset(PARENT[i]);
}
void Union(int u,int v){
    if(RANK[u]>=RANK[v]){
        RANK[u] = (RANK[u]==RANK[v])? RANK[u]+1: RANK[u];
        PARENT[v]=u;
    }
    else PARENT[u]=v;
}
struct edge{
    int u,v,w;
    edge(int a,int b,int c): u(a), v(b), w(c){} 
};
struct graph{
    vector<edge> edges;
};

int n,m,x,y,r,s;
graph g;

int kruskal(){
    int weight = 0;
    for(int i=1;i<=n;++i) makeset(i);
    sort(g.edges.begin(), g.edges.end(), [](edge a,edge b){return a.w < b.w;});
    for(edge &e: g.edges){
        int set1 = findset(e.u);
        int set2 = findset(e.v);
        if(set1 != set2){
            Union(set1,set2);
            weight += e.w;
        }
    }
    return weight;
}

int main() { 
    cin>>n>>m;
    while(m--){
        cin>>x>>y>>r;
        g.edges.push_back(edge(x,y,r));
    }
    cin>>s;
    cout << kruskal() << endl;
    
    return 0;
}
