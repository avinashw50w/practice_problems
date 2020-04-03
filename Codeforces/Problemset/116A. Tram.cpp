/*outputstandard output
Linear Kingdom has exactly one tram line. It has n stops, numbered from 1 to n in the order of tram's movement. 
At the i-th stop ai passengers exit the tram, while bi passengers enter it. The tram is empty before it 
arrives at the first stop. Also, when the tram arrives at the last stop, all passengers exit so that it 
becomes empty.

Your task is to calculate the tram's minimum capacity such that the number of people inside the tram at 
any time never exceeds this capacity. Note that at each stop all exiting passengers exit before any 
entering passenger enters the tram.

Input
The first line contains a single number n (2 ≤ n ≤ 1000) — the number of the tram's stops.

Then n lines follow, each contains two integers ai and bi (0 ≤ ai, bi ≤ 1000) — 
the number of passengers that exits the tram at the i-th stop, and the number of passengers that enter 
the tram at the i-th stop. The stops are given from the first to the last stop in the order of tram's movement.
4
0 3
2 5
4 2
4 0
outputCopy
6*/

#include <iostream>
using namespace std;

int main() {
	int n,a,b,sum=0,mx=0; cin >> n;
	while(n--) {
		cin>>a>>b;
		sum += (b-a);
		mx = max(mx, sum);
	}
	cout << mx << endl;
}