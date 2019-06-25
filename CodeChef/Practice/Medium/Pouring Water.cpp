/*Given two vessels, one of which can accommodate a liters of water and the other which can accommodate b liters of water, 
determine the number of steps required to obtain exactly c liters of water in one of the vessels.

At the beginning both vessels are empty. The following operations are counted as 'steps':

emptying a vessel,
filling a vessel,
pouring water from one vessel to the other, without spilling, until one of the vessels is either full or empty.
Input
An integer t, 1<=t<=100, denoting the number of test cases, followed by t sets of input data, each consisting of 
three positive integers a (the number of liters the first container can hold), 
b (the number of liters the second container can hold), 
and c (the final amount of liters of water one vessel should contain), not larger than 40000, given in separate lines.

Output
For each set of input data, output the minimum number of steps required to obtain c liters, or -1 if this is impossible.*/

#include <bits/stdc++.h>
using namespace std;

int solve(int A, int B, int C) {
	int a = 0, b = 0;
	int sum, count = 0;

	while(a != C and b != C) {
		if(a == 0) a = A;
		else if(b == B) b = 0;
		else {
			sum = a+b;
			b = min(B, sum);
			a = sum - b;
		}
		count++;

		if(a == 0 and b == 0)
			return -1;
	}
	return count;
}

int main() {
	int t; cin >> t;

	int A, B, C;

	while(t--) {
		cin >> A >> B >> C;

		if(A > C and B > C) {
			cout << -1 << endl;
			return 0;
		}

		if(A == C or B == C) {
			cout << 0 << endl;
			return 0;
		}

		if(C % __gcd(A, B) != 0) {
			cout << -1 << endl;
			return 0;
		}

		int cnt1 = solve(A, B, C);
		int cnt2 = solve(B, A, C);

		cout << min(cnt1, cnt2) << endl;
	}
}