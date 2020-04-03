/*/*Chef's love for Fibonacci numbers helps him to design following interesting problem.

He defines a function F for an array S as follows:

F = (summation of(fibonacci(sum(Si))) ) % 1000000007

where

Si denotes a non-empty subset of multiset S.
sum(Si) denotes the sum of all element of multiset Si.
Fibonacci(x) denotes the xth Fibonacci number.
Given an array A consisting of N elements. Chef asked you to process following two types of queries on this array accurately and efficiently.

C X Y: Change the value of Xth element of array to Y i.e AX = Y.
Q L R: Compute function F over the subarray defined by the elements of array A in the range L to R, both inclusive.
Please see the Note section if you need details regarding Fibonacci function.

Input

First line of input contains 2 space separated integer N and M denoting the size of array A and the number of queries to be performed. 
Next line of input contains N space separated integers denoting the elements of array A. Each of next M lines of input contains a query having one of the mentioned two types.

Output

For each query of type Q, output the value of function F for the given range of array A.

Constraints

1 ≤ N, M ≤ 105
1 ≤ Ai, Y ≤ 109
1 ≤ L, R, X ≤ N
type = {'C', 'Q'}

Alternate approach :
Build a segment tree where we store a 2x2 transition matrix in each node . ( Transition matrix m is [1,1],[1,0] and fib(n) = T^n ) . 
Let matrix for parent and its two child nodes be X,A,B respectively . We can easily see that X = A+B+A*B .
this is because, let the leaf nodes are 1 and 2, so its parent should contain F(1,2) = fib(1) + fib(2) + fib(1+2) = m^1 + m^2 + m^(1+2)
, here note that m^(1+2) = m^1 * m^2. 
To get the final answer just multiply the matrix by the base case matrix ([0,1]) .*/

#include <bits/stdc++.h>
using namespace std;

typedef uint64_t ll;
typedef vector< vector<ll> > vvi;
ll mod = 1000000007;
const int MAXN = 1e5 + 5;

struct Matrix {
	ll mat[2][2];
	Matrix() {
		mat[0][0] = mat[1][1] = 1;
		mat[0][1] = mat[1][0] = 0;
	}

	void init() {
		mat[0][0] = mat[0][1] = 0;
		mat[1][0] = mat[1][1] = 0;
	}

	void fibMat() {
		mat[0][0] = mat[0][1] = mat[1][0] = 1;
		mat[1][1] = 0;
	}

	Matrix operator+(const Matrix &a) const {
		Matrix res;
		for(int i=0;i<2;++i){
			for(int j=0;j<2;++j){
				res.mat[i][j] = this->mat[i][j] + a.mat[i][j];
				res.mat[i][j] %= mod;
			}
		}
		return res;
	}
};

Matrix multiply(Matrix a, Matrix b) {
	Matrix res;
	for(int i=0; i<2; ++i) {
		for(int j=0; j<2; ++j) {
			res.mat[i][j] = 0LL;
			for(int k=0; k<2; ++k)
				res.mat[i][j] += a.mat[i][k] * b.mat[k][j];
			res.mat[i][j] %= mod;
		}
	}
	return res;
}

Matrix power(Matrix a, int n) {
	Matrix res;
	if(n == 0) return res;
	while(n) {
		if(n&1) res = multiply(res, a);
		a = multiply(a, a);
		n >>= 1;
	}
	return res;
}

Matrix *tree = new Matrix[2*MAXN];
int N, Q;

void build() {
	for(int i = N-1; i > 0; --i) 
		tree[i] = (tree[i<<1] + tree[(i<<1)|1] + multiply(tree[i<<1], tree[(i<<1)|1]));
}

void modify(int i, int val) {
	Matrix F;
	F.fibMat();
	for(tree[i+=N] = power(F, val); i > 1; i >>= 1) 
		tree[i>>1] = (tree[i] + tree[i^1] + multiply(tree[i], tree[i^1]));
}

Matrix query(int l, int r) {
	Matrix ret; 
	ret.init();
	for(l += N, r += N+1; l<r; l>>=1, r>>=1) {
		if(l&1) {
			ret = ret + tree[l] + multiply(ret, tree[l]);
			l++;
		}
		if(r&1) {
			r--;
			ret = ret + tree[r] + multiply(ret, tree[r]);
		}
	}
	return ret;
}

int main() {
	cin >> N >> Q;
	Matrix F;
	F.fibMat(); 
	int a;
	for(int i=0; i<N; ++i) {
		cin >> a;
		tree[i+N] = power(F, a);
	}
	
	build();
	
	while(Q--) {
		char type;
		int x, y;
		cin >> type;
		if(type == 'C') {
			cin >> x >> y;
			modify(x-1, y);
		}
		else {
			int l, r;
			cin >> l >> r;
			Matrix ans = query(l-1, r-1);
			cout << ans.mat[0][1] << endl;
		}
	}
	return 0;
}
