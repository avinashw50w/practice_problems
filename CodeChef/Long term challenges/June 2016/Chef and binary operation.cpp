/*Today is Chef's birthday. His mom decided to surprise him with a truly fantastic gift: his favourite binary string B. But, unfortunately, all the stocks of binary string B have been sold out, and only a binary string A (A ≠ B) is available in the market.
She purchases the string A and tries to convert it to string B by applying any of following three operations zero or more times.
AND Operation:
She will choose a pair of indices i and j such that i != j and perform following sequence of operations.
result = Ai & Aj

Ai = result & Ai

Aj = result & Aj
OR Operation:
She will choose a pair of indices i and j such that i != j and perform following sequence of operations.
result = Ai | Aj

Ai = result | Ai

Aj = result | Aj
XOR Operation:
She will choose a pair of indices i and j such that i != j and perform following sequence of operations.
result = Ai ^ Aj

Ai = result ^ Ai

Aj = result ^ Aj
Chef's mom is eagerly waiting to surprise him with his favourite gift and therefore, she wants to convert string A to string B as fast as possible. Can you please help her by telling her the minimum number of operations she will require? If it is impossible to do so, then let Chef's mom know about it.
Input

First line of input contains a single integer T denoting the number of test cases. T test cases follow.
First line of each test case, will contain binary string A.
Second line of each test case, will contain binary string B.
Output

For each test case, Print "Lucky Chef" (without quotes) in first line and minimum number of operations required to convert string A to sting B in second line if conversion is possible. Print "Unlucky Chef" (without quotes) in a new line otherwise.
Constraints

1 ≤ T ≤ 105

1 ≤ |A| ≤ 106

1 ≤ |B| ≤ 106

A != B

|A| = |B|

sum of |A| over all test cases does not exceed 106

sum of |B| over all test cases does not exceed 106
Subtasks

Subtask #1 (40 points) : Sum of |A| & |B| over all test cases does not exceed 103

Subtask #2 (60 points) : Sum of |A| & |B| over all test cases does not exceed 106
Example

Input
2
101
010
1111
1010
Output
Lucky Chef
2
Unlucky Chef

Explanation

Example case 1.
Applying XOR operation with indices i = 1 and j = 2. Resulting string will be 011.
Then, Applying AND operation with indices i = 1 and j = 3. Resulting string will be 010.

Example case 2.
It is impossible to convert string A to string B.*/

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string A, B;
	int t;
	cin >> t;
	while(t--) {
		cin >> A >> B;
		if(A == B) { cout << "Lucky Chef\n0\n"; continue; }
		int n = A.size();
		int ones, zeroes, t1, t0;
		ones = zeroes = t1 = t0 = 0;
		rep(i,0,n){
			if(A[i] == '1') t1++;
			else t0++;
			if(A[i] != B[i]){
				if(A[i] == '1') ones++;
				else zeroes++;
			}
		}
		int ans = 0;
		if(ones == zeroes) ans += ones;
		else {
			if(ones > zeroes){
				ans += zeroes;
				ones -= zeroes;
				if(t0 > 0) ans += ones;
				else { cout << "Unlucky Chef\n"; continue; }
			}
			else if(zeroes > ones){
				ans += ones;
				zeroes -= ones;
				if(t1 > 0) ans += zeroes;
				else { cout << "Unlucky Chef\n"; continue; }
			}
		}
		cout << "Lucky Chef\n" << ans << "\n";
	}
	return 0;
}