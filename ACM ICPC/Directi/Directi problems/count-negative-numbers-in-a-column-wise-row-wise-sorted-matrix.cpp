/*Count Negative Numbers in a Column-Wise and Row-Wise Sorted Matrix
Find the number of negative numbers in a column-wise / row-wise sorted matrix M[][]. Suppose M has n rows and m columns.

Example:

Input:  M =  [-3, -2, -1,  1]
             [-2,  2,  3,  4]
             [4,   5,  7,  8]
Output : 4
We have 4 negative numbers in this matrix*/

int countNeg(int Mat[N][M]) {

	int cnt = 0;
	int i = 0, j = M-1;

	while (i < N and j >= 0) {

		if(Mat[i][j] < 0)
			cnt += (j + 1), i++;

		else j--;
	}

	return cnt;
}