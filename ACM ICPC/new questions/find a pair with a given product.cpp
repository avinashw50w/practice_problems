
bool find(int A[], int N, int prod) {

	if(N < 2) return false;

	unordered_set<int> s;

	REP(i, 0, N) {

		if(A[i] == 0) return prod == 0;

		if(prod % A[i] == 0) {
			if(s.find(prod/A[i]) != s.end()) return true;

			s.insert(A[i]);
		}
	}

	return false;
}