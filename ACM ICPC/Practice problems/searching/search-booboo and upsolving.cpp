/*The hero of this story is a toddler named BooBoo. Inspired by the legendary competitive coder Gena, BooBoo has also started preparing to race to the top of the ranks.

BooBoo is going to practice N different problems in the exact given order over the next M days. For each problem, he writes down the amount of time qi 
he will take to think and code the ith problem (He is quite good at estimating!). Before starting on the problems, he took advice from experienced competitive 
programmers on his practice routine and almost all of them advised him to keep his daily load at the minimum possible and avoid over training.

Since BooBoo already has N problems to solve, he asks you to find the minimum time T such that training everyday for a time ti≤T is sufficient to solve all the 
N problems in M days.

Note : Unlike in real world, you cannot think on a problem on one day and solve it on the other day. You need to do it on the very same day!

Input Format:

The first line contains two space separated integers N and M. The next line contains N space separated integers denoting the time qi required to solve the 
ith problem.

Output Format:

The output consists of one integer, the minimum time T as described in the problem statement.

Constraints:

1≤N≤105
1≤M≤N
1≤qi≤1012

SAMPLE INPUT 
5 3
1 2 2 1 3
SAMPLE OUTPUT 
3
Explanation
By setting T = 3, we can solve 1st two questions on day 1, next two on day 2 and 5th one on day 3.*/

/* Binary search the value of time t such that the days required for completing the work is <= M, if the person works t amount of time each day. */ 

const int maxn = 1000000000;
typedef long long int ll;
int n, m;
ll T[100000+2];

int daysRequiredFor(ll t) {
	int days = 1;
	ll currSum = 0;

	rep(i,0,n) {
		if(currSum + T[i] > t) {
			days += 1;
			currSum = T[i];
		}
		else 
			currSum += T[i];
	}

	return days;
}

int main() {

	cin>>n>>m;

	ll lo = 1, hi = 1LL * maxn * maxn;
	
	rep(i,0,n) {
		cin>>T[i];
		lo = max(lo, T[i]);
	}

	while(lo < hi) {
		ll mid = (lo + hi)>>1;

		if(daysRequiredFor(mid) <= m) hi = mid;

		else lo = mid+1;
	}

	cout << lo << endl;	// lo or hi , it doesn't matter, because the while loop ends when lo == hi
	return 0;
}
