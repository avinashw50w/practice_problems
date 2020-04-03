/*There are ‘n’ ticket windows in the railway station, ith window has ai tickets available. 
Price of a ticket is equal to the number of tickets remaining in that window at that time. 
When ‘m’ tickets have been sold, what’s the maximum amount of money the railway station can earn?
e.g.
INPUT: n=2, m=4
a1=2 , a2=5
OUTPUT: 14(2nd window sold 4 tickets so 5+4+3+2).*/

#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<b;++i)

int main() {

	int N, M;
	cin>>N>>M;

	int a, maxi = INT_MIN;
	map<int, int> f;

	REP(i, 0, N) {
		cin>>a;
		f[a]++;
		maxi = max(maxi, a);
	}

	int ans = 0;

	REP(i, 0, M) {

		ans += maxi;

		if(f[maxi]) f[maxi]--;

		if(f[maxi-1]) f[maxi-1]++;

		if(f[maxi] == 0) maxi -= 1;
	}

	cout << ans << endl;
}