/*You are given an array A of size N, and Q queries to deal with. For each query, you are given an integer X, and you're supposed to find out if X is present in the array A or not.

Input:
The first line contains two integers, N and Q, denoting the size of array A and number of queries. The second line contains N space separated integers, denoting the array of elements Ai. The next Q lines contain a single integer X per line.

Output:
For each query, print YES if the X is in the array, otherwise print NO.

Constraints:
1 <= N, Q <= 105
1 <= Ai <= 109
1 <= X <= 109*/
int a[MAXN+2];
int main() {
	int n,q,x;
	si(n); si(q);
	rep(i,0,n) si(a[i]);
	sort(a,a+n);
	while(q--){
		si(x);
		(binary_search(a,a+n,x))? puts("YES"): puts("NO");
	}
	return 0;
}
