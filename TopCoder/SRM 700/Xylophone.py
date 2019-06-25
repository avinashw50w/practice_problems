'''A xylophone is a musical instrument that consists of a sequence of wooden bars. In order to make a sound, you have to 
strike one of the bars by a mallet.

For the purpose of this problem we will assume that our xylophone has exactly 50 bars. The bars are numbered from 1 to 50 
in the order from the left to the right.

There are 7 notes: A, B, C, D, E, F, G. Each bar of our xylophone plays one of these notes. The notes repeat periodically. 
When you play the bars from the left to the right, you will hear the following sequence of notes: 
A,B,C,D,E,F,G,A,B,C,D,E,F,G,A,B,C,...

In other words: bar 1 produces the note A, bar 2 plays B, bar 3 plays C, ..., bar 7 plays G, and then the sequence of 
notes starts repeating: bar 8 plays the note A again, bar 9 is B, and so on.

You have hit a sequence of bars. You are given their numbers in the int[] keys. Return the number of distinct notes you've hit.

 
Definition
    	
Class:	Xylophone
Method:	countKeys
Parameters:	int[]
Returns:	int
Method signature:	int countKeys(int[] keys)
(be sure your method is public)
    
 
Constraints
-	keys will contain between 1 and 50 elements, inclusive.
-	Each element of keys will be between 1 and 50, inclusive.'''

class Xylophone():
	def countKeys(self, keys):
		return len(set(x % 7 for x in keys))