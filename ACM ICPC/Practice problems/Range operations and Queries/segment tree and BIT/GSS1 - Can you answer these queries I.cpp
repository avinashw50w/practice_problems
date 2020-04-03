/*You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| <= 15007 , 1 <= N <= 50000 ). A query is defined as follows: 
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x <= i <= j <= y }. 
Given M queries, your program must output the results of these queries. */

#include <bits/stdc++.h>
using namespace std;
typedef long ll;
const int oo = (1<<30);
const int MAXN = 50505;
int n, q;

struct node {
	ll sum, prefix, suffix, best;
};

int A[MAXN];
node tree[3 * MAXN];
node emp;

node makeNode(ll sum, ll prefix, ll suffix, ll best){
	node res;
	res.sum = sum;
	res.prefix = prefix;
	res.suffix = suffix;
	res.best = best;
	return res;
}

node combineNode(node l, node r) {
	ll max_prefix = l.prefix;
	ll max_suffix = r.suffix;
	if(max_prefix < l.sum + r.prefix) max_prefix = l.sum + r.prefix;
	if(max_suffix < r.sum + l.suffix) max_suffix = r.sum + l.suffix;

	ll best = max(l.suffix + r.prefix, max(l.best, r.best));

	return makeNode(l.sum + r.sum, max_prefix, max_suffix, best);
}

void build(int i, int l, int r) {
	if(l == r) {
		tree[i] = makeNode(A[l], A[l], A[l], A[l]);
		return;
	}
	int m = (l+r)>>1;
	build(2*i, l, m);
	build(2*i+1, m+1, r);
	tree[i] = combineNode(tree[2*i], tree[2*i+1]);
}

node query(int i, int l, int r, int ql, int qr) {
	emp.sum = emp.prefix = emp.suffix = emp.best = -oo;
	if(r < ql or l > qr) return emp;
	if(ql <= l and r <= qr) {
		return tree[i];
	}
	int m = (l+r)>>1;
	if(qr < m) return query(2*i, l, m, ql, qr);
	else if(ql > m) return query(2*i+1, m+1, r, ql, qr);
	node a = query(2*i, l, m, ql, qr);
	node b = query(2*i+1, m+1, r, ql, qr);
	return combineNode(a, b);
}


int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		scanf("%d",&A[i]);
	}
	build(1, 1, n);
	scanf("%d",&q);
	while(q--){
		int x, y;
		scanf("%d%d",&x,&y);
		node ans = query(1, 1, n, x, y);
		printf("%ld\n", ans.best);
	}
	
	return 0;
}
