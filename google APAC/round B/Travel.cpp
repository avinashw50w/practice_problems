/*There are N cities in Chelsea's state (numbered starting from 1, which is Chelsea's city), and M bidirectional roads directly connect them. (A pair of cities 
may even be directly connected by more than one road.) Because of changes in traffic patterns, it may take different amounts of time to use a road at different 
times of day, depending on when the journey starts. (However, the direction traveled on the road does not matter -- traffic is always equally bad in both 
directions!) All trips on a road start (and end) exactly on the hour, and a trip on one road can be started instantaneously after finishing a trip on another road.

Chelsea loves to travel and is deciding where to go for her winter holiday trip. She wonders how quickly she can get from her city to various other destination 
cities, depending on what time she leaves her city. (Her route to her destination may include other intermediate cities on the way.) Can you answer all of her 
questions?

Input

The first line of the input gives the number of test cases, T. T test cases follow.

The first line of each test case contains three integers: the number N of cities, the number M of roads, and the number K of Chelsea's questions.

2M lines -- M pairs of two lines -- follow. In each pair, the first line contains two different integers x and y that describe one bidirectional road between the 
x-th city and the y-th city. The second line contains 24 integers Cost[t] (0 ≤ t ≤ 23) that indicate the time cost, in hours, to use the road when departing 
at t o'clock on that road. It is guaranteed that Cost[t] ≤ Cost[t+1]+1 (0 ≤ t ≤ 22) and Cost[23] ≤ Cost[0]+1.

Then, an additional K lines follow. Each contains two integers D and S that comprise a question: what is the fewest number of hours it will take to get from 
city 1 to city D, if Chelsea departs city 1 at S o'clock?

Output

For each test case, output one line containing "Case #x: ", where x is the case number (starting from 1), followed by K distinct space-separated integers that 
are the answers to the questions, in order. If Chelsea cannot reach the destination city for a question, no matter which roads she takes, then output -1 for 
that question.

Limits

1 ≤ x, y ≤ N.
1 ≤ all Cost values ≤ 50.
1 ≤ D ≤ N.
0 ≤ S ≤ 23.
Small dataset

1 ≤ T ≤ 100.
2 ≤ N ≤ 20.
1 ≤ M ≤ 100.
1 ≤ K ≤ 100.
Large dataset

1 ≤ T ≤ 5.
2 ≤ N ≤ 500.
1 ≤ M ≤ 2000.
1 ≤ K ≤ 5000.
Sample


Input 
 	
3
3 3 2
1 2
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 3
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
2 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
2 1
3 3
3 1 2
1 2
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
2 2
3 4
3 3 3
1 2
7 23 23 25 26 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8
1 3
10 11 15 26 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11
2 3
7 29 28 27 26 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8
2 14
3 3
3 21


Output 
 
Case #1: 1 2
Case #2: 1 -1
Case #3: 17 26 13*/


int dp[600][24];	// dp[i][j] indicates that the min time to reach i from 0 if she starts from i at j o' clock
int v[600][24],vcnt;	// visited array
int cost[2000][24];
int road[2000][2];
vector<vector<int>> graph;

int main()
{
	int T;
	scanf("%d",&T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		fprintf(stderr, "Case #%d processing\n", testcase);
		graph.clear();
		
		printf("Case #%d:",testcase);
		int n,m,K;
		scanf("%d%d%d",&n,&m,&K);
		graph.resize(n);
		for (int i = 0; i < m; i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			graph[x].push_back(i);
			graph[y].push_back(i);
			road[i][0] = x;
			road[i][1] = y;
			for (int j = 0; j < 24; j++) {
				scanf("%d",&cost[i][j]);
			}
		}
		for (int i = 0; i < K; i++) {
			int D, S;
			scanf("%d%d",&D,&S);
			D--;
			memset(dp,-1,sizeof(dp));
			priority_queue<pair<int,pair<int,int>>> q;	// priority_queue(min time to reach dest, dest, start time)
			++vcnt;
			dp[0][S] = 0;	// min time to reach 0 from 0 if starts at S o' clock is 0
			q.push(make_pair(0,make_pair(0,S)));
			int ans = -1;
			while(!q.empty()) {
				auto pos = q.top().second; q.pop();
				if (pos.first == D) {
					ans = dp[pos.first][pos.second];
					break;
				}
				if (v[pos.first][pos.second] == vcnt) continue;
				v[pos.first][pos.second] = vcnt;
				for (auto edgeindex : graph[pos.first]) {
					int next = road[edgeindex][0] ^ road[edgeindex][1] ^ pos.first;	// x ^ y ^ x = y
					int cost = ::cost[edgeindex][pos.second];
					int ntime = (cost + pos.second)%24;

					if (dp[next][ntime] == -1 || dp[next][ntime] > dp[pos.first][pos.second] + cost)
					{
						dp[next][ntime] = dp[pos.first][pos.second] + cost;
						q.push(make_pair(-dp[next][ntime], make_pair(next,ntime)));
					}
				}
			}
			printf(" %d", ans);
		}
		puts("");
	}
	return 0;
}
