/*Print n x n spiral matrix using O(1) extra space
Given a number n, print a n x n spiral matrix (of numbers from 1 to n x n) in clockwise direction using O(1) space.

Input: n = 5

Output:
25 24 23 22 21
10  9  8  7 20
11  2  1  6 19
12  3  4  5 18
13 14 15 16 17
We strongly recommend you to minimize your browser and try this yourself first.

The solution becomes simple if extra space is allowed. We allocate memory for n x n matrix and for every element starting from n*n to 1, we start filling out matrix in spiral order. To maintain the spiral order four loops are used, each for top, right, bottom and left corner of the matrix.

But how to solve it in O(1) space?

An n x n matrix has ceil(n/2) square cycles. A cycle is formed by ith row, (n-i+1)th column, (n-i+1)th row and ith column where i varies from 1 to ceil(n/2).

25 24 23 22 21 
10 9  8  7  20
11 2  1  6  19
12 3  4  5  18
13 14 15 16 17
The first cycle is formed by elements of its first row, last column, last row and first column (marked by red). 
The first cycle consists of elements from n*n to (n-2)*(n-2) + 1. i.e. from 25 to 10.
The second cycle is formed by elements of second row, second-last column, second-last row and second column(marked by blue). 
The second cycle consists of elements from (n-2)*(n-2) to (n-4)*(n-4) + 1. i.e. from 9 to 2.
The third cycle is formed by elements of third row, third-last column, third-last row and third column(marked by black). 
The third cycle consists of elements from (n-4)*(n-4) to 1. i.e. only 1.
The idea is for each square cycle, we associate a marker to it. For outer cycle, the marker will have value 0, for second cycle, 
it will have value 1 and for third cycle it has value 2. In general for a n x n matrix, i’th cycle will have marker value of i – 1.

If we divide the matrix into two parts, upper right triangle(marked by orange) and lower left triangle(marked by green), 
then using the marker x, we can easily calculate the value that will be present at the index(i, j) in any n x n spiral matrix using the below formula –

25  24 23 22 21 
10  9  8  7  20 
11  2  1  6  19 
12  3  4  5  18 
13  14 15 16 17 
For upper right half,
mat[i][j] = (n-2*x)*(n-2*x)-(i-x)-(j-x)

For lower left half,
mat[i][j] = (n-2*x-2)*(n-2*x-2) + (i-x) + (j-x)
*/
// Prints spiral matrix of size n x n containing
// numbers from 1 to n x n
void printSpiral(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // x stores the layer in which (i, j)th
            // element lies
            int x;
 
            // Finds minimum of four inputs
            x = min(min(i, j), min(n-1-i, n-1-j));
 
            // For upper right half
            if (i <= j)
                printf("%2d ", (n-2*x)*(n-2*x) - (i-x) - (j-x));
 
            // for lower left half
            else
                printf("%2d ", (n-2*x-2)*(n-2*x-2) + (i-x) + (j-x));
        }
        printf("\n");
    }
}
 
// Driver code
int main()
{
    int n = 5;
 
    // print a n x n spiral matrix in O(1) space
    printSpiral(n);
 
    return 0;
}*/