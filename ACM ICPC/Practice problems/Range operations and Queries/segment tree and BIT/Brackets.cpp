/*We will call a bracket word any word constructed out of two sorts of characters: the opening bracket "(" and the closing bracket ")". 
Among these words we will distinguish correct bracket expressions. These are such bracket words in which the brackets can be matched into 
pairs such that

every pair consists of an opening bracket and a closing bracket appearing further in the bracket word
for every pair the part of the word between the brackets of this pair has equal number of opening and closing brackets
On a bracket word one can do the following operations:
replacement -- changes the i-th bracket into the opposite one
check -- if the word is a correct bracket expression
Task

Write a program which

reads (from standard input) the bracket word and the sequence of operations performed,
for every check operation determines if the current bracket word is a correct bracket expression,
writes out the outcome (to standard output).
Input

Ten test cases (given one under another, you have to process all!). Each of the test cases is a series of lines. The first line of a test 
consists of a single number n (1<=n<=30000) denoting the length of the bracket word. The second line consists of n brackets, not separated 
by any spaces. The third line consists of a single number m -- the number of operations. Each of the following m lines carries a number k 
denoting the operation performed. k=0 denotes the check operation, k>0 denotes replacement of k-th bracket by the opposite.

Output

For every test case your program should print a line:
Test i:
where i is replaced by the number of the test and in the following lines, for every check operation in the i-th test your program should 
print a line with the word YES, if the current bracket word is a correct bracket expression, and a line with a word NO otherwise. 
(There should be as many lines as check operations in the test.)

Example

Input:
4
()((
4
4
0
2
0
[and 9 test cases more]
Output:
Test 1:
YES
NO
[and 9 test cases more]*/

#include <bits/stdc++.h>
using namespace std;

#define MAXN 30303

struct node {
	int sum, minSum;
} tree[4 * MAXN];

char s[MAXN];

node combine(node l, node r) {
	node ret;
	ret.sum = l.sum + r.sum;
	ret.minSum = min(l.minSum, l.sum + r.minSum);

	return ret;
}

void build(int i, int l, int r) {
	if(l == r) {
		tree[i].sum = tree[i].minSum = (s[l]=='(')? 1 : -1;
		return;
	}
	int m = (l+r)>>1;
	build(2*i, l, m);
	build(2*i+1, m+1, r);
	tree[i] = combine(tree[2*i], tree[2*i+1]);
}

void modify(int i, int l, int r, int idx) {
	if(l == r) {
		tree[i].sum = tree[i].minSum = -tree[i].sum;
		return;
	}
	int m = (l+r)>>1;
	if(idx<=m) modify(2*i, l, m, idx);
	else modify(2*i+1, m+1, r, idx);
	tree[i] = combine(tree[2*i], tree[2*i+1]);
}


int main() {
	int N, test = 1, t, x, q;
	while(scanf("%d", &N) == 1) {
		scanf("%s", s);

		build(1, 0, N-1);

		printf("Test %d\n", test++);
		scanf("%d", &q);
		while(q--){
			scanf("%d",&x);
			if(x == 0) {
				if(tree[1].sum == 0 and tree[1].minSum == 0) printf("YES\n");
				else printf("NO\n");
			}
			else modify(1, 0, N-1, x-1);
		}
	}
	return 0;
}