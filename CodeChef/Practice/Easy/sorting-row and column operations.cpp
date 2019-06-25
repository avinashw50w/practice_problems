/*You are given an N × N grid initially filled by zeros. Let the rows and columns of the grid be numbered from 1 to N, inclusive. There are two 
types of operations can be applied to the grid:

RowAdd R X: all numbers in the row R should be increased by X.
ColAdd C X: all numbers in the column C should be increased by X.
Now after performing the sequence of such operations you need to find the maximum element in the grid.

Input

The first line of the input contains two space separated integers N and Q denoting the size of the grid and the number of performed operations 
respectively. Each of the following Q lines describe an operation in the format described above.

Output

Output a single line containing the maximum number at the grid after performing all the operations.

Constraints

1 ≤ N ≤ 314159
1 ≤ Q ≤ 314159
1 ≤ X ≤ 3141
1 ≤ R, C ≤ N*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);++i)

typedef long long int ll;

int main() {
	int n,q;
	string s;
	int i, val;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>q;
	int R[n+1]={}, C[n+1]={};
	while(q--){
		cin>> s >> i >> val;
		if(s == "RowAdd")
			R[i] += val;
		else C[i] += val;
	}
	ll ans = *max_element(R,R+n) + *max_element(C,C+n);
	cout << ans << "\n";
	return 0;
}
