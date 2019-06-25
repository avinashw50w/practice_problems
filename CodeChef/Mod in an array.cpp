/* You have an array A of size N containing only positive numbers. You have to output the maximum possible value of A[i]%A[j] where 1<=i,j<=N.
Input

The first line of each test case contains a single integer N denoting the size of the array. The next N lines contains integers A1, A2, ..., AN denoting the numbers
 
Output

Output a single integer answering what is asked in the problem.
 
Subtask 1 (20 points)

1 = N = 5000
1 = A[i] = 2*(10^9)
Subtask 2 (80 points)

1 = N = 1000000
1 = A[i] = 2*(10^9)
 
Example

Input:
2
1
2

Output:
1
 
Explanation

There will be four values, A[0]%A[0] = 0, A[0]%A[1]=1, A[1]%A[0]=0, A[1]%A[1]=0, and hence the output will be the maximum among them all, that is 1.*/

#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long

ll a[1000000+10];
int main(){
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	ll last = n-1 , maxx = -(1LL<<60);
	for(int i=n-2;i>=0;i--){
		maxx = max(maxx,a[i]%a[last]);
		maxx = max(maxx,a[last]%a[i]);
	}
	for(int i=0;i<n-1;i++){
		maxx = max(maxx,a[last]%a[i]);
		maxx = max(maxx,a[i]%a[last]);
	}
	cout<<maxx<<endl;
	return 0;
}
