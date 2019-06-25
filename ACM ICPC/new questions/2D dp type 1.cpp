// type : minimizing the maximum of all possible cases

/*Agon Packers and Movers specialize in moving large number luggages from one place to another.
The luggages are packed by the Packers, and after they're done with the job, the Movers take over.

First, the Packers put the packages they have packed in a single line, one behind the other, and then the 
Movers come one by one to pick the packages. A Mover can come only once, can only pick the first few packages in the line, 
and then take them with him. He might also choose not to pick any. Another Mover comes, and repeats the process, 
till all the packages are taken. The Movers need to carry all the packages.

The Movers are a friendly lot, and care about each other - so their goal is to minimize the maximum load that any Mover gets.
You are given the number of movers M in the first line. The next line contains the number of packages P.
The next line contains the weight of the 
P package (in Kilograms) in order - first weight representing of first package in the line, separated by space.
You need to print the maximum load any mover carries in the best possible case, in accordance with their goal.

Constraints:

1≤M≤15
1≤P≤250

Weight of each Package (W): 1≤W≤10000

INPUT
5 5 1 1 1 2 1

OUTPUT
2
*/

int M, P;
int a[250+1], dp[16][251];

int solve(int mov, int pack) {

	if(mov == M) {					// if all movers finshed their work
		if(pack != P) return 1e9;   // not all packages are moved (invalid case)
		else return 0;				// all packages are moved (valid case)
	}

	if(pack == P) return 0;			// all packages are moved (valid case)

	int &ret = dp[mov][pack];

	if(ret != -1) return ret;

	int ans = solve(mov + 1, pack);		// this mover will not carry any thing

	int sum = 0;

	for(int i = pack; i < P; ++i) {
		sum += a[i];				// this mover will take carry this package
		ans = min(ans, max(sum, solve(mov + 1, i + 1)));	  // solve for remaining movers and remaining packages and keep minimizing the ans;
	}
	return ret = ans;
}

int main() {

	cin >> M >> P;

	for(int i = 0; i < P; ++i) cin >> a[i];

	memset(dp, -1, sizeof(dp));

	cout << solve(0, 0) << endl;
}

//////////////////////////////////////////////////////////////////////////////////
// this can also be done using binary search. search the ans b/w the maximum weight and total weight(25 * 10^5)
int M, P, a[252];

int solve() {
	cin >> M >> P;

	int maxx = 0;
	rep(i, 0, P) cin >> a[i], maxx = max(maxx, a[i]);

	int ans = 0;

	int l = maxx, r = 25 * 1e5;

	while(l <= r) {
		int i = 0, sum = 0, movers = 1;

		int mid = (l + r) >> 1;

		while(i < P) {
		    
		    if(sum + a[i] <= mid) {
		    	sum += a[i];
		    	i++;
		    }

		    else {
		    	sum = 0;
		    	movers++;
		    }
		}

		if(movers <= M) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}

	return ans;
}