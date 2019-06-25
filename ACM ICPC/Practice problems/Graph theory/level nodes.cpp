/*You have been given a Tree consisting of 
N nodes. A tree is a fully-connected graph consisting of N nodes and N−1 edges. The nodes in this tree are indexed from 1 to N. Consider node indexed 
1 to be the root node of this tree. The root node lies at level one in the tree. You shall be given the tree and a single integer x . You need to find out the 
number of nodes lying on level x.

Input Format

The first line consists of a single integer 
N denoting the number of nodes in the tree. Each of the next n−1 lines consists of 2 integers a and b denoting an undirected edge between node a and node 
b. The next line consists of a single integer x.

Output Format

You need to print a single integers denoting the number of nodes on level x.

Constraints

1≤N≤105
1≤a,b≤N

Note

It is guaranteed that atleast one node shall lie on level x
SAMPLE INPUT 
20
11 1
1 2
13 3
15 4
17 5
11 6
2 7
1 8
15 9
4 10
15 12
5 13
2 14
17 15
15 16
11 17
15 18
9 19
16 20
2*/

#include <iostream>
#include <vector>
using namespace std;

int vis[100001];
int level[100001];
vector<int> g[100001];

void dfs(int u){
	vis[u]=1;
	for(int i=0;i<g[u].size();++i){
		if(!vis[g[u][i]]){
			level[g[u][i]] = level[u] + 1;
			dfs(g[u][i]);
		}
	}
}

int main()
{
    int n,a,b;
    cin>>n;
    
    for(int i=0;i<n-1;++i) {
    	cin>>a>>b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }

    level[1]=1;
    dfs(1);

    int x; cin>>x;
    int cnt = 0;

    for(int i=0;i<=100000;++i){
    	if(level[i]==x) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
