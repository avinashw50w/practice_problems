/*Rhezo and his friend Vanya love problem solving. They have a problem set containing N problems, with points assigned to each. Rhezo wants to solve problems 
in such a way that he gets the maximum number of points. Rhezo has a weird habit of solving only prime number of consecutive problems, that is, if he solves 
X consecutive problems from the problem set, then X should be prime. Vanya has already solved all problems from the problem set and he wonders how much 
maximum points Rhezo can get. Vanya can answer this, but can you?

Input:

First line contains a single integer N, denoting the number of problems in the problem set. 
Next line contains N space separated integers denoting the points assigned to the problems.

Output:

Print a single integer, the maximum points Rhezo can get.

Constraints:

1
≤
N
≤
5000
1≤N≤5000
1
≤
1≤Points of Problems
≤
10
5*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000+1;

vector<int> v;
bool p[maxn]; 
int pre[maxn], dp[maxn];

void seive() {
	v.push_back(2);
	for(int i=3; i<maxn; i+=2) {
		if(!p[i]){
			v.push_back(i);
			for(int j=i*i; j<maxn; j+= 2*i) p[j] = true;
		}
	}
}

int main() {

	seive();

	int n; cin>>n;

	for(int i=1;i<=n;++i){
		int x; cin>>x;
		pre[i] = pre[i-1] + x;	// cummulative sum of all points
	}

	dp[0] = dp[1] = 0;
	
	// if the number of elements are i
	for(int i=2; i<=n; ++i) {
		dp[i] = dp[i-1];
		
		for(int j=0; j<v.size() and v[j]<=i; ++j){
			int r = i-v[j]-1;

			if(r == -1) dp[i] = max(dp[i], pre[i]);

			else dp[i] = max(dp[i], dp[r] + (pre[i]-pre[r+1]) );
		}
	}

	cout << dp[n] << endl;
}
