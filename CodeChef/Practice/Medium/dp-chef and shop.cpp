/*hef likes shopping, and especially he likes to buy oranges. But right now he is short of money. He has only k rubles. There are n oranges. The i-th one costs 
costi rubles and has weight equal to weighti. Chef wants to buy a set of oranges with the maximal possible weight. Please help him, and tell him this weight.

Input

The first line of the input contains an integer T denoting the number of test cases. The first line of each test case contains two numbers n and k. The following 
n lines contain two numbers costi and weighti respectively.

Output

For each test case, output a single line containing maximal weight among all the affordable sets of oranges.

Constraints

1 ≤ T ≤ 250
1 ≤ n ≤ 10
1 ≤ k ≤ 100000000
1 ≤ weighti ≤ 100000000
1 ≤ costi ≤ 100000000*/

long cost[10], weight[10];

long Knapsack(long k, long n) {
	if(k == 0 || n == 0) return 0;

	if(cost[n-1] > k) return Knapsack(k, n-1);

	else return max(weight[n-1] + Knapsack(k-cost[n-1], n-1) , Knapsack(k, n-1));
}

int main() {
	
	caset{
		long n, k;
		cin>>n>>k;

		rep(i,0,n) cin>>cost[i]>>weight[i];

		cout << Knapsack(k, n) << "\n";
	}

	return 0;
}
