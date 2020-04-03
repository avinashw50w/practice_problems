/*You have an array containing n elements initially all 0. You need to do a number of update operations on it. In each update you specify l, r 
and val which are the starting index, ending index and value to be added. After each update, you add the 'val' to all elements from index l to r.
After 'u' updates are over, there will be q queries each containing an index for which you have to print the element at that index.

Input

First line consists of t, the number of test cases. (1<=t<=10)

Each test case consists of "n u",number of elements in the array and the number of update operations, in the first line 
(1<=n<=10000 and 1<=u<=100000)

Then follow u lines each of the format "l r val" (0<=l,r<n 0<=val<=10000)

Next line contains q, the number of queries. (1<=q<=10000)

Next q lines contain an index (0<=index<n)

Output

For each test case, output the answers to the corresponding queries in separate lines.*/

ll tree[2* MAXN];
int n;

void update(int l, int r, int val) {
	for(l+=n, r+=n+1; l<r; l>>=1, r>>=1) {
		if(l&1) tree[l++] += val;
		if(r&1) tree[--r] += val;
	}
}

void push() {
	for(int i=1; i<n; ++i){
		tree[i<<1] += tree[i];
		tree[(i<<1)|1] += tree[i];
		tree[i] = 0;
	}
}

int main() {
	int t; si(t);
	while(t--) {
		int u, l, r, val, q, idx;
		si(n); si(u);

		memset(tree, 0, sizeof tree);
		rep(i,0,u){
			si(l); si(r); si(val);
			update(l,r,val);
		}

		push();

		si(q);
		while(q--){
			si(idx);
			printf("%lld\n", tree[idx+n]);
		}
	}
	return 0;
}
