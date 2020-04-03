/* You are given a weighted graph with N nodes and M edges. Some of the nodes are marked as special nodes. Your task is to find the shortest 
pairwise distance between any two different special nodes.
Input

The first line of the input contains three space-separated integers N, M and K denoting the number of nodes, the number of edges, 
and the number of special nodes.
The following line contains K space-separated distinct integers A1, A2, ..., AK , denoting the special nodes.
Each of the following M lines (say, the jth) contains a triple Xj Yj Zj, denoting the edge connecting the nodes Xj and Yj, and having the weight of Zj.
Output

Output the shortest pairwise distance between any two different special nodes.
Constraints

2 = K = N
The given graph is connected.
The given graph doesn't contain self loops and multiple edges.
1 = Ai = N
1 = Zj = 104
1 = Xj, Yj = N
Subtasks

Subtask #1 (20 points): 2 = N = 300, N-1 = M = N*(N-1)/2, 2 = K = N
Subtask #2 (25 points): 2 = N = 105, N-1 = M = 105, 2 = K = 10
Subtask #3 (55 points): 2 = N = 105, N-1 = M = 3 * 105, 2 = K = 104
Example

Input:
5 5 3
1 3 5
1 2 3
2 3 4
3 4 1
4 5 8
1 5 19

Output:
7
Explanation

Nodes 1, 3 and 5 are special nodes. Shortest distance between nodes 1 and 3 is 7 and that between nodes 3 and 5 is 9. 
Shortest distance between nodes 1 and 5 is 16. Minimum of these distances is 7. Hence answer is 7.*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#define fore(i,x) for(typeof((x).begin())i=(x).begin();i!=(x).end();++i)
#define N 100000
#define inf (1<<30)
using namespace std;
#define pii pair<int,int>
#define vii vector<pii >
int n,m,k;
vii G[N+1];
int dist[N+1];
bool special[N+1];
int mini;

void dijkstra(int s){
	dist[s] = 0;
	priority_queue<pii,vii,greater<pii> > q;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(special[u] and u!=s){
			mini = dist[u];
			break;
		}
		fore(c,G[u]){
			int v=c->first, w=c->second;
			if(dist[v] > dist[u]+w){
				dist[v] = dist[u]+w;
				if(dist[v] < mini){
					q.push(pii(dist[v],v));
				}
			}
		}
	}
}

int main(){
	 cin>>n>>m>>k;
	while(k--){
		int z; cin>>z;
		special[z]=true;
	}
	int x,y,z;
	while(m--){
		cin>>x>>y>>z;
		G[x].push_back(pii(y,z));
		G[y].push_back(pii(x,z));
	}
	mini=inf;
	fill(dist+1,dist+n+1,inf);
	for(int i=1;i<=n;++i){
		if(!special[i]) continue;
		dijkstra(i);
	}
	cout<<mini<<endl;
}

/* DIFFICULTY: Medium

PREREQUISITES:
Dijkstra's Algorithm, Floyd Warshall, All Pairs Shortest Path Problem

PROBLEM:
Given is a graph G with N nodes and weighted edges. Out of these N nodes, K are special nodes. We are required to find the minimum distance between any two special nodes.

EXPLANATION:
Subtask 1
In this subtask N=300. This implies that we can simply perform the floyd-warshall algorithm for finding the shortest distance between all pairs of nodes.
 Once we have prepared the table of such distances all we need to do is iterate over all pairs of nodes and take the minimum of all distances between 
 the special nodes. Floyd-warshall algorithm is O(N3). This complexity is fine for this subtask.

Subtask 2
For this subtask N=105. Since, graph is connected, there are at least as many edges. Clearly, we can't apply the algorithm used in the first subtask 
since it will exceed time limit. The problem asks us the shortest distance between any two special nodes in the graph. This leads us to an observation. 
We only need to think about distances of nodes from the special nodes. In other words, we do not need the "all pairs shortest path" algorithms. 
We just need the shortest distance from the special nodes to all the nodes in the graph. For this subtask, the number of special nodes is less 
than or equal to 10. That is a fairly small number. All we have to do is run Dijkstra's algorithm from each of the special nodes. This will give us 
the shortest distance of each node from the special nodes. We can then find the shortest distance between any two special nodes. The complexity 
of dijkstra's algorithm is O(Nlog?N). Therefore, the complexity of this algorithm works out to be O(NKlog?N). This is sufficient for this subtask.

Subtask 3
In this subtask, the number of special nodes increases to 104. We can't get the previous algorithm to work under the given time limits.

Let us start by thinking of an algorithm to solve a simpler version of the given problem wherein all edges are of weight 1. Now we propose the
 formal algorithm for this problem and then prove its time complexity.

The formal algorithm is as follows:

We pick a random special node and perform a BFS from this point. We stop at the first level s which contains another special node.
We know that the minimum distance between any two special nodes can't be more than s. So we again take a special node at random which hasn't 
been taken before and perform a BFS again. If we don't find any special node in s distance, we terminate the search. If we do, then we update 
the value of s and repeat the procedure with some other special node taken at random.
It is pretty intuitive why this algorithm gives the correct answer. But why does it run within the given time limits? What is its time complexity?

In the first look the algorithm seems to have a complexity of O(NK). But in fact it is O(Nlog?N). Basically, we show that after each iteration 
of the BFS, the minimum distance to be searched before which another special node is found -- henceforth referred to as the radius of search -- 
becomes half. Let us see why.

After the first run of BFS from the randomly chosen special node, we can have two cases:

s=N2
s<N2
In the second case, we can clearly see that the search radius for the next BFS will be N2, i.e., half of the current one. This is because we
 will anyway terminate the search if we don't find a special node in that radius. But what happens in the second case?

If s=N2, this means that all the other special nodes apart from the one we started our BFS on must all be clustered within a radius of N-s. 
Since s=N2, this means that in the next BFS, we will definitely find a special within N2 radius of the one we start on.

Therefore, we see that in every iteration of BFS, we half our search radius of the graph. The algorithm therefore is O(Nlog?N).

We can now go back to our original problem. Since, our original problem involves edges of different weights, instead of performing BFS, 
we need to perform Dijkstra's algorithm. But how many times? Following the same reasoning as the simpler version of the problem, 
we get that Dijkstra will be performed O(log?Se) times, where Se is the sum of weights of all edges in the graph. 
This gives a total runtime of O(Nlog?Nlog?Se) which is sufficient for the given constraints.

Editorialist's program follows the editorial. Please see for implementation details.

OPTIMAL COMPLEXITY:
O(Nlog?Nlog?Se) where Se is the sum of weights of edges.*/
