
// count the sum of the powers of all the prime factors of N.
// eg, let N = 12 , so 12 = 2*2*3. So, sum of all their powers = 1 + 1 + 1 = 3

const int maxn = 1e6 + 1;
int cnt[maxn];

void prec() {
	for(int i = 2; i < maxn; ++i) {
		if(cnt[i] != 0) continue;

		for(int j = i; j < maxn; j += i) {
			int k = j;

			while(k % i == 0) cnt[j]++, k /= i;
		}
	}
}