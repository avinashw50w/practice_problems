/*Given a directed, weighted graph, consisting of N nodes and there are M edges ,of specified length between some of them in the graph.

Given  questions, inquring the shortest distance between a queried pair of nodes in the graph.

Answer all these questions as quickly as possible !

Input Format

First line has two integers , denoting the number of nodes in the graph and , denoting the number of edges in the graph. 
The next  lines each consist of three space separated integers   , where  and  denote the two nodes between which the directed edge  exists,  denotes the length of the edge between the corresponding edges. 
The next line contains a single integer , denoting number of queries. 
The next  lines each, contain two space separated integers  and , denoting the node numbers specified according to the question*/
#include <bits/stdc++.h>
using namespace std;
#define inf 100000000

int main() {
    int n,m,q,x,y,r,a,b;
    cin>>n>>m;
    int g[n][n];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i==j) g[i][j] = 0;
            else g[i][j] = inf;
        }
    }  
    
    while(m--){
        cin>>x>>y>>r;
        g[x-1][y-1] = r;
    }
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
            }
        }
    }
    cin>>q;
    while(q--){
        cin>>a>>b;
        (g[a-1][b-1] != inf)? cout << g[a-1][b-1] : cout << -1;
        cout << endl;
    }
    return 0;
}
