/* A simple subset sum problem */

int a[22];
int n,m;

bool solve(int k, int sum){
	for(int i=k; i<n; ++i) {
		if(sum == a[i]) return true;
		else if(sum > a[i])
			return solve(i+1, sum-a[i]) || solve(i+1, sum);
	}
	return false;
}
int main() {
	int t=inp();
	while(t--){
		n=inp(); m=inp();
		rep(i,0,n) a[i]=inp();
		(solve(0,m)) ? puts("Yes"): puts("No");
	}

	return 0;
}
