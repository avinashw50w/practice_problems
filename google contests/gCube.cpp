/*
-----------------------------------------------------------------------------
Author :            ---------------------------------------------------------
    UTKAR$H $AXENA  ---------------------------------------------------------
    IIT INDORE      ---------------------------------------------------------
-----------------------------------------------------------------------------
*/
/*
Googlers are very interested in cubes, but they are bored with normal three-dimensional cubes and also want to think about other kinds of cubes! A "D-dimensional cube" 
has D dimensions, all of equal length. (D may be any positive integer; for example, a 1-dimensional cube is a line segment, and a 2-dimensional cube is a square, and a 
4-dimensional cube is a hypercube.) A "D-dimensional cuboid" has D dimensions, but they might not all have the same lengths.

Suppose we have an N-dimensional cuboid. The N dimensions are numbered in order (0, 1, 2, ..., N - 1), and each dimension has a certain length. We want to solve many 
subproblems of this type:

1. Take all consecutive dimensions between the Li-th dimension and Ri-th dimension, inclusive.

2. Use those dimensions to form a D-dimensional cuboid, where D = Ri - Li + 1. (For example, if Li = 3 and Ri = 6, we would form a 4-dimensional cuboid using the 3rd, 4th, 5th, 
and 6th dimensions of our N-dimensional cuboid.)

3. Reshape it into a D-dimensional cube that has exactly the same volume as that D-dimensional cuboid, and find the edge length of that cube.

Each test case will have M subproblems like this, all of which use the same original N-dimensional cuboid.

Input

The first line of the input gives the number of test cases, T. T test cases follow.

Each test case begins with two integers N and M; N is the number of dimensions and M is the number of queries. Then there is one line with N positive integers ai, 
which are the lengths of the dimensions, in order. Then, M lines follow. In the ith line, there are two integers Li and Ri, which give the range of dimensions to use 
for the ith subproblem.

Output

For each test case, output one line containing "Case #x:", where x is the test case number (starting from 1). After that, output M lines, where the ith line has the edge 
length for the ith subproblem. An edge length will be considered correct if it is within an absolute error of 10-6 of the correct answer. See the FAQ for an explanation 
of what that means, and what formats of real numbers we accept.

Limits

1 = T = 100.
1 = ai = 109. 
0 = Li = Ri < N.

Small dataset

1 = N = 10.
1 = M = 10.
Large dataset

1 = N = 1000.
1 = M = 100.

Input  
2
2 2
1 4
0 0
0 1
3 2
1 2 3
0 1
1 2

Output 
Case #1:
1.000000000
2.000000000
Case #2:
1.414213562
2.449489743
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fre 	freopen("0.in","r",stdin),freopen("0.out","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define MOD 1000000007
#define lld signed long long int
#define pp pop_back()
#define ps(x) push_back(x)
#define mpa make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
#define boost ios_base::sync_with_stdio(0)
//vector<int> g[2*100000+5];int par[2*100000+5];
double A[1000000+5];
int solve(){
	int N,M;
	cin>>N>>M;
	for(int i=1;i<=N;++i)
	{
		cin>>A[i];
		A[i] = log10(A[i]);
	}
	int L,R;
	while(M--){
		cin>>L>>R;
		L++;
		R++;
		double ans = 0;
		for(int i=L;i<=R;++i){
			ans += A[i];
		}
		ans /= (R-L+1);
		printf("%0.12f\n",pow(10,ans));
	}
}
int main()
{
	freopen("0.in","r",stdin);
	freopen("0.out","w",stdout);

	int T,test = 0;
	cin>>T;

	while(T--){
		test++;
		printf("Case #%d:\n",test);
		solve();
	}
}
