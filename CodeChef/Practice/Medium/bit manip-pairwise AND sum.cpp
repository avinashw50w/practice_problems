/*You are given a sequence of N integer numbers A. Calculate the sum of Ai AND Aj for all the pairs (i, j) where i < j.

The AND operation is the Bitwise AND operation, defined as in here.

Input

The first line of input consists of the integer N. 

The second line contains N integer numbers - the sequence A.

Output

Output the answer to the problem on the first line of the output.

Example

Input:
5
1 2 3 4 5

Output:
9

Scoring

Subtask 1 (13 points): N <= 1000, Ai <= 1. 

Subtask 2 (39 points): N <= 1000, Ai <= 109. 

Subtask 3 (21 points): N <= 105, Ai <= 1. 

Subtask 4 (27 points): N <= 105, Ai <= 106. */

/*Solution to the sub tasks 1 and 3:
If you take a look at the AND function for all possible pairs of numbers in the sequence - 0,0; 0,1; 1,0; 1,1 - you will notice that AND equals to one only in 
case both arguments equal to one, otherwise it equals to zero and will not change the answer in any way. Thus, you just have to calculate the number of pairs 
(i, j) where i < j and both the i-th and the j-th numbers equal to one. Naturally, the answer equals to o * (o - 1) / 2, where o is the number of ones in the 
sequence.

Solution to the sub task 2:
In this sub task the constraints are designed in such a way that you can just do the brute force among all the pairs (i, j) where i < j and add the value of the 
i-th number AND the j-th number to the answer. That will do.

Solution to all the sub tasks:
Let's use the observation that we had in sub task 3, AND of two binary values is a natural number only in case both of them are true. Another observation is that 
in some exact bit of the result, AND depends only on this bit in its arguments. That gives rise to the following solution: let's solve the problem bit-by-bit. 
At first, let's count the number of nonzero 0-th bits - we will call this number f(0). Then, there are f(0) * (f(0)-1)/2 ways to add 2^0 to the answer. 
Generally, there will be f(i)*(f(i)-1)/2 ways to add 2^i to the answer, where f(i) is the number of numbers in the sequence that contain 2^i in their binary 
representation. Therefore, the final formula is the sum of f(i) * f(i-1)/2 * 2^i over all possible values of i. The maximal possible value of i equals to 29 here, 
as it is a binary logarithm of maximal possible value in the sequence.*/


int main() {
	#if 0
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	BOOST;
	int n; cin>>n;
	int a;
	ll f[32]={};
	rep(i,0,n) {
		cin>>a;
		for(int k=0; a>0; a>>=1, k++) {
			if(a & 1) f[k]++;
		}
	}
	ll ans = 0, two = 1;
	rep(i,0,32) {
		ans += ((f[i] * (f[i]-1))>>1) * two;
		two <<= 1;
	}

	cout << ans << "\n";
	return 0;
}
