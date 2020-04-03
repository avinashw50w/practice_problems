/*Chef has an array A of N numbers.
His teacher give him two numbers a and b and chef has to find
number of elements in array such that A[i] ≥ a and A[i] ≤ b where 1 ≤ i ≤ n and A[i] denotes the ith element of array.

Input:

The first line of input contains a single integer N denoting the number of elements in the array A.

Second Line contains N space separated Integers.

Third line contains Q ,the number of queries.

each query contains two space separated integer a and b.
Output

For each query output a single Integer giving the output of the problem.



Constraints

1 ≤ N, Q ≤ 100000
1 ≤ a ≤ b ≤ 109
1 ≤ A[i] ≤ 109*/

int main() {
	int n=inp();
	int a[n+1];
	rep(i,0,n) a[i]=inp();
	sort(a,a+n);
	int q=inp();
	int x,y;
	while(q--){
		x=inp();
		y=inp();
		int l = lower_bound(a,a+n,x)-a;
		int h = upper_bound(a,a+n,y)-a;
		printf("%d\n", (h-l));
	}
	return 0;
}
