/* find the no of ways to move from top-left corner to bottom-right corner of a N x M grid, given that u can move only to right and bottom.*/

// the no of ways  = (N+M)!/N!* M!

ll cal(int N, int R) {
	ll res = 1;
	R = min(R, N-R);

	for(int i = 0; i < R; ++i) {
		res *= (N-i);
		res /= (i+1);
	}
	return res;
}

ll solve(int N, int M) {

	if(N == 0 or M == 0) return 1;

	return cal(N+M, M);
}

/////////////////////////////////////////////////////////////
//if asked to output modulo mod

ll cal(int N, int R) {

	int fac[N+1];
	fac[0] = 1;
	REP(i, 1, N+1) fac[i] = (i * fac[i-1]) % mod;

	ifac[N] = mpow(fac[N], mod-2);

	PER(i, N-1, 0) ifac[i] = ((i+1) * ifac[i+1]) % mod;

	ll res = fac[N];

	res = (res * ifac[N-R]) % mod;
	res = (res * ifac[R]) % mod;

	return res;
}