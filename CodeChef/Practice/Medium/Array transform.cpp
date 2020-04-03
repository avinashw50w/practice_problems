/*Given n numbers, you can perform the following operation any number of times : Choose any subset of the numbers (possibly empty), 
none of which are 0. Decrement the numbers in the subset by 1, and increment the numbers not in the subset by K.

Is it possible to perform operations such that exactly n - 1 numbers become 0 ?

Input :

The first line contains the number of test cases T. 2*T lines follow, 2 for each case. 
The first line of a test case contains the numbers n and K. The next line contains n numbers, a_1...a_n.

Output :

Output T lines, one corresponding to each test case. 
For a test case, output "YES" if there is a sequence of operations as described, and "NO" otherwise.

Sample Input :
3
2 1
10 10
3 2
1 2 2
3 2
1 2 3

Sample Output :
YES
YES
NO*/

/*explanation: Lets suppose n-1 numbers are equal, then we can keep decementing all those n-1 numbers,
and keep incrementing the remaining one number by k until all the n-1 numebers become 0. 
So, if we can make atleast n-1 nos equal using this operations, then we are done.
So we need to check if its possible or not.
We can observe that the relative increment is equal to k+1(if the decrement operation is kept fixed).
Now keep the modulo of all the numbers by (k+1) in an array.
3 cases arise :
1. if the no of distinct modulo is 1, then print YES 
2. if the no of distinct modulo is 2, then 
   - if the frequency of one those distinct modulo is 1 then print YES otherwise NO 
3. if the no of distinct modulo is < 2 then print NO*/

/*New thing learned: if we want to check if we can make all the numbers of a given set equal, by using the following operation
1. increment one set of numbers by x and decement the remaining numbers by y
then check whether the modulo of all the numbers in the set by (x+y) are equal or not,
if they are all equal, ie, there is only one distinct modulo then it is possible, 
otherwise it is impossible to make all the numbers in the set equal */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, x;

	int t; cin >> t;

	while(t--)
	{
		int f[15] = {}, b[15] = {}, cnt = 0;

		cin >> n >> k;

		for(int i = 0; i < n; ++i) {
			cin >> x;
			x = x % (k+1);

			if(!f[x]) f[x]++, b[cnt++] = x;
			else f[x]++;
		}

		if(cnt > 2) 
			cout << "NO\n";
		else if(cnt == 1 or (cnt == 2 and (f[b[0]] == 1 or f[b[1]] == 1)))
			cout << "YES\n";
		else 
			cout << "NO\n";
	}
}