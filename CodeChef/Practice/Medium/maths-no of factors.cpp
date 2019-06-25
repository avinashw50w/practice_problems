/*Given N numbers, you need to tell the number of distinct factors of the product of these N numbers.

Input:

First line of input contains a single integer T, the number of test cases.

Each test starts with a line containing a single integer N.
The next line consists of N space separated integers (Ai).




Output:

For each test case, output on a separate line the total number of factors of the product of given numbers.


Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 10
2 ≤ Ai ≤ 1000000

Example:

Input:

3
3
3 5 7
3
2 4 6
2
5 5

Output:

8
10
3
*/

/*solution : Any number N can be represented as a product of some powers of their prime factors( N = p1^k1 . p2^k2 .... pn^kn). So, ind prime factors of each 
number and store them in an array. eg, 2,4,6  their product is 48 = 2^4 . 3^1 , here Number of distinct factors = number of combinations of 2 and 3 . 
So, number of ways of choosing 2 is 5 (not choosing 2 is also an option) and number of ways of choosing 3 is 2. So, total number of ways = 5*2 = 10  */

#define MAXN 1000000+5

int p[MAXN];
int f[MAXN];

void seive(){
	ll i, j;
	for(i=2; i*i<MAXN; ++i){
		if(p[i]==0){
			p[i]=i;
			for(j=i*i; j<MAXN; j+=i) 
				p[j] = i;
		}
	}
	
	for(; i<MAXN; ++i) 
		if(p[i]==0) p[i] = i;
}

void factorise(int n) {
	while(n>1){
		f[p[n]]++;
		n /= p[n];
	}
}

int main() {
	#if 0
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	BOOST;

	seive();
	
	caset{
		mset(f,0);
		int n; cin>>n;
		int a;
		rep(i,0,n) {
			cin>>a;
			factorise(a);
		}
		ll ans = 1;
		rep(i,0,MAXN){
			if(f[i]) ans *= (f[i]+1);
		}
		cout<< ans <<"\n";
	}
	return 0;
}
