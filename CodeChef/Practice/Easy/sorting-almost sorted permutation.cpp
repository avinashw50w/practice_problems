/*Given a sequence of n distinct numbers a[1..n], we want to sort them in an ascending order.

An interesting property of some sequences is that all numbers are almost at their correct position! More formally, the distance between the current position of any value is at most 1 from its correct position in a sorted order.

Now, you want to verify whether the input sequence has such a property.

Note that the time limit for this problem is 0.2 seconds. Please try to write a very efficient algorithm and implementation.

Input

The first line contains an integer T denoting the total number of test cases.

For each test case, the first line contains a single integer n, and the second line contains a[1..n] as a single space-separated list.

Output

For each test case, output "YES" or "NO" (without quotes) to indicate whether the input sequence has such a property.

Constraints

1 <= T <= 10
1 <= n <= 10^6
1 <= a[i] <= 10^9
PROBLEM:
Given an array AA, output "YES" if the array is sortable by moving the elements at maximum one index from their respective positions, otherwise 
output "NO".

EXPLANATION:
The given array is indexed from 1 to NN. We maintain an auxiliary array MarkMark which is initially set to 0.

Now, let us consider the first two elements of the array, i.e., A[1] and A[2]. If A[1]≤A[2] then we needn't do anything. 
However, if A[1]>A[2]A[1]>A[2] then we need to swap A[1] and A[2]. If we swap A[1] and A[2], we change Mark[2]Mark[2] from 00 
to 11. Doing so tells us that the element at position 2 wasn't at this position in the original array.

Next we consider elements at positions A[2] and A[3]. If Mark[2]=1Mark[2]=1, this would mean that the element at position 2 actually 
came from position 1. Since it has already been moved from its position, it can't be moved to the further right. This tells us that if Mark[2]=1
Mark[2]=1 and A[2]>A[3], then the array can't be sorted according to the given rules. On the other hand, if A[2]≤A[3], 
then we simply go onto the next pair of elements, i.e., A[3] and A[4]. If Mark[2]=0 and A[2]<A[3], then we swap A[2] and A[3], 
change Mark[3]Mark[3] from 00 to 11 and again proceed to considering the next pair of elements, i.e., A[3] and A[4].*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#ifdef __WIN32__
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif

inline int inp(){register int n=0, c=getchar_unlocked(); while(c<'0' || c>'9') c=getchar_unlocked();
while(c>='0' && c<='9'){n = (n<<3) + (n<<1) + c-48; c=getchar_unlocked();} return n;}

char _str[10];
#define WRITE_INT(_x)	\
{register int _i = 0;int _tmp = (_x);do{*(_str + _i++) = _tmp % 10 + 48;_tmp /= 10;  \
} while (_tmp != 0);for (_i--; _i >= 0; _i--) putchar_unlocked(*(_str + _i));}	     \

typedef long long int ll;

int main() {
	int t=inp();
	int n;
	while(t--){
		n=inp();
		int a[n+1];
		int flag=0;

		rep(i,0,n) {
			a[i]=inp();
			if(i>1){
				if(a[i] < a[i-1] && a[i] < a[i-2]){
					flag = 1;
				}
			}
		}
		(flag)? puts("NO"): puts("YES");
	}
	return 0;
}
