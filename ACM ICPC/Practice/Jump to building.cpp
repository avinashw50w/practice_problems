/* Our well known coding mafia went to the city. Farzi Coder is the boss here. He hired a new member named Lambu Keyboard in his gang. 
Farzi Coder is so smart (at least that's what he thinks), so he wants to test Lambu Keyboard's programming skills. He gave him this task:
There are n buildings (numbered from left to right) with heights H1, H2...Hn. You can start jumping from any building.
The rules of jumping are:
You can only jump to a building with lesser height than the height of the current building.
In first turn you can jump either way, and 2nd jump will be in the opposite direction of previous jump and must end in between 
current index and previous index, i.e if we start jumping from building 5, initially we can jump in either direction. 
Let's say we jump to building 8, then in next jump we can only jump in left direction and only on buildings with indices 6, 7. 
Let's say we jump to building 6, then next time we can only jump in right direction and between 6 and 8 i.e to 7.
We need to find the maximum number of jumps he can make, considering every building as the starting point.
Input
First line contains an integer n i.e. the number of buildings.

Second line contains n space separated integers denoting heights of buildings from 1 to n.
Output
One line containing n integers, the ith integer will denote the maximum possible number of jumps starting from ith building.
Constraints
1 = n = 5000
1 = H1, H2 ... Hn = 10000
Sample
Input

5
1 3 4 2 5
  
Output

0 1 1 1 2
  
Explanation

If starting building is with height 1 then you can't jump to any other building.

If starting building is with height 3 then you can jump either to building with height 2 on right or with height 1 on left. But there will be at most one jump.

If starting building is with height 5 then one possible optimal sequence is to jump to building with height 3 then to building with height 2. 
So maximum number of jumps is 2.  */
