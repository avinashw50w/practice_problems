/*Count zeros in a row wise and column wise sorted matrix
Given a N x N binary matrix (elements in matrix can be either 1 or 0) where each row and column of the matrix 
is sorted in ascending order, count number of 0s present in it.

Expected time complexity is O(N).

Examples:

Input: 
[0, 0, 0, 0, 1]
[0, 0, 0, 1, 1]
[0, 1, 1, 1, 1]
[1, 1, 1, 1, 1]
[1, 1, 1, 1, 1]

Output: 8

The idea is very simple. We start from the bottom-left corner of the matrix 
and repeat below steps until we find the top or right edge of the matrix.

1. Decrement row index until we find a 0.
2. Add number of 0s in current column i.e. current row index + 1 to the result and move right to next column (Increment col index by 1).
The above logic will work since the matrix is row-wise and column-wise sorted. 
The logic will also work for any matrix containing non-negative integers.*/

int countZeroes(int mat[N][N]) {

	int count = 0;
	int row = N-1, col = 0;

	while(col < N) {

		while(mat[row][col]) {
			if(--row < 0) return count;
		}

		count += row + 1;

		col++;
	}

	return count;
}

int main()
{
    int mat[N][N] =
    {
        { 0, 0, 0, 0, 1 },
        { 0, 0, 0, 1, 1 },
        { 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 }
    };
 
    cout << countZeroes(mat);
 
    return 0;
}