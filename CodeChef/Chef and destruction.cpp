/* Arrays have fallen out of Chef's good books, and he plans to destroy all arrays he possesses. He is left with the last array A, 
consisting of N positive integers. In order to destroy the array, he can perform the following 2 types of operations any number of times.
Choose any 2 elements, say X and Y, from the given array A such that X != Y, and remove them, or
Choose any 1 element, say X, from A, and remove it.


In order to destroy the array as quickly as possible, Chef is interested in knowing the minimum number of operations required to destroy it. Please help him achieve this task.
Input

The first line of input contains a single integer T denoting the number of test cases. First line of each test case contains a single 
integer N — the number of integers in the array A.

Second line of each test case contains N space separated integers denoting the array A.
Output

For each test case, output the required answer in a new line.
Constraints

1 ≤ T ≤ 50000

1 ≤ N ≤ 50000

1 ≤ Ai ≤ 109

sum of N over all test cases does not exceed 5 × 105

What is the simplest algorithm that we can think of? We can simply consider the adjacent elements in the array. If they are unequal, we discard both of them. If they are equal, we discard the first one and repeat the process until we exhaust the array. We have some observations to make here:

When would we be the luckiest? If every time we took a pair of elements and the elements would turn out to be unequal. This is because that would allow us to discard two elements in a single move.
When would we be the unluckiest? Let us assume element xx appears the highest number of times. What if we were left with all the xx's in the end. We would have to remove them one by one.
We need to design an algorithm which reduces the chance of being unlucky and increases the change of being lucky. If both these can be accomplished, we would have a strong algorithm which might be optimal. Our first aim is to try to pick up pairs of unequal elements. To do this, let us group the same elements together in the form (xixi, fifi), where xixi is the number and fifi the frequency (number of times it appears in array AA). Let us say there are kk distinct elements in the array. Thus,

∑ki=1fi=N∑i=1kfi=N

Once we have the kk pairs of distinct elements with their frequency, i.e., (xixi, fifi), we can proceed with thinking of a way to choose pairs of elements to discard. The simplest way is to choose any two xixi and xjxj which have non-zero frequency and reduce their corresponding fifi and fjfj by 1. This goes on till only one xlxl is left with non-zero frequency flfl. Now comes in the second observation. It will be best for us to minimize the flfl so as to avoid being unlucky. How can we do this?

Let us rely on our intuition to come up with an algorithm. At each step, we will choose two numbers xpxp, xqxq to discard such that xp≠xqxp≠xq and fpfp and fqfq are the highest frequencies amongst the elements left with non-zero frequency. This is the optimal approach. It is greedy. But what is the guarantee that the algorithm is correct? Let's try to prove it using exchange argument. This is a standard approach for proving the optimality of greedy algorithms. You can read more about greedy and their proofs here.

Let's say that at a particular step in the algorithm, we choose some xuxu and xvxv such that fufu and fvfv are not the two highest frequencies amongst the elements with non-zero frequencies. As per the exchange argument, we have to show that choosing xpxp and xqxq instead would yield a better solution.

What advantage do we get if we choose (xpxp, xqxq) instead of (xuxu, xvxv)? By reducing fpfp and fqfq by 1 each, we have possibly reduced the maximum value of flfl that can be left over in the end by 1 (since fpfp and fqfq are the highest frequencies). If we choose xuxu and xvxv instead, this possibility is gone. Therefore, at each step, choosing two numbers such that their frequencies are the highest two amongst those with non-zero frequency is always a better option. In other words, instead of choosing pair (xuxu, xvxv), we exchange the move with choosing (xpxp, xqxq) and discarding it. We have proved the optimality.

How do we implement this? To get the highest two frequencies at each step, we can use a max priority-queue. Such a data structure is in-built in most popular programming languages. One can also implement it in the form of max-heaps. Please see editorialist's solution for implementation details.

COMPLEXITY:
O(NlogN)O(Nlog⁡N) per test case.*/

inline void get(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
 
int a[50005];
priority_queue < int > freq;
 
bool cmp(int a, int b)
{
	return a > b;
}
 
int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n;
		get(n);
		F(i,n)
			get(a[i]);
 
		sort (a,a+n);
		F(i,n)
		{
			int count = 1;
			while (i<(n-1) && a[i] == a[i+1])
			{
				count++;
				i++;
			}
			freq.push(count);
		}
 
		int ans = 0;
		while (!freq.empty())
		{
			int a = freq.top();
			freq.pop();
			if (freq.empty())
			{
				ans += a;
				break;
			}
			int b = freq.top();
			freq.pop();
 
			if (a>1)
				freq.push(a-1);
			if (b>1)
				freq.push(b-1);
			ans += 1;
		}
 
		
		printf("%d\n", ans);
		// freq.clear(); 
 
	}
	return 0;
} 