/*Given an array of n non-negative integers: A1, A2, …, AN. Your mission is finding a pair of integers Au, Av (1 ≤ u < v ≤ N) such that (Au and Av) is as 
large as possible.
And is a bit-wise operation which is corresponding to & in C++ and Java.

 

Input

The first line of the input contains a single integer N. The ith line in the next N lines contains the Ai.

 

Output

Contains a single integer which is the largest value of Au and Av where 1 ≤ u < v ≤ N.

 

Constraints

50 points:

2 ≤ N ≤ 5000
0 ≤ Ai ≤ 109
50 points:

2 ≤ N ≤ 3 × 105
0 ≤ Ai ≤ 109 */

/*When we are ANDing two numbers, we would like to have a 1 at the most significant bit(MSB). So, first we'll try to get a 1 at MSB. Now, suppose we denote 
A[i]=b_in,b_in-1...b_i0, where b_i's are the bits that could be 1 or 0.

Let's say S be the set of A[i] whose b_in is 1 and S' be the set of A[i] whose b_in is 0. If size of S ≥ 2 we are sure that our answer will be maximum if we 
chose a pair of numbers from S, because n'th bit of their AND will be 1 for sure. So, we know our answer lies in S.

However, if size of S is less than 2, we can never have n'th bit 1 in our answer. So, we'll have to continue with n'th bit as 0. Note that our answer will now 
be in S'.

Now, we know our answer is in S or S' and we also know n'th bit of our answer. So, our new subproblem is to find (n-1)'th bit of our answer using numbers in 
S or S'. We can write a recursive code for this. What will be the complexity? For each of the n bits, we'll traverse whole array to sort according to their bits. 
So O(n*N). We will be keeping n=30, because A[i] ≤ 109.*/

int main() {

	int n, x;
	vector<int> a[2];

	cin >> n;
	rep(i,0,n){
		cin>>x;
		a[0].push_back(x);
	}
	x = 0;
	per(i, 31, 0) {
		a[x^1].clear();
		for(auto e: a[x])
			if(e & (1<<i))
				a[x^1].push_back(e);

		if(a[x^1].size() < 2) {
			a[x^1].clear();
			for(auto e: a[x])
				a[x^1].push_back(e);
		}

		x ^= 1;
	}

	int ans = a[x][0] & a[x][1];
	cout << ans << "\n";

	return 0;
}
