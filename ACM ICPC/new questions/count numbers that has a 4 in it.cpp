/*Given a positive integer N, calculate the number of positive integers under N that has at least one digit equal to 4.

For example, given 8, return 1 since only 4 contains digit 4.*/

bool has4(int n) {
	while(n > 3) {
		if(n%10 == 4) return true;
		n /= 10;
	}
	return false;
}

int solve(int N) {
	int cnt = 0;
	REP(i, 4, N) {
		if(has4(i)) cnt++;
	}

	return cnt;
}