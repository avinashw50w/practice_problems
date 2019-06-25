/*In how many ways can you tile a 3xn rectangle with 2x1 dominoes?

Here is a sample tiling of a 3x12 rectangle.

Input consists of several test cases followed by a line containing -1.
Each test case is a line containing an integer 0 ≤ n ≤ 30. For each test
case, output one integer number giving the number of possible tilings.  */

int n, T[33], h[33];

void prec() {
	T[0] = 1; // ways to fill a rectangle with no space is 1,(place no tile at all)
	h[0] = 0; 
	rep(i,1, 31){
		T[i] = ((i>=2)? T[i-2] : 0) + 2*h[i-1];
		h[i] = T[i-1] + ((i>=2)? h[i-2] : 0);
	}
}
int main() {
	prec();
	while(si(n) and n>=0){
		printf("%d\n", T[n]);
	}
	return 0;
}

////////////////////////////////////////////////////////

// or we can use the formula derived form the above expressions
//  T(n) = 4*T(n-2) - T(n-4);

T[0] = 1;
T[1] = 0;
T[2] = 3;
T[3] = 0;

rep(i, 4, 31) T[i] = 4*T[i-2] - T[i-4];


/////////////////////////////////////////////////////