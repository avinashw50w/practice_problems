#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
double ai, bi, atmp, btmp, x, y, q;
long long i, k, s, p2;
 
int main() {
	scanf("%lld %lld %lld %lf %lf", &i, &k, &s, &ai, &bi);
 
	if ((i & 1) != (k & 1)) {
		x = sqrt(2.0);
		y = sqrt(3.0);
		i++;
		atmp = x * (ai + bi) - x * y * (ai - bi);
		btmp = x * (ai - bi) + x * y * (ai + bi);
		ai = atmp;
		bi = btmp;
	}
 
	if (k >= i) p2 = 2LL * (k - i);
	else p2 = -2LL * (i - k);
	p2 -= s;
 
	q = (ai + bi) * pow(2.0, p2);
	printf("%.9lf\n", q);
	return 0;
}
