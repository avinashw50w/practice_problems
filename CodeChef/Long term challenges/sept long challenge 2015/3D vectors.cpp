#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define LOCAL 0
 
#define XMAX 77
#define PMAX 800000
#define NMAX 4194304 //8388608
 
char used[XMAX + 1][XMAX + 1][XMAX + 1];
int x[PMAX], y[PMAX], z[PMAX];
int N, Q;
 
void ReadInput() {
	if (LOCAL) {
		srand(12345);
		N = 300000;
		Q = 77;
	} else scanf("%d %d", &N, &Q);
	for (int i = 1; i <= N; i++) {
		if (LOCAL) {
			do {
				x[i] = 1 + (rand() % XMAX);
				y[i] = 1 + (rand() % XMAX);
				z[i] = 1 + (rand() % XMAX);
			} while (used[x[i]][y[i]][z[i]]);
			used[x[i]][y[i]][z[i]] = 1;
		} else scanf("%d %d %d", &x[i], &y[i], &z[i]);
	}
}
 
unsigned int mask[2] = {4294967295U, 0}, mask2[2] = {0, 4294967295U};
 
class FFT {
// The FFT functions were adapted from functions publicly
// available on the web:
// http://acm.math.spbu.ru/~kunyavskiy/notebook/fft-short.cpp
 
public:
 
int FFTMOD, LMAX;
 
FFT(int mod) {
	FFTMOD = mod;
	LMAX = -1;
}
 
void SetLMAX(int lmax) {
	LMAX = lmax;
}
 
#define ROOT 3
#define MROOT 23
#define MROOTP (1<<MROOT)
 
int rts[MROOTP + 10], brev[MROOTP + 10];
 
inline void madd(int& a, int b) {
	if ((a += b) >= FFTMOD) a -= FFTMOD;
}
 
int mpow(int a, int b){
	if (!b) return 1;
	if (b & 1) return ((long long) mpow(a, b-1) * (long long) a) % FFTMOD;
	int temp = mpow(a, b/2);
	return (temp * 1LL * temp) % FFTMOD;
}
 
void PrecalcRoots(){
	rts[0] = 1; // ROOT is primary root for FFTMOD
	rts[1] = mpow(ROOT, (FFTMOD-1) / MROOTP);
	for (int i = 2; i < MROOTP; i++)
		rts[i] = ((long long) rts[i-1] * (long long) rts[1]) % FFTMOD;
	for (int i = 0; i < MROOTP; i++)
		brev[i] = (brev[i>>1]>>1) | ((i&1) << (MROOT-1));
}
 
int FFTSIZE, FFTSIZE_BITS, FFTSIZE_INV;
 
void ComputeFFTSize() {
	FFTSIZE = 4;
	FFTSIZE_BITS = 2;
	while (FFTSIZE < LMAX) {
		FFTSIZE <<= 1;
		FFTSIZE_BITS++;
	}
	FFTSIZE_INV = mpow(FFTSIZE, FFTMOD - 2);
}
 
void fft(int a[NMAX], bool inv){
	for (int i = 0; i < FFTSIZE; i++){
		int temp = brev[i] >> (MROOT - FFTSIZE_BITS);
		if (temp > i) {
			int tmp = a[i];
			a[i] = a[temp];
			a[temp] = tmp;
		}
	}
	for (int step = 0; step < FFTSIZE_BITS; step++){
		int pos = 0, p2step = 1 << step, p2step1 = 1 << (step + 1);
		int dlt = (inv ? -1 : 1) * (1 << (MROOT - step - 1));
		for (int imax = p2step; imax < FFTSIZE; imax += p2step1) {
			for (int i = imax - p2step; i < imax; i++) {
				int ii = i ^ p2step;
				if (a[ii] == 0) {
					a[ii] = a[i];
				} else {
					int temp = ((long long) rts[pos] * (long long) a[ii]) % FFTMOD;
					a[ii] = a[i];
					a[i] += temp;
					a[i] -= (mask[(((unsigned int) a[i] - (unsigned int) FFTMOD) >> 31)] & FFTMOD);
					a[ii] -= temp;
					if (a[ii] < 0) a[ii] += FFTMOD;
					a[ii] += (mask2[((unsigned int) a[ii]) >> 31] & FFTMOD);
				}
				pos = (pos + dlt) & (MROOTP-1);
			}
			pos = (pos + dlt * p2step) & (MROOTP-1);
		}
	}
}
};
 
#define BASE 1000000000000000000LL
 
long long FRAC_SCALE;
unsigned int dcnt[2 * XMAX + 1][2 * XMAX + 1][2 * XMAX + 1];
long long frac[2 * XMAX + 1][2 * XMAX + 1][2 * XMAX + 1], tmpmax[2 * XMAX + 1][2 * XMAX + 1][2 * XMAX + 1];
int c[NMAX], d[NMAX];
 
FFT fft(998244353);
 
void PreprocessInput() {
	if (N < 10000) {
		FRAC_SCALE = 1000000000000LL;
	} else {
		FRAC_SCALE = 10000000LL;
	}
 
	int base = 2 * XMAX + 1, i, dx, dy, dz;
 
	fft.PrecalcRoots();
	fft.SetLMAX(NMAX);
	fft.ComputeFFTSize();
	
	for (i = 1; i <= N; i++) {
		c[x[i] * base * base + y[i] * base + z[i]] = 1;
		d[(XMAX - x[i]) * base * base + (XMAX - y[i]) * base + (XMAX - z[i])] = 1;
	}
 
	fft.fft(c, false);
	fft.fft(d, false);
	for (i = 0; i < NMAX; i++)
		c[i] = ((long long) c[i] * (long long) d[i]) % fft.FFTMOD;
 
	fft.fft(c, true);
 
	for (i = 0; i < NMAX; i++)
		c[i] = ((long long) c[i] * (long long) fft.FFTSIZE_INV) % fft.FFTMOD;
 
	for (i = 0; i < NMAX; i++)
		if (c[i] > 0) {
			dx = i / base / base;
			dy = (i % (base * base)) / base;
			dz = i % base;
			if (dx == XMAX && dy == XMAX && dz == XMAX) continue;
			dcnt[dx][dy][dz] = c[i];
		}
 
	for (dx = -XMAX; dx <= XMAX; dx++)
		for (dy = -XMAX; dy <= XMAX; dy++)
			for (dz = -XMAX; dz <= XMAX; dz++)
				if (dcnt[dx + XMAX][dy + XMAX][dz + XMAX] > 0) {
					frac[dx + XMAX][dy + XMAX][dz + XMAX] = (long long) (FRAC_SCALE * dcnt[dx + XMAX][dy + XMAX][dz + XMAX] / sqrt(dx * dx * dx * dx + dy * dy * dy * dy + dz * dz * dz * dz));
					tmpmax[dx + XMAX][dy + XMAX][dz + XMAX] = BASE / frac[dx + XMAX][dy + XMAX][dz + XMAX];
				}
}
 
typedef long long BIGNUM[2];
 
void add(BIGNUM a, long long x) {
	a[0] += x;
	if (a[0] >= BASE) {
		a[1] += a[0] / BASE;
		a[0] %= BASE;
	}
}
 
void multiply(BIGNUM a, int x, BIGNUM rez) {
	rez[0] = rez[1] = 0;
	for (int bit = 20; bit >= 0; bit--) {
		rez[0] <<= 1; rez[1] <<= 1;
		if (rez[0] >= BASE) {
			rez[1]++;
			rez[0] %= BASE;
		}
		if ((x & (1 << bit)) > 0) {
			rez[0] += a[0];
			rez[1] += a[1];
			if (rez[0] >= BASE) {
				rez[1]++;
				rez[0] %= BASE;
			}
		}
	}
}
 
BIGNUM q, r;
 
void divide(BIGNUM a, int x) {
	q[1] = a[1] / x;
	long long li = 0, ls = BASE - 1, q0ans = 0;
	while (li <= ls) {
		q[0] = li + ((ls - li) >> 1);
		//fprintf(stderr, "A: %lld-%lld: %lld\n", li, ls, q[0]);
		multiply(q, x, r);
		if (r[1] < a[1] || (r[1] == a[1] && r[0] <= a[0])) {
			q0ans = q[0];
			li = q[0] + 1;
		} else ls = q[0] - 1;
	}
	a[1] = q[1];
	a[0] = q0ans;
}
 
void ProcessQueries() {
	int A, B, C, D, dx, dy, dz;
	BIGNUM ans;
	while (Q--) {
		if (LOCAL) {
			A = 1 + (rand() % XMAX);
			B = 1 + (rand() % XMAX);
			C = 1 + (rand() % XMAX);
			D = 1 + (rand() % 7777);
		} else scanf("%d %d %d %d", &A, &B, &C, &D);
		ans[0] = ans[1] = 0;
		for (dx = -XMAX; dx <= XMAX; dx++)
			for (dy = -XMAX; dy <= XMAX; dy++)
				for (dz = -XMAX; dz <= XMAX; dz++)
					if (dcnt[dx + XMAX][dy + XMAX][dz + XMAX] > 0) {
						long long tmp = abs(A * dx + B * dy + C * dz + D);
						if (tmp >= tmpmax[dx + XMAX][dy + XMAX][dz + XMAX]) {
							exit(111);
							long long chunk = tmpmax[dx + XMAX][dy + XMAX][dz + XMAX];
							long long total_chunk = 0;
							while (total_chunk < tmp) {
								if (total_chunk + chunk > tmp) chunk = tmp - total_chunk;
								add(ans, chunk * frac[dx + XMAX][dy + XMAX][dz + XMAX]);
								total_chunk += chunk;
							}
						} else add(ans, tmp * frac[dx + XMAX][dy + XMAX][dz + XMAX]);
					}
		divide(ans, N);
		divide(ans, N - 1);
		if (ans[1] > 0) {
			exit(112);
		} else {
			if (FRAC_SCALE == 1000000000000LL)
				printf("%lld.%012lld\n", ans[0] / FRAC_SCALE, ans[0] % FRAC_SCALE);
			else
				printf("%lld.%07lld\n", ans[0] / FRAC_SCALE, ans[0] % FRAC_SCALE);
		}
	}
}
 
int main() {
//	freopen("y.txt", "r", stdin);
	ReadInput();
	PreprocessInput();
	ProcessQueries();
	return 0;
}
