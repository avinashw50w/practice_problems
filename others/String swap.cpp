/*In this problem, you are given a string of N characters(1-indexed), and an integer D. You perform multiple operations 
on this string. In the first operation you select the first D characters of the string, ie. the substring S[1...D] and reverse it. 
The other characters remain unchanged. Thus, after the first operation the string changes as shown:



S1S2S3...SD-1SDSD+1...SN-1SN => SDSD-1....S3S2S1SD+1...SN-1SN

The original string is then thrown away, and the new string thus obtained will be used for the subsequent operations.

In the next operation, you select the next D characters, ie the substring S[2...D+1] of the current string and reverse them. 
You continue performing this operation a total of N-D+1 times (selecting substring S[i....(i+D-1)] in the i operation.

Your task is to determine the string that will be obtained at the end.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	string S; cin >> S;

	int N = S.size();

	int D; cin >> D;

	cout << S.substr(D-1);
	string s1 = S.substr(0, D-1);

	if((N-D+1) % 2 == 0) cout << s1;
	else {
		reverse(s1.begin(), s1.end());
		cout << s1;
	}

	cout << endl;
}