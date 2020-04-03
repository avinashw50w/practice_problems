/*Chandu's girlfriend loves arrays that are sorted in non-increasing order. Today is her birthday. Chandu wants to give her some sorted arrays on her birthday. But the shop has only unsorted arrays. So, Chandu bought T unsorted arrays and is trying to sort them. But, he doesn't have much time to sort the arrays manually as he is getting late for the birthday party. So, he asked you to write a program to sort the T arrays in non-increasing order. Help him, or his girlfriend will kill him.

Input:
First line contains an integer T, denoting the number of test cases.
First line of each test case contains an integer N, denoting the size of the array.
Second line contains N space separated integers, denoting the array elements Ai.

Output: 
For each test case, print the sorted array in non-increasing order.

Constraints:
1 <= T <= 100
1 <= N <= 105
0 <= Ai <= 109 */

int a[100000+2];
int main() {
	caset{
		int n; si(n);
		rep(i,0,n) si(a[i]);
		sort(a,a+n,greater<int>());
		rep(i,0,n) printf("%d ", a[i]);
		printf("\n");
	}
	return 0;
}
