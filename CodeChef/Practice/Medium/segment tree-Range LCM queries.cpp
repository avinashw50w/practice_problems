/*Given an array of integers, evaluate queries of the form LCM(l, r). There might be many queries, hence evaluate the queries efficiently.

LCM (l, r) denotes the LCM of array elements
           that lie between the index l and r
           (inclusive of both indices) 

Mathematically, 
LCM(l, r) = LCM(arr[l],  arr[l+1] , ......... ,
                                  arr[r-1], arr[r])  */
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)

const int mod = 1000000007;
const int MAXN = 100000+9;

int tree[4 * MAXN], A[MAXN];

int lcm(int a, int b) { return a*b/__gcd(a,b); }

void build(int node, int l, int r) {
	if(l == r) {
		tree[node] = A[l];
		return;
	}
	int mid = (l+r)>>1;
	int left = node<<1;
	int right = left|1; 
	build(left, l, mid);
	build(right, mid+1, r);

	tree[node] = lcm(tree[left], tree[right]);
}

void query(int node, int l, int r, int a, int b) {

	if(l>r || b<l || r<a) return 1;

	if(a<=l && r<=b) return tree[node];

	int mid = (l+r)>>1;
	int left = node<<1;
	int right = left|1;

	int x = query(left, l, mid, a, b);
	int y = query(right, mid+1, r, a, b);

	return lcm(x, y);
}

int main() {


	return 0;
}
