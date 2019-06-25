/*In the previous problem Chandu bought some unsorted arrays and sorted them (in non-increasing order). Now, he has many sorted arrays to give to his girlfriend. But, the number of sorted arrays are very large so Chandu decided to merge two sorted arrays into one sorted array. But he is too lazy to do that. So, he asked your help to merge the two sorted arrays into one sorted array (in non-increasing order).

Input:
First line contains an integer T, denoting the number of test cases.
First line of each test case contains two space separated integers N and M, denoting the size of the two sorted arrays.
Second line of each test case contains N space separated integers, denoting the first sorted array A.
Third line of each test case contains M space separated integers, denoting the second array B.

Output:
For each test case, print (N + M) space separated integer representing the merged array.

Constraints:
1 <= T <= 100
1 <= N, M <= 5*104
0 <= Ai, Bi <= 109 

*/
int a[50000+2], b[50000+2], c[100000+2];
int main() {
	caset{
		int n,m, k=0; si(n); si(m);
		rep(i,0,n) si(a[i]);
		rep(i,0,m) si(b[i]);
		int i=n-1,j=m-1;
		while(i>=0 and j>=0){
			if(a[i]<=b[j]) c[k++] = a[i--];
			else c[k++] = b[j--];
		}
		while(i>=0) c[k++] = a[i--];
		while(j>=0) c[k++] = b[j--];
		for(int i=m+n-1;i>=0;--i) printf("%d ", c[i]);
		printf("\n");
	}
 	return 0;
}
