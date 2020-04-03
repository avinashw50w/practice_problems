/*Given an array A your task is to tell at which position the equilibrium first occurs in the array. 
Equilibrium position in an array is a position such that the sum of elements below it is equal to the sum of elements after it.

Input:
The first line of input contains an integer T denoting the no of test cases then T test cases follow. 
First line of each test case contains an integer N denoting the size of the array. 
Then in the next line are N space separated values of the array A.

Output:
For each test case in a new  line print the position at which the elements are at equilibrium if no equilibrium point exists print -1.
*/

// equilibrium point in an array 
int findEqPoint(int A[], int N) {

	int sum = 0, leftsum = 0;

	REP(i, 0, N) sum += A[i];

	REP(i, 0, N) {
		sum -= A[i];

		if(leftsum == sum) return i;

		leftsum += A[i];
	}

	return -1;
}

///////////////////////////////////////////
//// equilibrium points in a matrix of size N x M

vector<int> findEqPointInMatrix(int mat[][maxn], int N, int M) {

	vector<int> res;

	REP(i, 0, N) {
		int eq = findEqPoint(mat[i], M);
		res.push_back(eq);
	}

	REP(j, 0, M) {
		int a[N];
		REP(i, 0, N) a[i] = mat[i][j];
		int eq = findEqPoint(a, N);
		res.push_back(eq);
	}

	return res;
}