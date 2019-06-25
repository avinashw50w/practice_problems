/*Chef loves research! Now he is looking for subarray of maximal length with non-zero product.

Chef has an array A with N elements: A1, A2, ..., AN.

Subarray Aij of array A is elements from index i to index j: Ai, Ai+1, ..., Aj.

Product of subarray Aij is product of all its elements (from ith to jth).

Input

First line contains sinlge integer N denoting the number of elements.
Second line contains N space-separated integers A1, A2, ..., AN denoting the elements of array.
 

Output

In a single line print single integer - the maximal length of subarray with non-zero product.
 

Constraints

1 ≤ N ≤ 100000
0 ≤ Ai ≤ 10000*/

/* eg 1 2 3 4 0 5 3 3 0 4 2 8 5 0 3 6 7 0 */
int main() {
	int n=inp();
	int a[n+1];
	rep(i,0,n) a[i]=inp();
	int ans=0, cnt=0;
	rep(i,0,n){
		cnt++;
		if(a[i]==0) cnt=0;
		ans = max(ans,cnt);
	}
	printf("%d\n", ans);
	return 0;
}
