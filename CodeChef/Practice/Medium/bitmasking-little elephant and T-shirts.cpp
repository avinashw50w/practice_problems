/*Little Elephant and his friends are going to a party. Each person has his own collection of T-Shirts. There are 100 different kind of T-Shirts. Each T-Shirt has 
a unique id between 1 and 100. No person has two T-Shirts of the same ID.

They want to know how many arrangements are there in which no two persons wear same T-Shirt. One arrangement is considered different from another arrangement if 
there is at least one person wearing a different kind of T-Shirt in another arrangement.

Input

First line of the input contains a single integer T denoting number of test cases. Then T test cases follow.

For each test case, first line contains an integer N, denoting the total number of persons. Each of the next N lines contains at least 1 and at most 100 space 
separated distinct integers, denoting the ID's of the T-Shirts ith person has.

Output

For each test case, print in single line the required number of ways modulo 1000000007 = 109+7.

Constraints

1 ≤ T ≤ 10
1 ≤ N ≤ 10
Example

Input:
2
2
3 5
8 100
3
5 100 1
2
5 100

Output:
4
4*/

int amask;

vector<int> shirt[101];
int dp[(1<<10) + 1][101];

long long solve(int mask, int i) {
	if(mask == amask) return 1;

	if(i > 100) return 0;

	if(dp[mask][i] != -1) return dp[mask][i];

	long long ways = solve(mask, i+1);

	int len = shirt[i].size();

	rep(j, 0, len) {
		if(mask & (1<<shirt[i][j])) continue;

		ways = ( ways + solve(mask | (1<<shirt[i][j]), i+1) ) % mod;
	}

	return dp[mask][i] = ways;
}

int main() {
	caset{
		rep(i,0,101) shirt[i].clear();

		string s, tmp;
		int x, N;

		cin >> N;
		cin.ignore();
		rep(i,0,N){
			getline(cin, s);
			stringstream ss(s);

			while(ss >> tmp) {
				stringstream st;
				st << tmp;
				st >> x;

				shirt[x].push_back(i);
			}		
		}

		amask = (1<<N) - 1;

		mset(dp, -1);

		cout << solve(0, 1) << endl;
	}

	return 0;
}


//////////////////////////////////////////////////////////////////////////////

int main() {
	
	caset{
		rep(i,0,101) shirt[i].clear();

		int N ; scanf("%d",&N);

		string s;
		cin.ignore();

		rep(i,0,N){
			int x = 0;
			getline(cin, s); 

			for(int j=0; s[j]; ++j) {
				if(s[j] == ' ') { 
					shirt[x].push_back(i);
					x = 0; continue; 
				}

				x = x*10 + s[j]-'0';
			}
			shirt[x].push_back(i);
		}

		amask = (1<<N) - 1;

		mset(dp, -1);

		printf("%lld\n", solve(0, 1));
	}

	return 0;
}
