/*Chef recently learned about the classic Longest Increasing Subsequence problem. However, Chef found out that while the length of the longest 
increasing subsequence is unique, the longest increasing subsequence itself is not necessarily unique; for example, in the array [1, 3, 2, 4], 
there are two longest increasing subsequences: [1, 3, 4] and [1, 2, 4].
Chef decided to investigate on this more, and now he has sufficient mastery in it that he was able to come up with a problem:
Given an integer K, output an integer N and a permutation of the array [1, 2, ..., N] such that there are exactly K longest increasing 
subsequences. Chef also requires that 1 ≤ N ≤ 100, otherwise he found the problem is too easy.
In case there are multiple possible answers, any one will be accepted.
Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case consists of a single line containing a single integer K.
Output

For each test case, output two lines. The first line contains a single integer, N. The second line contains N space separated integers 
denoting the permutation of [1,2,...,N].
Constraints

1 ≤ T ≤ 2×104
1 ≤ K ≤ 105
Example

Input:
2
1
2

Output:
5
1 2 3 4 5
4
1 3 2 4
Explanation

Example case 1. Here, K = 1. The array [1, 2, 3, 4, 5] indeed contains exactly one longest increasing subsequence: the whole sequence itself.
Example case 2. Here, K = 2. As explained in the problem statement, the array [1, 3, 2, 4] contains exactly two longest increasing subsequences:
 [1, 3, 4] and [1, 2, 4].*/

#include <bits/stdc++.h>
using namespace std;
int k;
 
void solve()
{
	cin >> k;
	int high = 1000;
	vector<int> vec;
	vector<int> values;
	int low = 0;
	int acc = 1;
	for(int i = 20; i >= 0; --i) {
		vec.push_back(high + 1);
		vec.push_back(high);
		high += 2;
		acc ++;
		if (k >> i & 1) {
			for( ; acc; ) {
				acc --;
				vec.push_back(low);
				low ++;
			}
		}
	}
	int n = vec.size();
	values = vec;
	sort(values.begin(), values.end());
	printf("%d\n", n);
	for(int i = 0; i < n; ++ i) {
		if (i) putchar(' ');
		printf("%d", (int)(lower_bound(values.begin(), values.end(), vec[i]) - values.begin()) + 1);
	}
	printf("\n");
}
 
int main()
{
	int t;
	for(cin >> t; t --; ) solve();
	return 0;
}

/*The array [N,N−1,N−2,…,1][N,N−1,N−2,…,1] has exactly NN LISes. (But you can't simply use this because K≫NK≫N.)
Given two arrays AA and BB that have XX and YY LISes respectively, you can form an array with X⋅YX⋅Y LISes by adding |A||A| to each element of BB and appending them.
Given two arrays AA and BB that have XX and YY LISes respectively, you can form an array with X+YX+Y LISes by adding |B||B| to each element of AA and appending them. This only works if the LIS length is the same in AA and BB. If not, you can always increase the LIS length without changing the LIS count of any array AA by appending |A|+1|A|+1 at the end.

Using these, simply express KK in ternary:
K=a0+3⋅(a1+3⋅(a2+3⋅(a3+…)))
K=a0+3⋅(a1+3⋅(a2+3⋅(a3+…)))
And then apply the principles above to construct a short array with exactly KK LISes. For K≤105K≤105, you'll need a length of at most N=94N=94.

EXPLANATION:
Like many construction-based problems, this one admits many solutions. This editorial will focus on the author's solution. Feel free to describe yours!

We'll use the following notation and terms to simplify things:

For an array AA, let |A||A| be its length.
For an array AA, let ALISALIS be the length of the longest increasing subsequence in AA. We'll also call it the LIS length of AA.
For an array AA, let A#A# be the number of longest increasing subsequences in AA. We'll also call it the LIS count of AA.
Setter's solution
For small KK, a simple solution exists: [N,N−1,N−2,…,3,2,1][N,N−1,N−2,…,3,2,1]. This array has a LIS length of 11 and a LIS count of NN. So if we choose N:=KN:=K, then we have an answer! Unfortunately, due to problem restrictions, this will only work for K≤100K≤100.

In the other extreme, the array [1,2,3,…,N−2,N−1,N][1,2,3,…,N−2,N−1,N] has a LIS length of NN and a LIS count of 11, though this also doesn't help much.

LIS-product of arrays
An interesting thing happens in the array [3,2,1,7,6,5,4][3,2,1,7,6,5,4]. The LIS length of this array is 22. What is its LIS count? There are 33 ways to select the first number ([3,2,1][3,2,1]) and 44 ways to select the second number ([7,6,5,4][7,6,5,4]), so there are 3⋅4=123⋅4=12 ways to form an increasing subsequence of length 22, so the LIS count is 1212.

Notice that we just constructed an array whose LIS count is greater than its length! More generally, [X,X−1,…,2,1,X+Y,X+Y−1,…,X+2,X+1][X,X−1,…,2,1,X+Y,X+Y−1,…,X+2,X+1] has length X+YX+Y but a LIS count of X⋅YX⋅Y. And for XX and YY greater than one, X⋅YX⋅Y is always ≥X+Y≥X+Y. This lets us answer more KKs beyond 100100!

Unfortunately, this solution is only good for K≤50⋅50K≤50⋅50 (the largest product you can get), and even then, there are some KKs which are still unachievable, in particular, prime KKs.

We can extend the above observation even more: Let AA and BB be two arrays with lengths mm and nn, respectively. Consider the following array: [A1,A2,…,Am−1,Am,m+B1,m+B2,…,m+Bn−1,m+Bn][A1,A2,…,Am−1,Am,m+B1,m+B2,…,m+Bn−1,m+Bn]. Notice that in this array, the last nn elements are larger than the first mm elements! Thus, to form a longest increasing subsequence, we can construct the longest increasing subsequences in the first mm and last nn individually, and then combine them. Thus, this array has the following properties:

It has length m+nm+n
Its LIS length is the sum of the LIS lengths of AA and BB; in other words, ALIS+BLISALIS+BLIS.
Its LIS count is the product of the LIS counts of AA and BB; in other words, A#⋅B#A#⋅B#.
This is pretty useful because it allows us to chain multiplications together! For example, we can form an array for every KK that's a power of 22, e.g. for K=211K=211 by performing the operation above repeatedly for [2,1][2,1]:
[2,1,4,3,6,5,8,7,10,9,12,11,14,13,16,15,18,17,20,19,22,21]
[2,1,4,3,6,5,8,7,10,9,12,11,14,13,16,15,18,17,20,19,22,21]
Let's call the array [A1,…,Am,m+B1,…,m+Bn][A1,…,Am,m+B1,…,m+Bn] the LIS-product of AA and BB, and denote it as A⋅′BA⋅′B. It has the following properties:

|A⋅′B|=|A|+|B||A⋅′B|=|A|+|B|
(A⋅′B)LIS=ALIS+BLIS(A⋅′B)LIS=ALIS+BLIS
(A⋅′B)#=A#⋅B#(A⋅′B)#=A#⋅B#
The LIS-product allows us to construct answers for some KK beyond 50⋅5050⋅50 and even beyond 105105!

Unfortunately, this still doesn't help us answer some KKs, in particular those where KK is prime or has a large prime factor. So far we can only construct LIS counts that can be expressed as products of other LIS counts. It would be nice if we can construct LIS counts that can be expressed as sums of other LIS counts.

LIS-sum of arrays
Fortunately, there is a way! Given two arrays AA and BB with lengths mm and nn, respectively, consider the array [n+A1,n+A2,…,n+Am−1,n+Am,B1,B2,…,Bn−1,Bn][n+A1,n+A2,…,n+Am−1,n+Am,B1,B2,…,Bn−1,Bn]. This time, the first mm elements are larger than the last nn elements. Thus, we can't form an increasing sequence that contain elements from both parts. It means that the LIS length of this array is max(ALIS,BLIS)max(ALIS,BLIS). But what's the LIS count? An interesting thing happens:

If ALIS<BLISALIS<BLIS, then the LIS count is B#B# because all increasing subsequences in the first mm elements have lengths ≤ALIS<BLIS≤ALIS<BLIS.
If ALIS>BLISALIS>BLIS, then similarly the LIS count is A#A#.
If ALIS=BLISALIS=BLIS, then the LIS count is A#+B#A#+B#, because all LISes in both parts have the same length.
The last part is crucial: Notice that we can now form LIS counts that are sums of other LIS counts! But with one restriction though: we can only do that if the LIS lengths are equal. But thankfully, there's a way to make the LIS lengths equal, at the cost of increasing the lengths by a bit. For an array AA, consider the LIS product A⋅′[1]A⋅′[1]. The array [1][1] has LIS length of 11 and LIS count of 11, so according to the properties of LIS product, A⋅′[1]A⋅′[1] has a LIS length of ALIS+1ALIS+1 and a LIS count of A#⋅1=A#A#⋅1=A#. Notice that we increased the LIS length without increasing the LIS count! Similarly, A⋅′[1,2,…,n]A⋅′[1,2,…,n] increases the LIS length by nn while retaining the LIS count. Thus, if ALIS≠BLISALIS≠BLIS, we can make them equal using this property!

Thus, for any arrays AA and BB such that ALIS=BLISALIS=BLIS we can call the array [n+A1,…,n+Am,B1,…,Bn][n+A1,…,n+Am,B1,…,Bn] the LIS-sum of AA and BB, and denote it as A+′BA+′B. It has the following properties:

|A+′B|=|A|+|B||A+′B|=|A|+|B|
(A+′B)LIS=ALIS=BLIS(A+′B)LIS=ALIS=BLIS
(A+′B)#=A#+B#(A+′B)#=A#+B#
LIS-arithmetic
By combining the LIS-sum with the LIS-product, we can now answer even more KKs than before! For example, we can now also construct any KK of the form ab+cdab+cd, or a+b(c+de)a+b(c+de), etc.. Pretty much any expression involving additions and multiplications! We can do this because of the following crucial properties:

(A⋅′B)#=A#⋅B#(A⋅′B)#=A#⋅B#
(A+′B)#=A#+B#(A+′B)#=A#+B#
This allows us to directly convert normal arithmetic into LIS arithmetic! For our primitive element, we can start with the array [1][1], which has a LIS length of 11 and a LIS count of 11. Let's denote the array [1][1] by the symbol 1′1′.

Here are a few examples:

We can form an array with a LIS count of kk by doing 1′+′1′+′…+′1′k1′+′1′+′…+′1′⏞k. This results in the array [k,k−1,…,2,1][k,k−1,…,2,1] which we already know above. Let's denote this array by k′k′.
We can form an array with a LIS count of 1818 by noticing that 18=(4⋅3)+(3⋅2)18=(4⋅3)+(3⋅2). The array (4′⋅′3′)+′(3′⋅′2′)(4′⋅′3′)+′(3′⋅′2′) has such a LIS count!

This yields the array: [4,3,2,1,7,6,5]+′[3,2,1,5,4]=[9,8,7,6,12,11,10,3,2,1,5,4][4,3,2,1,7,6,5]+′[3,2,1,5,4]=[9,8,7,6,12,11,10,3,2,1,5,4].

We can form an array with a LIS count of 1818 by noticing that 18=(4⋅2⋅2)+218=(4⋅2⋅2)+2. The array (4′⋅′2′⋅′2′)+′(2′⋅′1′⋅′1′)(4′⋅′2′⋅′2′)+′(2′⋅′1′⋅′1′) has such a LIS count! Notice the need to "multiply" by 1′1′ in the second term. This is because +′+′ requires that both arrays have the same LIS length.

This yields the array: [4,3,2,1,6,5,8,7]+′[2,1,3,4]=[8,7,6,5,10,9,12,11,2,1,3,4][4,3,2,1,6,5,8,7]+′[2,1,3,4]=[8,7,6,5,10,9,12,11,2,1,3,4].

Notice that we're simply converting each arithmetic expression directly into a LIS-arithmetic expression!

The solution
This still leaves the question: how should we represent KK to get an array length ≤100≤100? To answer this, notice that there are huge savings in the length of the array if the terms involved have a small sum. An intuitive way to do this is to have as many LIS-products ⋅′⋅′ as possible.

The first idea is to represent KK in binary. This way, we can express KK in the form 2e1+2e2+…+2ek2e1+2e2+…+2ek, so we can build the array (2′)e1+′(2′)e2+′…+′(2′)ek(2′)e1+′(2′)e2+′…+′(2′)ek, where "LIS-exponentiation" is defined as repeated LIS-products. This works, as long as we adjust each array first before applying +′+′, so that they get the same LIS lengths. This is a good solution that gives us a length of <500<500 for all K≤105K≤105! Unfortunately, this doesn't pass the problem bounds; the longest one is >300>300.

The next idea to reduce the length is to use ternary instead. In other words, if K=a0+a131+a232+…K=a0+a131+a232+…, then the array we form is a0′+′a1′⋅′(3′)1+′a2′⋅′(3′)2+′…a0′+′a1′⋅′(3′)1+′a2′⋅′(3′)2+′… (again remembering to adjust before applying +′+′). If ai=1ai=1, we can skip multiplying by ai′=1′ai′=1′ to shorten the array a bit. We also skip terms with ai=0ai=0.

Why is this better? It's better because in binary, every two elements we include doubles the LIS count, while in ternary, every three elements we include triples the LIS count. Thus, on average, in binary every element multiplies the LIS count by 21/221/2 while in ternary every element multiplies the LIS count by 31/331/3. Since 21/2<31/321/2<31/3, ternary is more efficient. In fact, ternary is the most efficient base among all bases! By using ternary, the maximum length we now need is <250<250. Unfortunately, it still a bit far from 100100.

The next idea is write the ternary form differently: Instead of writing it as a0+a131+a232+…a0+a131+a232+…, we write it as a0+3(a1+3(a2+…))a0+3(a1+3(a2+…)). Thus, the array we form is a0′+3′⋅′(a1′+3′⋅′(a2′+′…))a0′+3′⋅′(a1′+3′⋅′(a2′+′…)) (again remembering to adjust before applying +′+′ and to skip ai=0ai=0).

As an example, consider K=80K=80. The ternary form of this is 2+2⋅3+2⋅32+2⋅332+2⋅3+2⋅32+2⋅33, so you normally you would form the array (2′⋅′1′⋅′1′⋅′1′)+′(2′⋅′3′⋅′1′⋅′1′)+′(2′⋅′3′⋅′3′⋅′1′)+′(2′⋅′3′⋅′3′⋅′3′)(2′⋅′1′⋅′1′⋅′1′)+′(2′⋅′3′⋅′1′⋅′1′)+′(2′⋅′3′⋅′3′⋅′1′)+′(2′⋅′3′⋅′3′⋅′3′), which has length (2+1+1+1)+(2+3+1+1)+(2+3+3+1)+(2+3+3+3)=32(2+1+1+1)+(2+3+1+1)+(2+3+3+1)+(2+3+3+3)=32. However, writing the ternary form as 2+3⋅(2+3⋅(2+3⋅2))2+3⋅(2+3⋅(2+3⋅2)), the array would be (2′⋅′1′⋅′1′⋅′1′)+′3′⋅′[(2′⋅′1′⋅′1′)+′3′⋅′(2′⋅′1′+′3′⋅′2′)](2′⋅′1′⋅′1′⋅′1′)+′3′⋅′[(2′⋅′1′⋅′1′)+′3′⋅′(2′⋅′1′+′3′⋅′2′)], which only has length (2+1+1+1)+3+(2+1+1)+3+(2+1)+(3+2)=23(2+1+1+1)+3+(2+1+1)+3+(2+1)+(3+2)=23. In general, the smaller the total numbers that appear on your representation, the better.

Using this technique, we are now able to reduce the required length to at most 9494, and we've now solved the problem!

Here's a solution that uses 48 numbers in the worst case: say n=2a0+2a1+⋯+2ann=2a0+2a1+⋯+2an where a1<a2<...<ana1<a2<...<an. For the time b
eing let's assume that we are allowed to put non-integer numbers in the list (we can "uncompress" them later). Start with the list 
{2,1,4,3,⋯,2an,2an−1}{2,1,4,3,⋯,2an,2an−1} (basically anan blocks, where the i'th block consists of {i+1,i}{i+1,i}). There are 2an2an LIS's 
in it with length anan. We now want to add 2an−12an−1 more LIS's. To do this, add any an−an−1an−an−1 distinct real numbers in the range 
[p,q][p,q] to the left of the list in increasing order, where p is the larger number in the (an−1+1)(an−1+1)'th block from the right and q 
is the smaller number in the an−1an−1'th block. This ensures that 2an−12an−1 new LIS's are formed, each starting with the newly added numbers. 
Similarly add these numbers for the rest of the bits. The total number of numbers used will be approximately 3b(n)3b(n) where b(n)b(n) is the 
number of bits in n. Code*/