/*Alexandra has some distinct integer numbers a1,a2...an.
Count number of pairs (i,j) such that:
1<= i <= n
1<= j <= n
ai < aj
 
Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.The first line of each test case contains a single 
integer n denoting the number of numbers Alexandra has. The second line contains n space-separated distinct integers a1, a2, ..., an denoting these numbers.
 
Output

For each test case, output a single line containing number of pairs for corresponding test case.
 
Constraints

1 ≤ T ≤ 4
1 ≤ n ≤ 100000
0 ≤ ai ≤ 109
All the ai are distinct */

/* usually the number of pairs will be n*(n-1)/2 , and if order of elements in a pair is considered then it is twice of n*(n+1)/2. 
but it is sure that one of the pair (i, j) or (j, i) will satisfy ai < aj*/ 
int a;
int main() {
	int t; si(t);
	while(t--){
		int n; si(n);
		rep(i,0,n) si(a);
		printf("%lld\n",(ll)n*(n-1)>>1);
	}
	return 0;
}