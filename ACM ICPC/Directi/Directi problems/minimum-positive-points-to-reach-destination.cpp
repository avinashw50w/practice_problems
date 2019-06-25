/*Minimum Initial Points to Reach Destination
Given a grid with each cell consisting of positive, negative or no points i.e, zero points. We can move across a cell only if we have positive points ( > 0 ). Whenever we pass through a cell, points in that cell are added to our overall points. We need to find minimum initial points to reach cell (m-1, n-1) from (0, 0).

Constraints :

From a cell (i, j) we can move to (i+1, j) or (i, j+1).
We cannot move from (i, j) if your overall points at (i, j) is <= 0.
We have to reach at (n-1, m-1) with minimum positive points i.e., > 0.
Example:

Input: points[m][n] = { {-2, -3,   3}, 
                        {-5, -10,  1}, 
                        {10,  30, -5} 
                      };
Output: 7

At the first look, this problem looks similar Max/Min Cost Path, but maximum overall points gained will not guarantee the minimum initial points. 
Also, it is compulsory in the current problem that the points never drops to zero or below. For instance, 
Suppose following two paths exists from source to destination cell.

We can solve this problem through bottom-up table filling dynamic programing technique.

To begin with, we should maintain a 2D array dp of the same size as the grid, where dp[i][j] represents the minimum points 
that guarantees the continuation of the journey to destination before entering the cell (i, j). It’s but obvious that dp[0][0] 
is our final solution. Hence, for this problem, we need to fill the table from the bottom right corner to left top.
Now, let us decide minimum points needed to leave cell (i, j) (remember we are moving from bottom to up). There are only two 
paths to choose: (i+1, j) and (i, j+1). Of course we will choose the cell that the player can finish the rest of his journey 
with a smaller initial points. Therefore we have: min_Points_on_exit = min(dp[i+1][j], dp[i][j+1])
Now we know how to compute min_Points_on_exit, but we need to fill the table dp[][] to get the solution in dp[0][0].

How to compute dp[i][j]?
     The value of dp[i][j] can be written as below.

dp[i][j] = max(min_Points_on_exit – points[i][j], 1)


Let us see how above expression covers all cases.

If points[i][j] == 0, then nothing is gained in this cell; the player can leave the cell with the same points as he enters 
the room with, i.e. dp[i][j] = min_Points_on_exit.
If dp[i][j] < 0, then the player must have points greater than min_Points_on_exit before entering (i, j) in order to compensate 
for the points lost in this cell. The minimum amount of compensation is " - points[i][j] ", so we have dp[i][j] = min_Points_on_exit - points[i][j].
If dp[i][j] > 0, then the player could enter (i, j) with points as little as min_Points_on_exit – points[i][j]. since he could 
gain “points[i][j]” points in this cell. However, the value of min_Points_on_exit – points[i][j] might drop to 0 or below in this situation. 
When this happens, we must clip the value to 1 in order to make sure dp[i][j] stays positive:
dp[i][j] = max(min_Points_on_exit – points[i][j], 1).
Finally return dp[0][0] which is our answer.*/

int minInitialPoints(int points[][C])
{
    // dp[i][j] represents the minimum initial points player
    // should have so that when starts with cell(i, j) successfully
    // reaches the destination cell(m-1, n-1)
    int dp[R][C];
    int m = R, n = C;
 
    // Base case
    dp[m-1][n-1] = points[m-1][n-1] > 0? 1:
                   abs(points[m-1][n-1]) + 1;
 
    // Fill last row and last column as base to fill
    // entire table
    for (int i = m-2; i >= 0; i--)
         dp[i][n-1] = max(dp[i+1][n-1] - points[i][n-1], 1);
    
    for (int j = n-2; j >= 0; j--)
         dp[m-1][j] = max(dp[m-1][j+1] - points[m-1][j], 1);
 
    // fill the table in bottom-up fashion
    for (int i=m-2; i>=0; i--)
    {
        for (int j=n-2; j>=0; j--)
        {
            int min_points_on_exit = min(dp[i+1][j], dp[i][j+1]);
            dp[i][j] = max(min_points_on_exit - points[i][j], 1);
        }
     }
 
     return dp[0][0];
}