/*Problem:
You are given a set of N positive numbers A[0], A[1], ..., A[N-1]. At each step you pick two unequal numbers and replace the larger one by 
the difference. You stop when all numbers are equal. Find at what number will you stop.

Explanation:
You stop at the GCD of the numbers. To prove this, we just use the fact that gcd(a, b) = gcd(a-b, b), where a > b. Now, let the original 
GCD be G. After a single step, since gcd(a, b) = gcd(a-b, b), in particular, gcd(A[i], A[j]) = gcd(A[i]-A[j], A[j]), we get that the gcd 
remains G.

If we finally end at the number K, then gcd(K, K, K, ..., K) = K. But since after each step the gcd remains invariant, we get that K = G.*/

#include <stdio.h>
#define gc getchar_unlocked
inline int inp(){register int n,c; while((c=gc())<'0');n=c-'0';while((c=gc())>='0')n=(n<<1)+(n<<3)+c-'0';return n;}

inline int gcd(int a,int b){return (b==0)?a:gcd(b,a%b);}

int main(){
	int t, n, g, i;
	t=inp();
	while(t--){
		n=inp();
		g=0;
		for(i=0;i<n;++i){
			g=gcd(g,inp());
		}
		printf("%d\n", g);
	}
	return 0;
}