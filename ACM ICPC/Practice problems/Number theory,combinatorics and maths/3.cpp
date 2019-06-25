/*The Monk wants to teach all its disciples a lesson about patience, since they are always in a hurry to do something crazy. To teach them this, he gives them a list of N numbers, which may or may not be distinct. The students are supposed to solve a simple Mathematical equation based on the array of these N numbers.

g(x) - GCD (a[ 0 ], a[ 1 ], a[ 2 ]... a[n-1] )
f(x) - (a[ 0 ] * a[ 1 ] * a[ 2 ]... * a[n-1] )
The value of the MonkQuotient is: 109 + 7.

The equation to be solved is: ( f(x)g(x) ) % MonkQuotient

Input constraints:
The first line of input will contain an integer — N. The next line will contain N integers denoting the elements of the list.

Output constraints:
Print the required answer of the equation.

Constraints:
1 ≤ N ≤ 50 
1 ≤ Ai ≤ 103  */

int n, a[55];

ll mpow(ll a,ll b){
	if(b==0) return 1;
	ll x = mpow(a,b/2);
	x = (x*x)%mod;
	if(b&1) x = (x*a)%mod;
	return x;
}

int main() {
	si(n);
	int g = 0;
	ll f = 1;
	rep(i,0,n) {
		si(a[i]);
		g = __gcd(g,a[i]);
		f = (f*a[i])%mod;
	}
	
	printf("%lld\n", mpow(f,g));
	return 0;
}
