/*Problem Statement
    	
Let S be a sequence of (not necessarily distinct) integers. We say that S is closed under addition if it has the following property: For any pair of valid and distinct indices i and j, the number S[i]+S[j] does also occur in the sequence S (one or more times).

Note that the numbers S[i] and S[j] may be equal, only the indices i and j are required to be distinct. Also note that from the definition it follows that any 0-element or 1-element sequence is closed under addition, as there are no valid pairs of distinct indices into such a sequence.

You are given a sequence of integers in a int[] elements. Return "closed" (quotes for clarity) if the given sequence is closed under addition. Otherwise, return "not closed".

 
Definition
    	
Class:	SumFullSet
Method:	isSumFullSet
Parameters:	int[]
Returns:	String
Method signature:	String isSumFullSet(int[] elements)
(be sure your method is public)
    
 
Constraints
-	Number of elements in elements will be between 1 and 50, both inclusive.
-	Each element of elements will be between -50 and 50, both inclusive.
 
Examples
0)	
    	
{-1,0,1}
Returns: "closed"
(-1) + 0 = (-1), which does appear in our sequence
(-1) + 1 = 0, which does appear in our sequence
0 + 1 = 1, which does appear in our sequence
hence, our sequence is closed under addition
1)	
    	
{-1,1}
Returns: "not closed"
2)	
    	
{0,1}
Returns: "closed"
*/
/* This was a basic implementation problem. A sequence SS is said to be closed under addition if you select any two distinct indices ii, jj in the sequence, then the corresponding sum S[i]+S[j]S[i]+S[j] should also be present in the sequence SS.

We iterate over each valid pair of indices (i,j(i,j such that i≠j)i≠j) in the sequence SS and check whether S[i]+S[j]S[i]+S[j] lies in the sequence or not. If there exists at least one such pair (i,j)(i,j) where S[i]+S[j]S[i]+S[j] does not lie in SS, then the sequence S is not closed, otherwise it is closed.

Please find below a neat implementation of this approach.
*/
public String isSumFullSet(int[] elements) {
    boolean ok = true;
 
    for (int i = 0; i < elements.length; i++) {
       for (int j = i + 1; j < elements.length; j++) {
           int x = elements[i] + elements[j];
 
           boolean found = false;
           for (int element : elements) {
               if (element == x) {
                   found = true;
               }
           }
 
           if (!found) {
               ok = false;
           }
       }
    }
 
    return ok ? "closed" : "not closed";
}
/*
Observation based faster approach
Let us categorise some important properties of closed under sum sequences.

0 or 1-element sequences are closed by definition.
Sequence SS can not have more than one positive elements.

Proof : Let us take two largest positive elements xx, yy (may be equal too) in SS, then element x+yx+y should also be in SS. But it is not possible, as xx and yy are the two largest element, then x+yx+y will be strictly larger than both xx and yy. 
This leads to contradiction of the fact that xx and yy are the two largest elements of SS.

Similarly, it also can't contain more than one negative elements.
If SS has both negative and positive elements, then magnitude (absolute value) of both of them should be same.

Proof : Assume that there are two numbers x,yx,y in SS, such that x<0,y>0x<0,y>0 and |x|≠|y||x|≠|y|. So, the element x+yx+y is non-zero, which means that it will be either negative or positive. Also note that Note that x+yx+y can not be equal to xx or yy. As this element x+yx+y should lie in SS, but this will violate the previous condition that a closed sequence should have at most one positive/negative elements.

Hence, it means that if a sequence contains both positive and negative elements, then they should be xx and −x-x. Also note that x + -x = 0 should also be present in the sequence SS for it to be closed.

If a sequence SS is closed, then if you add any number of zeros in it, it will still be closed.
If a set does not satisfy the above properties, then it won't be closed.

Please see the following pseudo code for details. */

public String isSumFullSet2(int[] elements) {
    // Check condition 1
    if (elements.length == 1) {
        return "closed";
    }
 
    // Check condition 2
    int countPositives = 0;
    int countNegatives = 0;
 
    for (int x : elements) {
        if (x < 0) {
            countNegatives++;
        }
        if (x > 0) {
            countPositives++;
        }
    }
 
    if (countNegatives > 1 || countPositives > 1) {
        return "not closed";
    }
 
    // Check if the positive and negative elements are same in magnitude or not.
    if (countNegatives == 1 && countPositives == 1) {
        int negativeElement = 0;
        int positiveElement = 0;
        boolean containsZero = false;
         
        for (int x : elements) {
            if (x < 0) {
                negativeElement = x;
            }
            if (x > 0) {
                positiveElement = x;
            }
            if (x == 0) {
                containsZero = true;
            }
        }
 
        if (Math.abs(negativeElement) != Math.abs(positiveElement)) {
            return "not closed";
        }
         
        if (!containsZero) {
            return "not closed";
        }
    }
 
    // Condition 4 will be satisfied implicitly here,
    // because number of non-zero elements at this place could be 0 or 2.
    // Rest all the elements will be zeros.
 
    return "closed";
}