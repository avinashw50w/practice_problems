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

sum of N over all test cases does not exceed 5 × 105*/

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