/*you have given array of Size N and two numbers M, K. K is size of subarray and M is count of subarray. 
You have to return sum of max M subarray of size K (non-overlapping) 

N = 7, M = 3 , K = 1 

A={2 10 7 18 5 33 0} = 61 — subsets are: 33, 18, 10 (top M of size K) 

M=2,K=2 
{3,2,100,1} = 106 - subsets are: (3,2), (100,1) 2 subsets of size 2*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)

vector<int> solve(int a[], int N, int M, int K) {
	int ksum[N-K+1];
	int sum = 0, l = 0;
	for(int i=0; i<K; ++i) 
		sum += a[i];
	ksum[l++] = sum;
	
	for(int i=K; i<N; ++i) {
		sum += a[i] - a[i-K];
		ksum[l++] = sum;
	}

	int dp[N-K+1];
	dp[0] = ksum[0];
	
	for(int i=1; i<N-K+1; ++i) {
		dp[i] = max( dp[i-1], ksum[i] + (i-K>=0? dp[i-K]: 0) );
	}
	
	sort(dp, dp+N-K+1, greater<int>());
	// sorting the dp array will take O(nlogn) in worst case(k = 1)
	// so use  a min heap of size M. Store the first M elements of dp[i],
	// then for the M+1 element, check if it is less than heap.top(), 
	// if yes then replace it with the element, oterwise proceed to the next number of dp.
	
	vector<int> ans;
	for(int i=0; i<M; ++i)
		ans.push_back(dp[i]);
		
	return ans;
}


int main() {
	int a[] = {5, 2, 4, 6, 3, 7, 1, 7};
	int N = sizeof(a)/sizeof(a[0]);
	int K = 3, M = 3;

	vector<int> ans = solve(a, N, M, K);
	for(int i = 0; i<M; ++i) cout << ans[i] <<" ";
}


///////////////////////////////////////////////////////////////////
/*
const int maxn = 50;
int N, K;
int dp[maxn][maxn];
int ksum[maxn];

int solve(int index, int M) {
	if(M == 0 || index >= N) return 0;

	if(dp[index][M] != -1) return dp[index][M];

	int mxSum = 0;
	for(int i = index; i < N-K+1; ++i) {
		int t = ksum[i] + solve(i+K, M-1);
		maxSum = max(maxSum, t);
	}
	return dp[index][M] = maxSum;
}

///////////////////////////////////////////////////////////*/