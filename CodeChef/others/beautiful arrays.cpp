/*An array a is called beautiful if for every pair of numbers ai, aj, (i ≠ j), there exists an ak such that ak = ai * aj. Note that k can be equal to i or j too.

Find out whether the given array a is beautiful or not!

Input
First line of the input contains an integer T denoting the number of test cases. T test cases follow.

First line of each test case contains an integer n denoting number of elements in a.

Next line contains n space separated integers denoting the array a.

Output
For each test case, output a single line containing "yes" or "no" (without quotes) corresponding to the answer of the problem.

Constraints
1 ≤ T ≤ 106
1 ≤ n ≤ 105
Sum of n over all the test cases ≤ 106
-109 ≤ ai ≤ 109
Example
Input
3
2
0 1
2
1 2
2
5 6

Output:
yes
yes
no*/

int main()
{
 
	int test; scanf("%d", &test); 
	while(test--)
	{
		int n; scanf("%d", &n);
		int a; int zeroCnt=0,oneCnt=0,minusOne=0,others=0;
		rep(n) {
			scanf("%d", &n);
			if(a==0) zeroCnt++;
			else if(a==1) oneCnt++;
			else if(a==-1) minusOne++;
			else others++;
		}
		if(others>1) printf("no\n");
		else if(minusOne && others) printf("no\n");
		else if(minusOne>1 && !oneCnt) printf("no\n");
		else printf("yes\n");
		
	}
return 0;
}  