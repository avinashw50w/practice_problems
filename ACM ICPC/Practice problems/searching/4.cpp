/*There are N temples in a straight line and K monks who want to spread their enlightening power to the entire road of temples. All the monks have an enlightenment value, which denotes the range of enlightenment which they can spread in both the directions. Since, they do not want to waste their efficiency on trivial things of the world, they want to keep their range minimum.

Also, when we say that the N temples are in a straight line, we mean that that all the temples lie on something like an X-axis in a graph.

Find the minimum enlightenment value such that all the temples can receive it.

Input Format:
The first line contains two integers, N and K - denoting the number of temples and number of monks. The next line contains N integers denoting the position of the temples in the straight line.

Output format:
Print the answer in a new line.

Constraints:
1 <= N <= 105
1 <= K < N 
1 <= Positioni <= 107*/

int pos[MAXN+2];
int n,k;

int check(int p, int k){
	int curr = pos[0]+p;
	k--;
	for(int i=1;i<n;++i){
		if(curr + p >= pos[i]) continue;

		if(k == 0) return 0;

		curr = pos[i]+p;
		k--;
	}
	return 1;
}
int main() { 
	si(n); si(k);
	rep(i,0,n) si(pos[i]);
	sort(pos,pos+n);
	int l = 0, r = (int)1e7, mid;

	while(l<=r){
		mid = l + (r-l)/2;
		int a = check(mid, k);
		int b = check(mid-1, k);
		if(a==1 and b==0) break;

		if(a == 0) l = mid+1;

		else r = mid-1;
	}

	printf("%d\n", mid);
	return 0;
}
