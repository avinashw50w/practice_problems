/* In this problem, you are given a string of N characters(1-indexed), and an integer D. You perform multiple operations on this string. 
In the first operation you select the first D characters of the string, ie. the substring S[1...D] and reverse it. 
The other characters remain unchanged. Thus, after the first operation the string changes as shown:



S1S2S3...SD-1SDSD+1...SN-1SN => SDSD-1....S3S2S1SD+1...SN-1SN
The original string is then thrown away, and the new string thus obtained will be used for the subsequent operations.
In the next operation, you select the next D characters, ie the substring S[2...D+1] of the current string and reverse them. 
You continue performing this operation a total 
of N-D+1 times (selecting substring S[i....(i+D-1)] in the i operation.
Your task is to determine the string that will be obtained at the end.
Input

The first line of the input contains a single integer T, the number of test cases.The description of T test cases follows.
Every test case has two lines. The first line contains the string S, and the next line contains the value of integer D for that test case.
Output

For each test case output a single line, containing the value oft the string at the end.
Constraints

1 = T = 10
1 = |S| = 105
1 = D = |S|
 
Example

Input:
1
hello
3

Output:
lloeh
 
Explanation

After the first operation, the string hello becomes lehlo.
After the second operation, the string lehlo becomes llheo.
After the third and final operation, the string llheo becomes lloeh.

Thus the answer is lloeh  */

#include<stdio.h>
#include<math.h>
#include<string.h>
char str[100005];
int main()
{
	int t;
	long n,d,i;
	scanf("%d",&t);
	while(t--)
	{
		
		scanf("%s",str+1);
		n=strlen(str+1);
		scanf("%ld",&d);
		  printf("%s",str+d);
		  if((n-d+1)%2==1)
		{
		for(i=d-1;i>=1;i--)
		  printf("%c",str[i]);
	    }
		else
		{
		for(i=1;i<=d-1;i++)
		  printf("%c",str[i]);
	    } 
		printf("\n");
	}
	return 0;
}
