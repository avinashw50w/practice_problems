/*Imagine you have a collection of N wines placed next to each other on a shelf. For simplicity, let's number the wines from left to right 
as they are standing on the shelf with integers from 1 to N, respectively. The price of the ith wine is pi. (prices of different wines 
can be different).Because the wines get better every year, supposing today is the year 1, on year y the price of the ith wine will be y*pi, 
i.e. y-times the value that current year.You want to sell all the wines you have, but you want to sell exactly one wine per year, 
starting on this year. One more constraint - on each year you are allowed to sell only either the leftmost or the rightmost wine on the 
shelf and you are not allowed to reorder the wines on the shelf (i.e. they must stay in the same order as they are in the beginning).
You want to find out, what is the maximum profit you can get, if you sell the wines in optimal order?"  */

int N;     // number of wines
int p[N]; // price of wines

int profit(int l, int r) {
	if(l > r) return 0;   // if there are no wines left
	int year = N - (r-l+1) + 1;
	return max( 
		year*p[l] + profit(l+1, r),  // include the cost of the leftmost wine and recurse rightward : T(N-1)
		year*p[r] + profit(l, r-1)   // include the cost of the righmost wine and recurse leftwards : T(N-1)
		);
}

/* but, the above recursive approach has an exponential time complexity : O(2^N) ,  T(N) = 2.T(N-1) => T(N) = (2^k).T(N-k)
 for k = N , T(N) = (2^N).T(1) <= 2^N ;  or T(N) = O(2^N)  */

/* dp solution */

int N;
int dp[N][N]  // initialize it to -1
int p[N];

int profit(int l, int r) {
	if(l > r) return 0;

	if(dp[l][r] != -1) return dp[l][r];

	int year = N - (r-l+1) + 1;

	return dp[l][r] = max(
		year*p[l] + profit(l+1, r),
		year*p[r] + profit(l, r-1)
		);
}

// time complexity : O(N^2)  , because for all the combinations of l and r, the ans will occur in the dp array which is of N x N size
