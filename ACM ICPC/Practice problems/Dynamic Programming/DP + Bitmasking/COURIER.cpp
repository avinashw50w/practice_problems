/*Byteland is a scarcely populated country, and residents of different cities seldom communicate with each other. There is no regular postal 
service and throughout most of the year a one-man courier establishment suffices to transport all freight. However, on Christmas Day there is 
somewhat more work for the courier than usual, and since he can only transport one parcel at a time on his bicycle, he finds himself riding 
back and forth among the cities of Byteland.

The courier needs to schedule a route which would allow him to leave his home city, perform the individual orders in arbitrary order (i.e. 
travel to the city of the sender and transport the parcel to the city of the recipient, carrying no more than one parcel at a time), and finally 
return home. All roads are bi-directional, but not all cities are connected by roads directly; some pairs of cities may be connected by more 
than one road. Knowing the lengths of all the roads and the errands to be performed, determine the length of the shortest possible cycling 
route for the courier.

Input

The input begins with the integer t, the number of test cases. Then t test cases follow.

Each test case begins with a line containing three integers: n m b, denoting the number of cities in Byteland, the number of roads, and the 
number of the courier's home city, respectively (1<=n<=100,1<=b<=m<=10000). The next m lines contain three integers each, the i-th being ui vi 
di, which means that cities ui and vi are connected by a road of length di (1<=ui,vi<=100, 1<=di<= 10000). The following line contains integer 
z - the number of transport requests the courier has received (1<=z<=5). After that, z lines with the description of the orders follow. 
Each consists of three integers, the j-th being uj vj bj, which signifies that bj parcels should be transported (individually) from city uj 
to city vj. The sum of all bj does not exceed 12.

Output

For each test case output a line with a single integer - the length of the shortest possible bicycle route for the courier.

Example

Sample input:
1
5 7 2
1 2 7
1 3 5
1 5 2
2 4 10
2 5 1
3 4 3
3 5 4
3
1 4 2
5 3 1
5 1 1

Sample output:
43
*/

int N, M, home;
int dist[101][101];
vector<pii> routines;
ll dp[1<<15][101];

void clear() {
	mset(dp, -1);
	mset(dist, oo);
	rep(i,0,101) dist[i][i] = 0;
	routines.clear();
}
// Here mask represents the set of parcels
ll solve(int mask, int city) {
	if(dp[mask][city] != -1) return dp[mask][city];

	ll res = oo, f = 0;
	int sz = routines.size();
	rep(i,0,sz) {
		if((mask & (1<<i)) == 0) {	// if the ith parcel is not delivered
			f = 1;
			int u = routines[i].first;
			int v = routines[i].second;
			res = min(res, dist[city][u] + dist[u][v] + solve(mask | (1<<i), v));
		}
	}

	if(f == 0) return dp[mask][city] = dist[city][home];

	else return dp[mask][city] = res;	
}

int main() {
	caset {
		clear();
		si(N); si(M); si(home);
		home--;

		rep(i,0,M) {
			int u, v, w;
			si(u); si(v); si(w);
			u--; v--;
			dist[u][v] = w;
			dist[v][u] = w;
		}
		int z; si(z);
		rep(i,0,z) {
			int u, v, b;
			si(u); si(v); si(b);
			u--; v--;

			rep(k,0,b) routines.push_back({u, v});
		}

		rep(k,0,N) rep(i,0,N) rep(j,0,N) dist[i][j] =  min(dist[i][j], dist[i][k] + dist[k][j]);

		ll ans = solve(0, home);

		printf("%lld\n", ans);
	}
	return 0;
}


