/*Correct bracket sequences can be defined recursively as follows:

The empty string "" is a correct sequence.
If "X" and "Y" are correct sequences, then "XY" (the concatenation of X and Y) is a correct sequence.
If "X" is a correct sequence, then "(X)" and "[X]" are also correct sequences.
Each correct bracket sequence can be derived using the above rules.
Examples of correct bracket sequences include "", "()", "()[][]", "([]())", and "([[()]])".

You are given a String s that only contains the characters '(', ')', '[', and ']'. We want to erase some subset of characters of s (possibly none of them, but not all of them). Moreover, we want to do it in such a way that the resulting string will be a correct non-empty bracket sequence. Compute and return the number of ways in which this can be done.

 
Definition
    	
Class:	BracketSequenceDiv1
Method:	count
Parameters:	String
Returns:	long
Method signature:	long count(String s)
(be sure your method is public)
    
 
Constraints
-	s will contain between 1 and 40 characters, inclusive.
-	Each character in s will be one of '(', ')', '[', ']'.
 
Examples
0)	
    	
"()[]"
Returns: 3
There are 3 valid ways to erase some characters and obtain a correct non-empty bracket sequence:
Erase nothing and obtain "()[]".
Erase the first two characters and obtain "[]".
Erase the last two characters and obtain "()". 

Imagine the string starts with "(" or "[", then we can count the number of strings in which the first character is not removed. Since the 
string must be a valid bracket sequence, the opening bracket at the start needs to have a corresponding closing bracket. So we search for 
all positions ii such that s[i]s[i] is "]" or ")" (The one that corresponds to the starting character). We count the number of strings in 
which character 0 and ii are matched as brackets. The characters between 1 and i−1i-1, inclusive must all be removed in a way so that they 
generate a valid bracket string, because we want s[i]s[i] to close 0. The same happens with the characters between ii and n−1n-1, inclusive, 
they must be removed in a way that the result is a valid bracket string. Note how we reached smaller versions of the problem.

So we define a function f(a,b)f(a,b) that will tell us the number of ways to remove characters in the substring [a,b)[a,b) (that is the 
substring that is formed by all characters with indices greater than or equal to aa and smaller than bb. There are two options:

s[a]s[a] is removed, so the number of ways to remove the remaining characters in [a,b)[a,b) is: f(a+1,b)f(a+1,b) (so we ignore aa).
s[a]s[a] is not removed, which means it must be an opening bracket "(" or "[". So any character s[i]s[i] with a<i<ba<i<b can be the 
corresponding closing bracket (as long as it is equal to ")" or "]" depending on the value of s[a]s[a]). The string generated between aa 
and ii must also be a proper bracket sequence found after removing chracters from substring [a+1,i)[a+1,i), so there are f(a+1,i)f(a+1,i)
 ways to do that. In addition, the characters after ii must also make a proper bracket string, so we count the number of ways to remove 
 characters in [i+1,b)[i+1,b) to form valid bracket strings: f(i+1,b)f(i+1,b). In total, there are f(a+1,i)×f(i+1,b)f(a+1,i)×f(i+1,b) 
 ways to do this, and this is for every valid ii. The addition of all these results plus f(a+1,b)f(a+1,b) is the result for f(a,b)f(a,b).
As a base case, when a=ba=b, the substring is empty and already a valid bracket sequence so f(a,a)=1f(a,a)=1.

The solution is f(0,n)f(0,n), where nn is the length of ss. Note that this means that the empty string is a valid result but the problem 
statement forbids that. So just subtract 1 from f(0,n)f(0,n) to find the wanted result. We can implement f(a,b)f(a,b) through dynamic 
programming or memoization.*/

long mem[41][41];
 
string s;
 
long f(int a, int b)
{
    long & res = mem[a][b];
    if (res == -1) {
        if (a == b) {
            res = 1;
        } else {
            res = 0;
            // include s[a]
            char opos = '\0';
            if (s[a] == '(') {
                opos = ')';
            } else if (s[a] == '[') {
                opos = ']';
            }
            if (opos != '\0') {
                for (int i = a + 1; i < b; i++) {
                    if ( s[i] == opos ) {
                        res += f(a + 1, i) * f(i + 1, b);
                    }
                }
            }
            // dont include s[a]
            res += f(a + 1, b);
        }
    }
    return res;
}