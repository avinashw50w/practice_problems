/*You are given 3 positive integers N1, N2, N3 up to 1018 and need to count the number of ordered triples (X1, X2, X3) such that 1 = Xi = Ni for i = 1, 2, 3. You should output the 
answer modulo 109 + 7.

QUICK EXPLANATION:
By sorting input numbers we can assume that N1 = N2 = N3. Then the answer is N1 * (N2 - 1) * (N3 - 2). Watch out for integer overflows during calculation of this number modulo 109 + 7.

ALTERNATIVE SOLUTION:
The problem could be solved using inclusion-exclusion principle. The formula for the answer in this case is
N1 * N2 * N3 - min{N1, N2} * N3 - min{N2, N3} * N1 - min{N3, N1} * N2 + 2 * min{N1, N2, N3}.*/
#include <stdio.h>
#include <algorithm>


const int mod = (int)1e9 + 7;

int main(){
	int t, i;
	long long int a[3], ans;

	scanf("%d",&t);
	while(t--){
		for(i=0;i<3;++i)
			scanf("%lld",&a[i]);

		std::sort(a,a+3);
		ans=1;
		for(i=0;i<3;++i){
			ans *= ((a[i]-i) % mod);
			ans %= mod;
		}

		printf("%lld\n", ans);
	}
	return 0;
}
