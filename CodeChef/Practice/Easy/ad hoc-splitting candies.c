/*Cyael is a teacher at a very famous school in Byteland and she is known by her students for being very polite to them and also to encourage them to get good marks on their tests.
Then, if they get good marks she will reward them with candies :) However, she knows they are all very good at Mathematics, so she decided to split the candies evenly to all the 
students she considers worth of receiving them, so they don't fight with each other.
She has a bag which initially contains N candies and she intends to split the candies evenly to K students. To do this she will proceed as follows: while she has more than K 
candies she will give exactly 1 candy to each student until she has less than K candies. On this situation, as she can't split candies equally among all students she will keep the 
remaining candies to herself.
Your job is to tell how many candies will each student and the teacher
receive after the splitting is performed.
Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case will consist of 2 space separated integers, N and K denoting the number of candies and the number of students as described above.
Output

For each test case, output a single line containing two space separated integers, the first one being the number of candies each student will get, followed by the number of 
candies the teacher will get.
Constraints

T<=100 in each test file
0 <= N,K <= 233 - 1  

*** take care of cases when n or k or both is 0 ****/
#include <stdio.h>
#define ll long long int
int main(){
	int t; scanf("%d",&t);
	ll n,k;
	while(t--){
		scanf("%lld%lld",&n,&k);

		if(k==0 && n==0) { printf("0 0\n"); 		continue; }
		if(k==0 && n!=0) { printf("0 %lld\n",n); 	continue; }
		if(k!=0 && n==0) { printf("0 0\n"); 		continue; }
		
		printf("%lld %lld\n",n/k, n%k);
	}
	return 0;
}
