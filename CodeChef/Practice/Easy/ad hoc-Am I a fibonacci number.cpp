/*The Head Chef has been playing with Fibonacci numbers for long . He has learnt several tricks related to Fibonacci numbers . Now he wants to test his chefs in the skills . 

A fibonacci number is defined by the recurrence :

f(n) = f(n-1) + f(n-2) for n > 2 
and f(1) = 0 
and f(2) = 1 . 

Given a number A , determine if it is a fibonacci number.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The only line of each test case contains a single integer A denoting the number to be checked .
Output

For each test case, output a single line containing "YES" if the given number is a fibonacci number , otherwise output a single line containing "NO" .
Constraints

1 = T = 1000
1 = number of digits in A = 1000
The sum of number of digits in A in all test cases <= 10000.*/
#include<stdio.h>
#include<string.h>
    int main()
    {
    	int f[5001],i,t,a;
    	char str[1001];
    	scanf("%d",&t);
    	f[0]=0;
    	f[1]=1;
    	for(i=2;i<=5000;i++)
    	{
    		f[i]=f[i-1]+f[i-2];
    	}
    	while(t--)
    	{
    		scanf("%s",str);
    		a=0;
    		for(i=0;i<strlen(str);i++)
    		{
    		a=a*10+(str[i]-'0');
    		}
    		int flag =0;
    		for(i=0;i<5000;i++)
    		{
    			if(a==f[i])
    			{
    				flag=1;
    				break;
    			}
    		}
    		if(flag)
    		printf("YES\n");
    		else
    		printf("NO\n");
    	}
    	return 0;
    }  
