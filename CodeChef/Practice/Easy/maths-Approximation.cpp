/*Chef has recently learnt some new facts about the famous number π. For example, he was surprised that ordinary fractions are sometimes used to represent this number approximately. For example, 22/7, 355/113 or even 103993/33102.

Soon, by calculating the value of 22/7 and 355/113 on paper Chef became quite disappointed because these values are not precise enough. For example, 22/7 differs in the third digit after the decimal point. So, these values are definitely should not be used for serious calculations.

However, Chef doesn't know anything about 103993/33102. This fraction is quite inconvenient to calculate on paper. Chef is curious how precise this value is. So he asks you to help him and to calculate the first K digits after the decimal point of such an approximation of π. He consider this ordinary fraction as infinite decimal fraction so formally he asks you to calculate this approximation truncated to the first K digits after the decimal point.

Input

The first line of the input contains an integer T, denoting the number of test cases. The description of T test cases follows. The only line of each test case contains a single integer K.

Output

For each test case output a single line containing the value of 103993/33102 truncated to the first K digits after the decimal point. Note that for K = 0 you should output just "3" without decimal point (quotes are for clarity).

Constraints

0 ≤ K ≤ 106
1 ≤ T ≤ 2000
The sum of K over the input does not exceed 106 */
/*EXPLANATION
For the uninitiated, arbitrary precision math is all about doing in code, all that we've been taught to do on paper in elementary. Lets look at how you can divide 103993 with 33102 on paper.

Step 1
       ________
33102 / 103993 \ 3
         99306
       --------
          4687

Step 2
       ________
33102 / 103993 \ 3.1
         99306
       --------
          46870
          33102
         -------
          13768

As you can see, from adding the decimal point onwards, the process is repetitive.

Multiply the remainder by 10.
Find the next digit in the quotient.
Generate the next remainder.*/


int main() {
	int t, k;
	
	t=inp();
	while(t--){
		k=inp();
		if(k==0) { printf("3\n"); continue; }
		else printf("3.");
		int rem = 4687;
		rep(i,0,k){
			rem *= 10;
			printf("%d", rem / 33102);
			rem %= 33102;
		}
		printf("\n");
	}
	return 0;
}
