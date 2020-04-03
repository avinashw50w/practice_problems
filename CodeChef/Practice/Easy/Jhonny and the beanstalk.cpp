/*You must know that beanstalks in Byteland grow in a very special way. At the lowest (1st) level, there is exactly one stem. At any level(including the 1st), a stem can end (forming exactly one leaf), or branch into exactly two stems which grow into the next level, following the same rules.

Johnny believes he has managed to count the number of leaves at each of the levels of the beanstalk. However, you must know that before he began to count, Johnny ate one or two of the other beans he found in his grandfather's shed, and that's why he is not quite sure of his results. Please verify whether Johnny's results may possibly be correct, at least in theory.

Input

The input starts with a line containing integer t, the number of test cases (1<= t <= 20). The descriptions of exactly t test cases follow.

Each test case starts with an integer k, representing the number of levels of the beanstalk (1<= k<=106). The next k non-negative space-separated integers (not greater than 106) represent the number of leaves of the beanstalk at successive levels, starting from level 1.

Output

For each test case, output a line containing exactly one of the words 'Yes' or 'No', depending on whether a beanstalk having the stated leaf counts can grow in accordance with the Bytelandian rules.

Example

Input:
2
3
0 1 2
3
0 0 3

Output:
Yes
No*/

int main() {
	int n,i,stem,leaves;
	caset{
		si(n);		
		stem = 1;
		for(i=1; i<= n-1; ++i){
			si(leaves);
			if(leaves > stem) break;
			stem -= leaves;
			stem *= 2;
		}
		si(leaves);
		(i == n and leaves == stem) ? puts("Yes") : puts("No");
	}
	return 0;
}
