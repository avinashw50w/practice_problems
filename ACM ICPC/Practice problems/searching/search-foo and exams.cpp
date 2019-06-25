/*Foo was not amongst the most brilliant students of his class. So, he has some pending exams to clear. As the exams are approaching, this time he vowed 
to pass in all of them. This will only happen if he is not under stress. Foo's stress can be calculated using a simple function called Foo_function which 
depends upon the time for which Foo studies continuously .

Foo_funtion is defined as follows:

F(t)=A(t^3)+B(t^2)+C*(t)+D, F(t)<=10^18

where A,B,C,D belong to the set of prime numbers. t is the time in minutes for which foo studies continuously.

As foo is not very good at solving cubic equations, he seeks your help to find out the maximum number of minutes for which he can study continuously without 
taking stress. Help him find t such that F(t+1) > K, and F(t) <= K, where K is the maximum stress Foo can bear.

Input:

The first line of the input contains a single integer T denoting the number of test cases. each test case consists of a single line containing 5 space 
seperated positive numbers a, b, c, d, K.

Output:

for each test case, output a single integer t denoting the maximum time for which foo can study continuously without taking stress.

Constraints:

1 <= T <= 10^4 
A, B, C, D belong to a set of prime numbers such that F(t) would never exceed 10^18
t >= 0 
1 <= K <= 10^18*/
#include <iostream>
#include <algorithm>
using namespace std;

typedef uint64_t ull;

long long a,b,c,d,k;

ull F(int x) { return (a*x*x*x + b*x*x + c*x + d); }

int Bsearch() {
	int l=0, r=1000000;
	while(l<=r) {
		int mid = (l+r)>>1;
		ull temp = F(mid);
		if(temp <= k && (mid == r || F(mid+1) > k)) return mid;

		if(temp < k) l = mid+1;
		else if(temp > k) r = mid-1;
	}
}

int main() {
	int t; cin>>t;
	while(t--) {
		cin>>a>>b>>c>>d>>k;

		int ans = Bsearch();

		cout<<ans<<endl;
	}
}