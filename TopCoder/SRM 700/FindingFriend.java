/*	
Your friend just took part in a popular online programming contest. The participants were split across roomCount rooms, 
with each room containing exactly roomSize contestants. We will use n = roomCount * roomSize to denote the total number of contestants.

The contest was such that there were no ties. After the contest, each contestant had a distinct rank between 1 and n, 
inclusive. (The contestant with rank 1 is the winner.)

A room winner is the contestant with the best (i.e., smallest) rank in their room.

You do not know the final standings. The only thing you know are the ranks of all room winners. More precisely, 
you are given a int[] leaders with roomCount elements. The i-th element of leaders denotes the rank of the room winner 
of the i-th room.

Your friend just told you that her rank in this contest was friendPlace.

Return the number of different rooms in which your friend could have competed, given the information you have.

 
Definition
    	
Class:	FindingFriend
Method:	find
Parameters:	int, int[], int
Returns:	int
Method signature:	int find(int roomSize, int[] leaders, int friendPlace)
(be sure your method is public)
    
 
Notes
-The value of n is not explicitly given in the arguments, but can be computed as roomSize times the number of elements in leaders.
Examples
0)	
    	
2
{5,1,2}
4
Returns: 2
We have 6 contestants: 3 rooms with 2 contestants in each of them. Your friend finished 4-th. Given the information you have, there are only two possible distributions of contestant ranks into rooms:
Room 1: ranks 5 and 6. Room 2: ranks 1 and 3. Room 3: ranks 2 and 4.
Room 1: ranks 5 and 6. Room 2: ranks 1 and 4. Room 3: ranks 2 and 3.
Your friend has competed either in room 2 or in room 3. There are two possible rooms, so the correct return value is 2.
1)	
    	
5
{1,2,3,4,5}
4
Returns: 1
You know for sure your friend is in room 4, as she is its room winner. */

/*An obvious condition is that if your friend is a room winner, you return 1. Another obvious condition is that your friend 
can only be in rooms where the room winner has a lower rank than friendPlace. What other conditions do we need?

First, let's sort the rooms by leaders. For example, the first sample would be {1,2,5}, with 2 people in each room. 
Now, let's look at the person who placed 6th. They can't possibly go in the first two rooms, since that would force 
someone with place less than 5 to go into the last room, which would make 5 not the leader. So, the idea is that places 1-4 
must be in the first 2 rooms. We can note that if the room winner of the i-th room is roomSize * i + 1, then everyone from 
place 1 to roomSize*i must be in the first i-1 rooms. So, we can come up with the solution below.*/

import java.util.Arrays;
import java.util.HashSet;
 
public class FindingFriend {
  public int find(int roomSize, int[] leaders, int friendPlace) {
    for (int i = 0; i < leaders.length; i++) {
      if (leaders[i] == friendPlace) return 1;
    }
    Arrays.sort(leaders);
    int count = 0;
    for (int i = 0; i < leaders.length; i++) {
      if (leaders[i] > friendPlace) break;
      if (leaders[i] == roomSize * i + 1)
        count = 0;
      count++;
    }
    return count;
  }
}
