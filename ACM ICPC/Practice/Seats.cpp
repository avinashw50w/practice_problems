/* There are N seats in a theatre, all of them in a single row. The seats are numbered from 1 to N. You are given two types of events:
1 — A person arrives. Persons are numbered from 1 in order of their arrival.
2 i — Person i leaves the theatre.
A person arriving in the theatre chooses a seat according to the following algorithm:

If the entire theatre is empty, the person will occupy seat 1.

Otherwise, he will occupy the seat which is farthest possible from any nearest seated persons. In other words, in the seat which maximizes the minimum distance to any other person currently seated. If there are many such seats, the person will occupy the leftmost of them. 

Input

The first line of input contains 2 space-separated integers: the first is N, denoting the number of seats, and the second is Q, denoting the number of events.
Then Q events follow in the format described above.
Output

For each person arriving, output the seat number that he occupies.
Constraints

1 = N = 1018
1 = Q = 2 * 105
Each query is valid.
Example

Input:
2 7
1
1
2 1
1
2 2
2 3
1

Output:
1
2
1
1

Explanation:

Initially both seats are empty (x denotes empty seat and number denotes id of person occupying it):

xx

Query 1: Person #1 arrives and takes seat 1 (so output 1):

1x

Query 2: Person #2 arrives and takes seat 2 (so output 2):

12

Query 3: Person #1 leaves:

x2

Query 4: Person #3 arrives and takes seat 1 (so output 1):

32

Query 5: Person #2 leaves:

3x

Query 6 Person #3 leaves:

xx

Query 7: Person #4 arrives and takes seat 1 (so output 1):

4x  */

using namespace std;
const long long INF = 2*(1e18 + 1007);
long long n;
struct segment
{
	long long l, r;
	segment(){}
	segment(long long _l, long long _r)
	{
		l = _l;
		r = _r;
	}
	long long bestPos()
	{
		long long ans = (l + r) / 2;
		if (ans <= 0)
		{
			ans = 1;
		}
		if (ans > n) ans = n;
		return ans;
	}
	long long bestLen()
	{
		if (r - l + 1 <= 2)
		{
			return -100000;
		}
		return min(bestPos() - l, r - bestPos());
	}	
};
bool operator<(segment y, segment x)
{
	return make_pair(-y.bestLen(), y.bestPos()) < make_pair(-x.bestLen(), x.bestPos());
}
struct segment2
{
	long long l, r;
	segment2(){}
	segment2(long long _l, long long _r)
	{
		l = _l;
		r = _r;
	}
	long long bestPos()
	{
		long long ans = (l + r) / 2;
		if (ans <= 0)
		{
			ans = 1;
		}
		if (ans > n) ans = n;
	}
	long long bestLen()
	{
		if (r - l + 1 <= 2)
		{
			return -100000;
		}
		return min(bestPos() - l, r - bestPos());
	}
	bool operator<(segment2 x)
	{
		return l < x.l;
	}
};
bool operator<(segment2 y, segment2 x)
{
	return y.l < x.l;
}
set<segment>s;
set<segment2>s2;
long long pos[200007];
int posp = 1;
void add(long long l, long long r)
{
	s.insert(segment(l, r));
	s2.insert(segment2(l, r));
}
void del(long long l, long long r)
{
	s.erase(segment(l, r));
	s2.erase(segment2(l, r));
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	scanf("%lld%d", &n, &q);
	add(-INF, INF);
	for (int i = 1; i <= q; i++)
	{
		int mode;
		scanf("%d", &mode);
		if (mode == 1)
		{
			segment ourBest = *s.begin();
			pos[posp] = ourBest.bestPos();
			printf("%lld\n", pos[posp]);
			del(ourBest.l, ourBest.r);
			add(ourBest.l, pos[posp]);
			add(pos[posp], ourBest.r);
			posp++;
		}
		else
		{
			int x;
			scanf("%d", &x);
			set<segment2>::iterator it = s2.lower_bound(segment2(pos[x], -1));
			segment2 r = *it;
			it--;
			segment2 l = *it;
			del(l.l, l.r);
			del(r.l, r.r);
			add(l.l, r.r);
		}
	}
} 
Comments 

