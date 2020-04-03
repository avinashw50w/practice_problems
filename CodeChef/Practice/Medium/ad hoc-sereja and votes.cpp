/*Sereja conducted a voting about N of his opinions. Ai percent of people voted for opinion number i.
This statistics is called valid if sum of all Ai is equal to 100.

Now let us define rounding up of a statistics A.

If Ai is not an integer, it will be rounded up to next integer.
Otherwise it will be left as it is.
e.g. 4.1 became 5, 4.9 became 5 but 6 will still be 6.

Now let us consider a statistics B of size N in which each of Bi is an integer. Now he wants to know whether there exists some valid statistic A of size N 
(may contain real numbers) such that after rounding it up, it becomes same as B?

Input

First line of input contain integer T - number of test cases.
For each test, case first line contains integer N - number of opinions.
Next line contains N integers B1, B2, ..., BN as defined in the problem.
Output

For each test case, output YES or NO denoting the answer of the problem, i.e. if there exists some statistics A which could be rounded to make it B, print YES 
otherwise NO.

Constraints

1 ≤ T ≤ 50
1 ≤ N ≤ 10000
0 ≤ Bi ≤ 1000 */
/*EXPLANATION:
Let's define a small positive infinitesimal quantity e(epsilon). 
For Bi, corresponding element in array A can be in range [Bi-1+e,Bi](both ranges included). 
However, Bi = 0, the above range is invalid, so we'll ignore all zero elements. Let's say size of the remaining array B(after removing 0s) is N. 
We now consider the lower and upper bounds on the sum of all numbers in A(note: any real number between these bounds can be generated). So, if 100 lies within 
these bounds, then answer is yes.

LOWER BOUND:
Now, what is the minimum possible sum? It's S = [sum over all Bi] - N(number of non-negative elements in B) + e. So, we get condition for validity that S ≤ 100. 
If we ignore the e, we get S = [sum over all Bi] - N(number of non-negative elements in B) < 100.

UPPER BOUND:
Now, what is the maximum possible sum? It's S = sum over all Bi. So, we get one more validity condition that S ≥ 100.*/

int main() {
	#if 0
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n, a;
	caset{
		cin>>n;
		int sum = 0, maxSum = 100+n-1;
		rep(i,0,n){
			cin>>a;
			sum += a;
			if(a == 0) maxSum--;
		}

		if(sum>=100 && sum<=maxSum) puts("YES");
		else puts("NO");
	}
	return 0;
}
