/*King Xerxes has huge Persian army of 'N' soldiers.They are standing in straight line and each ith soldiers has power Pi . King Xerxes knows 
that collaboration between adjacent soldiers is more,So Xerxes want to send longest continuous chain of his soldiers among 'N' soldiers such 
that their power is strictly increasing.As King Xerxes knows black magic,He can increase or decrease the power of ith soldier.You are the 
advisor of King Xerxes,He asked you to tell the length of longest continuous increasing chain of soldiers of current army.

At any time, King Xerxes will do two operations :

1 x y : Increase the power of xth soldier by 'y' - (if negative, it means decrease.)

0 x y : Ask you the length of longest continuous increasing chain of soldiers in range [x , y] inclusive

Input :

First Line contains an integer indicating number of test cases 't'
For each case,there are two integers separated by a space in a line 'N' , 'Q' indicating number of soldiers in Persian army and number of 
queries.
Next Line contains 'N' space separated integers Pi indicating power of ith soldier.
Next 'Q' lines contains three integers 'T' , 'x' and 'y' where T can be 0 or 1 indicating type of query.

Output :

For Each query of type 0,Print the answer as asked in the problem.

Constraints :

1 <= t <= 10 
1 <= N,Q <= 105 
1 <= Pi <= 109 
For type 1 query: 1 <= x <= N , |y| <= 109 
For type 0 query: 1 <= x <= y <= N 

SAMPLE INPUT 
1
5 6
5 1 2 3 2 
0 1 5
1 5 4
0 1 5
0 3 5
1 3 10
0 3 5
SAMPLE OUTPUT 
3
4
3
2
*/

/* basically the problem is to find the longest increasing subsequence for any range asked in the query
we can also change the value of the element in the array */

#include <bits/stdc++.h>
using namespace std;

typedef long ll;
const int MAXN = 1e5+5;
int N, Q;
int A[MAXN];

namespace SegmentTree {
	struct node{
		ll ans, prefix, suffix, range, Lval, Rval;

		void init() { ans = prefix = suffix = Lval = Rval = range = 0; }

		node() { init(); }
	};

	node tree[4 * MAXN];
	node emp;

	node CombineNode(node left, node right) {
		node res;
		res.ans = max(left.ans, right.ans);
		
		if(left.Rval < right.Lval)
			res.ans = max(res.ans, left.suffix + right.prefix);
		
		res.range = left.range + right.range;
		res.Lval = left.Lval; 
		res.Rval = right.Rval;

		if(left.prefix == left.range) {
			if(left.Rval < right.Lval)
				res.prefix = left.range + right.prefix;
			else 
				res.prefix = left.range;
		}
		else res.prefix = left.prefix;
		
		if(right.suffix == right.range) {
			if(left.Rval < right.Lval)
				res.suffix = right.range + left.suffix;
			else 
				res.suffix = right.range;
		}
		else res.suffix = right.suffix;

		return res;
	}

	node make_node(int idx, int val) {
		node res;
		res.range = 1;
		res.ans = res.prefix = res.suffix = 1;
		res.Lval = res.Rval = val;
		return res;
	}

	void build(int i, int l, int r) {
		if(l == r) {
			tree[i] = make_node(l, A[l]);
			return;
		}

		int mid = (l+r)>>1;
		
		build(2*i, l, mid);
		build(2*i+1, mid+1, r);
		tree[i] = CombineNode(tree[2*i], tree[2*i+1]);
	}

	void update(int i, int l, int r, int idx, int val) {
		if(l == r) {
			tree[i].Lval += val;
			tree[i].Rval += val;
			return;
		}

		int mid = (l+r)>>1;
		if(idx <= mid)
			update(2*i, l, mid, idx, val);
		else 
			update(2*i+1, mid+1, r, idx, val);

		tree[i] = CombineNode(tree[2*i], tree[2*i+1]);
	}
	
	node query(int i, int l, int r, int ql, int qr) {
		if(r < ql or qr < l) return emp;

		if(ql <= l and r <= qr) return tree[i];

		int mid = (l+r)>>1;

		node a = query(2*i, l, mid, ql, qr);
		node b = query(2*i+1, mid+1, r, ql, qr);
		return CombineNode(a, b);
	}
}

using namespace SegmentTree;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t, type, x, y;
	cin>>t;
	while(t--) {
		cin >> N >> Q;
		for(int i=1;i<=N;++i) cin >> A[i];

		build(1, 1, N);

		while(Q--) {
			cin >> type >> x >> y;
			if(type == 0) {
				node ret = query(1, 1, N, x, y);
				cout << ret.ans << endl;
			}
			else {
				A[x] += y;
				update(1,1, N, x, y);
			}
		}
	}
	return 0;
}

/*Problem: Report longest increasing substring of a subarray A[L..R]. (Range Queries and Point Updates)

Lets maintain a segment tree. tree[i] (with responsibility from si to sj)
tree[i] has three attributes: Prefix, *Suffix** and Ans*.

Prefix = length of longest increasing substring in subarray A[si..sj] that starts at si.
Suffix = length of longest increasing substring in subarray A[si..sj] that ends at sj.
Ans = length of longest increasing substring in subarray A[si..sj].
A common hurdle: How do we think that these attributes will be required

The Ans attribute is quite obvious. Think from here is this Ans attribute enough. How to check that ? Simple, just come with up with a strategy
 that can calculate tree[i] for all i. If you are able to do so then the attribute is enough. Otherwise include those attribute which you think 
 are lacking.

Lets try to think a strategy with only Ans attribute. Always construct the segment tree using divide and conquer thinking. Think that I want 
to compute tree[i] assuming I have successfully computed its children tree[2i] and tree[2i+1]. That is assume we have all required attributes 
for ranges A[si..mid] and A[mid+1..sj]. How should I get respective for A[si..sj]. After this point everything depends upon the attribute you 
want to calculate. Like here we want to calculate Ans for [si..sj]. The longest increasing substring can come from A[si..mid] or A[mid+1..sj].
So tree[i].Ans = max( tree[2i].Ans, tree[2i+1].Ans). But is it enough? We are missing a case where an even longer substring can come with 
some part in left child [si..mid] and some part in [mid+1..sj] iff A[mid] ≤ A[mid+1]

We realize that Ans attribute is not enough to compute the tree. Now analyse what type of extra information we want to calculate this Ans. 
We notice that the part of the missed substring that lies in [si..mid] is a suffix of left child. Similarly the part of it in right child is 
prefix of right child. Here we decide to include two more attributes mentioned previously. Now the additional case that we were missing can 
be covered here
tree[i].Ans = max( tree[i].Ans, tree[2i].Suffix + tree[2i+1].Prefix)

Remember as we have included Prefix and Suffix attributes, we need to also compute the same for tree[i]. In general cases if calculation of 
additional attributes is not possible, we might want to add further attributes and do the same process. But here you will see that we don't 
require any more attributes. As prefix of [si..sj] is prefix of [si..mid] OR [si..mid]+prefix of [mid+1..sj]
Therefore tree[i].Prefix = tree[2i].Prefix OR (mid-si+1 + tree[2i+1].Prefix). 
Note: Second part is valid iff [si..mid] is increasing and A[mid] ≤A[mid+1] . Increasing part can be checked by condition tree[2*i].
Ans==(mid-si+1).

Similar thing holds same for computation of Suffix.

Thus these three attributes are sufficient to compute the Segment tree. Each update changes atmost O(log N) nodes and each query can be 
answered by merging of O(log N) intervals. Overall Time Complexity = O(N + Qlog N)*/

