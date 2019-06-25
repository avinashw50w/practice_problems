/*Alvin has A apple candies, and Berto has B banana candies. (I know, they have weird tastes.) 
Alvin and Berto always wants the split of candies to be as fair as possible. 
The problem is, Alvin only wants apple candies and Berto only wants banana candies!

Here comes Chef to the rescue! Chef bought an infinite number of candy packs. There are two types of packs:

Packs containing exactly C apple candies.
Packs containing exactly D banana candies.
Chef wants to give some (could be zero) apple candy packs to Alvin and some (could be zero) banana candy packs 
to Berto in such a way that the absolute difference between the number of candies they have is minimized. 
What is this minimum absolute difference?

Note that Chef doesn't want to open any pack; he gives each pack in full.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

Each test case consists of a single line containing four integers A, B, C, and D separated by single spaces.

Output
For each test case, output a single line containing a single integer, 
the minimum absolute difference between the number of candies they can have.

Constraints
1 ≤ T ≤ 104
1 ≤ A, B, C, D ≤ 1014
Example
Input:
2
1 5 10 3
1 2 2 2

Output:
0
1*/

/*to find the min value of |(A + xC) - (B + yD)|
=> |(A-B) + (xC-yD)|, here xC - yD is a linear diphantine equation. 
So xC - yD is a multiple of gcd(C, D). */

#include <bits/stdc++.h>
using namespace std;

typedef long long Int;

int main() {
	Int T, A, B, C, D;
	Int R, R1;
	cin >> T;

	while(T--) {
		cin >> A >> B >> C >> D;

		Int P = __gcd(C, D);

		R = abs(A-B) % P;
		R1 = P - R;

		cout << min(R, R1) << endl;
	}
}