/*Little Alice likes to play with her collection of N integers. She knows her collection very well, and often likes to come up with different 
observations about the numbers.

For example, Alice had recently learned that two numbers can be jealous of each other in case they have a non-trivial common divisor (i.e. 
greater than one divisor). For example, the numbers 8 and 12 are jealous of each other, because they have common divisor 4. But the numbers 8 
and 9 aren't jealous of each other, because they don't have any common divisors other than 1.

Alice wants to organize a tea-party, and to invite some of the numbers from her collection. She wants to invite as much numbers as possible, 
in such a way that no two number among the invited are jealous of each other. Please help her to find the maximal amount of numbers she can 
invite.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains a single integer N denoting the amount of numbers in Alice's collection.

The second line contains N space-separated integers A1, A2, ..., AN denoting the numbers from the collection.

Output

For each test case, output a single line containing the maximal amount of numbers that can be invited to the tea-party.

Constraints

1 ≤ T ≤ 104
1 ≤ N ≤ 103
1 ≤ Sum of N over all the test cases in a single file ≤ 104
1 ≤ Ai ≤ 103*/

/*PREREQUISITES:
Dynamic programming, prime factorization

PROBLEM:
Given a list of positive integers, find the size of the largest pairwise-coprime sublist.

QUICK EXPLANATION:
Let's call a prime number small if p≤√1000, i.e., p≤31. There are 11 such primes, so a set of small primes can be represented 
by a bit set of 11 bits.

Let S(k) be the set of small prime factors of k.

Sort the list a1,…,an by their largest prime factor. Then, if S is a set of small primes, define the function F(i,S) as the 
size of largest pairwise-coprime sublist of a1,…,ai such that are also pairwise-coprime with S. Then the answer we're looking for 
must be F(n,NULL). F(i,S) can be computed with the following recurrence:
F(i,S)={F(i−1,S)						if S∩S(ai)≠NULL
		max(F(i−1,S),1+F(pi,S∪S(ai)))  if S∩S(ai)=NULL
		

where pi is the largest index i′ less than i and such that either ai′=1 or the largest prime factor of ai′ is different from the largest 
prime factor of ai.

For the base case, we have F(0,S)=0 for any S.*/

/*========================================================================================*/
const int MAXN = 1000+5;
int N, a;
int vis[1<<11], dp[1<<11], isp[MAXN];

vector<int> bucket[MAXN/2], primes, plist;

void gen() {
	for(ll i=2; i<=MAXN; ++i){
		if(!isp[i]){
			primes.push_back(i);
			isp[i] = i;
			for(ll j=i*i; j<=MAXN; j+=i)
				isp[j] = i;
		}
	}
}

int main() {

	gen();

	caset{
		rep(i,0,MAXN/2) bucket[i].clear();
		plist.clear();
		mset(vis,0);

		si(N);
		int cntOne = 0;
		rep(i,0,N) {
			si(a);
			if(a == 1) cntOne++;
			else{
				int mask = 0;
				rep(j,0,11)
					if(a%primes[j] == 0)
						mask |= (1<<j);

				for(int j=primes.size()-1; j>=0; --j) {
					if(a%primes[j] == 0){
						bucket[j].push_back(mask);
						break;
					}
				}
			}
		}

		dp[0] = cntOne;
		vis[0] = 1;
		plist.push_back(0);

		rep(i,0,primes.size()) {
			if(bucket[i].empty()) continue;
			sort(all(bucket[i]));
			bucket[i].erase(unique(all(bucket[i])), bucket[i].end());
			reverse(all(bucket[i]));

			vector<int> nlist = plist;
			rep(j,0,plist.size()) {
				int pmask = plist[j];
				rep(k,0,bucket[i].size()) {
					int cmask = bucket[i][k];
					if((pmask & cmask) == 0) {
						int nmask = (pmask | cmask);
						if(!vis[nmask]) {
							vis[nmask] = 1;
							dp[nmask] = dp[pmask] + 1;
							nlist.push_back(nmask);
						}
						else dp[nmask] = max(dp[nmask], dp[pmask] + 1);
					}
				}
			}
			if(nlist.size() > plist.size()){
				sort(all(nlist));
				reverse(all(nlist));
				plist = nlist;
			}
		}

		int ans = 0;

		rep(i,0,plist.size()) 
			ans = max(ans, dp[plist[i]]);

		printf("%d\n", ans);
	}
	return 0;
}
