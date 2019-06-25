/*1. Consider a N-bit integer A. We call an integer A' as shuffle-A, if A' can be obtained by shuffling the bits of A in its binary representation. 
For eg. if N = 5 and 
A = 6 = (00110)2, A' can be any 5-bit integer having exactly two 1s in it i.e., any of (00011)2, (00101)2, (00110)2, (01010)2, ...., (11000)2.

2. Given two N-bit integers A and B, find the maximum possible value of (A' xor B') where A' is a shuffle-A, B' is a shuffle-B and xor is the bit-wise xor operator.

Given N, A and B, please help Po in opening the dragon scroll.
Input

First line contains an integer T ( number of test cases, around 100 ). T cases follow, each having N A B in a single line, separated by a space. ( 1 <= N <= 30, 0 <= A,B < 2N )
Output

For each case, output the maximum possible value of (shuffle-A xor shuffle-B) in a separate line.
Example

Input:
3
3 5 4
5 0 1
4 3 7


Output:
7
16
14
*/
int main() {
	int t, n, a, b;
	t=inp();
	while(t--){
		n=inp();
		a=inp();
		b=inp();
		int cnta = __builtin_popcount(a);
		int cntb = __builtin_popcount(b);
		int m = cnta+cntb;
		m = min(m, n);
		int ans = 0;
		for(int i=n-1;i>=n-m;--i) ans ^= (1<<i);
		printf("%d\n",ans);
	}
	return 0;
}
