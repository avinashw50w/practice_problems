/*Given an N x N matrix, find a k x k submatrix where k <= N and k >= 1, such that sum of all the elements in submatrix is maximum. 
A Simple Solution is to consider all possible sub-squares of size k x k in our input matrix and find the one which has maximum sum. 
Time complexity of above solution is O(N^2k^2).

We can solve this problem in O(N^2) time. This problem is mainly an extension of this problem of printing all sums. 
The idea is to preprocess the given square matrix. In the preprocessing step, calculate sum of all vertical strips 
of size k x 1 in a temporary square matrix stripSum[][]. Once we have sum of all vertical strips, we can calculate 
sum of first sub-square in a row as sum of first k strips in that row, and for remaining sub-squares, 
we can calculate sum in O(1) time by removing the leftmost strip of previous subsquare and adding the rightmost strip 
of new square.The input matrix can contain zero, positive and negative numbers.*/

int getMaxSubSquare(int mat[][N], int K) {
	
	if(K > N) return -1;
	// strip[i][j] stores the sum of the vertical strip starting
	// from position (i, j)
	int strip[N][N];
	// calculate strips for every starting point
	REP(j, 0, N) {

		int sum = 0;
		
		REP(i, 0, K) sum += mat[i][j];
		strip[0][j] = sum;

		REP(i, 1, N-K+1) {
			sum += (mat[i+K-1][j] - mat[i-1][j]);
			strip[i][j] = sum;
		}
	}

	int maxSum = INT_MIN, *pos = NULL;

	REP(i, 0, N-K+1) {

		int sum = 0;
		REP(j, 0, K) sum += strip[i][j];

		if(sum > maxSum) {
			maxSum = sum;
			pos = &(mat[i][0]);
		}

		REP(j, 1, N-K+1) {
			
			sum += (strip[i][j+k-1] - strip[i][j-1]);

			if(sum > maxSum) {
				maxSum = sum;
				pos = &(mat[i][j]);
			}
		}
	}

	REP(i, 0, K) {
		REP(j, 0, K)
			cout << *(pos + i*N + j) << " ";
    	cout << endl;
	}

	return maxSum;
}