/* Atul is into graph theory, and he is learning about trees nowadays. He observed that the removal of an edge from a given tree T will result in the formation of two separate trees, T1 and T2.

Each vertex of the tree T is assigned a positive integer. Your task is to remove an edge, such that the Tree_diff of the resultant trees is minimized. Tree_diff is defined as the following:

 F(T) = Sum of numbers written on each vertex of a tree T
 Tree_diff(T) = abs(F(T1) - F(T2))
Input Format 
The first line will contain an integer N, i.e. the number of vertices in the tree.
The next line will contain N integers separated by a single space, i.e. the values assigned to each of the vertices.
The next N−1 lines contain a pair of integers each, separated by a single space, that denote the edges of the tree.
In the above input, the vertices are numbered from 1 to N.

Output Format 
A single line containing the minimum value of Tree_diff.

Constraints 
3≤N≤105 
1≤ number written on each vertex ≤1001

Sample Input

6
100 200 100 500 100 600
1 2
2 3
2 5
4 5
5 6
Sample Output

400
Explanation

Originally, we can represent tree as

         1(100)
          \
           2(200)
          / \
    (100)5   3(100)
        / \
  (500)4   6(600)
Cutting the edge at 1 2 would result in Tree_diff = 1500-100 = 1400 
Cutting the edge at 2 3 would result in Tree_diff = 1500-100 = 1400 
Cutting the edge at 2 5 would result in Tree_diff = 1200-400 = 800 
Cutting the edge at 4 5 would result in Tree_diff = 1100-500 = 600 
Cutting the edge at 5 6 would result in Tree_diff = 1000-600 = 400

Hence, the answer is 400.   */


#include <bits/stdc++.h>
#define vi vector<int> 
#define ll long long int
using namespace std;
ll sum[100002];
ll mini=1010101010;
ll cost[100002];
vi *g;
vi V;
ll dfs(int u){
        V[u]=1;
        ll val=0;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            if(!V[v])
                val+=dfs(v);
        }
        return sum[u]=cost[u]+val;
}
    

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;cin>>n;
    g=new vi[n+1];
    V=vi(n+1,0);
    ll total_cost=0;
    for(int i=1;i<=n;i++){cin>>cost[i] , total_cost+=cost[i];};
    for(int i=0;i<n;i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        mini=min(mini,abs((total_cost-sum[i])-sum[i]));
    }
    cout<<mini;
    return 0;
}
