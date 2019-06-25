/*The fight for the best number in the globe is going to finally come to an end.The top two contenders for the best number are number 2 and 
number 3.It's the final the entire world was waiting for. Expectorates from all across the globe came to witness the breath taking finals.

The finals began in an astonishing way.A common problem was set for both of them which included both these number.The problem goes like this.

Given a binary string (that is a string consisting of only 0 and 1). They were supposed to perform two types of query on the string.

Type 0: Given two indices l and r.Print the value of the binary string from l to r modulo 3.

Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.

The problem proved to be a really tough one for both of them.Hours passed by but neither of them could solve the problem.So both of them wants 
you to solve this problem and then you get the right to choose the best number in the globe.

Input:

The first line contains N denoting the length of the binary string .The second line contains the N length binary string.Third line contains 
the integer Q indicating the number of queries to perform.This is followed up by Q lines where each line contains a query.

Output:

For each query of Type 0 print the value modulo 3.

Constraints:

1<= N <=10^5

1<= Q <= 10^5

0 <= l <= r < N

SAMPLE INPUT 
5
10010
6
0 2 4
0 2 3
1 1
0 0 4
1 1
0 0 3
SAMPLE OUTPUT 
2
1
2
1
Explanation
Query 1 : This is of type 0. The binary string is 010 which is equal to 2 and 2%3=2. So answer is 2.

Query 2 : This is of type 0. The binary string is 01 which is equal to 1 ( (2^1) * 0 +(2^0) * 1 ) =0 + 1 =1) and 1%3=1. So answer is 1.

Query 3 : This is of type 1. The value at index 1 is 0 so we flip it .The new string is 11010.

Query 4 : This is of type 0. The binary string is 11010 ( (2^0) * 0 +(2^1) * 1 +(2^2) * 0 +(2^3) * 1 +(2^4) * 1 = 2 + 8 +16 =26 ) which is 
equal to 26 and 26%3=2. So answer is 2.*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAXN = 1e5 + 5;
const int M = 3;

ll N, Q;
ll tree[3*MAXN], A[MAXN], two[MAXN];

void prec() {
	two[0] = 1;
	for(int i=1;i<MAXN;++i) two[i] = (2 * two[i-1]) % M;
}

void build(int node, int l, int r) {
	if(l == r) {
		tree[node] = A[l];
		return;
	}
	int mid = (l+r)>>1;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    tree[node] = ((tree[2*node] * two[r-mid]) + tree[2*node+1]) % M;
}

void update(int node, int l, int r, int idx) {
	if(l == r) {
		A[idx] = 1;
		tree[node] = 1;
		return;
	}
	int mid = (l+r)>>1;
	if(idx <= mid)
		update(2*node, l, mid, idx);
	else
		update(2*node+1, mid+1, r, idx);
	tree[node] = ((tree[2*node] * two[r-mid]) % M + tree[2*node+1]) % M;
}

ll query(int node, int l, int r, int ql, int qr) {
	if(ql > r || qr < l) return 0;

	if(ql <= l && r <= qr) 
		return (tree[node] * two[qr-r]) % M;

	int mid = (l+r)>>1;
	ll a = query(2*node, l, mid, ql, qr);
	ll b = query(2*node+1, mid+1, r, ql, qr);
	return (a + b) % M;
}

int main() {
	int type, l, r;
	char c;
	cin >> N;
	for(int i=1; i<=N; ++i) {
		cin >> c;
		A[i] = c - '0';
	}
	
	prec();

	build(1, 1, N);

	cin >> Q;
	while(Q--) {
		cin >> type;
		if(type == 0) {
			cin >> l >> r; 
			l++; r++;
			cout << query(1, 1, N, l, r) << endl;
		}
		else if(type == 1) {
			cin >> l;
			l++;
			if(A[l] == 0) {
				A[l] = 1;
				update(1, 1, N, l);
			}
		}
	}
	return 0;
}