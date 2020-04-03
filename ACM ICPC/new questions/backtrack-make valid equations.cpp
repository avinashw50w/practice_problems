/*make valid equations : eg, given 2 _ 8 _ 5 _ 1 _ 6 = 3 , then insert either + or - in the blanks to make the equation valid. 

you are given the array A[] containing the numbers in the equations in the order they appear in the equation.*/

#include <iostream>
using namespace std;

int A[10];
char symbol[10];

void printEqn(int N) {
	for(int i = 1; i < N; ++i)
		printf("%d %c ", A[i-1], symbol[i]);

	printf("= %d", A[N-1]);
}

void solve(int k, int N, int R) {
	int tmp = R;

	if(k == N) {
		if(R == A[N-1]) printEqn(N);
		else return;
	}

	else {
		R = R + A[k];
		symbol[k] = '+';
		solve(k+1, N, R);

		// backtrack
		tmp = tmp - A[k];
		symbol[k] = '-';
		solve(k+1, N, tmp);
	}
}

int main() {
	int N; cin>>N;
	for(int i = 0; i < N; ++i) cin>>A[i];

	solve(1, N, A[0]);
}