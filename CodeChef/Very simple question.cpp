/* Chef has an array A of N numbers.
His teacher give him two numbers a and b and chef has to find
number of elements in array such that A[i] = a and A[i] = b where 1 = i = n and A[i] denotes the ith element of array.
Input:

The first line of input contains a single integer N denoting the number of elements in the array A.

Second Line contains N space separated Integers.

Third line contains Q ,the number of queries.
each query contains two space separated integer a and b.
Output

For each query output a single Integer giving the output of the problem.

Constraints

1 = N, Q = 100000
1 = a = b = 109
1 = A[i] = 109

Example

Input:
7
2 5 6 7 1 3 4
2
1 7
3 5


Output:
7
3
      */
#include <algorithm>
#include <iostream>
#include <vector>
#define all(x) (x).begin(),(x).end()
using namespace std;

int main(){
	int n;cin>>n;
	int a;
	vector<int> s;
	for(int i=0;i<n;i++) {
		cin>>a;
		s.push_back(a);
	}
	sort(all(s));
	int q; cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		int l = lower_bound(all(s),a) - s.begin();
		int h = upper_bound(all(s),b) - s.begin();
		cout << h-l << endl;
	}
	return 0;
}

