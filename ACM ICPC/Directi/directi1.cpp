/*A ternary string consists of only a, b, c following the given 3 rules 
1. a's cannot be consecutive. 
2.b can appear only once. 

Find the nuber of possible ternary string of length n.*/

/*
Reasoning: 
Case 1 : can append "c" to any n-1 length sequence to make an n length sequence. 
Case 2 : can append "b" to any n-1 length sequence that has no b in it already. 
Case 3 : can append "ca" to any n-2 length sequence 
Case 4 : can append "ba" to any n-2 length sequence that has no b in it already. 

Logic used is similar but put into a more compact recursive relation:
C(n) = C(n-1) + C(n-2) + F(n-1) + F(n-2)
where C(n) is computed for the case 1 and 3 , and
F(n) is especially for the case 2 and case 4   

C(n) has base cases C(1) = 3, C(2) = 7. 

This "has no b in it already" is a sequence consisting of only "a" and "c" 
So we have to form another recurrence relation for the string containing only a's and c's

Now, to form a string of length n :
case 1: "c" can be appended to any n-1 length sequence
case 2: "a" can be appended to n-1 length sequence whose last charcter is c,
		ie, we can append ca to any n-2 length sequence
therefore :
F(n) = F(n-1) + F(n-2)

base cases : F(0) = no of ways to form a string of len 0 with only a and c  = 1 (no string at all)
			 F(1) = no of ways to form a string of len 1 with only a and c = 2 ( a or c )
			 
which is very easily found with relation f(n) = f(n-1) + f(n-2) which has an offset of 2 from the Fibonacci sequence.*/
