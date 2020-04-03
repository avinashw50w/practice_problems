#include<iostream>
#include <sstream>
using namespace std;
#define MAX 100001
#define ll long long
int main(){
	int a[MAX]={};
	for(int i=1;i<MAX;i++){
		if(i<10) a[i] = 1;
		else if(i<100){
			if(i%11 == 0) a[i] = 1;
		}
		else if(i<1000){
			if(i%10 == i/100) a[i] = 1;
		}
		else if(i<10000){
			if((i%10 == i/1000) && ((i%100)/10 == (i/100)%10)) a[i] = 1;
		}
		else{
			if((i%10 == i/10000) && ((i%100)/10 == (i/1000)%10)) a[i] = 1;
		}
	}
	int t;cin>>t;
	while(t--){
		int l,r; cin>>l>>r;
		ll sum = 0;
		for(int i=l;i<=r;i++){
			if(a[i]) sum += i;
		}
		cout<< sum <<endl;
	}
	return 0;
}

/* A number is called palindromic if its decimal representation is a palindrome. You are given a range, described by a pair of integers L and R. 
Find the sum of all palindromic numbers lying in the range [L, R], inclusive of both the extrema.
Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a pair of space separated integers L and R denoting the range for which you are required to find the sum of the palindromic numbers.
Output

For each test case, output a single line containing the sum of all the palindromic numbers in the given range.
Constraints

1 = T = 100
Subtask 1 (34 points) : 1 = L = R = 103
Subtask 2 (66 points) : 1 = L = R = 105*/
