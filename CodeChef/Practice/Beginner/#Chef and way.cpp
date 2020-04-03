/* After visiting a childhood friend, Chef wants to get back to his home. 
Friend lives at the first street, and Chef himself lives at the N-th 
(and the last) street.Their city is a bit special: you can move from the X-th street 
to the Y-th street if and only if 1 <= Y - X <= K, where K is the integer value that is given to you. 
Chef wants to get to home in such a way that the product of all the visited streets' special numbers is minimal 
(including the first and the N-th street). Please, help him to find such a product.
Input

The first line of input consists of two integer numbers - N and K - the number of streets and the value of K respectively. 
The second line consist of N numbers - A1, A2, ..., AN respectively, where Ai equals to the special number of the i-th street.
Output

Please output the value of the minimal possible product, modulo 1000000007.
Constraints

1 = N = 10^5
1 = Ai = 10^5
1 = K = N
Example

Input:
4 2
1 2 3 4.

Output:
8
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>
#define ll long long int
#define gc getchar()
#define mod 1000000007
using namespace std;
inline ll input(){
	int n = 0;
	register int c = gc;
	while(c==' '||c=='\n') c=gc;
	while(c>='0' && c<='9') {
		n = (n<<3)+(n<<1)+c-48;
		c=gc;
	}
	return n;
}

int main(){
	int n = input();
	int k = input();
	int a[n+2];
	int trace[n+2];
	double f[n+2];
	deque<int> d;
	a[0] = input();
	d.push_back(0);
	f[0] = log(a[0]);
	trace[0] = -1;
	for(int i=1;i<n;i++){
		a[i]=input();
		while(!d.empty() && i-d.front() > k) d.pop_front();
		f[i] = f[d.front()] + log(a[i]);
		trace[i] = d.front();
		while(!d.empty() && f[i] <= f[d.back()]) d.pop_back();
		d.push_back(i);
	}

	int i = n-1;
	ll ans = 1;
	while(i>=0){
		ans *= (ll)a[i];
		ans %= mod;
		i = trace[i];
	}
	cout << ans%mod <<endl;
	return 0;
}
////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<math.h>
 
#define mod 1000000007
 struct node{
  double val;
  int pos;
 };
 
int main(){
 
  long long int i,j,ans,a[100005],k,n,m;
  int minim[100005];
 
  struct node pq[100005];
  scanf("%lld%lld",&n,&k);
  for(i=1;i<=n;i++)
    scanf("%lld",&a[i]);
  minim[1]=0;
  pq[1].val=log(a[1]);
  pq[1].pos=1;
  int start=1,end=1;
  for(i=2;i<=n;i++)
    {
      if(i-pq[start].pos>k) start++;
      minim[i]=pq[start].pos;
      double temp=log(a[i])+pq[start].val;
      while(temp<pq[end].val && end>=start) end--;
      
	  end++;
      pq[end].val=temp;
      pq[end].pos=i;
    }
  i=n;
  ans=1;
  while(i>0)
    {
      ans=(ans*a[i])%mod;
      i=minim[i];
    }
  printf("%lld\n",ans[n]%mod);
  return 0;
}
//////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#define ll long long int
#define gc getchar()
#define pii pair<double,int>
#define mp make_pair
#define mod 1000000007
using namespace std;
inline ll input(){
	int n = 0;
	register int c = gc;
	while(c==' '||c=='\n') c=gc;
	while(c>='0' && c<='9') {
		n = (n<<3)+(n<<1)+c-48;
		c=gc;
	}
	return n;
}
struct comp{
	bool operator()(const pii &a,const pii &b){
		return a.first<b.first;
	}
};
int main(){
	int n = input();
	int k = input();
	int a[n+2];
	int trace[n+2];
	a[0] = input();
	trace[0] = -1;
	priority_queue<pii,vector<pii>,comp> q;
	q.push(mp((double)log(a[0]),0));
	for(int i=1;i<n;i++){
		a[i]=input();
		while(!q.empty() && i-q.top().second>k) q.pop();
		trace[i] = q.top().second;
		double tmp = q.top().first + log(a[i]);
		q.push(mp(tmp,i));
	}

	int i = n-1;
	int ans = 1;
	while(i>=0){
		ans = ((ll)a[i]*ans)%mod;
		i = trace[i];
	}
	cout << ans%mod <<endl;
	return 0;
}

/* EXPLANATION
This can be modelled as a graph problem where each street a node and edged denoting the streets which can take as given in the problem. For N = 8 and K = 3 the 
following diagram depicts such a graph.



In the graph the weight of each edge is the weight of the node to which it is directing to. The first street is always takesn so we have to account for w[0] in all our answers. 
All you need to do is find the minimum cost path from the first node to the last node, where cost of the path is the product of all the weights of the edges on its path.

If the cost was just sum then we can find simply use Dijkstra's shortest path algorithm to do this. We can convert the product to sum by just using log values of the weights. 
Since log is a monotonically increasing function we have w1 > w2 iff lof(w1) > log(w2). So in the modified graph using the log values if find the path with minimum cost we can compute the products of actual weight modulo 1000000007 and output it as answer. The value of N can be at maximum of 10^5 so we can only solve subtask1 using this. We will now look at a simple solution which uses the properties of the graph.

Note that in the graph the edges only go forward so there are no chances of having a cycle in this graph. For a given node all the incoming edges have the same cost 
hence the minimum cost path to reach a node is just the minimum cost path value among all its predecessors (all nodes which have edges to this node) multiplied by the 
weight of current node.

subtask1: If we just have an array min[] of length n. min[i] will store the minimum value to reach node i. The answer will be min[n-1].

We will fill this array by traversing from left to right. Since we start on first street we set min[0] = w[0].

For an index i we look back K positions before (since these are the only possible predesecorrs) and find the index j which has the minimum value. Now we set min[i] = min[j]*w[i]

The problem with this approach is the values of products can quickly get beyond 64-bit integer range the maximum native integer support provided by most programming languages. 
If you are using languages like python or Java which have big integer support or have your own implementation of big integer you can directly code this. 
Refer editorialist's solution for a Java implementation.

You overcome this by simply using logvalues, min[i] will store the log of the min value and we will store another array ans where ans[i] will store the min value modulo 1000000007.

set min[0] = log(w[0]) and ans[0] = w[0] For an index i we look back K positions before and find the index j which has the minimum value. 
Now we set min[i] = min[j]+ log(w[i]) and ans[i] = (ans[j] * w[i]) % 1000000007

But this solution has a time complexity of O(NK) and hence can't be used to solve subtask2

subtask2: We can slightly modify the previous algorithm to solve this subtask. At an index i we need to find the minimum value stored in the previous K indices 
i.e. (i-K, i-1), at index i+1 we need the minimum in range (i-K+1, i), So going forward we we would never need the value at i-K. All we need to do is somehow 
maintain the minimum value in the sliding window of length K. We provide one way of doing this.

Have a Priority Queue of a Pair, the pair has two parameters logValue and index. We will define the priorityqueue ordering based on logvalue and use index for 
eviction of pairs from the priority queue.

set ans[0] = w[0] add <log(w
0
0
), 0=""> to the priority queue. While processing any index i we do the following. -let j be the index of the top item in the priority queue -while the value of (i-j) > K 
delete the top value in the priorityqueue and keep udating j -set ans[i] = (ans[j] * w[i]) % 1000000007 and add <pq.top().logvalue +="" math.log(a[i]),="" i=""> 
to the priority queue

This algorithm will always give the sliding minimum we needed and hence the right answer. Because of the deletions this also might look like a O(NK) algorithm. 
But if you look carefully there are exactly N items added to the priority queue hence at max N items be deleted, so giving an amortized cost of O(1) for the deletions.

You can use other techniques for computing this sliding minimum like using a segment tree since the the window is nothing but a range and we have to find range minimum. But this might be an overkill.*/
