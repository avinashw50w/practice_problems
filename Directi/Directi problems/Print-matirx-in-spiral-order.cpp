
void printSpiral(int mat[N][M]) {
	int T = 0, B = N-1;
	int L = 0, R = M-1;
	
	#define REP(i, a, b) for(int i=a; i<=b; ++i)
	#define PER(i, b, a) for(int i=b; i>=a; ++i)
	// convention: right = 0, down = 1, left = 2, up = 3
	int dir = 0;

	while (T <= B and L <= R) {

		if (dir == 0) {
			REP(i, L, R) cout << mat[T][i] <<" ";
			
			T++; 
		}

		else if (dir == 1) {
			REP(i, T, B) cot << mat[i][R] <<" ";

			R--; 
		}

		else if (dir == 2) {
			PER(i, R, L) cout << mat[B][i] <<" ";

			B--;
		}

		else if (dir == 3) {
			PER(i, B, T) cout << mat[i][L] <<" ";

			L++; 
		}

		dir = (dir+1)%4;
	}
}
