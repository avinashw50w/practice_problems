/*Roy has a rope of length 
L
L meters. This rope has several other ropes attached to it at the end of every meter (except for the end of the rope). 
At each meter there are two ropes attached to this main rope, let's call them upper and lower ropes. See the following example.

			|	|		|
		-------------------------
			|		|		|
			|				|

Roy lit the rope on fire from the left end. This fire burns down the rope by 
1
1 meter/minute. 
Your task is to find how much time (in minutes) will the fire take to burn down the entire rope.

Input: 
First line contains T - number of test cases.
First line of each test case contains L - length of the rope.
Second line of each test case contains L−1 integers separated by space denoting lengths of all the upper ropes at each meter.
Third line of each test case contains L−1 integers separated by space denoting lengths all the lower ropes at each meter.

Output:
Output the time (in minutes) required to burn down the entire rope for each test case in a new line.

Constraints:
1≤T≤10 
2≤L≤1000000 
0≤upper[i]≤1000000 where 1≤i≤L−1 
0≤lower[i]≤1000000 where  */

/*This Question could be solved easily in a backward thinking as you
can start from the end of the rope.

For each Minute, Fire goes in 3 directions so,

Initialize a variable timeLeft=0.

Note: When I say first , second,... node, I mean from the end of the rope.

Loop over the rope nodes in a reverse order:

Check for the first node, (up and down) ropes, then choose the maximum,
Why the maximum ?????

Because when you calculate the time for the maximum rope, the other rope 
will be burnt during that time (as it has shorter length).

When you have the maximum, determine if it needs extra time to be burnt,

Firstly:

subtract (1) from the maximum as one unit from it will be burnt
during the time of the horizontal rope burning (as fire goes in directions at the same time).

Secondly:

Check how many horizontal units have been burnt, since maybe some parts 
of maximum (of up , down) rope burnt during the burning of the next parts
of the horizontal rope, this is the benefit form the variable (timeLeft),as you should increase it by 1, (indicating the time used for the burning of the 
horizontal rope until node (i) from the last).

So subtract (timeLeft) from the maximum rope time at node (i) and increase theresult to the answer.

Note: 
l−1>=i>=1.
Note: You should increase the extra time to the burning time, so you
should subtract (burning time for horizontal rope at node (i−1) + extra time for the maximum burning for node (i) ) from the next node (i−1) maximum and so on...........

Time Complexity: O(L).

Memory Space Complexity: O(L).*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000+1;
int n;
long long up[maxn], down[maxn];

int main() {
	int t; cin>>t;
	while(t--) {

		cin>>n;

		for(int i=1; i<=n-1; ++i) cin>>up[i];
		for(int i=1; i<=n-1; ++i) cin>>down[i];	

		long long ans = n, time_taken = 0;	// initial ans = n ,ie, time taken to burn the horizontal rope

		for(int i=n-1; i>=1; --i) {

			long long vertical_rope_time = max(0LL, max(up[i], down[i]) - 1 - time_taken);	// time taken to burn the vertical rope

			ans += vertical_rope_time;

			time_taken += vertical_rope_time + 1;	// time taken to burn vertical rope + the horizontal rope in between two consecutive vertical ropes
		}

		cout << ans << endl;
	}
}