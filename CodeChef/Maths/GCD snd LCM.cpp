/* Two integers A and B are the inputs. Write a program to find GCD and LCM of A and B.
Input

The first line contains an integer T, total number of testcases. Then follow T lines, each line contains an integer A and B.
Output

Display the GCD and LCM of A and B separated by space respectively.
Constraints

1 ≤ T ≤ 1000
1 ≤ A,B ≤ 1000000  */

#include <stdio.h>
 
int main(void) {
	// your code goes here
	int t;
	int a, b, m, n;
	scanf ("%d", &t);
	
	while (t--) {
	    scanf ("%d %d", &a, &b);
	    m = a;
	    n = b;
	    
	    while (n) {
	        m = m % n;
	        m ^= n ^= m ^= n;
	    }
	    
	    printf ("%d %d\n", m, (a * b) / m);
	}
	return 0;
} 