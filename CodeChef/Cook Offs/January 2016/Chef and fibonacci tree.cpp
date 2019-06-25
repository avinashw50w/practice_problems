/* Chef likes to play with trees a lot. This time, he has a rooted tree T consisting of N nodes labelled uniquely with the integers 
from {1, … N}. The node labelled 1 is the root of the tree. Each node in the given tree T stores a non-negative integer, initially all of which are zeros. Chef wants to perform 2 types of operations over the tree accurately and efficiently.
U X K: Update the subtree rooted at node X such that the the root X will have FK (the Kth Fibonacci number) added to it, all its children will have Fk+1 (the (K+1)th Fibonacci number) added to them, and so on. More formally, any node in the subtree rooted at X will have (K+D)th fibonacci number added to them, where D is the distance of the node from X.
Q X: Report the value stored at the node X.
Since the answer to each query can be very large, output it modulo 109 + 7.
NOTE:
FK denotes the Kth Fibonacci number, and the series is generated as follows:
FK = 1, if K ≤ 2 .
FK = FK-1 + FK-2, otherwise.
To know more about Fibonacci numbers, click here.
Input:

First line of input contains two integer N and M denoting the number of nodes in the tree T, and the number of queries to be processed, respectively. Next N-1 lines of input contain an integer each, where the integer in the ith line denotes the parent of the (i+1)th node. 
Each of the next M lines contains one of the 2 types of queries mentioned above.
Output:

For each operation of type Q, output the required answer modulo 109 + 7.
Constraints:

1 ≤ N, M, K ≤ 105
1 ≤ U, V, X ≤ N

EXPLANATION:
There are are two approaches to this question. In this editorial, we discuss the one is based on caching of update operations. The other one can be found in setter's solution.

Caching of updates/queries is a very powerful technique. It works on two principles:

We break the updates down into N−−√N blocks, where NN is the number of nodes in the tree.
After processing one block of N−−√N updates, we should be able to remake the data structure we are maintaining (graph or tree or anything other way of representing data) quickly. Quickly normally means linear or quasi-linear time.
For the queries that need to be answered, we should be able to quickly calculate the answer for them inclusive of the updates that are in the current block. We should be able to iterate over the updates and find the answer quickly, preferably in constant time or so.
Let's see how we can get these 3 factors to work in this problem. We will maintain a buffer vector called updatesupdates which stores at most N−−√N pairs of the form (x,k)(x,k) which tells us that UU xx kk operation had been called. Once the buffer becomes N−−√N long we remake the entire tree structure.

We begin by having an array fib[i]fib[i] which holds the ithith fibonacci. This array should be at least 2∗1052∗105 in length since KK can at max be 105105. We maintain an array val[i]val[i] which holds the value of node ii inclusive of the updates just before the ones currently in the buffer. To answer a particular query QQ xx at any given point in time, we first take ans=val[x]ans=val[x]; then we iterate over the updates in the buffer to see which updates affect xx. If some update does, we add the appropriate fibonacci number as per the specification in the update to our answer variable ansans. Then we simply output ansans.

The part that is left in this algorithm is to describe how to know whether a particular update in the buffer affects a query node or not, if it does then what fibonacci number is to be added, and how to remake the valval array quickly.

We start with the first two things, i.e., checking whether an update in the buffer affects the query node or not and what fibonacci number to add if it does. For this, we need to quickly determine whether a node lies within the subtree of another node or not. There is a very standard technique to do this: in-out linearisation of the tree. While doing a DFS of the tree, we can map the subtree of a node to a specific range in the array. If the range of a node xx lies within the range of another node yy then xx lies in the subtree of yy. Thus, if we prebuild this structure for the tree, then we can determine in constant time which updates in the buffer affect the query node. For an update that affects the query node, how can we know which fibonacci number to be added. We can do this by keeping another array depth[i]depth[i] which gives the depth of the ithith node (depth of root is 0). Now, if an update UU x1x1 kk affects a query node x2x2, then the fibonacci number to be added to the query answer is fib[k+depth[x2]−depth[x1]]fib[k+depth[x2]−depth[x1]].

We have everything in place now. All we need to do is find a way to rebuild the tree after the buffer reaches length N−−√N. The rebuildrebuild routine will be very similar to a DFS function. We just have to work a way out to propagate an update at a node down to its subtree. Fibonacci numbers have a very interesting recurrence. Let's have an array node_updatenode_update. In this array, node_update[v]node_update[v] is a list kk's from all those updates that exist in the buffer that were for node vv (i.e., updates of the form UU vv kk). Let's say we have pp, qq stored at a particular node vv. This means we have to add fib[p]+fib[q]fib[p]+fib[q] to val[v]val[v]. For the children of vv, we need to add ((fib[p−1]+fib[p])+(fib[q−1]+fib[q]))((fib[p−1]+fib[p])+(fib[q−1]+fib[q])).
Analogously, for the grand-children, we need to add ((fib[p]+fib[p+1])+(fib[q]+fib[q+1]))((fib[p]+fib[p+1])+(fib[q]+fib[q+1])).
This leads us to an important observation:

((fib[p−1]+fib[p])+(fib[q−1]+fib[q]))((fib[p−1]+fib[p])+(fib[q−1]+fib[q])) = ((fib[p]+fib[p])+(fib[p−1]+fib[q−1]))((fib[p]+fib[p])+(fib[p−1]+fib[q−1]))
((fib[p]+fib[p+1])+(fib[q]+fib[q+1]))((fib[p]+fib[p+1])+(fib[q]+fib[q+1])) = ((fib[p+1]+fib[q+1])+(fib[p]+fib[q]))((fib[p+1]+fib[q+1])+(fib[p]+fib[q]))

Essentially, all we need to pass on to the children of vv is the sum of fibonacci numbers at vv and the sum of fibonacci numbers which are one before the fibonacci numbers at vv. This gives us the way to rebuild the valval array. Here is the pseudocode:

//v is the node we are currently at in the recursion
//current is the value that needs to be added here
//prev is the value that was added to the parent of this node
rebuild(v, current, prev)
{
    //this value stores the sum of fibonacci numbers which
    //are one before the fibonacci numbers at v
    upd = 0;

    for(i = 0 to node_update[v].size()-1)
    {
        //adding update values at this node to current
        current += fib[node_update[v][i]];
        upd += fib[node_update[v][i]-1];
    }

    //adding current to val[v]
    val[v] += current;

    //preparing new_current and new_prev
    new_current = current + upd + prev;
    new_prev = current

    for(c = children of v)
    {
        //recursively building children
        rebuild(c, new_current, new_prev);
    }

    //now that val[v] has been updated, clear the
    //backlog for next block of updates.
    node_update[v].clear();
}
The rebuildrebuild function is just a modified DFS; it is O(N)O(N). It is called as rebuild(1,0,0)rebuild(1,0,0). 
Since, this is done at most N−−√N times, the complexity of this is O(NN−−√)O(NN). Each query can be answered in O(N−−√)O(N) 
since it only requires constant number of operations per update operation stored in the buffer (which at max has N−−√N updates).
 Thus, net complexity is O(NN−−√)O(NN).*/
#include <algorithm>
#include <iostream>
#include <cassert>
#include <map>
#include <vector>
#include <cstdio>
 
#define NMAX 100010
 
using namespace std;
 
int bit0[NMAX];
int bit1[NMAX];
 
 
int lev[NMAX];
int st[NMAX];
int en[NMAX];
 
int fib[NMAX+10];
 
vector<int> child[NMAX];
 
 
int N;
 
const int mod = (1e9)+7;
 
inline int add(int a, int b){
	return (a+b)%mod;
}
 
void upd(int x, int val, int *tree){
	for(;x < N; x+=(x&-x)){
		tree[x] = add(tree[x],val);
		if(!x) break;
	}
}
 
void range_upd(int i, int j, int val, int *tree){
	upd(i,val,tree);
	upd(j+1,-val,tree);
}
 
int read(int x, int *tree){
	int val;
	val = 0;
 
	for(;x >= 0; x-=(x&-x)){
		val = add(val,tree[x]);
		if(!x) break;
	}
 
	return val;
}
 
 
 
inline int get_fib(int k){
	if(k >= 0) return fib[k];
	k *=-1;
	return fib[k]*((k&1) ? 1 : -1);
}
 
void update(int v, int k){
	int f1 = get_fib(k-lev[v]);
	int f0 = get_fib(k-lev[v]-1);
 
	range_upd(st[v],en[v],f0,bit0);
	range_upd(st[v],en[v],f1,bit1);
}
 
int query(int x){
	int v1,v0;
	v0 = (1LL*read(st[x],bit0)*get_fib(lev[x]))%mod;
	v1 = (1LL*read(st[x],bit1)*get_fib(lev[x]+1))%mod;
	return (add(v0,v1)+mod)%mod;
}
 
int tim;
 
void dfs(int v, int l){
	lev[v] = l;
	st[v] = tim++;
 
 
	int i,u;
 
	for(i = 0; i <child[v].size(); ++i){
		u = child[v][i];
		dfs(u,l+1);
	}
 
	en[v] = tim-1;
}
 
int M;
 
void init(){
	int i;
	fib[0]= 0;
	fib[1] = 1;
 
	for(i = 2; i <= 1e5 + 10; ++i){
		fib[i] = add(fib[i-1],fib[i-2]);
	}
	dfs(0,0);
}
 
int main(){
	int i,v,k;
	char c;
	scanf("%d%d",&N,&M);
 
	for(i = 1; i < N; ++i){
		scanf("%d",&v);
		--v;
		child[v].push_back(i);
	}
 
	init();
 
	while(M--){
		scanf(" %c%d",&c,&v);
		--v;
		if(c == 'U'){
			scanf("%d",&k);
			update(v,k);
			continue;
		}
 
		printf("%d\n",query(v));
	}
 
	return 0;
}

// another implementation

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)
 
using namespace std;
 
#define MAXN 111111
vector<int> graph[MAXN];
int N;
 
int Left[MAXN], Right[MAXN], Depth[MAXN], O = 0;
 
void dfs(int v) {
  Left[v] = O++;
  REP(i, graph[v].size()) {
    Depth[graph[v][i]] = Depth[v] + 1;
    dfs(graph[v][i]);
  }
  Right[v] = O;
}
 
#define MOD 1000000007
int F[3 * MAXN];
 
int f1[MAXN], f2[MAXN];
void add(int x, int val1, int val2) {
  x++;
  while (x < MAXN) {
    f1[x] = (f1[x] + val1) % MOD;
    f2[x] = (f2[x] + val2) % MOD;
    x += x & -x;
  }
}
 
pair<int, int> get(int x) {
  int val1 = 0, val2 = 0;
  x++;
  while (x) {
    val1 = (val1 + f1[x]) % MOD;
    val2 = (val2 + f2[x]) % MOD;
    // printf("getting: %d val1: %d val2: %d\n", x, f1[x], f2[x]);
    x -= x & -x;
  }
  return make_pair(val1, val2);
}
 
int main(int argc, char *argv[]) {
  int Q;
  scanf("%d%d", &N, &Q);
  REP(i, N - 1) {
    int parent;
    scanf("%d", &parent);
    graph[parent - 1].push_back(i + 1);
  }
  dfs(0);
 
  F[MAXN] = F[MAXN + 1] = 1;
  FOR(i, MAXN + 2, 3 * MAXN - 1) F[i] = (F[i - 1] + F[i - 2]) % MOD;
  FORD(i, MAXN - 1, 0) F[i] = (F[i + 2] - F[i + 1]) % MOD;
 
  while (Q--) {
    char cmd[5];
    scanf("%s", cmd);
    if (cmd[0] == 'U') {
      int v, k;
      scanf("%d%d", &v, &k);
      v--; k--;
  
      add(Left[v], F[k - Depth[v] + MAXN], F[k - Depth[v] + 1 + MAXN]);
      add(Right[v], -F[k - Depth[v] + MAXN], -F[k - Depth[v] + 1 + MAXN]);
    }
    else {
      int v;
      scanf("%d", &v);
      v--;
      pair<int, int> ans = get(Left[v]);
      int a = (
        (long long)ans.first * F[Depth[v] + MAXN - 2] +
        (long long)ans.second * F[Depth[v] + MAXN - 1]
      ) % MOD;
      if (a < 0) a += MOD;
      printf("%d\n", a);
    }
  }
  return 0;
}