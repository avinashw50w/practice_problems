/*You are given n cubes in a certain order, and your task is to build towers using them.
Whenever two cubes are one on top of the other, the upper cube must be smaller than the lower cube.

You must process the cubes in the given order. You can always either place the cube on top of
an existing tower, or begin a new tower. What is the minimum possible number of towers?

Input

The first input line contains an integer n: the number of cubes.

The next line contains n integers k1,k2,…,kn: the sizes of the cubes.

Output

Print one integer: the minimum number of towers.

Constraints
1≤n≤2⋅105
1≤ki≤109
Example

Input:
5
3 8 2 1 5

Output:
2
here 3,2,1 and 8,5 are the two possible such towers.

IDEA: answer is the longest non-decreasing subsequence. it works because each
element of the subsequence can be used as the base of each tower.
eg. if the subsequence is a b c, then all the elements btw a and b will be less
than a and b which can be used to form a tower with base as 'a'.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		int pos = upper_bound(v.begin(), v.end(), a) - v.begin();

		if (pos < v.size()) {
			v[pos] = a;
		}
		else v.push_back(a);
	}
	cout << v.size() << "\n";
}