/* 	
You are playing a treasure hunt game. The game is played on a rectangular board that is divided into a grid of unit squares. You are given the layout of the board in the String[] board. Each character in board represents one square of the board. The meanings of the characters in board:

'O' (capital oh): This square contains a landmark.
'.': This square is empty.
'?': You do not know the contents of this square. It may contain a landmark and it may be empty.
A treasure is buried under one of the squares. You know something about its location:

The row in which the treasure is buried is between T and B, inclusive, where T is the topmost row that contains a landmark and B 
is the bottommost row that contains a landmark.
The column in which the treasure is buried is between L and R, inclusive, where L is the leftmost column that contains a 
landmark and R is the rightmost column that contains a landmark.
Thus, you can narrow your search space to a sub-rectangle of the original grid.

Suppose k is the number of grid squares which are unknown to you. In other words, let k be the number of '?' characters in board. 
There are 2^k different boards that correspond to the information you have. For each of those boards, compute the number of 
squares that may contain the treasure. Find and return the sum of those 2^k numbers.

 
Definition
    	
Class:	XMarksTheSpot
Method:	countArea
Parameters:	String[]
Returns:	int
Method signature:	int countArea(String[] board)
(be sure your method is public)
    
 
Constraints
-	board will have between 1 and 50 elements, inclusive.
-	Each element of board will be the same length.
-	Each element of board will have between 1 and 50 characters, inclusive.
-	Each character of each element of board will be "O", ".", or "?".
-	The number of "?" characters among all elements of board is at most 19.
-	There will be at least one "O" character among all elements of board.
 
Examples
0)	
    	
{
"?.",
".O"
}
Returns: 5
If the top left corner is empty, we only have 1 possible location of the treasure: the bottom right corner. 
If the top left corner is a landmark, the treasure can be anywhere in the grid: 4 possible locations. 
The return value is therefore 1 + 4 = 5.*/

/*A 2^k * n * m solution is obvious, but it is a bit too slow for this problem. How can we speed this up? 
We can take advantage of preprocessing to get it faster. Namely, we can pre-compute the existing topmost/bottomost/leftmost/
rightmost landmarks ('O') so we don't need to redo our work. Then, when considering a configuraiton, we only need to do O(k) 
work to update these positions. See the code below for more details.*/


public class XMarksTheSpot {
  public int countArea(String[] board) {
    int n = board.length;
    int m = board[0].length();
    int mnx = n, mxx = -1, mny = m, mxy = -1;
    int[] px = new int[21];
    int[] py = new int[21];
    int idx = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i].charAt(j) == 'O') {
          mnx = Math.min(i, mnx);
          mxx = Math.max(i, mxx);
          mny = Math.min(j, mny);
          mxy = Math.max(j, mxy);
        } else if (board[i].charAt(j) == '?') {
          px[idx] = i;
          py[idx] = j;
          idx++;
        }
      }
    }
    int ret = 0;
    for (int i = 0; i < 1 << idx; i++) {
      int cmnx = mnx, cmxx = mxx, cmny = mny, cmxy = mxy;
      for (int j = 0; j < idx; j++) {
        if (((i>>j)&1) == 1) {
          cmnx = Math.min(cmnx, px[j]);
          cmxx = Math.max(cmxx, px[j]);
          cmny = Math.min(cmny, py[j]);
          cmxy = Math.max(cmxy, py[j]);
        }
      }
      ret += (cmxx - cmnx + 1) * (cmxy - cmny + 1);
    }
    return ret;
  }
}