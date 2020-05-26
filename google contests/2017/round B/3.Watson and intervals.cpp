/*Sherlock and Watson have mastered the intricacies of the language C++ in their programming course, so they have moved on to algorithmic problems. In today's 
class, the tutor introduced the problem of merging one-dimensional intervals. N intervals are given, and the ith interval is defined by the inclusive endpoints 
[Li, Ri], where Li ≤ Ri. 

The tutor defined the covered area of a set of intervals as the number of integers appearing in at least one of the intervals. 
(Formally, an integer p contributes to the covered area if there is some j such that Lj ≤ p ≤ Rj.) 

Now, Watson always likes to challenge Sherlock. He has asked Sherlock to remove exactly one interval such that the covered area of the remaining intervals is 
minimized. Help Sherlock find this minimum possible covered area, after removing exactly one of the N intervals.

Input

Each test case consists of one line with eight integers N, L1, R1, A, B, C1, C2, and M. N is the number of intervals, and the other seven values are parameters 
that you should use to generate the other intervals, as follows: 

First define x1 = L1 and y1 = R1. Then, use the recurrences below to generate xi, yi for i = 2 to N:

xi = ( A*xi-1 + B*yi-1 + C1 ) modulo M.
yi = ( A*yi-1 + B*xi-1 + C2 ) modulo M.
We define Li = min(xi, yi) and Ri = max(xi, yi), for all i = 2 to N.
Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the minimum possible covered area of all 
of the intervals remaining after removing exactly one interval.

Limits

1 ≤ T ≤ 50.
0 ≤ L1 ≤ R1 ≤ 109.
0 ≤ A ≤ 109.
0 ≤ B ≤ 109.
0 ≤ C1 ≤ 109.
0 ≤ C2 ≤ 109.
1 ≤ M ≤ 109.

Small dataset

1 ≤ N ≤ 1000.
Large dataset

1 ≤ N ≤ 5 * 105(500000).
Sample


Input 
 	
Output 
 
3
1 1 1 1 1 1 1 1
3 2 5 1 2 3 4 10
4 3 4 3 3 8 10 10

Case #1: 0
Case #2: 4
Case #3: 9

In case 1, using the generation method, the set of intervals generated are: {[1, 1]}. Removing the only interval, the covered area is 0.

In case 2, using the generation method, the set of intervals generated are: {[2, 5], [3, 5], [4, 7]}. Removing the 
first, second or third interval would cause the covered area of remaining intervals to be 5, 6 and 4, respectively.

In case 3, using the generation method, the set of intervals generated are: {[3, 4], [1, 9], [0, 8], [2, 4]}. 
Removing the first, second, third or fourth interval 
would cause the covered area of remaining intervals to be 10, 9, 9 and 10, respectively.*/
#include <bits/stdc++.h>
using namespace std;
 
#define sd(mark) scanf("%d",&mark)
#define ss(mark) scanf("%s",&mark)
#define sl(mark) scanf("%lld",&mark)
#define debug(mark) printf("check%d\n",mark)
#define clr(mark) memset(mark,0,sizeof(mark))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long
#define N 500010

vector<pair<int,int> > events;
set<int> sett;
pair<int,int> interval[N];
int Count[N];
int main()
{
	// freopen("C1.in","r",stdin);
	// freopen("C1.out","w",stdout);
	int t;
	sd(t);
	for(int tt=1;tt<=t;++tt)
	{
		cerr<<tt<<'\n';
		events.clear();
		sett.clear();
		clr(Count);
		ll n,L1,R1,A,B,C1,C2,M,i,j;
		sl(n);sl(L1);sl(R1);sl(A);sl(B);sl(C1);sl(C2);sl(M);	
		ll x=L1,y=R1;
		interval[0].F=L1;
		interval[0].S=R1;
		events.PB(MP(L1,1));
		events.PB(MP(R1+1,-1));

		for(i=1;i<n;++i)
		{
			interval[i].F=(A*x+B*y+C1)%M;
			interval[i].S=(A*y+B*x+C2)%M;
			x=interval[i].F;
			y=interval[i].S;
			interval[i].F=min(x,y);
			interval[i].S=max(x,y);
			events.PB(MP(interval[i].F,i+1));
			events.PB(MP(interval[i].S+1,-i-1));
			// printf("%lld %lld\n",x,y);
		}
		sort(events.begin(),events.end());
		int prev=0,ans=0;
		for(i=0;i<events.size();++i)
		{
			int cur=events[i].F;
			int pos=abs(events[i].S)-1;
			if((int)sett.size() > 0)
				ans=ans+cur-prev;
			if((int)sett.size() == 1)
				Count[*sett.begin()]+=(cur-prev);
			if(events[i].S < 0)
				sett.erase(pos);
			else
				sett.insert(pos);
			prev=cur;
		}
		int maxx=0;
		for(i=0;i<n;++i)
			maxx=max(maxx,Count[i]);
		printf("Case #%d: %d\n",tt,ans-maxx);
	}
}