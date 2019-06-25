/* Anup recently visited Amrithapuri for ACM ICPC regional contest. A student walked up to Anup, gave him a paper which had a long programming 
question on it and asked him to solve it by 18th of January, 2015. As Anup was busy with school kids, he posted the question as cook off 
question, asking wider community to solve that question. Following is the question:
function f(A[0..N-1], L, R, P):
	if L > R:
		return f(A, R, L, P)
	ANSWER = 0
	C[] = A[L..R]
	for each subset S of C:
		G = GCD(S)
		for each prime factor PF of G:
			if PF == P:
				ANSWER = MAX(ANSWER, SIZE(S))
	return ANSWER

Clarifications:
Line 5 loops over all 2^(R-L+1) subsets.
GCD(S) returns the Greatest common divisor of all the elements in S.
SIZE(S) returns the number of elements in S.

Given: N, M, A[0..N-1], B[0..M-1]
Required: 

Where L = (B[i] + B[j]) % N
R = (B[i] - B[j] + N) % N
As the answer can be large. Output it modulo 1000000007.
Input

First line has two integer N and M. Second line has N space separated integers representing the array A. Third line has M space separated 
integers representing the array B.
Output

Output single integer which is the required answer modulo 1000000007
Constraints

1 ≤ N ≤ 100000
1 ≤ M ≤ 500
1 ≤ A[i] ≤ 100000
0 ≤ B[i] < N
Example

Input:
5 2
1 2 3 4 5
1 2

Output:
34
Explanation

Here are the answers of few calls to function f()
f(A, 2, 0, 2) = 1
f(A, 2, 0, 5) = 0
f(A, 3, 4, 2) = 1  

Solution:
DIFFICULTY:
MEDIUM-HARD

PRE-REQUISITES:
Mo's algorithm 
Number Theory

PROBLEM:
For a prime P and array A, F(A, L, R, P) denotes number of A[i], (L ≤ i ≤ R) divisible by P. Given an array A of size N and another array B 
of size M, find 
imag 
where, 
L = (B[i] + B[j]) % N 
R = (B[i] - B[j] + N) % N

EXPLANATION:
Read post in pre-requisite if you don't know about Mo's algorithm.

If we note that L and R being generated here are random. So, we'll have to calculate F(A, L, R, P), for each query. So our problem now is that: 
Given M * M queries of form L, R, for each query find Sum[F(A, L, R, P)2] for all primes p less than 106.

Now, we can note here that if we have answer for query (L, R), how fast can we calculate answer for (L, R+1). Suppose we have an array cnt, 
where cnt[i] denotes the F(A, L, R, i) (i are primes). So our answer here is sum{cnt[i]2} for all i primes. 
Now, we have to make certain changes in cnt array since a new number A[R+1] has been added.

ans = answer for (L,R)
for all p = prime factors of A[R+1]:
    //update the answer
    //answer is affected due to change in cnt[p]
    ans -= cnt[p]*cnt[p]
    cnt[p]++;
    ans += cnt[p]*cnt[p]
print ans
And, similarily we can also remove a number from our answer. 
In complexity: O(number of prime factors), we can insert/delete a number from our data structure. 
So, basically, what we have here is a data structure in which we can insert/delete a number in O(K), where K < number of distinct prime factors 
of number(worst case 7). 
If we have all the numbers in range [L, R] organized in our data strcture, we can transform to [L', R'] in O((|L-L'| + |R-R'|) * K).

Now, what we'll use here is popularly known as Mo's algorithm among chinese. It's a offline query algorithm. We process all our queries in 
such a order such that transform cost is minmised. 
Here's the sorting function we use:

//we break array A into sqrt(N) chunks.
S = the max integer number which is less than sqrt(N);
bool cmp(Query A, Query B)
{
    //if starting point belongs to different chunks
    //sort on increasing starting point
    if (A.l / S ！= B.l / S) return A.l / S < B.l / S;

    //if starting point is present in same chunk
    //sort according to decreasing ending point.
    return A.r > B.r
}
We sort all the queries by this comparator, and process all queries in order. It can be proved easily that the total transform cost is 
O(N * sqrt(N) * K)  */

#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;
 
#define N (NLIMIT + 100)
#define M (MLIMIT + 100)
#define A (ALIMIT + 100)
#define BLOCK 300
 
#define NLIMIT 100000
#define MLIMIT 500
#define ALIMIT 100000
#define MOD 1000000007
 
int a[N], b[M], ans[M*M], c[A], square[A];
vector <int> primeFactors[A];
 
long long answer = 1;
 
int expmod(int a, int b) {
	long long x = 1, y = a;
	while(b) {
		if(b&1) x = (x * y) % MOD;
		y = (y * y) % MOD;
		b >>= 1;
	}
	return (int) x;
}
 
void updatePrime(int prime, int v) {
	answer -= square[c[prime]];
	c[prime] += v;
	answer += square[c[prime]];
}
 
void add(int i) {
	int x = a[i];
	for(int j=0; j<primeFactors[x].size(); j++) {
		updatePrime(primeFactors[x][j], 1);
	}
}
 
void remove(int i) {
	int x = a[i];
	for(int j=0; j<primeFactors[x].size(); j++) {
		updatePrime(primeFactors[x][j], -1);
	}
}
 
struct node {
	int l, r, i;
}q[M*M];
 
bool cmp(node a, node b) {
	return ( (a.l/BLOCK < b.l/BLOCK) || ((a.l/BLOCK == b.l/BLOCK) && a.r < b.r) );
}
 
int main() {
	square[0] = 0;
	for(int i=1; i<A; i++) {
		c[i] = 0;
		square[i] = ((long long)i * i) % MOD;
		int x = i;
		for(int j=2; j*j <= x; j++)
			if(x % j == 0) {
				primeFactors[i].push_back(j);
				while(x % j == 0) {
					x /= j;
				}
			}
		if(x > 1) {
			primeFactors[i].push_back(x);
		}
	}
 
	int n, m;
	scanf("%d%d", &n, &m);
 
	assert(1 <= n && n <= NLIMIT);
	assert(1 <= m && m <= MLIMIT);
 
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
		assert(1 <= a[i] && a[i] <= ALIMIT);
	}
 
	for(int i=0; i<m; i++) {
		scanf("%d", &b[i]);
		assert(0 <= b[i] && b[i] < n);
	}
 
	for(int i=0; i<m; i++)
		for(int j=0; j<m; j++)
		{
			int tt = i*m+j;
			q[tt].l = (b[i] + b[j]) % n;
			q[tt].r = (b[i] - b[j] + n) % n;
			if(q[tt].l > q[tt].r) {
				swap(q[tt].l, q[tt].r);
			}
			q[tt].i = tt;
		}
 
	int pm = m;
	m *= m;
	sort(q, q+m, cmp);
 
	int curL = 0, curR = 0;
	answer = 0;
 
	for(int qq=0; qq<m; qq++) {
		int l = q[qq].l;
		int r = q[qq].r;
		while(curL > l) {
			add(--curL);
		}
		while(curR <= r) {
			add(curR++);
		}
		while(curL < l) {
			remove(curL++);
		}
		while(curR > r+1) {
			remove(--curR);
		}
		answer %= MOD;
		if(answer < 0) {
			answer += MOD;
		} 
		ans[q[qq].i] = (int)answer;
	}
 
	answer = 0;
	for(int i=0; i<pm; i++) {
		long long cur = 1;
		for(int j=0; j<pm; j++) {
			(cur *= ans[i*pm+j]) %= MOD;
		}
		answer += cur;
		if(answer >= MOD) {
			answer -= MOD;
		}
	}
	printf("%lld\n", answer);
}

