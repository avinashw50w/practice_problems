/*There are N coins kept on the table, numbered from 0 to N - 1. Initially, each coin is kept tails up. 
You have to perform two types of operations :

1) Flip all coins numbered between A and B inclusive. This is represented by the command "0 A B"

2) Answer how many coins numbered between A and B inclusive are heads up. This is represented by the command "1 A B".

Input :

The first line contains two integers, N and Q. Each of the next Q lines are either of the form "0 A B" or "1 A B" as mentioned above.

Output :

Output 1 line for each of the queries of the form "1 A B" containing the required answer for the corresponding query.

Sample Input :
4 7
1 0 3
0 1 2
1 0 1
1 0 0
0 0 3
1 0 3 
1 3 3

Sample Output :
0
1
0
2
1

Constraints :
1 <= N <= 100000
1 <= Q <= 100000
0 <= A <= B <= N - 1  */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400004;

int tree[MAXN], lazy[MAXN];

void push(int l, int r, int node) {
	if(lazy[node]) {
		if(l != r) {
			lazy[node<<1] ^= 1;   	// changing the parity of the children of the node (a lazy node with value 1 indicates that the node needs to be updated)
			lazy[(node<<1)|1] ^= 1;
		}
		lazy[node] = 0;
		tree[node] = (r-l+1) - tree[node]; // after flipping, no of new heads = total coins in curr node - no of old heads
	}
}

void update(int node, int l, int r, int a, int b) {
	push(l,r,node);

	if(l>r || b<l || r<a) return;

	if(a<=l && r<=b) {
		lazy[node] = 1;
		push(l,r,node);
		return;
	}
	int left = node<<1;
	int right = left|1;
	int mid = (l+r)>>1;

	update(left, l, mid, a, b);
	update(right, mid+1, r, a, b);

	tree[node] = tree[left] + tree[right];
}

int query(int node, int l, int r, int a, int b) {
	push(l, r, node);

	if(b<l || r<a) return 0;

	if(a<=l && r<=b) return tree[node];

	int left = node<<1;
	int right = left|1;
	int mid = (l+r)>>1;

	int x = query(left, l, mid, a, b);
	int y = query(right, mid+1, r, a, b);

	return x+y;
}



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q, t, a, b; 
	cin>>n>>q;
	while(q--) { 
		cin>>t>>a>>b; 
		if(t==0) 
			update(1, 0, n-1, a, b); 
		else if(t==1) 
			cout<< query(1, 0, n-1, a, b) << "\n"; 
	}
	return 0;
}
