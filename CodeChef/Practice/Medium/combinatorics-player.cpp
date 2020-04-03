/*There are N songs in the album. In the very beginning random song is chosen(here and further "random song" means that every song has equal probability to be 
chosen). After some song is over the next one is chosen randomly and independently of what have been played before. 

Nikita G., being the only one who is not going to drop out from the university, wonders, what is the expected number of songs guys have to listen to until every 
song is played at least once. 

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows. 

The first and only line of each test case contains a single integer N denoting the number of songs in the album. 

Output

For each test case, output a single line containing the expected number of songs the guys will listen to. Your answer will be considered as correct if it has an 
absolute or relative error less than 10−1. More formally if the expected output is A and your output is B, your output will be considered as correct if and only if
|A − B| ≤ 10−1 * max{|A|, |B|, 1}. 

Constraints

1 ≤ T ≤ 100
1 ≤ N ≤ 3000*/

/* this is also known as coupon's collector problem : Given n coupons, how many coupons do you expect you need to draw with replacement before having drawn 
each coupon at least once? 
Calculating the expectation[edit]
Let T be the time to collect all n coupons, and let ti be the time to collect the i-th coupon after i − 1 coupons have been collected. Think of T and ti as 
random variables. Observe that the probability of collecting a new coupon is pi = (n − (i − 1))/n. Therefore, ti has geometric distribution with expectation 1/pi. 
By the linearity of expectations we have:
E(T) = E(t1) + E(t2) + E(t3) + ..... + E(tn) = 1/p1 + 1/p2 + 1/p3 + ..... + 1/pn = n/n + n/n-1 + n/n-2 + .... + n/1 = n(1 + 1/2 + 1/3 + ... + 1/n) = nH(n)

H(n) =  (approx) log(n+0.5) + 0.5772 + 0.04021/(n*n + 0.8848)*/
/* refer : https://en.wikipedia.org/wiki/Coupon_collector%27s_problem#Solution  */
int main() {
	int t=inp();
	while(t--) {
		int N = inp();

		double ans = (double)N * (log(N + 0.577) + 0.577 + 0.0402/(N*N + 0.8848));
		printf("%f\n", ans);
	}
	
	return 0;
}
