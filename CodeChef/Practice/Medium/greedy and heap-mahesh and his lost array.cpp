/*Mahesh got a beautiful array named A as a birthday gift from his beautiful girlfriend Namratha. There are N positive integers in that array. Mahesh loved the 
array so much that he started to spend a lot of time on it everyday. One day, he wrote down all possible subsets of the array. Then for each subset, he calculated 
the sum of elements in that subset and wrote it down on a paper. Unfortunately, Mahesh lost the beautiful array :(. He still has the paper on which he wrote all 
subset sums. Your task is to rebuild beautiful array A and help the couple stay happy :)

Input

The first line of the input contains an integer T denoting the number of test cases.
First line of each test case contains one integer N, the number of elements in A.
Second line of each test case contains 2^N integers, the values written on paper

Output

For each test case, output one line with N space separated integers in non-decreasing order.*/
/*PROBLEM:
You have an unknown set of length N. We take all 2 ^ N subsets of it and sum elements for each subset. Given what we obtained, restore a possible initial set.

QUICK EXPLANATION
We build our solution step by step. Each step we take smallest element from sums. Suppose we’re at step i and we found element x[i]. We should erase now from sums all sums formed by x[i] and a non-empty subset of {x[1], x[2], ..., x[i – 1]}.

EXPLANATION
Let’s call all 2^N sums sumSet. Also, let’s call a possible solution valueSet (making sum of all subsets of valueSet, you should obtain sumSet). The problem says there is always a possible solution. We’ll implement sumSet as a multiset from C++. This container allows following things, which will be needed later: find/delete an element and keep the set in increasing order. We’ll note first element from current sum set as sumSet[1], second element as sumSet[2] and so on. Let’s read all numbers from the input and add all of them in multiset sumSet.

Smallest element from sumSet is always 0 (and it corresponds to empty subset). It does not give us any information, so let’s erase it from the set and move on. What’s smallest element now? Is it an element from valueSet? Is it a sum of a subset of valueSet?

There exists at least one element from valueSet equal to smallest element from sumSet. Why? Suppose first element of sumSet is a sum of other elements of valueSet. sumSet[1] = valueSet[k1] + valueSet[k2] + .... where k1, k2, ... are some indexes.

Since numbers are positive, we get that valueSet[k1] <= sumSet[1], valueSet[k2] <= sumSet[1] and so on. Since sumSet[1] is smallest element possible, we can only get that valueSet[k1] = sumSet[1], valueSet[k2] = sumSet[1] and so on.

This means at least one element from valueSet will have value equal to sumSet[1]. We’ve found one element from valueSet. Let’s add it to valueSet (we build the set incrementally) and erase it from sumSet. Let’s move now to our new sumSet[1] element (smallest element from sumSet, not deleted yet). We can follow same logic from above and see that sumSet[1] is a new element from valueSet. Let’s add it to valueSet and erase it from sumSet.

We move once again to sumSet[1]. Now, we have a problem. It can be one of following 2 possibilities:

sum of subset {valueSet[1], valueSet[2]}

a new element of valueSet.

Case b) is ideal, because we found one more element of valueSet. What to do with case a)? We know sum valueSet[1] + valueSet[2]. So we can simply erase it from sumSet, before considering sumSet[1]. Then, only case a) is left, so we find valueSet[3]. We erase now valueSet[3] from sumSet (I know, it becomes boring already, I’ll finish in a moment :) ).

It’s more tricky now what can be sumSet[1]. It can be one of following: valueSet[3]+valueSet[1], valueSet[3]+valueSet[2], valueSet[3]+valueSet[1]+valueSet[2]. We can fix this by erasing all those elements from sumSet before considering sumSet[1]. Once again, we’re left with valueSet[4]. Let’s note that all sums that should be erased contain a valueSet[3] term and a non-empty subset of {valueSet[1], valueSet[2]}. Sums of subsets of {valueSet[1], valueSet[2]} are already erased in previous steps.

Generalizing the algorithm
Let’s generalize the algorithm. Suppose you want to calculate valueSet[n]. We need firstly to erase from set a combination of valueSet[n – 1] and a non-empty subset of {valueSet[1], valueSet[2], ..., valueSet[n – 2]}. Then, the smallest element is valueSet[n].

We can keep an additional array subsets[] representing all subset sums obtained from {valueSet[1], valueSet[2], ..., valueSet[n – 2]}. Then, at step of calculating valueSet[n], we need to erase subsets[j] + valueSet[n – 1] from our sumSet. Now, valueSet[n] is calculated.

The new subset sum list will be the old one plus the one that contains valueSet[n – 1]. So, after we calculate valueSet[n], we update subsets with all values valueSet[n – 1] + subSets[j]. We run this algorithm as long as there is at least one element in sumSet.

Time Complexity
Each element is added in the multiset once and erased once. Hence, the complexity is O(2 ^ N * log(2 ^ N)) = O(2 ^ N * N).*/
const int MAXN = 1<<15;

int ans[15], A[MAXN+1], subset[MAXN+1], mark[MAXN+1];

int Bsearch(int l, int r, int val) {
	while(l <= r) {
		int mid = (l+r)>>1;
		if(A[mid] == val) {
			if(mark[mid] == 1) l = mid+1;

			else if(mid == l || mark[mid-1] == 1 || A[mid-1] < A[mid])
				return mid;
			else r = mid-1;
		}
		else if(A[mid] < val) l = mid+1;
		else r = mid-1;
	}
	return -1;
}
int main() {
	
	int n, N, tmp;
	BOOST;
	caset{
		cin>>n;
		N = (1<<n);

		rep(i,0,N) cin>> A[i];
		sort(A, A+N);

		memset(mark, 0, N*(sizeof(int)));
		ans[0] = subset[0] = A[1];
		int aCnt = 2, subCnt = 1;

		rep(i, 1, n) {
			while(mark[aCnt] == 1) aCnt++;

			ans[i] = A[aCnt];
			if(i == n-1) break;

			subset[subCnt++] = A[aCnt];
			mark[aCnt] = 1;
			aCnt++;

			int len = subCnt - 1;
			rep(j, 0, len) {
				tmp =  ans[i] + subset[j];
				subset[subCnt++] = tmp;
				int pos = Bsearch(aCnt, N-1, tmp);
				mark[pos] = 1;
			}
		}

		rep(i,0,n) cout << ans[i] << " ";
		cout << "\n";


	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////

#include <cstdio>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

#define N 16

int b[1<<N], c[1<<N];
int a[N];

// a[] holds the final answer
// b holds the input numbers
// c holds the all combination of sums possible till that point in time.

int main() {
	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;


		int m = 1 << n;
		for(int i=0; i<m; i++) {
			cin >> b[i];
		}

		sort(b, b+m);

		multiset <int> s; // This holds the sums we are expecting to occur
		int ptr = 0, fptr = 0;

		for(int i=1; i<m; i++) {
			int expected = -1;
			if(!s.empty()) {
				expected = *s.begin();
			}

			if(b[i] == expected) { // This is expected, so it is not a new number
				s.erase(s.begin());
			} else {
				// We did not expect this number, so this is a value of a[]
				// add it to a. Also add the new expectations to s.
				a[fptr] = b[i];
				int tptr = ptr;
				for(int j=0; j<tptr; j++) {
					c[ptr] = c[j] + a[fptr];
					s.insert(c[ptr]);
					ptr++;
				}
				c[ptr++] = a[fptr];
				fptr++;
			}
		}

		for(int i=0; i<fptr; i++) printf("%d ", a[i]);
		printf("\n");
	}
}