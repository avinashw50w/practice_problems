/*Andrii is good in Math, but not in Programming. He is asking you to solve following problem: Given an integer number N and two sets of 
integer A and B. Let set A contain all numbers from 1 to N and set B contain all numbers from N + 1 to 2N. Multiset C contains all sums a + b 
such that a belongs to A and b belongs to B. Note that multiset may contain several elements with the same values. For example, if N equals to 
three, then A = {1, 2, 3}, B = {4, 5, 6} and C = {5, 6, 6, 7, 7, 7, 8, 8, 9}. Andrii has M queries about multiset C. Every query is defined by 
a single integer q. Andrii wants to know the number of times q is contained in C. For example, number 6 is contained two times, 1 is not 
contained in C at all. 
Please, help Andrii to answer all the queries.

Input

The first line of the input contains two integers N and M. Each of the next M line contains one integer q, the query asked by Andrii.*/
#include <stdio.h>

int main() {
	long long n,m,a, ans;
	scanf("%lld%lld",&n,&m);
	while(m--){
		scanf("%lld",&a);
		if(a < (n+1)) ans = 0;
		else if(a > 2*n) ans = 3*n-a+1;
		else ans = a-n-1;
		printf("%lld\n", ans);
	}
	return 0;
}